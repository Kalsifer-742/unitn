<?php
    session_start();

    if(!isset($_SESSION["username"]) || !isset($_SESSION["password"])){
        header('Location: login.php');
    }
    else{
        $sql_db = new mysqli("localhost", "root", "", "bici");

        if ($sql_db->connect_errno) {
            echo '<p>Failed to connect to MySQL: '.$sql_db->connect_error .'</p>';
            header('Location: login.php');
        }

        $res = $sql_db->query('SELECT password FROM amministratori WHERE user_id ="'.$_SESSION["username"].'"');
        $res = $res->fetch_assoc();
        $sql_db -> close();
        if(hash('sha256', $_SESSION["password"]) != $res['password']){
            header('Location: login.php');
        }
    }
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Admin</title>
    <link rel="stylesheet" href="style.css">
    <link rel="stylesheet" href="admin.css">
</head>
<body>
    <div id="title">Noleggi attivi</div>
    <?php
        $sql_db = new mysqli("localhost", "root", "", "bici");

        if ($sql_db->connect_errno) {
            echo '<p>Failed to connect to MySQL: '.$sql_db->connect_error .'</p>';
        }
        else{
            $res = $sql_db->query('SELECT biciclette.id, utenti.nome, utenti.cognome, noleggi.id_stazione_partenza FROM biciclette, utenti, noleggi WHERE noleggi.id_utente = utenti.id AND noleggi.id_bicicletta = biciclette.id AND noleggi.data_fine IS NULL');
        
            echo '<table>';
            echo '<th>Id Bicicletta</th><th>Nome Utente</th><th>Cognome utente</th><th>Stazione di partenza</th>';
            foreach($res as $row){
                echo '<tr>';
                echo '<td>'.$row['id'].'</td>';
                echo '<td>'.$row['nome'].'</td>';
                echo '<td>'.$row['cognome'].'</td>';
                echo '<td>'.$row['id_stazione_partenza'].'</td>';
                echo '</tr>';
            }
            echo '</table>';
        }

        $sql_db -> close();
    ?>
</body>

</html>
