<?php

    include('connect.php');
	
	//$friends = array('733096989', '569336795', '580330091', '653886428', '617909808', '694106256');
	$friends = explode(',', $_POST['friends']);
	$friends[] = $_POST['uid'];
	
	$query = "SELECT uid, score FROM scores WHERE uid IN (".join($friends, ",").") ORDER BY score ASC";
	$result = mysql_query($query) or die("{'error':1}");
	
	$output = array();
    while($row = mysql_fetch_array($result)){
		$output[] = array('uid'=>$row['uid'], 'score'=>$row['score'] );
    }
	echo json_encode($output);
    
    mysql_close($connection);
      
?>