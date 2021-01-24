var addon = require("bindings")("addon")

var obj1 = addon.CreateObject(10);
var obj2 = addon.CreateObject(13);
var result = addon.Add(obj1, obj2);
console.log(result);