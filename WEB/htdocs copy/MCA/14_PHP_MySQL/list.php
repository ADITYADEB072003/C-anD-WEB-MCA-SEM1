<?php
require "db.php";
echo "<h3>Databases</h3>";
$result=$conn->query("SHOW DATABASES");
while($row=$result->fetch_assoc()) echo htmlspecialchars($row["Database"])."<br>";

echo "<h3>Tables in college_db</h3>";
$result=$conn->query("SHOW TABLES");
while($row=$result->fetch_array()) echo htmlspecialchars($row[0])."<br>";
$result=$conn->query("desc students");
while($row=$result->fetch_array()) echo ($row[0])."<br>";
?>
