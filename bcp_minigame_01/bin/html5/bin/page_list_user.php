<?php
    include "daoUser.php";    
    
    $daoUser = new daoUser($connection);
	
    $page = 1;
    if (isset($_REQUEST["page"])) {
        $page = 1;
    } 
	
	$action = "";
	if (isset($_REQUEST["action"])) {
		$action = $_REQUEST["action"];
	}
    
   
    $total_rows = $daoUser->getTotalUsers();
    $mount = 1000;
    // calcular todas las apginas
    $total_pages = ceil($total_rows / $mount);
    
    $list = $daoUser->getUsers(($page - 1) * $mount , $mount); 
    $len  = count($list);
        
?>
<html>
    <head>
        <script language="javascript">
            function gotoIndex() {
                window.location = "index.php"; 
            }
            
            function addQuestion() {
                /*
                document.fUserList.action = "page_list_question.php?action=add";
                document.fUserList.submit();            
                */
            }
            
            function onChangeSelect() {
                //var i = document.fUserList.page_select.selectedIndex;
               // var value = document.fUserList.page_select.options[i].value;
                document.fUserList.action = "page_list_user.php";
                document.fUserList.submit();   

            }
            
        </script>
    </head>
    <body>
        <h3>Usuarios , 1000 usuarios por pagina</h3> <br/>
		 <a href="export_users_excel.php"> Exporta a Excel Todos</a> <br />

        <form name="fUserList" method="POST">
        <table border="0">
            <tr>
                <td>Pagina Actual : </td>
                <td>
                    <select name="page" size="1" onchange="onChangeSelect();">
                     <?php
                        for ($k = 1; $k <= $total_pages; $k++) {
                     ?>
                        <option value="<?php echo $k; ?>" <?php if ($page == $k) { echo "selected";} ?>><?php echo $k; ?></option>
                     <?php
                        }
                     ?>   
                    </select>
                </td>
            </tr>
            <tr>
                <td>Cantidad Total de Usuarios : </td>
                <td><?php echo $total_rows; ?></td>
            </tr>
        </table>
        

        
        <table border="1">
            <tr>
                <td>Indice</td>
                <td>id</td>
                <td>facebook</td>
                <td>name</td>
                <td>score</td>
                <td>fecha de juego</td>
				<td>cantidad de jugadas</td>
            </tr>
            <?php
            for ($i = 0; $i < $len ; $i++) {
                $user = $list[$i];
            ?>
            <tr>
                <td><?php echo ((($page - 1) * $mount) + ($i + 1)); ?></td>
                <td><?php echo $user["id"]?></td>
                <td><?php echo $user["uid"]?></td>
                <td><?php echo $user["name_fb"]?></td>
                <td><?php echo $user["score"]?></td>
                <td><?php echo $user["date"]?></td>
                <td><?php echo $user["plays"]?></td>
            </tr>    
            <?php
            }
            ?>
        </table>
            <input type="button" value="Regresar" onclick="gotoIndex()"/>
        </form>
    </body>
</html>