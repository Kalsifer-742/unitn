<?php
    $id = $_REQUEST['id'];

    $sql_db = new mysqli("localhost", "root", "", "bici");

    $res = $sql_db->query('SELECT * FROM slot LEFT JOIN biciclette ON id_bicicletta=biciclette.id WHERE id_stazione="'.$id.'"');
    foreach($res as $row){
        if($row["stato"] == "libero"){
            $result .= $row["stato"] . " - <em>nessun modello</em><br>";
        }
        else{
            $result .= $row["stato"] . " - <em>" . $row["modello"] . "<em><br>";
        }
    }

    $sql_db -> close();

    echo $result;
?>