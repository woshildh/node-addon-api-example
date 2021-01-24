var addon = require("bindings")("addon")

var obj = new addon.MyObject(2);
console.log(obj.value(), obj.plusOne()); //2, 3

var obj2 = new addon.MyObject(5);
console.log(obj == obj2);