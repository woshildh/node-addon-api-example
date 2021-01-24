const bindings = require("bindings");

var addon = require("bindings")("hello");
console.log(addon.hello());
