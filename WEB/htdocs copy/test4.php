<!DOCTYPE html>
<html>
<body>
    <form action="<?php echo $_SERVER["PHP_SELF"] ?>" method="post">
        <label for="vowel">Enter a Number:</label>
        <input type="text" name="vowel">
        <input type="submit">
    </form>
    <br/>

    <?php
    if(count($_POST) > 0){
        $n = $_POST["vowel"];

        // Print multiplication table
        echo "<br>Multiplication Table for $n:<br>";
        for ($i = 1; $i <= 10; $i++) {
            echo "$n x $i = " . ($n * $i) . "<br>";
        }

        // Check if the number is prime
        $isprime = true;
        if ($n == 1) {
            echo "NOT a prime";
        } else if ($n > 1) {
            for ($i = 2; $i < $n; $i++) {
                if ($n % $i == 0) {
                    $isprime = false;
                    break;
                }
            }
            if ($isprime) {
                echo "PRIME";
            } else {
                echo "not a prime";
            }
        } else {
            echo "NOT a prime";
        }

        // Calculate the sum of digits
        $number = $n;
        $sum = 0;
        while ($number > 0) {
            $digit = $number % 10;
            $sum += $digit;
            $number /= 10;
        }
        echo "<br>Sum: " . $sum;

        // Reverse the sum of digits
        $reverse = 0;
        $temp = $sum;
        while ($temp > 0) {
            $reverse = $reverse * 10 + $temp % 10;
            $temp = (int)($temp / 10);
        }
        echo "<br>Reversed Sum: <input type='text' value='$reverse' readonly>";

        // Show the multiplication result in an input box
        echo "<br>Multiplication Result: <input type='text' value='" . ($n * 10) . "' readonly>";
    }
    ?>
</body>
</html>
