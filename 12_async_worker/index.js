const asyncWorker = require("bindings")("asyncModule");

let result = asyncWorker.runSimpleAsyncWorker(1, AsyncWorkerCompletion);
console.log("runSimpleAsyncWorker returned '"+result+"'.");

function AsyncWorkerCompletion (err, result) {
    if (err) {
        console.log("SimpleAsyncWorker returned an error: ", err);
    } else {
        console.log("SimpleAsyncWorker returned '"+result+"'.");
    }
};
