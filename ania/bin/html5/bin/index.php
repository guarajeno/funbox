<!DOCTYPE html>
<html lang="en">
<head>
	<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
	<meta charset="utf-8">
	<title>ania</title>
	<script type="text/javascript" src="js/jquery.js"></script>
	<script type="text/javascript" src="js/json2.js"></script>
	<script language="javascript">
		//var state = "NO_REGISTERED";
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
			console.log("buscando a: " + $nickname + ", " + $password);
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
			if (data.id == 0)
			{
				document.getElementById("login-input-user").value = "";
				document.getElementById("login-input-password").value = "";
				alert("Error , tu nickname y/o password no son correctos.");
			}
			else
			{
				alert("Se ha logueado correctamente.");
				UserManager.onLoginOk(data);
				hideLoginPopup();
				//alert("Nombre : " + data.name + "\n Apellidos : " + data.lastname + "\n Cumpleaños : " + data.date_brithday + "\n Score : " + data.score);
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
				//alert("Nombre : " + data.name + "\n Apellidos : " + data.lastname + "\n Cumpleaños : " + data.date_brithday + "\n Score : " + data.score);
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
		
		// login popup
		
		function showLoginPopup() {
			//if (state == "REGISTERED") return;
			
			console.log('showLoginPopup');
			document.getElementById("login-popup").style.top = "150px";
		}
		
		function hideLoginPopup() {
			console.log('hideLoginPopup');
			document.getElementById("login-popup").style.top = "-1000px";
		}
		
		function onLoginClick()
		{
			hideLoginPopup();
			console.log('click login');
			var user = document.getElementById("login-input-user").value;
			var password = document.getElementById("login-input-password").value;
			
			if (user == "" || password == "")
			{
				alert("Debe llenar los campos correctamente.")
			}
			else
			{
				getUser(user, password);
			}
		}
		
		// register popup
		
		function showRegisterPopup() {
			console.log('showRegisterPopup');
			hideLoginPopup();
			document.getElementById("register-popup").style.top = "150px";
		}
		
		function hideRegisterPopup() {
			console.log('hideREgisterPopup');
			document.getElementById("register-popup").style.top = "-1000px";
		}
		
		function onRegisterClick()
		{
			hideRegisterPopup();
			console.log('click register');
			//function registerUser($nickname , $password , $name , $lastname , $date_birthday)
			var nickname = document.getElementById("register-input-user").value;
			var password = document.getElementById("register-input-password").value;
			var name = document.getElementById("register-input-name").value;
			var lastname = document.getElementById("register-input-lastname").value;
			var date_birthday = document.getElementById("register-input-year").value + "-" + document.getElementById("register-input-day").value + "-" + document.getElementById("register-input-month").value;
			
			if (nickname == "" || password == "" || name == "" || lastname == "" || date_birthday == "")
			{
				alert("Debe llenar todos los campos para poder registrarse correctamente.");
			}
			else
			{
				registerUser(nickname, password, name, lastname, date_birthday);
			}
		}
		
		</script>
</head>

<body style="padding: 0; margin: 0; overflow: hidden">
	
	<!-- <div id="haxe:trace" style="position: absolute; z-index: 2147483647; display: none;"></div> -->
	
	<div id="haxe:jeash" style="background-color: #0; width: 2000px; height: 820px" data-framerate="60"></div>
	<div id="video_episode_01" style="top: -1000px">
		<div id="video_01_container" style="position: relative; left: 58px; top: 35px;">
			<video id="video_01" width="1024" height="600" controls="controls" preload="true">
				<source src="video/episode01_preview.mp4" type="video/mp4" />
			</video>
		</div>
		<div id="video_01_close" style="background-image: url('./img/common/web_common_button_close_normal.png'); width:192px; height:68px; position: relative; left: 950px; top: -620px;" onclick="hideVideos();"></div>
		
		<div id="login-popup" style="background-image: url('./img/home/web_home_login_support.png'); width:624px; height:403px; position: fixed; left: 350px; top: -1000px;">
			<input type="text" id="login-input-user" size="20" style="position:absolute; left: 240px; top: 102px; width: 260px; height:23px; border: 0; outline: 0; background: transparent;">
			<input type="text" id="login-input-password" size="20" style="position:absolute; left: 240px; top: 172px; width: 260px; height:23px; border: 0; outline: 0; background: transparent;">
			<a><button type="button" style="background-image: url('./img/home/web_home_login_enter_normal.png'); width:250px; height:54px; position: absolute; left: 250px; top: 220px; cursor: pointer; border: 0; background-color: transparent;" onclick="onLoginClick();"></button></a>
			<button type="button" style="background-image: url('./img/home/web_home_login_enter_normal.png'); width:250px; height:54px; position: absolute; left: 100px; top: 320px; cursor: pointer; border: 0; background: transparent;" onclick="showRegisterPopup();"></button>
			<button type="button" style="background-image: url('./img/home/web_home_login_close02_normal.png'); width:50px; height:50px; position: absolute; left: 590px; top: 20px; cursor: pointer; border: 0; background-color: transparent;" onclick="hideLoginPopup();"></button>
		</div>
		
		<div id="register-popup" style="background-image: url('./img/home/web_home_register_support.png'); width:602px; height:580px; position: fixed; left: 480px; top: -1000px;">
			<input type="text" id="register-input-name" style="position:absolute; left: 210px; top: 128px; width: 260px; height:23px; border: 0; outline: 0; background: transparent;">
			<input type="text" id="register-input-lastname" style="position:absolute; left: 210px; top: 198px; width: 260px; height:23px; border: 0; outline: 0; background: transparent;">
			<!--input type="number" id="input-lastname" style="position:absolute; left: 210px; top: 268px; width: 60px; height:23px; border: 0; outline: 0; /*background: transparent;*/"-->
			<select id="register-input-day" style="position:absolute; left: 205px; top: 270px; width: 80px; height:23px; border: 0; outline: 0; background: transparent;">
				<option value="1">1</option>
				<option value="2">2</option>
				<option value="3">3</option>
				<option value="4">4</option>
				<option value="5">5</option>
				<option value="6">6</option>
				<option value="7">7</option>
				<option value="8">8</option>
				<option value="9">9</option>
				<option value="10">10</option>
				<option value="11">11</option>
				<option value="12">12</option>
				<option value="13">13</option>
				<option value="14">14</option>
				<option value="15">15</option>
				<option value="16">16</option>
				<option value="17">17</option>
				<option value="18">18</option>
				<option value="19">19</option>
				<option value="20">20</option>
				<option value="21">21</option>
				<option value="22">22</option>
				<option value="23">23</option>
				<option value="24">24</option>
				<option value="25">25</option>
				<option value="26">26</option>
				<option value="27">27</option>
				<option value="28">28</option>
				<option value="29">29</option>
				<option value="30">30</option>
				<option value="31">31</option>
			</select>
			<select id="register-input-month" style="position:absolute; left: 305px; top: 270px; width: 80px; height:23px; border: 0; outline: 0; background: transparent;">
				<option value="1">Enero</option>
				<option value="2">Febrero</option>
				<option value="3">Marzo</option>
				<option value="4">Abril</option>
				<option value="5">Mayo</option>
				<option value="6">Junio</option>
				<option value="7">Julio</option>
				<option value="8">Agosto</option>
				<option value="9">Setiembre</option>
				<option value="10">Octubre</option>
				<option value="11">Noviembre</option>
				<option value="12">Diciembre</option>
			</select>
			<select id="register-input-year" style="position:absolute; left: 415px; top: 270px; width: 80px; height:23px; border: 0; outline: 0; background: transparent;">
				<option value="1990">1990</option>
				<option value="1991">1991</option>
				<option value="1992">1992</option>
				<option value="1993">1993</option>
				<option value="1994">1994</option>
				<option value="1995">1995</option>
				<option value="1996">1996</option>
				<option value="1997">1997</option>
				<option value="1998">1998</option>
				<option value="1999">1999</option>
				<option value="2000">2000</option>
				<option value="2001">2001</option>
				<option value="2002">2002</option>
				<option value="2003">2003</option>
				<option value="2004">2004</option>
				<option value="2005">2005</option>
				<option value="2006">2006</option>
				<option value="2007">2007</option>
				<option value="2008">2008</option>
				<option value="2009">2009</option>
				<option value="2010">2010</option>
				<option value="2011">2011</option>
				<option value="2012">2012</option>
				<option value="2013">2013</option>
			</select>
			<input type="text" id="register-input-user" style="position:absolute; left: 210px; top: 338px; width: 260px; height:23px; border: 0; outline: 0; background: transparent;">
			<input type="text" id="register-input-password" style="position:absolute; left: 210px; top: 408px; width: 260px; height:23px; border: 0; outline: 0; background: transparent;">
			
			<button type="button" style="background-image: url('./img/home/web_home_register_register_normal.png'); width:250px; height:54px; position: absolute; left: 220px; top: 460px; cursor: pointer; border: 0; background-color: transparent;" onclick="onRegisterClick();"></button>
			<button type="button" style="background-image: url('./img/home/web_home_login_close02_normal.png'); width:50px; height:50px; position: absolute; left: 570px; top: -10px; cursor: pointer; border: 0; background-color: transparent;" onclick="hideRegisterPopup();"></button>
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
			//document.getElementById("login-popup").style.top = 200 + "px";
			document.getElementById("login-popup").style.left = (middleWidth - 320) + "px";
			document.getElementById("register-popup").style.left = (middleWidth - 240) + "px";
			
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
		//UserManager.sendScore(20);
		hideLoginPopup();
		document.getElementsByTagName("body")[0].style.overflow = "hidden";
		//document.getElementsByTagName("body")[0].style.overflowY = "hidden";
	</script>
</body>
</html>