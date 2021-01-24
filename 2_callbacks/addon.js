const addon = require("bindings")("addon");

addon(function(msg) {
    console.log("callback", msg);
});