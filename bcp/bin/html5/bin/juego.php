<?php
    require 'facebook-php/src/facebook.php';
	include('connect.php');

    // Init the Facebook SDK
    $facebook = new Facebook(array(
         'appId'  => $app_id,
         'secret' => $app_secret,
));

// Get the current user
$user = $facebook->getUser();

// If the user has not installed the app, redirect them to the Login Dialog
if (!$user) {
	$loginUrl = $facebook->getLoginUrl(array(
	'scope' => $scope,
	'redirect_uri' => $app_url,
	));

   print('<script> top.location.href=\'' . $loginUrl . '\'</script>');
	die();
}

if($user && isset($_GET["logout"])){
	$logoutUrl = $facebook->getLogoutUrl();
   print('<script> top.location.href=\'' . $logoutUrl . '\'</script>');
}

?>
<!DOCTYPE HTML>
<html>
<head>
<meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1">
<meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1.0">
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<meta property="og:title" content="Banco de Crédito BCP | Cuenta Hipotecario Planilla BCP"/>
<meta property="og:type" content="website"/>
<meta property="og:url" content="http://www.cuentapremiobcp.com"/>
<meta property="og:description" content="Planilla" />
<meta property="og:image" content="/img/fb.jpg"/>
<meta property="fb:admins" content="1185016284" />
<link href="css/reset.css" rel="stylesheet" type="text/css" />
<link href="css/main.css" rel="stylesheet" type="text/css" />
<link href="css/bootstrap.css" rel="stylesheet" media="screen">
<link href="css/bootstrap-responsive.css" rel="stylesheet" media="screen">
<title>Seguridad BCP</title>
</head>

<body>
<div id="lightbox"></div>
<!-- /lightbox -->
<div id="lightbox-panel-youtube">
  <div id="lightbox-cerrar-youtube">
    <p align="center"><a href="javascript:cerrarLightbox();"><img src="img/btn_equis.png" width="38" height="37"></a></a>
  </div>
  <div id="lightbox-contenido-youtube"> </div>
</div>
<div class="navbar-wrapper" id="banda">
  <div id="cinta"><span>Juntos somos más seguros</span></div>
  <div class="container">
    <div class="navbar">
      <div class="navbar-inner"> <a href="#" class="brand">
        <div id="logo"><span>logo</span></div>
        </a>
        <div class="nav-collapse collapse">
          <ul class="nav">
            <!--li><a id="lblLogin" onClick="javascript:onLogin();">Login FB</a></li-->
            <li id="s1"><a>Inicio</a></li>
            <li class="active" id="s2"><a>Clonación</a></li>
            <li id="s3"><a>Cambiazo</a></li>
            <li id="s4"><a>Marcaje</a></li>
            <li id="s5"><a>Phishing</a></li>
          </ul>
        </div>
      </div>
    </div>
  </div>
