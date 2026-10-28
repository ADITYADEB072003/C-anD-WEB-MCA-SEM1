
<?php
$conn = mysqli_connect("127.0.0.1", "root", "123456789", "college_db");

if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}

$sql = "SELECT * FROM students";
$result = mysqli_query($conn, $sql);

// $sql1="insert into students values(4,'Aditya','it',82.5,'adi@hotmail.com')";

// if (mysqli_query($conn, $sql1)) {
//     echo "New record created successfully.<br>";
// } else {
//     echo "Error: " . mysqli_error($conn);
// }

if ($result) {
    echo "Query executed successfully.<br>";

    while ($row = mysqli_fetch_array($result)) {
        echo "<table border='2'>";
        echo "<tr><td>Roll1: </td><td>" . $row["id"] . "</td></tr>";
        echo "<tr><td>Name: </td><td>" . $row["name"] . "</td></tr>";
        echo "<tr><td>Marks: </td><td>" . $row["marks"] . "</td></tr>";
        echo "</table>";
    }
} else {
    echo "Error: " . mysqli_error($conn);
}

mysqli_close($conn);
echo "MySQL connection closed successfully.";
?>
