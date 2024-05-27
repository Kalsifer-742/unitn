<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Login</title>
    <link rel="stylesheet" href="style.css">
    <link rel="stylesheet" href="registration.css">
</head>
<body>
    <div id="root">
    <img src="r_logo.png" alt="Logo" id="logo">
        <form method="post" action="r_auth.php">
            <div id="input">
                <label>Nome</label>
                <input type="text" name="name">
            </div>
            <div id="input">
                <label>Cognome</label>
                <input type="text" name="surname">
            </div>
            <div id="input">
                <label>Cap</label>
                <input type="text" name="cap">
            </div>
            <div id="input">
                <label>Indirizzo</label>
                <input type="text" name="address">
            </div>
            <div id="input">
                <label>Numero carta di credito</label>
                <input type="text" name="nc">
            </div>
            <div id="input">
                <label>Cellulare</label>
                <input type="text" name="cell">
            </div>
            <div id="input">
                <label>Mail</label>
                <input type="text" name="mail">
            </div>
            <div id="input">
                <label>Data di nascita</label>
                <input type="text" name="b_date">
            </div>
            <div id="button">
                <input type="submit" value="Registrati" id="submit">
            </div>
        </form>
    </div>
</body>

</html>
