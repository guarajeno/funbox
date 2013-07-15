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
	
	if($user && isset($_POST['uid'])){
		$theuid = $_POST['uid'];
		$thescore = (int)$_POST['score'];
		$name_fb = $_POST['name_fb'];
		
		$checkSQL = mysql_query("SELECT uid,score FROM scores WHERE uid=$theuid");
		
		if(mysql_num_rows($checkSQL)>0){
			$row = mysql_fetch_row($checkSQL);

			/* modificar cantidad de jugadas */
			$modifyplays = "UPDATE scores SET date = NOW() , plays = (plays + 1) WHERE scores.uid = $theuid";
			$resultplays = mysql_query($modifyplays);
			
			/* modificar  el nombre del usaurio de facebook */
			$current_score = (int)$row[1];
			if($thescore > $current_score){
				$modifyscore = "UPDATE scores SET score='$thescore'	WHERE scores.uid = $theuid";
				echo $modifyscore;
				$result = mysql_query($modifyscore);
			}
		}else{
			$addscore = "INSERT INTO scores (uid,score,date,name_fb,plays) VALUES (\"$theuid\",\"$thescore\", now() , \"$name_fb\" , 1)";	
			$result = mysql_query($addscore);
		}
		if(mysql_affected_rows()){
			echo "done";
		}else{
			echo "none";
		}
	}else{
		echo "fail";
	}
    
    mysql_close($connection);
?>