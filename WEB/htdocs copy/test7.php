<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>Formula Calculator</title>
</head>
<body>

<h2>Formula Calculator</h2>

<form method="post" action="<?php echo htmlspecialchars($_SERVER['PHP_SELF']); ?>">
    Enter a number (n): <input type="text" name="number">
    <input type="submit" value="Calculate">
</form>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Retrieve the user input
    $n = isset($_POST['number']) ? intval($_POST['number']) : 0;

    // Check if the input is valid
    if ($n >= 2) {
        // Initialize result
        $result = 0;

        // Calculate the expression for each value of $i
        for ($i = 2; $i <= $n; $i++) {
            $result += 1 - 1 / ($i * $i) + 1 / ($i * $i) - 1 / ($i * $i);
        }

        // Display the result
        echo "<p>The result of the expression for n = $n is: $result</p>";
    } else {
        echo "<p>Please enter a valid number greater than or equal to 2.</p>";
    }
}
?>

</body>
</html>
