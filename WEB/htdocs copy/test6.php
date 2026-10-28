<!DOCTYPE html>
<html>
<head>
<style>
p{
    text-align: center;
    color: aquamarine;

}

</style>
</head>
<body>
<form action="<?php echo $_SERVER["PHP_SELF"]?>" method="post">
<input type"text" name="factor">
<input type="submit">

</form>
<p> <?php factor()?></p>
</body>
<?php
 function factor (){
    if(isset($_POST['factor'])){
        
        $number = $_POST['factor'];

        echo "The factors of $number are: <br>";

        for($i = 1; $i <= $number; $i++){
            if($number % $i == 0){
                echo "<input type='text' value='$i'>" ;
            }
        }
    }
}
    ?>
</html>