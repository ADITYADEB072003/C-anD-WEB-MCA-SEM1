<!DOCTYPE html>
<html><body>
<form method="post">
    <input type="number" name="num" placeholder="Number" required>
    <button name="check">Check</button>
</form>
<?php
if(isset($_POST['check'])){
    $n=(int)$_POST['num'];
    echo "<h3>Positive/Negative/Zero and Even/Odd</h3>";
    if($n>0) echo "Positive<br>";
    elseif($n<0) echo "Negative<br>";
    else echo "Zero<br>";
    echo ($n%2==0) ? "Even" : "Odd";
}
?>
<hr>
<form method="post">
    <input type="number" name="grade" min="0" max="100" placeholder="Grade 0-100" required>
    <button name="gradeBtn">Find Grade</button>
</form>
<?php
if(isset($_POST['gradeBtn'])){
    $g=(int)$_POST['grade'];
    $band = $g>=90 ? 1 : ($g>=80 ? 2 : ($g>=70 ? 3 : ($g>=60 ? 4 : 5)));
    switch($band){
        case 1: $letter="A"; break;
        case 2: $letter="B"; break;
        case 3: $letter="C"; break;
        case 4: $letter="D"; break;
        default: $letter="F";
    }
    echo "Letter Grade: $letter";
}
?>
<hr>
<form method="post">
    <input type="number" name="tableNum" required>
    <button name="tableBtn">Multiplication Table</button>
</form>
<?php
if(isset($_POST['tableBtn'])){
    $n=(int)$_POST['tableNum'];
    for($i=1;$i<=10;$i++) echo "$n × $i = ".$n*$i."<br>";
}
?>
<hr>
<form method="post">
    <input type="number" name="fact" min="0" required>
    <button name="factBtn">Factorial & Prime</button>
</form>
<?php
if(isset($_POST['factBtn'])){
    $n=(int)$_POST['fact'];
    $fact=1; $i=1;
    while($i<=$n){$fact*=$i;$i++;}
    $prime = $n>=2; $i=2;
    while($i*$i<=$n){if($n%$i==0){$prime=false;break;}$i++;}
    echo "Factorial = $fact<br>";
    echo $prime ? "$n is Prime" : "$n is Not Prime";
}
?>
</body></html>
