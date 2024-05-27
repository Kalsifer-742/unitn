<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Login</title>
    <link rel="stylesheet" href="style.css">
    <link rel="stylesheet" href="login.css">
</head>
<body>
    <div id="root">
    <img src="logo.png" alt="Logo" id="logo">
        <form method="post" action="auth.php">
            <div id="username">
                <label>Username</label>
                <input type="text" name="user">
            </div>
            <div id="password">
                <label>Password</label>
                <input type="text" name="password">
            </div>
            <div id="bt">
                <input type="submit" value="Accedi" id="submit">
            </div>
        </form>
        <div id="bt">
            <button onClick="document.location.href = 'registration.php'">Registrazione</button>
        </div>
    </div>
</body>
</html>