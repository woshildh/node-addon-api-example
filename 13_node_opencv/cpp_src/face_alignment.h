/*
@author: Raichu
@file: utils.h 
@time: 2020/12/24
@contact: wk@travelsky.com
@project: umeface 
@software: CLion
*/

//
// Created by Raichu on 2020/12/24.
//

#ifndef UMEFACE_UTILS_H
#define UMEFACE_UTILS_H

#include <vector>
#include <string>
#include <opencv2/opencv.hpp>

cv::Mat UmeyamaEstimate(cv::Mat& src, cv::Mat& dst);   // similarity estimation
cv::Mat MeanAxis0(const cv::Mat &src);
cv::Mat ElementwiseMinus(const cv::Mat &A,const cv::Mat &B);
cv::Mat VarAxis0(const cv::Mat &src);
int MatrixRank(cv::Mat& M);

#endif //UMEFACE_UTILS_H
