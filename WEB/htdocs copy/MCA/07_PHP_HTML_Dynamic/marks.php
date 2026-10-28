<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $name = htmlspecialchars($_POST["name"]);
    $marks = [$_POST["m1"], $_POST["m2"], $_POST["m3"], $_POST["m4"], $_POST["m5"]];

    $total = array_sum($marks);
    $percentage = $total / 5;

    if ($percentage >= 90) $grade = "A";
    elseif ($percentage >= 80) $grade = "B";
    elseif ($percentage >= 70) $grade = "C";
    elseif ($percentage >= 60) $grade = "D";
    else $grade = "F";

    echo "Name: $name<br>";
    echo "Marks: " . implode(", ", $marks) . "<br>";
    echo "Total: $total / 500<br>";
    echo "Percentage: $percentage%<br>";
    echo "Grade: $grade<br>";
    echo "Result: " . ($percentage >= 40 ? "Pass" : "Fail");
}
?>

<form method="post">
    <input type="text" name="name" placeholder="Name" required><br>
    <?php for ($i = 1; $i <= 5; $i++) { ?>
        <input type="number" name="m<?= $i ?>" placeholder="Subject <?= $i ?>" min="0" max="100" required><br>
    <?php } ?>
    <button type="submit">Submit</button>
</form>