<?php
if(isset($_POST['check'])){
    $a=(int)$_POST['no'];
    // $b=(int)$_POST['no1'];
    // if ($a>$b){
    // echo $a."LArger";
    // }
    // else if ($a<$b){
    //     echo $b."LArger";
    // }
    // else{
    //     echo "Both Equal";
    // }
    $sum=0;
    $temp=$a;
    $reverse=0;
     while($a!=0){
        $digit=$a%10;
        $reverse=$reverse*10+$digit;
        $a = intdiv($a, 10);
     }
     if($temp==$reverse){
       echo 'alert("Palindrome")';

     }
     else{
        echo 'alert(" Not a Palindrome")';


     }
    
}
?>
<html>
    <body>
        <form method="post">
            <input type="number" name ="no">
            <!-- <input type="number" name ="no1"> -->
            <button type="submit" name="check">Submit</button>
        </form>
    </body>
</html>