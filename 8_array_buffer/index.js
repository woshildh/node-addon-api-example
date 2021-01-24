const array_buffer_to_native = require("bindings")("array_buffer_to_native")
const array = new Int32Array(10);

for(var i = 0; i < 10; ++i) {
    array[i] = i * 10 + 2;
}

array_buffer_to_native.AcceptArrayBuffer(array.buffer);
