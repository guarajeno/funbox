<?php 
header("Pragma: public"); 
header("Expires: 0"); 
$filename = "users.xls"; 
header("Content-type: application/x-msdownload"); 
header("Content-Disposition: attachment; filename=$filename"); 
header("Pragma: no-cache"); 
header("Cache-Control: must-revalidate, post-check=0, pre-check=0"); 

include "daoUser.php";    
$daoUser = new daoUser($connection);
$list = $daoUser->getAllUsers(); 
$len  = count($list);
?>
<table>
    <tr>
        <td>id</td>
        <td>id facebook</td>
        <td>nombre facebook</td>
        <td>puntaje</td>
        <td>date</td>
        <td>canidad de jugadas</td>
    </tr>
    <?php
    for ($i = 0; $i < $len ; $i++) {
        $user = $list[$i];
    ?>
    <tr>
        <td><?php echo $user["id"];?></td>
        <td><?php echo $user["uid"];?></td>
        <td><?php echo $user["name_fb"];?></td>
        <td><?php echo $user["score"];?></td>
        <td><?php echo $user["date"];?></td>
        <td><?php echo $user["plays"];?></td>

    </tr>    
    <?php
    }
    ?>
</table>