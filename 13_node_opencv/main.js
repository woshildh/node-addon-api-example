const cv = require("opencv4nodejs")
const ufa = require("./build/Release/UMEFaceAlignment")

const buffer = new Float32Array(10);
buffer[0] = 400.0; buffer[1] = 688.0; buffer[2] = 695.0; buffer[3] = 697.0; buffer[4] = 602.0;
buffer[5] = 868.0; buffer[6] = 435.0; buffer[7] = 1057.0; buffer[8] = 659.0; buffer[9] = 1058.0;
const image = new cv.Mat(buffer, 5, 2, cv.CV_32F);

const buffer2 = new Float32Array(10);
buffer2[0] = 38.2946; buffer2[1] = 51.6963; buffer2[2] = 73.5318; buffer2[3] = 51.5014; buffer2[4] = 56.0252;
buffer2[5] = 71.7366; buffer2[6] = 41.5493; buffer2[7] = 92.3655; buffer2[8] = 70.7299; buffer2[9] = 92.2041;
const image2 = new cv.Mat(buffer2, 5, 2, cv.CV_32F);

var result = ufa.FaceAlignment(image.getData(), image2.getData());

console.log(result)