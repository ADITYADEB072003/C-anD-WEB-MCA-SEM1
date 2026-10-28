//Write a PHP program to find the sum of all numeric elements stored in an array.
<!Doctype html>
<html>
    <body>
    <form action="<?php echo $_SERVER["PHP_SELF"] ?>" method="post">
<input type="text" name="vowel">
<input type="submit"></form>

</form>
<?php
    if(count($_POST)>0){
    $a=array();
$b=$_POST['vowel'];
for ($i=0;$i<strlen($b);$i++){
$a[$i]=$b[$i];
}
$count=count($a)  ; 
$sum=0;
foreach($a as $g){
    if(is_numeric(($g))){
        $sum+=$g;
       
    }
}
$average=$sum/$count;
echo "SUM:-".$sum;
echo "Average:".$average;
}
    
    
    ?>



    </body>