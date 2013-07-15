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
		$theuid = (int)$_POST['uid'];
		$thescore = (int)$_POST['score'];
		
		$checkSQL = mysql_query("SELECT uid,score FROM scores WHERE uid=$theuid");
		if(mysql_num_rows($checkSQL)>0){
			$row = mysql_fetch_row($checkSQL);
			$current_score = (int)$row[1];
			if($thescore > $current_score){
				$modifyscore = "UPDATE scores SET score='$thescore', date = NOW() WHERE scores.uid = $theuid";
				$result = mysql_query($modifyscore);
			}
		}else{
			$addscore = "INSERT INTO scores (uid,score,date) VALUES (\"$theuid\",\"$thescore\", now())";	
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