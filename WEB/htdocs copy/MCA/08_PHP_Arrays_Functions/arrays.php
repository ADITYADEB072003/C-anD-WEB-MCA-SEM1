<?php
function statistics($arr) {
    return [min($arr), max($arr), array_sum($arr) / count($arr)];
}

$numbers = [45, 12, 78, 34, 90, 23, 67, 56, 89, 10];
[$min, $max, $avg] = statistics($numbers);

echo "<h3>Indexed Array</h3>";
echo "Minimum: $min<br>Maximum: $max<br>Average: $avg<br>";

$students = ["Aman"=>82, "Riya"=>95, "Karan"=>76, "Neha"=>88];
arsort($students);

echo "<h3>Students</h3>";
foreach ($students as $name => $marks)
    echo "$name : $marks<br>";

echo "Topper: " . array_key_first($students) . "<br>";

$a = [5, 2, 8];
sort($a);
echo "sort(): "; print_r($a);

array_push($a, 10);
echo "<br>array_push(): "; print_r($a);

echo "<br>in_array(8): " . (in_array(8, $a) ? "true" : "false");
echo "<br>array_search(10): " . array_search(10, $a);
echo "<br>count(): " . count($a);

function greet($name = "Student") {
    return "Hello, $name";
}

function addAll(...$args) {
    return array_sum($args);
}

echo "<br>" . greet();
echo "<br>" . greet("Aditya");
echo "<br>Sum: " . addAll(10, 20, 30, 40);
?>