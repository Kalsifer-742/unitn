<?php
    $sql_db = new mysqli("localhost", "root", "", "bici");

    if ($sql_db->connect_errno) {
        echo '<p>Failed to connect to MySQL: '.$sql_db->connect_error .'</p>';
        header('Location: registration.php');
    }

    //echo "INSERT INTO utenti (nome, cognome, cap, indirizzo, num_carta_credito, cellulare, mail, data_nascita) VALUES ('".$_POST['name']."','".$_POST['surname']."',".$_POST['cap'].",'".$_POST['address']."',".$_POST['nc'].",".$_POST['cell'].",'".$_POST['mail']."','".$_POST['b_date']."')";
    
    //aggiungere AUTO_INCREMENT su id nella tabella utenti
    $res = $sql_db->query("INSERT INTO utenti (nome, cognome, cap, indirizzo, num_carta_credito, cellulare, mail, data_nascita) VALUES ('".$_POST['name']."','".$_POST['surname']."',".$_POST['cap'].",'".$_POST['address']."',".$_POST['nc'].",".$_POST['cell'].",'".$_POST['mail']."','".$_POST['b_date']."')");   
    
    header('Location: login.php');
    $sql_db -> close();
?>