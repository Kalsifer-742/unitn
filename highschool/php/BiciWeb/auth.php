<?php
    session_start();

    $sql_db = new mysqli("localhost", "root", "", "bici");

    if ($sql_db->connect_errno) {
        echo '<p>Failed to connect to MySQL: '.$sql_db->connect_error .'</p>';
        header('Location: login.php');
    }

    $res = $sql_db->query('SELECT password FROM amministratori WHERE user_id ="'.$_POST['user'].'"');
    $res = $res->fetch_assoc();
    $sql_db -> close();
    if(hash('sha256', $_POST['password']) == $res['password']){ //user_id = 1 | password = LaSpiga
        if(!isset($_SESSION["username"]) || !isset($_SESSION["password"])){
            $_SESSION["username"] = $_POST['user'];
            $_SESSION["password"] = $_POST['password'];
        }
        header('Location: admin.php');
    }
    else{
        header('Location: login.php');
    }
?>