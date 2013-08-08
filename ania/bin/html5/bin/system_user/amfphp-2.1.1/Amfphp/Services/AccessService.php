<?php
/**
 * A built-in amfphp service that allows introspection into services and their methods.
 * Remove from production servers
 */
require_once "../../config_db.php";
require_once "Services/Service.php";
	

class AccessService extends Service {


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
				$response["error"] = "nickname_duplicate";
			}
			$this->rollback();
		}
        
        return $response;
	}
    
    public function login($email , $password) {
        $email     = $this->secureParam($email);        
		$password  = $this->secureParam($password);
        // convertir a minuscula
        $email = strtolower($email);
        
        // buscar si existe el correo
        $sql = "SELECT * FROM player p , user u WHERE p.user_id = u.id AND email_rg = '%s'";
        $query_param = sprintf($sql , $email);
        $rs = $this->query($query_param);
        $user = array("user_id" => 0 , "msg" => "error");
        
        if ($rs) {
            while ($row = $this->fetch_array($rs)) {
                $user = $row;
            }
            /* Si existe usuario */
            if ($user["user_id"] == 0) {
                $user["msg"] = "error_mail";
            } else {
                /* buscar si esta bien su contraseña
                */
                $sql = "SELECT * FROM player p , user u WHERE p.user_id = u.id AND email_rg = '%s' AND password = '%s'";
                $query_param = sprintf($sql , $email, $password);
                $rs = $this->query($query_param);
                
                if ($rs) {
                    $user["user_id"] = 0;
                    while ($row = $this->fetch_array($rs)) {
                        $user = $row;
                    }
                    /* validar si existe usuario*/
                    if ($user["user_id"] == 0) {
                        $user["msg"] = "error_password";
                    } else {
                        $user["msg"] = "success";
                    }
                }
            
            }
        }
        /*
        $user = array("user_id" => 0);
        while ($row = $this->fetch_array($rs)) {
            $user = $row;
        }
        */
        return $user;
    }
}
?>