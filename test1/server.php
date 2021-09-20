<?php
    session_start();
    //initializing variables
    $username ="";
    $email = "";
    $errors = array();

    //$DATABASE_HOST = '127.0.0.1';
    //$DATABASE_USER = 'root';
    //$DATABASE_PASS = '';
    //$DATABASE_NAME = 'registration';
    // Try and connect using the info above.
    //$db = mysqli_connect($DATABASE_HOST, $DATABASE_USER, $DATABASE_PASS, $DATABASE_NAME);
    //if (mysqli_connect_errno()) {
        // If there is an error with the connection, stop the script and display the error.
    //    exit('Failed to connect to MySQL: ' . mysqli_connect_error());
    //}
    //connect to the database
    $db=mysqli_connect('127.0.0.1','root','');
    if(!$db)
    {
        echo 'Not Connected To Server';
    }

    if(!mysqli_select_db($db,'registration'))
    {
        echo 'Database Not Selected';
    }
    //if the register button is clicked
    if (isset($_POST['register'])){
        $username = mysqli_real_escape_string($db,$_POST['username']);
        $email = mysqli_real_escape_string($db,$_POST['email']);
        $password_1 = mysqli_real_escape_string($db,$_POST['password_1']);
        $password_2 = mysqli_real_escape_string($db,$_POST['password_2']);

        //ensure that form fields are filled properly
        if (empty($username)){
            array_push($errors,"Username is required");
        }
        if (empty($email)){
            array_push($errors,"Email is required");
        }        
        if (empty($password_1)){
            array_push($errors,"Password is required");
        }
        if($password_1 != $password_2){
            array_push($errors,"The two password do not match");
        }
        //if there is no errors, save user to the database
        if(count($errors) == 0){
            $password = /*md5(*/$password_1/*)*/;//encrypt password before storing in database (security purpose)
            $sql="INSERT INTO users (username,email,password) VALUES ('$username','$email','$password')";
            mysqli_query($db,$sql);

            $_SESSION['username']=$username;
            $_SESSION['success']="You are now logged in";
            header('location: index.php');//redirect to home page
        }
    }
    //log user in from login page
    if (isset($_POST['login']))
    {
        $db=mysqli_connect('127.0.0.1','root','');
        $username = mysqli_real_escape_string($db,$_POST['username']);
        $password = mysqli_real_escape_string($db,$_POST['password']);
        
        //ensure that form fields are filled properly
        if (empty($username)){
            array_push($errors,"Username is required");
        }
        if (empty($password)){
            array_push($errors,"Password is required");
        }
        if (count($errors) == 1)
        {   
            $username = stripcslashes($username);
            $password = stripcslashes($password);
            $username = mysqli_real_escape_string($db,$username);
            $password = mysqli_real_escape_string($db,$password);
            $con=mysql_select_db("registration");
            $db=mysqli_connect('127.0.0.1','root','');
            //$password = md5($password); //encrypt password before comparing with that from database
            $query = mysqli_query("select * FROM users WHERE username='$username' AND password='$password'") or die("Failed to query database".mysqli_error());
            $row=mysqli_fetch_array($query);
            if($row['username']==$username && $row['password']==$password)
            {
                $_SESSION['username']=$username;
                $_SESSION['success']="You are now logged in";
                header('location: index.php');//redirect to home page
            }
            else{
                array_push($errors,"Wrong username/password combination");
            }
            //$result= mysqli_query($db,$query);
                //if (mysqli_num_rows($result) == 1)
                //{
                    //log user in
                    //$_SESSION['username']=$username;
                    //$_SESSION['success']="You are now logged in";
                    //header('location: index.php');//redirect to home page
                //}
                //else
                //{
                //    array_push($errors,"Wrong username/password combination");    
                //}
        }
    }
    //logout
    if (isset($_GET['logout'])) {
        session_destroy();
        unset($_SESSION['username']);
        header('location: login.php');
    }
?>