<!DOCTYPE html>
<html>
    <head>
<style>
    input
    {color: white;
        background-color:rebeccapurple;
        border: 1px solid red;
    }
</style>
</head>
<body>

<form action="<?php echo $_SERVER['PHP_SELF']?>" method="post">
<input type="text" name="name" placeholder="Name">
<input type="submit">
<input type="reset">
</form>
</body>
<?php
if(count($_POST)>0){
$vowel=$_POST['name'];
$vowel=strtoupper($vowel);
$len=strlen($vowel);
$countvowel=0;
for($i=0;$i<$len;$i++){
   if($vowel[$i]=='A'||$vowel[$i]=='E'||$vowel[$i]=='I'||$vowel[$i]=='O'||$vowel[$i]=='U'){
        $countvowel++;
    }
}
echo "NO OF VOWELS:-<input type='text' value='$countvowel' read-only='true'>";
}
?>
</html>