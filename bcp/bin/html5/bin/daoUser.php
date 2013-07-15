<?php
    include_once "connect.php";
    
    class daoUser {
		
		var $connection;
		
		public function daoUser($conn) {
			$this->connection = $conn;
		}
            
        public function getUsers($from , $mount) {
            $query = "SELECT id , uid , (SELECT @rownum:=0) r , score , date , name_fb , plays FROM scores p ORDER BY p.id ASC LIMIT ".$from.",".$mount." ";
            $score_query = mysql_query($query , $this->connection);
            $arrScores = array();
            while ($row = mysql_fetch_array($score_query)) {
                $arrScores[] = $row;
            }
            return $arrScores;
        }
		
        public function getAllUsers() {
            $query = "SELECT * FROM scores p, (SELECT @rownum:=0) r ORDER BY p.id ASC";
            $score_query = mysql_query($query , $this->connection);
            $arrScores = array();
            while ($row = mysql_fetch_array($score_query)) {
                $arrScores[] = $row;
            }
            return $arrScores;
        }		
        
        public function getUser($id) {
            $query = "SELECT * FROM scores WHERE uid = ".$id;
            $result_db = mysql_query($query , $this->connection);
            $s = mysql_fetch_array($result_db);
            return $s;
        }
        
        public function getTotalUsers() {
            $query = "SELECT count(*) AS mount";
            $query.= " FROM scores";
            $result_db = mysql_query($query , $this->connection);
            $row = mysql_fetch_array($result_db);
            return $row["mount"];
        }
        
        public function deleteUser($id) {
            $query = "DELETE FROM scores WHERE uid = ".$id;
            mysql_query($query , $this->connection);
        }
    }
?>