<!Doctype html>
<html>
<body>
    <form action="<?php echo $_SERVER["PHP_SELF"] ?>" method="post">
<input type="text" name="vowel">
<input type="submit"></form>
<br/>
<?php
if(count($_POST)>0){
$n=$_POST["vowel"];
if($n%2==0){
    echo "EVEN <br>";
}
else{
    echo "odd <br>";
}
$fact=1;
for($k = $n ; $k >= 1; $k--){
    $fact *= $k;
}
echo "Factorial".$fact;


}?>
</body>
</html>