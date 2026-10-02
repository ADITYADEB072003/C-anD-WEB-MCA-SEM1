let arr = [10, 20, 30, 40];


// ==================== ADD ====================

console.log("Find", arr.find(x => x < 30)); // 30
console.log("Filter", arr.filter(x => x < 30)); // [10, 20]
// Add 50 at the END
arr.push(50);
// [10, 20, 30, 40, 50]


// Add 5 at the BEGINNING
arr.unshift(5);
// [5, 10, 20, 30, 40, 50]


// ==================== REMOVE ====================

// Remove the LAST element
arr.pop();
// [5, 10, 20, 30, 40]


// Remove the FIRST element
arr.shift();
// [10, 20, 30, 40]


// ==================== SPLICE ====================

// splice(start, deleteCount, addElement)

// index 1 → remove 20 and add 3
arr.splice(1, 1, 3);
// [10, 3, 30, 40]


// ==================== SEARCH ====================

// Find the index of 30
let index = arr.indexOf(30);
// 2

// Check whether 30 exists
let check = arr.includes(30);
// true


// ==================== SLICE ====================

// Copy elements from index 1 up to (NOT including) index 3
let x = arr.slice(1, 3);
// [3, 30]


// ==================== MAP ====================

// Multiply EVERY element by 2
let doubled = arr.map(x => x * 2);
// [20, 6, 60, 80]


// ==================== FILTER ====================

// Keep only elements greater than 20
let big = arr.filter(x => x > 20);
// [30, 40]


// ==================== REDUCE ====================

// Add all elements
let sum = arr.reduce((a, b) => a + b, 0);
// 83


// ==================== FIND ====================

// Find the FIRST element greater than 20
let value = arr.find(x => x > 20);
// 30


// ==================== SORT ====================

// Sort from BIG → SMALL
arr.sort((a, b) => b - a);
// [40, 30, 10, 3]


// ==================== REVERSE ====================

// Reverse the array
arr.reverse();
// [3, 10, 30, 40]


console.log(arr);
console.log(x);