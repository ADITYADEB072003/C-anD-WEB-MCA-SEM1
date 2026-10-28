<html>
    <body>
<form action="<?php echo $_SERVER['PHP_SELF'];?>" method="post">
<input type="text" name="char">
<input type="submit">
</form>
<?php 
if(count($_POST)>0){
    $n=$_POST["char"];
    $len=strlen($n);
    $reverse="";
    for($i=$len-1;$i>=0;$i--){
        $reverse.=$n[$i];

    }
    if($reverse==$n){
        echo "palindrome";
        echo "<p>Reversed Text: $reverse</p>";
    }
        else{
            echo "not a palindrome";
    echo "<p>Reversed Text: $reverse</p>";}
}
?>
    </body>
</html>