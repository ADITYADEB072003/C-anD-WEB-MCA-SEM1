
<?php
$conn = mysqli_connect("127.0.0.1", "root", "123456789", "college_db");

if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
} else {
    echo "Connection established<br>";
}

$sql = "SELECT * FROM employee";
$result = mysqli_query($conn, $sql);
?>

<!DOCTYPE html>
<html>
<head>
    <title>Employee Details</title>

    <style>
        body {
            font-family: Arial, sans-serif;
            background-color: #f4f6f9;
            padding: 30px;
        }

        h2 {
            text-align: center;
            color: #333;
        }

        table {
            width: 80%;
            margin: 20px auto;
            border-collapse: collapse;
            background-color: white;
            box-shadow: 0 4px 10px rgba(0, 0, 0, 0.1);
        }

        th {
            background-color: #2563eb;
            color: white;
            padding: 12px;
            text-align: left;
        }

        td {
            padding: 10px 12px;
            border-bottom: 1px solid #ddd;
        }

        tr:nth-child(even) {
            background-color: #f2f6fc;
        }

        tr:hover {
            background-color: #dbeafe;
        }

        th, td {
            border: 1px solid #ddd;
        }
    </style>
</head>

<body>

<h2>Employee Details</h2>

<table>
    <tr>
        <th>ID</th>
        <th>Name</th>
        <th>Department</th>
        <th>Salary</th>
        <th>Marks</th>
    </tr>

    <?php
    if ($result) {
        while ($row = mysqli_fetch_array($result)) {
            echo "<tr>";
            echo "<td>" . htmlspecialchars($row[0]) . "</td>";
            echo "<td>" . htmlspecialchars($row[1]) . "</td>";
            echo "<td>" . htmlspecialchars($row[2]) . "</td>";
            echo "<td>" . htmlspecialchars($row[3]) . "</td>";
           
            echo "</tr>";
        }
    }
    ?>
</table>

</body>
</html>

<?php
mysqli_close($conn);
?>
