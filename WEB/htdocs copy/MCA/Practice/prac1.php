<?php
// 1. Global variable
$globalMessage = "Global variable";

// 2. Indexed array
$a = [10, 20, 30, 40, 50];

echo "<h2>Indexed Array</h2>";

foreach ($a as $value) {
    echo "<p>$value</p>";
}

// Display complete array
echo "<pre>";
print_r($a);
echo "</pre>";

// Count elements
echo "<p>Count = " . count($a) . "</p>";


// 3. Associative array
$b = [
    "Name" => "Aditya",
    "Age" => 22,
    "Percentage" => 82.5,
    "isStudent" => true
];

echo "<h2>Associative Array</h2>";

foreach ($b as $key => $value) {
    if (is_bool($value)) {
        $value = $value ? "True" : "False";
    }

    echo "<p>$key : $value</p>";
}


// 4. Multidimensional array
$c = [
    [
        "Name" => "Aditya",
        "Age" => 22,
        "Percentage" => 82.5,
        "isStudent" => true
    ],
    [
        "Name" => "John",
        "Age" => 25,
        "Percentage" => 75.0,
        "isStudent" => false
    ]
];

echo "<h2>Multidimensional Array</h2>";

foreach ($c as $index => $subArray) {
    echo "<h3>Sub-array $index</h3>";
    echo "<pre>";
    print_r($subArray);
    echo "</pre>";

    foreach ($subArray as $key => $value) {
        if (is_bool($value)) {
            $value = $value ? "True" : "False";
        }

        echo "<p>$key : $value</p>";
    }
}


// 5. Function and global variable
function displayMessage($message) {
    global $globalMessage;

    echo "<p>$message</p>";

    $name = "Aditya";

    echo "<h2>$globalMessage</h2><hr>";
}

displayMessage("Hello, welcome to the PHP practice session!");

?>