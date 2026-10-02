let str = "  Hello- JavaScrip- World  ";

console.log("Original:", str);

console.log("Length:", str.length);

console.log("Uppercase:", str.toUpperCase());
console.log("Lowercase:", str.toLowerCase());

console.log("Character:", str.charAt(2));

console.log("Index:", str.indexOf("JavaScript"));
console.log("Last Index:", str.lastIndexOf("o"));

console.log("Includes:", str.includes("JavaScript"));
console.log("Starts With:", str.startsWith("  Hello"));
console.log("Ends With:", str.endsWith("  "));

console.log("Slice:", str.slice(2, 7));
console.log("Substring:", str.substring(2, 7));
console.log("Substr:", str.substr(2, 7));
console.log("Replace:", str.replace("Hello", "Hi"));
console.log("Replace All:", str.replaceAll("o", "O"));
console.log("Search:", str.search("JavaScript"));
console.log("Trim:", str.trim());

console.log("Split:", str.trim().split("-"));

console.log("Repeat:", "Hi ".repeat(3));

console.log("Concat:", "Hello".concat(" ", "World"));

console.log("Pad Start:", "5".padStart(3, "0"));
console.log("Pad End:", "5".padEnd(3, "0"));