<?php
$connection = mysql_connect('juntossomosmasseguros.com', 'usuario_segurida', 'VEbMwNWwR34wDU2F');
if (!$connection) {
    die('Could not connect: ' . mysql_error());
}
mysql_select_db('bcp_seguridad', $connection) or die('Could not select database.');

$app_id = '170131295263'; // App ID 460895720674183
//$app_id = '250996878261404';
$app_secret = '6f549409ed43dd6017ce1a8147bff4d6';
//$app_secret = 'bfc7b858eabb28e441911ad0a8500c85';

$app_url = 'http://funbox.com.pe/bcp_ep/juego.php';
//$app_url = 'http://www.funbox.com.pe/bcp_ep/juego.php';
$scope = 'email,publish_actions,read_friendlists';


?>