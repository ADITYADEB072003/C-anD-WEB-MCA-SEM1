<?php
$name = "Aditya";
$age = 22;
$percentage = 82.5;
$isStudent = true;
define("COLLEGE", "Manipal University Jaipur");

echo "String: $name<br>";
print "Integer: $age<br>";
echo "Float: $percentage<br>";
echo "Boolean: "; var_dump($isStudent);
echo "Constant: " . COLLEGE . "<br>";

echo "<h3>print_r()</h3>";
print_r([$name, $age, $percentage, $isStudent]);
print_r(array( $name, "age" => $age, "percentage" => $percentage, "isStudent" => $isStudent));

echo "<h3>var_dump()</h3>";
var_dump($name, $age, $percentage, $isStudent);
?>
<hr>
<form method="post">
    <input type="number" name="a" step="any" placeholder="First number" required>
    <input type="number" name="b" step="any" placeholder="Second number" required>
    <button>Calculate</button>
</form>
<?php
if (isset($_POST['a'], $_POST['b'])) {
    $a=(float)$_POST['a']; $b=(float)$_POST['b'];
    echo "<table border='1' cellpadding='8'>";
    echo "<tr><th>Operation</th><th>Result</th></tr>";
    echo "<tr><td>Addition</td><td>".($a+$b)."</td></tr>";
    echo "<tr><td>Subtraction</td><td>".($a-$b)."</td></tr>";
    echo "<tr><td>Multiplication</td><td>".($a*$b)."</td></tr>";
    echo "<tr><td>Division</td><td>".($b != 0 ? $a/$b : "Cannot divide by zero")."</td></tr>";
    echo "<tr><td>a == b</td><td>".(($a==$b)?"true":"false")."</td></tr>";
    echo "<tr><td>a > b</td><td>".(($a>$b)?"true":"false")."</td></tr>";
    echo "<tr><td>a > 0 AND b > 0</td><td>".(($a>0 && $b>0)?"true":"false")."</td></tr>";
    echo "</table>";
}
?>
<?php
$globalMessage = "Global variable";
function showScope() {
    $localMessage = "Local variable";
    global $globalMessage;
    echo "<p>$localMessage</p>";
    echo "<p>$globalMessage</p>";
}
showScope();
?>