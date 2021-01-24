var CreateObject = require("bindings")("addon");

var obj = CreateObject(10);
console.log(obj.PlusOne()); // 11

var obj2 = CreateObject(200);
console.log(obj2.PlusOne()); //201
console.log(obj.PlusOne()); //12 