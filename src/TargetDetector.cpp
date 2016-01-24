#include "TargetDetector.hpp"
#include "Target.hpp"
#include <iostream>
//public methods

TargetDetector::TargetDetector() {
    //do derpy things
}

Target* TargetDetector::processImage(Mat input) {
    originalSecretImage = input.clone();
    input = thresholdImage(input, 0, 102, 227, 255);
    //secretImage = input.clone();
    dilate(input, input, Mat());
    secretImage = input.clone();
    imshow("Di of lated", input);
    std::vector<std::vector<Point> > contours = contour(input);
    std::vector<Point> finalContour = filterContours(contours);
    Target toReturn(finalContour);
    return &toReturn;
}

Mat TargetDetector::getSecrets() {
    return secretImage;
}

//private methods

Mat TargetDetector::canny(Mat input){
    Canny(input, input, 0, 20, 3);
    return input;
}


Mat TargetDetector::thresholdImage(Mat input, int minHue, int maxHue, int minVal, int maxVal){
    //defining variables
    Mat threshLow;
    Mat threshHigh;
    Mat hueResult;
    Mat valResult;

    //seperating image into HSV (or in this case, really just HV)
    cv::Mat cvted;
    cv::cvtColor(input, cvted, CV_BGR2HSV);

    std::vector<cv::Mat> separated(3);
    cv::split(cvted, separated);
    Mat hue = separated.at(0).clone();
    Mat val = separated.at(2).clone();

    //Hue
    threshold(hue, threshLow, minHue, 255, THRESH_BINARY);
    threshold(hue, threshHigh, maxHue, 255, THRESH_BINARY_INV);
    hueResult = threshLow & threshHigh;

    //Value
    threshold(val, threshLow, minVal, 255, THRESH_BINARY);
    threshold(val, threshHigh, maxVal, 255, THRESH_BINARY_INV);
    valResult = threshLow & threshHigh;

    Mat combined = hueResult & valResult;

    return combined;
}

std::vector<std::vector<Point> > TargetDetector::contour(Mat input){
    std::vector<std::vector<Point> > contours;

    findContours(input, contours, CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE);
    return contours;
}

std::vector<Point> TargetDetector::filterContours(std::vector<std::vector<Point> > contours){
    Mat thirdTime(Size(1000,1000), CV_8UC1, Scalar( rand()&255, rand()&255, rand()&255 ));
    for(int j = 0; j < contours.size(); j++){
        std::vector<Point> outputContour;
        std::vector<std::vector<Point> > pointless;
        approxPolyDP(contours[j], outputContour, (cv::arcLength(cv::Mat(contours.at(j)), true) * 0.02), true);
        pointless.push_back(outputContour);
        Scalar color( rand()&255, rand()&255, rand()&255 );
        drawContours(thirdTime, pointless, 0, color);

        if (outputContour.size() == 4 && contourArea(outputContour) > 100){//&& isContourConvex(outputContour)) {

            //return outputContour;

        }
    }
    imshow("originalSecretImage", thirdTime);

    return std::vector<Point>();
}