</div>
<div id="seccion1"></div>
<!-- <div id="seccion2"></div>
<div id="seccion3"></div>
<div id="seccion4"></div>
<div id="seccion5"></div>-->
<div class="container">
  <div class="banners" id="banner">
    <ul>
      <li>
        <div id="texto1">
          <div id="haxe:jeash" style="background-color: #0; width: 640px; height: 700px"> <span>Tú tienes el instinto para proteger lo que quieres.</span><br>
            Hazlo igual con tus operaciones en el banco. </div>
        </div>
       <div id="scoreTabs"><div class="tabs"><a href="javascript:openTab(2)" class="opt2 tab">Global</a><a class="opt1 tab" href="javascript:openTab(1)">Amigos</a></div><div id="facebook-bar"><p class="msg">Cargando ranking...</p></div>
       
       <a href="#" class="btn_prev control">ANTERIOR</a> <a href="#" class="btn_next control">SIGUIENTE</a>
       </div>
      </li>
      <li>
        <div id="texto2">
          <div class="tit"> Clonación </div>
          <div id="txt_clonacion"> Al menor descuido, un estafador copia la banda <br>
            magnética de tu tarjeta para usarla luego. <br>
            Pero tú ya tienes el instinto para evitarlo. </div>
          <div class="col1"> <img src="img/img_youtube.jpg" id="youtube1">
            <p>Mira cómo</p>
          </div>
        </div>
      </li>
      <li>
        <div id="texto3">
          <div class="tit2"> Cambiazo </div>
          <div id="txt_cambiazo"> Un estafador busca copiar tu clave y cambiar tu tarjeta <br>
            por otra.
            Pero tú ya tienes el instinto para evitarlo. </div>
          <div class="col1"> <img src="img/img_youtube.jpg" id="youtube2">
            <p>Mira cómo</p>
          </div>
        </div>
      </li>
      <li>
        <div id="texto4">
          <div class="tit3"> Marcaje </div>
          <div id="txt_marcaje"> Cuando retiras mucho dinero en efectivo, un grupo de <br>
            estafadores te siguen para quitártelo.<br>
            Pero tú ya tienes el instinto para evitarlo. </div>
          <div class="col1"> <img src="img/img_youtube.jpg" id="youtube3">
            <p>Mira cómo</p>
          </div>
        </div>
      </li>
      <li>
        <div id="texto5">
          <div class="tit4"> Phishing y Troyanos </div>
          <div id="txt_pishing"> Los estafadores buscan acceder a tus cuentas vía <br>
            internet enviándote mails falsos a nombre del banco<br>
            y virus.
            Pero tú ya tienes el instinto para evitarlo. </div>
          <div class="col1"> <img src="img/img_youtube.jpg" id="youtube4">
            <p>Mira cómo</p>
          </div>
        </div>
      </li>
    </ul>
  </div>
</div>
<div style="display:none"> </div>
<div id="overlay"></div>
<script src="js/jquery.js"></script> 
<script src="js/jquery-easing.js"></script> 
<script src="js/bootstrap.js"></script> 
<script type="text/javascript" src="js/jquery.cycle.all.js"></script>

<script>function winParameters () { return null; }</script> 
<script id="haxe:jeash:script" type="text/javascript" src="./bcp.js"></script> 
<script type="text/javascript">
  var _gaq = _gaq || [];
  _gaq.push(['_setAccount', 'UA-35160300-17']);
  _gaq.push(['_trackPageview']);
 
  (function() {
    var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
    ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
    var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ga, s);
  })();
 
