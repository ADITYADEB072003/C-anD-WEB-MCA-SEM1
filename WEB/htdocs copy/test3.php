<!Doctype html>
<html>
<body>
<form action="<?php echo $_SERVER["PHP_SELF"] ?>" method="post">
<input type="text" name="vowel">
<input type="text" name="vowel1">
<input type="submit">


</form>
<br/>
<?php
if(count($_POST)>0){
$n=$_POST["vowel"];
$m=$_POST["vowel1"];

$fact=1;
for($k = $n ; $k <=$m; $k++){
    if($k%2==0){
        echo "EVEN:-".$k."<br>";
    }
    else{
        echo "odd:-".$k;
    }
}



}?>
</body>
</html>