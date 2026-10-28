<!DOCTYPE html>
<html>
    <body>
<form action="<?php echo $_SERVER['PHP_SELF'];?>"
method="post">
Enter a number :<input type="text" name="square"></br>
<input type="submit">

</form>
<?php
if(count($_POST)>0 && isset($_POST["square"])){
$n=$_POST["square"];
echo "Square of $n = ".($n*$n);
}
?>
    </body>
</html>