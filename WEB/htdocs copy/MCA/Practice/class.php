
<?php

// Interface
interface Printable {
    public function display();
}

// Trait
trait Greeting {
    public function greet() {
        echo "Hello! Welcome to PHP OOP.<br>";
    }
}

// Abstract class
abstract class Person {
    public $name;
    protected $age;
    private $salary = 30000;
    public static $count = 0;

    // Constructor
    public function __construct($name, $age) {
        $this->name = $name;
        $this->age = $age;
        self::$count++;
        echo "Constructor called.<br>";
    }

    // Encapsulation: accessing private data through a method
    public function showSalary() {
        echo "Salary: " . $this->salary . "<br>";
    }

    // Abstract method
    abstract public function work();

    // Regular method
    public function details() {
        echo "Name: " . $this->name . "<br>";
        echo "Age: " . $this->age . "<br>";
    }

    // Destructor
    public function __destruct() {
        echo "Object destroyed.<br>";
    }
}

// Inheritance
class Student extends Person implements Printable {
    use Greeting;

    public function work() {
        echo "Student is studying.<br>";
    }

    // Method overriding / polymorphism
    public function display() {
        echo "Displaying student details.<br>";
    }

    public static function totalObjects() {
        echo "Total objects created: " . self::$count . "<br>";
    }
}

// Creating an object
$s1 = new Student("Aditya", 22);

// Calling methods
$s1->greet();
$s1->details();
$s1->showSalary();
$s1->work();
$s1->display();

// Static method
Student::totalObjects();

// Destructor runs when the object is destroyed
unset($s1);

?>
