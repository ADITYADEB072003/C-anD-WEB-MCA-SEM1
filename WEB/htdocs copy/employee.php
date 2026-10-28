<!DOCTYPE html> 
<html>
<head>

</head>
<title></title>
<body>
<h1> EMPLOYEE details </h1>
<form action="<?php echo $_SERVER['PHP_SELF']?>" method="post">
    
    <input type="text" name="salary">
    <input type="submit" value="Submit">
</form>
<?php
if(isset($_POST['salary'])){
    $n=$_POST['salary'];
    $number=$n;
    $lenght=strlen($n);
    $sum=0;
  $sum1=0;
      while($number>0){
        $digit=$number%10;
        $sum1+=$digit;
        $sum+=pow($digit,$lenght);
        $rev=$rev*10+$digit;
        $number = (int)($number / 10);

    }
    if($sum==$n ){
        print("ARMSTRONG");
        print("<br>");

    }
else{
    print("NOT A ARMSTRONG NUMBER");
    print("<br>");
}
if($rev == $n){
    echo "palindrome";
}
else{
    echo "not a palindrome";
}
echo "Sum:-$sum1";
}

?>


</body>
</html>
