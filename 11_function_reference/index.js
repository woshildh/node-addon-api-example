const addon = require("bindings")("addon")

function JSFnRef() {
    console.log("Hi, I\'am a js function reference!");
}

function JSFn() {
    console.log("Hi, I\'am a js function!");
}

const func_call = new addon.NativeAddon(JSFnRef, JSFn);

for(let i = 0; i < 5; i++) {
    func_call.tryCallByStoredReference();
}

try {
    addon.tryCallByStoredFunction()
} catch (err) {
    console.error('This code crashes because JSFn is valid only inside the constructor function.')
    console.error('The lifespan of the JSFn function is limited to the execution of the constructor function.')
    console.error('After that, the function stored in JSFn is ready to be garbage collected and it cannot be used anymore.')
}
