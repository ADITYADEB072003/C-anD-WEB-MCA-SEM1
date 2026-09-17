const addNumbers = () => {

//     let a=confirm("Enter first number");
//    if(a==true){
//     let num1 = parseFloat(prompt("Enter the first number:"));
//     let num2 = parseFloat(prompt("Enter the second number:"));
//     let sum = num1 + num2;
//    }
//    else{
//     alert("You cancelled the operation.");
//     return;
//    }    
    
   let array=[2,3,5,6,7,8,9,10];
   let a=array.sort((a,b)=>b-a).join(",");
   for(let i=a.length;i>0;i++){
    document.write(a);
   }    
   
};