</script>
<div id="fb-root"></div>
<script>
	/* variables para los amigos */
   var friends_fbobj = null,
   		friends_ids,
		globals_fbobj = null,
   		globals_ids,
   		loggedIn = 0,
		fbid = 0,
		fbme = null;

  // Additional JS functions here
  window.fbAsyncInit = function() {
    FB.init({
      appId      : '<?php echo $facebook->getAppID() ?>', 
      status     : true, // check login status
      cookie     : true, // enable cookies to allow the server to access the session
      xfbml      : true  // parse XFBML
    });
	
    /* Este codigo es para saber si se logeo o no el usuario*/
	FB.getLoginStatus(function(response) {
	  if (response.status === 'connected') {
		var uid = response.authResponse.userID;
		var accessToken = response.authResponse.accessToken;
		//buttonlogin.value = "Logged";
		showUserInfo();
		
	  } else if (response.status === 'not_authorized') {
		// the user is logged in to Facebook, 
		// but has not authenticated your app
		 console.log('User cancelled login or did not fully authorize.');

	  } else {
		// the user isn't logged in to Facebook.
		 onLogin();
	  }
	});
  };
  
  function showUserInfo(){
	FB.api('/me?fields=id,picture.type(square),first_name,name', function(response) {
		//console.log('Usuario Logeado ' + response.name + '.');
		fbme = response;
		fbme.pic_square = response.picture.data.url;
		fbme.uid = fbme.id;
		fbid = fbme.id;
		$('#lblLogin').html("Bienvenido, "+response.first_name);
		loggedIn = !0;
		openTab(1);
	});  
 }
 
 var $facebookBox = $("#facebook-bar");
 var $tabs = $('#scoreTabs .tabs');
  
 function openTab(id){
	$tabs.find('.tab').removeClass('active');
	$facebookBox.empty().append('<p class="msg">Cargando ranking...</p>');
	
	switch(id){
		case 1:
		onGetIdsFriends();
		$tabs.find('.opt1').addClass('active');
		$('#scoreTabs .control').show();
		break;
		case 2:
		onGetIdsGlobal();
		$tabs.find('.opt2').addClass('active');
		$('#scoreTabs .control').hide();
		break;
		default:
		onGetIdsFriends();
	}
 }
  
  function onLogin() {
		if(!loggedIn){
			FB.login(function(response) {
				if (response.authResponse) {
					showUserInfo();
				} else {
					//console.log('User cancelled login or did not fully authorize.');
				}
			} , {scope: '<?php echo $scope; ?>'});
		}else{
			window.location.href = '<?php echo $app_url; ?>?logout';
		}
  }
  
	function onGetIdsGlobal(){
		if(fbid>0){
			$.post('getglobal_scores.php', function(data, textStatus) {
				globals_fbobj = data;
			  	globals_ids = [];
				
				var inTop6 = false;
				var topSix = [];
				for(var m=0; m<6; m++){
					globals_fbobj[m].rank = parseInt(globals_fbobj[m].rank);
					topSix.push(globals_fbobj[m]);
					if(globals_fbobj[m].uid == fbid){
						inTop6 = true;
					}
				}
				if(!inTop6){
					for(var p=0; p<globals_fbobj.length; p++){
						if(globals_fbobj[p].uid == fbid){
							topSix[5] = globals_fbobj[p];
						}
					}
				}
				
				for(var i=0; i<topSix.length; i++){
					globals_ids.push(topSix[i].uid);
				}
				
				var fql = 'SELECT uid , first_name, pic_square FROM user WHERE uid IN ('+globals_ids.join(",")+')';
				FB.api( { method: 'fql.query', query: fql },
				function(response) {
					var shortList = response;
					for(var p=0; p<topSix.length; p++){
						for(var o = 0; o<shortList.length; o++){
							if(topSix[p].uid == response[o].uid){
								shortList[o].rank = parseInt(topSix[p].rank);
								shortList[o].score = topSix[p].score;
							}
						}
					}
					$facebookBox.empty();
					$.each(shortList, function(index, value){
						var player = $('<div class="friend"><img src="'+value.pic_square+'" class="picture"> <strong class="position"'+(value.score==0?' style="display:none;"':'')+'>'+(value.rank)+'</strong> <span class="name">'+value.first_name+'</span> <span class="score">'+(value.score==0?"":value.score)+'</span></div>');
						if(fbid == value.uid){
							player.addClass('self');
						}
						$facebookBox.append(player);
					});
					
				});
				  
			}, 'json');
		}
	}
  
	function onGetIdsFriends() 
	{	
		if(fbid>0){
		var fql = 'SELECT uid , first_name, pic_square FROM user WHERE is_app_user=1 AND uid IN (SELECT uid2 FROM friend WHERE uid1 = me())';
		FB.api(
		  {
			method: 'fql.query',
			query: fql
		  },
		  function(response) {
			  friends_fbobj = response;
			  friends_ids = [];			  
			  for(var i=0; i<response.length; i++){
				  friends_ids[i] = response[i].uid;
			  }
			 //friends_ids = ['733096989', '569336795', '580330091', '653886428', '617909808', '694106256',"552673675", "553370195", "553408802", "553735704", "554386106", "555930570", "557576755", "558007080", "558797508", "559917435", "563037083", "563637459", "564376335", "565171480", "565267489", "566591683", "566616848", "567851678", "568817436", "569266553", "569336795", "569872805", "569992847", "571169509", "571641323", "573146155", "573500187", "573578407"]; //, 
			  var strFriendsId = friends_ids.join(",");
			  if(strFriendsId==""){
				  strFriendsId = fbid;
			  }
			  $.post('getscores.php', {"uid":fbid, "friends":strFriendsId }, function(data, textStatus) {
				 var top_friends = [];
				 if(friends_fbobj.length>0){	 
				  for(var o = 0; o<friends_fbobj.length; o++){
					  for( var k = 0; k<data.length; k++){
						  // Que amigos que han jugado tienen un score guardado
						  if(friends_fbobj[o].uid == data[k].uid){
							var top_friend = friends_fbobj[o];
								top_friend.score = data[k].score;
							top_friends.push(top_friend);
						  }
						  if(fbme.id == data[k].uid){
							  fbme.score = data[k].score;
						  }
					  }
				  };
				 }else{
					fbme.score = data[0].score;
				 }
				  var friendList = [];
				  var empty = 0;
				  
				  friendList.push(fbme);
				  for(var m=0; m<top_friends.length; m++){
					  if(top_friends[m]!=null){
						  friendList.push(top_friends[m]);
					  }
				  }
				  
				  friendList.sort(function(a,b){ return b.score - a.score; }); // Orden descendiente
/*if(m<6){
  var maleFemale = ["http://b.static.ak.fbcdn.net/rsrc.php/v1/yo/r/UlIqmHJn-SK.gif", "https://fbcdn-profile-a.akamaihd.net/static-ak/rsrc.php/v1/y9/r/IB7NOFmPw2a.gif"];
  topSix.push({pic_square:maleFemale[m % 2], score:0, first_name:""});
  empty++;
}			  
*/				  
				  $facebookBox.empty();
				  $.each(friendList, function(index, value){
					  var player = $('<div class="friend"><img src="'+value.pic_square+'" class="picture"> <strong class="position"'+(value.score==0?' style="display:none;"':'')+'>'+(index+1)+'</strong> <span class="name">'+value.first_name+'</span> <span class="score">'+(value.score==0?"":value.score)+'</span></div>');
					 if(fbid == value.uid){
						 player.addClass('self');
					 }
					 $facebookBox.append(player);
				  });
				  
					$facebookBox.splitUp(6, '<div class="page" />').cycle({ 
						fx:     'fade',
						speed:  'fast',
						timeout: 0, 				
						pause: 1,				
						next:   '.btn_next',
						prev:   '.btn_prev'
					});

				  
				}, "json");
		  }
		);
	  }
	}
  
  
  function getTipoFraude(){
	  var active = $('.nav .active').text();
		if(active == "Clonación"){
			active = "la "+active;
		}else{
			active = "el "+active;
		}
	  return active;
  }
  function onSendScore(points) {
	  if(fbid>0){
		$.post("insert.php",  { uid: fbid, score: points },
		  function (response){ if(response=="fail"){ alert("No se pudieron guardar sus datos, intente nuevamente."); } });
	  }
  }
  
