const addNumbers = () => {

    var a = 2;
    var b = 3;
    var c = a + b;

    console.log(a + " + " + b + " = " + c);

    var result = document.getElementById("result");

    result.style.background = "yellow";
    result.style.color = "black";
    result.style.fontSize = "200px";
    result.style.fontWeight = "bold";

    result.innerHTML = a + " + " + b + " = " + c;
};