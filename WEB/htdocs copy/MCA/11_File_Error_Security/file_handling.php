<?php
// (a) Write feedback to file
if (isset($_POST['submit'])) {
    $name = $_POST['name'];
    $feedback = $_POST['feedback'];

    $file = fopen("feedback.txt", "a");
    fwrite($file, "Name: $name\nFeedback: $feedback\n\n");
    fclose($file);

    echo "Feedback saved successfully!<br>";
}

// (b) Read file line by line
if (isset($_POST['read'])) {
    $file = fopen("feedback.txt", "r");

    while (($line = fgets($file)) !== false) {
        echo htmlspecialchars($line) . "<br>";
    }

    fclose($file);
}

// (c) Exception handling
try {
    $file = fopen("missing.txt", "r");

    if ($file === false)
        throw new Exception("File does not exist!");

    fclose($file);
} catch (Exception $e) {
    echo $e->getMessage() . "<br>";
}

try {
    $a = 10;
    $b = 0;

    if ($b == 0)
        throw new Exception("Division by zero!");

    echo $a / $b;
} catch (Exception $e) {
    echo $e->getMessage() . "<br>";
}

// // (d) SQL Injection prevention
// $conn = new mysqli("127.0.0.1", "root", "123456789", "college_db");

// if (isset($_POST['search'])) {
//     $username = $_POST['username'];

//     $stmt = $conn->prepare("SELECT * FROM students WHERE name = ?");
//     $stmt->bind_param("s", $username);
//     $stmt->execute();

//     $result = $stmt->get_result();

//     while ($row = $result->fetch_assoc()) {
//         echo htmlspecialchars($row['name']) . "<br>";
//     }

//     $stmt->close();
// }

// $conn->close();
// ?>

<h3>Feedback Form</h3>
<form method="post">
    <input type="text" name="name" placeholder="Name" required>
    <textarea name="feedback" placeholder="Feedback" required></textarea>
    <button name="submit">Submit Feedback</button>
    <button name="read">Read Feedback</button>
</form> 

<hr>

<!-- <h3>Search Student</h3>
<form method="post">
    <input type="text" name="username" placeholder="Student name" required>
    <button name="search">Search</button>
</form> -->