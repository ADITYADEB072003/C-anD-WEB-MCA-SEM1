<!Doctype html>
<html>
<body>
<form action="<?php echo $_SERVER["PHP_SELF"] ?>" method="post">
<input type="text" name="vowel">
<input type="submit">

<?php
if(count($_POST)>0){
    $countvowel=0;
    $n=$_POST["vowel"];
    $inputUpper=strtoupper($n);
    $length=strlen($inputUpper);
    for($i=0;$i<$length;$i++){
        if($inputUpper[$i]=="A"||$inputUpper[$i]=="E"||$inputUpper[$i]=="I" ||$inputUpper[$i]=="O"||$inputUpper[$i]==""){
            $countvowel++;
        }
      
    }
    $reverse = "";
    for($k = $length - 1; $k >= 0; $k--){
        $reverse .= $inputUpper[$k];
    }

    echo "<br>Reversed string: " . $reverse;
    echo " VOWEL:-".$countvowel;
}


?>

</form>
</body>
</html>
