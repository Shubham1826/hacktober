let fruit = ['Apple','Mango'];
console.log(fruit);
console.log(fruit.length);
let first = fruit[0];
console.log(first);

let last = fruit[fruit.length - 1]
console.log(last);

let newarr = fruit.push('Banana');// add last
console.log(newarr);
console.log(fruit);

let k = fruit.pop();// remove from last
console.log(fruit);

let l = fruit.shift();// remove from front
console.log(fruit);

let u = fruit.unshift("Orange");
console.log(fruit);


let p = fruit.indexOf("Mango");
console.log(p);

let r = fruit.splice(1);
console.log(r);
console.log(fruit);


let a = ['Debadyuti', 50, "$" ,5.2]
console.log(a);
let copy = a.slice();
console.log(copy);
console.log(copy[10]);



let newarray = [];
newarray.push("java");
console.log(newarray);
