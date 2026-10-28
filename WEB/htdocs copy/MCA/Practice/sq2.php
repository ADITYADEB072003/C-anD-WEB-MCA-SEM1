
<?php
$conn = new mysqli("127.0.0.1", "root", "123456789", "college_db");

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$sql = "SELECT * FROM students";
$result = $conn->query($sql);

//Insert query
$sql1 = "INSERT INTO students VALUES (41, 'Aditya', 'IT', 82.5, 'adi@hotmail.com')";

if ($conn->query($sql1) === TRUE) {
    echo "New record created successfully.<br>";
} else {
    echo "Error: " . $conn->error;
}

if ($result) {
    echo "Query executed successfully.<br>";

    while ($row = $result->fetch_assoc()) {
        echo "<table border='2'>";
        echo "<tr><td>Roll:</td><td>" . $row["id"] . "</td></tr>";
        echo "<tr><td>Name:</td><td>" . $row["name"] . "</td></tr>";
        echo "<tr><td>Marks:</td><td>" . $row["marks"] . "</td></tr>";
        echo "</table><br>";
    }
} else {
    echo "Error: " . $conn->error;
}

$conn->close();
echo "MySQL connection closed successfully.";
?>
