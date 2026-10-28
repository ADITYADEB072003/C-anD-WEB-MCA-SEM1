<?php
$conn = new mysqli("127.0.0.1","root","123456789","college_db");
if($conn->connect_error){
    die("Connection failed: ".$conn->connect_error);
}
echo "MySQL connection successful.<br>";
?>
