<?php
include 'config_db.php'
?>

<!DOCTYPE html>
<html lang="en">
<head>
	<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
	<meta charset="utf-8">
	<title>ania</title>
	<title>amfPHP JSON Pizza Example</title>
	<script type="text/javascript" src="js/jquery.js"></script>
	<script type="text/javascript" src="js/json2.js"></script>
	<script language="javascript">
		// Registro de usuario
		function registerUser($nickname , $password , $name , $lastname , $date_birthday)
		{
			var data = JSON.stringify({"serviceName":"UserService", "methodName":"registerUser","parameters":[$nickname, $password , $name , $lastname , $date_birthday]});
			$.post("amfphp-2.1.1/Amfphp/?contentType=application/json", data, onSuccess)
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
			alert("save score");
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
				default:
					alert("error: " + data.msg);
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

<body style="padding: 0; margin: 0;">
	
	<!-- <div id="haxe:trace" style="position: absolute; z-index: 2147483647; display: none;"></div> -->
	
	<div id="haxe:jeash" style="background-color: #0; width: 2000px; height: 820px" data-framerate="60"></div>
	<div id="video_episode_01" style="top: -1000px">
		<div id="video_01_container" style="position: relative; left: 58px; top: 35px;">
			<video id="video_01" width="1024" height="600" controls="controls" preload="true">
				<source src="video/episode01_preview.flv" type="video/flv" />
			</video>
		</div>
		<div id="video_01_close" style="background-image: url('./img/common/web_common_button_close_normal.png'); width:192px; height:68px; position: relative; left: 950px; top: -620px;" onclick="hideVideos()">
		</div>
	</div>
	<script>function winParameters () { return null; }</script>
	<script>
		//alert("hola");
		document.getElementById("video_episode_01").style.backgroundImage = "url('./img/common/web_common_videosupport.png')";
		document.getElementById("video_episode_01").style.position = "absolute";
		document.getElementById("video_episode_01").style.width = "1121px";
		document.getElementById("video_episode_01").style.height = "690px";
		
		function showVideo01(x, y)
		{
			document.getElementById("video_episode_01").style.left = x + "px";
			document.getElementById("video_episode_01").style.top = y + "px";
		}
		
		function hideVideos()
		{
			document.getElementById("video_episode_01").style.top = "-1000px";
			document.getElementById("video_01").pause();
		}
		
		function resize(factor, middleWidth)
		{
			document.getElementById("video_episode_01").style.backgroundSize = 1121 * factor + "px " + 690 * factor + "px";
			document.getElementById("video_episode_01").style.width = 1121 * factor + "px";
			document.getElementById("video_episode_01").style.height = 690 * factor + "px";
			document.getElementById("video_episode_01").style.left = (middleWidth - (1121 * factor / 2)) + "px";
			
			document.getElementById("video_01_container").style.left = 58 * factor + "px";
			document.getElementById("video_01_container").style.top = 35 * factor + "px";
			
			document.getElementById("video_01_close").style.backgroundSize = 192 * factor + "px " + 68 * factor + "px";
			document.getElementById("video_01_close").style.width = 192 * factor + "px";
			document.getElementById("video_01_close").style.height = 68 * factor + "px";
			document.getElementById("video_01_close").style.left = 950 * factor + "px";
			document.getElementById("video_01_close").style.top = (-620 * factor) + "px";
			
			document.getElementById("video_01").style.width = 1024 * factor + "px";
			document.getElementById("video_01").style.height = 600 * factor + "px";
		}
	</script>
	<script id="haxe:jeash:script" type="text/javascript" src="./ania.js"></script>
	<script>
		UserManager.sendScore(20);
	</script>
</body>
</html>