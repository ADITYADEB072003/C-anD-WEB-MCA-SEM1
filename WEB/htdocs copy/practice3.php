<!Doctype html>
<html>
    <body>
    <form action="<?php echo $_SERVER["PHP_SELF"] ?>" method="post">
<input type="text" name="vowel">
<input type="submit"></form>

</form>
<?php
if(count($_POST)>0){
  $sum=0;
$b=$_POST['vowel'];
for($i=$b;$i<50;$i++){
    
if($i%2==0){
    echo $i."&nbsp";
    $sum=$sum+$i;
}
}
echo "SUM of even no:-".$sum;



}
else{
    echo "NO";
}
?>
</body>
</html>