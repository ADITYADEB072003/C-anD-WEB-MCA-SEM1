<?php
if (isset($_POST["text"])) {
    $s = $_POST["text"];
    $clean = strtolower(str_replace(" ", "", $s));

    echo "Original: $s<br>";
    echo "Length: " . strlen($s) . "<br>";
    echo "Reverse: " . strrev($s) . "<br>";
    echo "Palindrome: " . ($clean == strrev($clean) ? "Yes" : "No") . "<br>";
    echo "Vowels: " . (strlen($clean) - strlen(str_replace(["a","e","i","o","u"], "", $clean)));
}
?>

<form method="post">
    <input name="text" placeholder="Enter string" required>
    <button name="b">Process</button>
</form>

<?php
$ua = $_SERVER['HTTP_USER_AGENT'];

$browser = preg_match('/Edg/i', $ua) ? "Edge" :
           (preg_match('/Chrome/i', $ua) ? "Chrome" :
           (preg_match('/Firefox/i', $ua) ? "Firefox" : "Safari"));

$os = preg_match('/Windows/i', $ua) ? "Windows" :
      (preg_match('/Android/i', $ua) ? "Android" :
      (preg_match('/Mac/i', $ua) ? "macOS" : "Linux"));

echo "<h3>Browser Detection</h3>";
echo "Browser: $browser<br>OS: $os";
?> -->

<hr>



<?php
if (isset($_POST["b"])) {
    $n = $_POST["text"];

    echo preg_match("/^[A-Za-z ]+$/", $n)
        ? "Valid name"
        : "Invalid name";
}
?>