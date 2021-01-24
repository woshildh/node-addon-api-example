var estimate_pi = require("bindings")("pi_estimate");
var calculations = 100000000;

function printResult(type, pi, ms) {
    console.log(type, 'method:');
    console.log('\tπ ≈ ' + pi +
                ' (' + Math.abs(pi - Math.PI) + ' away from actual)');
    console.log('\tTook ' + ms + 'ms');
    console.log();
}

function runSync() {
    var start = Date.now();
    var result = estimate_pi.estimatePISync(calculations);
    printResult('Sync', result, Date.now() - start);
    console.log("Sync run finished.");
}

function runAsync() {
    function done (err, result) {
        printResult('Async', result, Date.now() - start);
    }
    var start = Date.now();
    estimate_pi.estimatePIAsync(calculations, done); // 异步计算不会阻塞 js 的主线程
    console.log("Async run finished.");
}

runSync();
runAsync();

