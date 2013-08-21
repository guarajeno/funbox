<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>amfPHP JSON Pizza Example</title>
<script type="text/javascript" src="js/jquery.js"></script>
<script type="text/javascript" src="js/json2.js"></script>

<script language="javascript">


// Registro de usuario
function registerUser($nickname , $password , $name , $lastname , $date_birthday)
{
    var data = JSON.stringify({"serviceName":"UserService", "methodName":"registerUser","parameters":[$nickname, $password , $name , $lastname , $date_birthday]});
    $.post("amfphp-2.1.1/Amfphp/?contentType=application/json", data, onSuccessRegisterUser)
	.fail(function() 
		{
			console.log("error" , "Error de comunication");
		}
	);
} 

function onSuccessRegisterUser(data)
{
	switch (data.msg) {
		case "fail_register_user":
			alert("Error , no se pudi guardar al usuario");
			break;
		case "fail_nickname_duplicate":
			alert("Error , el nickname ya existe");
			break;
		case "success":
			alert("Se guardó correctamente, id del usuario es " + data.user_id);
			break;
	}
}


// Obtener un usuario en base al nickname y password
function getUser($nickname , $password)
{
    var data = JSON.stringify({"serviceName":"UserService", "methodName":"getUser","parameters":[$nickname, $password]});
    $.post("amfphp-2.1.1/Amfphp/?contentType=application/json", data, onSuccessGetUser)
	.fail(function() 
		{
			console.log("error" , "Error de comunication");
		}
	);
} 

function onSuccessGetUser(data)
{
	if (data.id == 0) {
		alert("Error , tu nickname y/o password no son correctos");
	} else {
		alert("Nombre : " + data.name + "\n Apellidos : " + data.lastname + "\n Cumpleaños : " + data.date_brithday + "\n Score : " + data.score);
	}
}


// Obtener un usuario en base a su id
function getUserById($id)
{
    var data = JSON.stringify({"serviceName":"UserService", "methodName":"getUserById","parameters":[$id]});
    $.post("amfphp-2.1.1/Amfphp/?contentType=application/json", data, onSuccessGetUserById)
	.fail(function() 
		{
			console.log("error" , "Error de comunication");
		}
	);
} 

function onSuccessGetUserById(data)
{
	if (data.id == 0) {
		alert("Error , No existe un usuario con ese id");
	} else {
		alert("Nombre : " + data.name + "\n Apellidos : " + data.lastname + "\n Cumpleaños : " + data.date_brithday + "\n Score : " + data.score);
	}
}

// guardar el score
function saveScore($user_id, $game_id , $score_game , $time_game)
{
    var data = JSON.stringify({"serviceName":"UserService", "methodName":"saveScore","parameters":[$user_id, $game_id , $score_game , $time_game]});
    $.post("amfphp-2.1.1/Amfphp/?contentType=application/json", data, onSuccessSaveScore)
	.fail(function() 
		{
			console.log("error" , "Error de comunication");
		}
	);
} 

function onSuccessSaveScore(data)
{
	switch (data.msg) {
		case "fail_save_insert":
			alert("Error , no se pudo guardar el score nuevo");
			break;
		case "fail_save_score":
			alert("Error , no se pudo actualizar el score");
			break;
		case "fail_save_score_total":
			alert("Error , no se pudo actualizar el score total");
			break;
		case "fail_save_data":
			alert("Error , no se pudo guardar los demas datos (tiempo de juego , cantidad de jugadas , fecha de juego)");
			break;
		case "success":
			alert("Se guardó exitosamente, su score total actual es : " + data.score_total + " del usuario : " + data.user_id);
			break;
	}
}



/* Funciones de testeo */
function onTestRegister() {
	registerUser("funbox" , "123" , "Funbox Testing" , "VideoGames" , "2013-08-30");
}

function onTestGetUser() {
	getUser("funbox" , "123");
}

function onTestGetUserById() {
	getUserById("19");
}

function onTestSaveScore() {
	saveScore("19", "1" , "10" , "1000");
}



</script>

</head>

<body>

<input type="button" value="Register User" id="bimButton" onClick="javascript:onTestRegister();" width="200" height="100" /> </br>
<input type="button" value="getUser" id="bimButton" onClick="javascript:onTestGetUser();" width="200" height="100" /></br>
<input type="button" value="getUserById" id="bimButton" onClick="javascript:onTestGetUserById();" width="200" height="100" /></br>
<input type="button" value="Save Score" id="bimButton" onClick="javascript:onTestSaveScore();" width="200" height="100" />
<div id="response" />
</body>
</html>
