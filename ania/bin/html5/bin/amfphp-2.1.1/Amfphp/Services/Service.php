<?php
require_once "../../config_db.php";
// require_once dirname(dirname(dirname(dirname(__FILE__))))."/config_db.php";
	
class Service {
	
    protected $cn;

	// mensajes genericos para las modificaciones
	public static $MSG_SUCCESSFUL = "successful";
	public static $MSG_FAIL       = "fail";
    
	protected $last_nro_error;
	
	public function __construct($create_conecction = false) {
		// realiza una conexion cada vez que se crear la clase.
		// Cuando se invoca a cualquier metodo se instancia la clase
		if ($create_conecction) {
			$this->cn = mysql_connect(DB_HOST, DB_USER, DB_PASS) or die("Failed to connect to MySQL");
			mysql_select_db(DB_NAME , $this->cn);
			// disabilitando el autocommit de la BD
			$sql = "SET AUTOCOMMIT = 0";
			mysql_query($sql , $this->cn);
		}
	}
	
	// funciones de utilidad
	protected function secureParam($param) {
		return mysql_real_escape_string($param);
	}
	
	protected function isAffectOneRow() {
		// verificar si afectó a la tabla
		$rows = mysql_affected_rows($this->cn);
		return (($rows == 1)?true:false);
	}
	
	protected function query($sql) {
		$rs = mysql_query($sql , $this->cn);
		if (mysql_errno()) {
			$this->last_nro_error = mysql_errno();
			$error = "MySQL error ".mysql_errno().": ".mysql_error()."\n<br>When executing:<br>\n$sql\n<br>";
			$log = mysql_query("INSERT INTO errors (error_date, error_text) VALUES (NOW(),'".$this->escape_data($error)."')" , $this->cn); 
		}
		return $rs;
	}
	
	protected function getLastNroError() {
		return $this->last_nro_error;
	}
	
	private function escape_data($data){
		if(ini_get('magic_quotes_gpc')){
		  $data = stripslashes($data);
		}
		return mysql_real_escape_string(trim($data), $this->cn);
	} 
	
	protected function fetch_array($rs) {
		return mysql_fetch_assoc($rs);
	}
    
    protected function num_rows($rs) {
        return mysql_num_rows($rs);
    }
	
	protected function begin() {
		mysql_query("BEGIN" , $this->cn);
	}
	
	protected function commit() {
		mysql_query("COMMIT" , $this->cn);
	}
	
	protected function rollback() {
		mysql_query("ROLLBACK" , $this->cn);
	}
    
    protected function insert_id() {
		return mysql_insert_id();
	}
    
    public function __destruct() {
       // destruir la conexion
	    if (isset($this->cn)) {
			mysql_close($this->cn);
            unset($this->cn);
	    }
   }
	
	
}
?>
