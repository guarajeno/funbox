<?php
/**
 * A built-in amfphp service that allows introspection into services and their methods.
 * Remove from production servers
 */
require_once "../../config_db.php";
require_once "Services/Service.php";
	

class UserService extends Service {


	public function __construct() {
		parent::__construct(true);
	}

	// Usuario
	public function registerUser($nickname, $password , $name , $lastname , $date_birthday) {
		// parse params
		$nickname = $this->secureParam($nickname);        
		$password = md5($this->secureParam($password));        
		$name     = $this->secureParam($name);
		$lastname = $this->secureParam($lastname);
		$date_birthday = $this->secureParam($date_birthday);
		

        $response = array("msg" => "success" , "user_id" => 0);
		$this->begin();
		
		// se arma el query
		$query_format = "INSERT INTO user
			(
			nickname,
			password,
			name,
			lastname ,
			date_birthday,
			score
			) VALUES (
			'%s' , 
			'%s' , 
			'%s' , 
			'%s' , 
			'%s' ,
			%d)";
		$query_param = sprintf($query_format ,
			$nickname,
			$password,
			$name,
			$lastname,
			$date_birthday,
			0);
			
		$response["msg"] = "fail_register_user";  
		// execute query
		$rs = $this->query($query_param);
		$user_id = $this->insert_id();
		
		if ($rs) {
			$response["msg"] = "success";
			$response["user_id"] = $user_id;
			$this->commit();
		} else {
			// el error 1062 es cuando ya existe un dato en la BD
			if ($this->getLastNroError() == 1062) {
				$response["msg"] = "fail_nickname_duplicate";
			}
			$this->rollback();
		}
        
        return $response;
	}
	
	
	public function saveScore($user_id, $game_id , $score_game , $time_game) {
		// parse params
		$user_id = $this->secureParam($user_id);        
		$game_id = $this->secureParam($game_id);       
		$score_game = $this->secureParam($score_game);
		$time_game = $this->secureParam($time_game);
		
		$response = array("msg" => "success" , "user_id" => $user_id , "score_total" => 0);
		
		$query_format = "SELECT * FROM player WHERE game_id = %d AND user_id = %s";
		$query_param = sprintf($query_format ,
			$game_id,
			$user_id);
		$rs = $this->query($query_param);
		$count_score = $this->num_rows($rs);
		
		$this->begin();
		
		if ($count_score == 0) {
			// insert score en la BD
			$sql = "INSERT INTO player (user_id , game_id , count_game , last_game , time_game, score_game)
					VALUES ( %s , %d , 1 , NOW() , %d , %d)";
			$sql_param = sprintf($sql ,
				$user_id,
				$game_id,
				$time_game,
				$score_game);
			$rs = $this->query($sql_param);
			if (!$rs) {
				$this->rollback();
				$response["msg"] = "fail_save_insert";
			}
		} else {
			// actualizar los datos comunes
			$sql = "UPDATE player SET count_game = count_game + 1 , last_game = NOW() , time_game = %d 
					 WHERE user_id = %d AND game_id = %d";
			$sql_param = sprintf($sql ,
				$time_game,
				$user_id,
				$game_id);
			$rs = $this->query($sql_param);
			if ($rs) {
				// actualizar el score si es el valor nuevo es mayor
				$sql = "UPDATE player SET score_game = %d
					 WHERE user_id = %d AND game_id = %d AND score_game < %d";
				$sql_param = sprintf($sql ,
					$score_game,
					$user_id,
					$game_id, 
					$score_game);
				$rs = $this->query($sql_param);
				if (!$rs) {
					$this->rollback();
					$response["msg"] = "fail_save_score";
				}
			} else {
				$response["msg"] = "fail_save_data";
				$this->rollback();
			}
		}
		
		// guardar el score total 			
		if ($response["msg"] == "success") {
			// calculate score total
			$sql = "UPDATE user SET score = (SELECT sum(p.score_game) as score_total FROM player p WHERE p.user_id = %s GROUP BY user_id) WHERE id = %s";
			$sql_param = sprintf($sql ,
			$user_id,
			$user_id);
			$rs = $this->query($sql_param);
			if (!$rs) {
				$this->rollback();
				$response["msg"] = "fail_save_score_total";
			} else {
				// guardar en la BD
				$this->commit();
				// obtener el ultimo score del usuario
				$user = $this->getUserById($user_id);
				$response["score_total"] = $user["score"];

			}
		} else {
			$this->rollback();
		}
		
		return $response;
	}
	
	public function getUser($nickname , $password) {
		// parse params
		$nickname = $this->secureParam($nickname);        
		$password = md5($this->secureParam($password));        
		
		$query_format = "SELECT id , name , lastname , nickname , date_birthday , score FROM user WHERE nickname = '%s' AND password = '%s'";
		$query_param = sprintf($query_format ,
			$nickname,
			$password);
			
		$rs = $this->query($query_param);
		$user = array("id" => 0);
		if ($row = $this->fetch_array($rs) ) {
			$user["id"] = $row["id"];
			$user["name"] = $row["name"];
			$user["lastname"] = $row["lastname"];
			$user["nickname"] = $row["nickname"];
			$user["date_brithday"] = $row["date_birthday"];
			$user["score"] = $row["score"];
		}
		return $user;
	}	
	
	
	public function getUserById($user_id) {
		// parse params
		$user_id = $this->secureParam($user_id);        
		
		$query_format = "SELECT id , name , lastname , nickname , date_birthday , score  FROM user WHERE id = %s";
		$query_param = sprintf($query_format ,
			$user_id);
		$rs = $this->query($query_param);
		$user = array("id" => 0);
		if ($row = $this->fetch_array($rs) ) {
			$user["id"] = $row["id"];
			$user["name"] = $row["name"];
			$user["lastname"] = $row["lastname"];
			$user["nickname"] = $row["nickname"];
			$user["date_birthday"] = $row["date_birthday"];
			$user["score"] = $row["score"];
		}
		return $user;
	}	
}
?>