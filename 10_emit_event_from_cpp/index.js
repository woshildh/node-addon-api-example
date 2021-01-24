const EventEmitter = require('events').EventEmitter;
const addon = require("bindings")("emit_from_cpp");
console.log(addon)
const emitter = new EventEmitter();

emitter.on('start', ()=>{
    console.log("start...");
});

emitter.on('data', (evt)=>{
    console.log(evt);
});

emitter.on('end', ()=>{
    console.log("end...");
});
// 注意这个不是异步的，会阻塞主线程
addon.callEmit(emitter.emit.bind(emitter)); 

console.log('--------');