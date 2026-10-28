
<!DOCTYPE html>
<html>
<body>
    <form method="post">
        <label>Enter number for factorial:</label>
        <input type="number" name="fact" required>

        <label>Enter number to check prime:</label>
        <input type="number" name="prime" required>

        <button type="submit" name="check">Submit</button>
    </form>

    <?php
    if (isset($_POST['check'])) {

        // Factorial
        $a = $_POST['fact'];
        $fact = 1;

        for ($i = 1; $i <= $a; $i++) {
            $fact *= $i;
        }

        echo "Factorial = " . $fact . "<br>";

        // Prime number
        $a = $_POST['prime'];
        $fact1 = 1;

        if ($a <= 1) {
            $fact1 = 0;
        } else {
            for ($i = 2; $i < $a; $i++) {
                if ($a % $i == 0) {
                    $fact1 = 0;
                    break;
                }
            }
        }

        if ($fact1 == 0) {
            echo "Not Prime";
        } else {
            echo "Prime";
        }
    }
    ?>
</body>
</html>
