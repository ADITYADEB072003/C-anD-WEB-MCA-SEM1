<?php
require "db.php";
if($conn->query("ALTER TABLE students ADD COLUMN email VARCHAR(150)")){
    echo "Email column added.";
}else{
    echo "Operation result: ".htmlspecialchars($conn->error);
}
?>
