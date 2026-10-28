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
    $charcount=0;
    for($i=0;$i<$len;$i++){
        $charcount++;
    }
    $vowelCount = 0;
        $vowels = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'];
        for ($i = 0; $i <$len; $i++) {
            if (in_array($n[$i], $vowels)) {
                $vowelCount++;
            }
        }
        $digitCount=0;
        for ($i = 0; $i < $len; $i++) {
            if (is_numeric($n[$i])) {
                $digitCount++;
            }
        }
        echo "The number of characters in the string is: ". $charcount . "<br>";
        echo "DIGIT COUNT:-". $digitCount . "<br>";
        echo "VOWEL:-".$vowelCount."<br>";
}
?>
    </body>
</html>