var openIntrvl = 0;
	window.openOnce = false;

function postFacebook(score){
	openIntrvl = setTimeout(function(){ _postFacebook(score); }, 500);
}
function postTwitter(score){
	openIntrvl = setTimeout(function(){ _postTwitter(score);} , 500);
}

function _postFacebook(score){
	clearTimeout(openIntrvl);
	if (score && !window.openOnce) {
		window.openOnce = true;
		FB.ui({ method: 'feed',
			caption: 'Acabo de hacer ' + score + ' puntos mientras aprendía a prevenir '+getTipoFraude(),
			picture: 'http://circusint.com/clientes/bcp/seguridad/img/200x200.jpg',
			name: 'Tú también juega y protégete contra los fraudes aquí:',
			link: 'http://www.juntossomosmasseguros.com'
		}, function(){});
	}
	setTimeout(function(){ window.openOnce = false; }, 1200);
	return false;
}
function _postTwitter(score){
	clearTimeout(openIntrvl);
	if (score && !window.openOnce) {
		window.openOnce = true;
		var message = 'Acabo de hacer ' + score + ' puntos mientras aprendía a prevenir '+getTipoFraude()+'. '+'Juega y protégete contra los fraudes aquí';
		var url = 'http://juntossomosmasseguros.com';
		var D=550,A=450,C=screen.height,B=screen.width,H=Math.round((B/2)-(D/2)),G=0;
		window.open("https://twitter.com/share?text="+encodeURIComponent(message)+"&url="+encodeURIComponent(url), "tweetit", 'left='+H+',top='+G+',width='+D+',height='+A+',personalbar=0,toolbar=0,scrollbars=1,resizable=1');
	}
	setTimeout(function(){ window.openOnce = false; }, 1200);
	return false;
}


  // Load the SDK asynchronously
  (function(d){
     var js, id = 'facebook-jssdk', ref = d.getElementsByTagName('script')[0];
     if (d.getElementById(id)) {return;}
     js = d.createElement('script'); js.id = id; js.async = true;
     js.src = "//connect.facebook.net/en_US/all.js";
     ref.parentNode.insertBefore(js, ref);
   }(document));
</script>
</body>
</html>