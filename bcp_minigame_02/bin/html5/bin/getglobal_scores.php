<?php

    include('connect.php');
  	
	mysql_query("SET @rank=0");
	$query = "SELECT @rank:=@rank+1 AS rank, uid, score FROM scores ORDER BY score DESC;";
	$result = mysql_query($query) or die("{'error'=>'1'}");//die(mysql_error());
	
	$output = array();
    while($row = mysql_fetch_array($result)){
		$output[] = array('uid'=>$row['uid'], score=>$row['score'], rank=>$row['rank']);
    }
	echo json_encode($output);
    
    mysql_close($connection);
      
?>