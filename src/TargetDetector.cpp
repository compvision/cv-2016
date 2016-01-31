#include "TargetDetector.hpp"
#include "Target.hpp"
#include <iostream>
//public methods

TargetDetector::TargetDetector() {
    //do derpy things
}

Target* TargetDetector::processImage(Mat input) {
    secretImage = input.clone();
    input = thresholdImage(input, 0, 102, 227, 255);
    dilate(input, input, Mat());

    std::vector<std::vector<Point> > contours = contour(input);
    std::cout << "not contours" << std::endl;
    std::vector<Point> finalContour = filterContours(contours);
    std::cout << "not filterContours" << std::endl;

    if (finalContour.size() == 0) {
        return NULL;
    }
    else {
        Target* toReturn = new Target(finalContour);
        return toReturn;
    }
}

Mat TargetDetector::getOutlinedImage() {
    return secretImage;
}
//private methods

Mat TargetDetector::canny(Mat input) {
    Canny(input, input, 0, 20, 3);
    return input;
}


Mat TargetDetector::thresholdImage(Mat input, int minHue, int maxHue, int minVal, int maxVal) {
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

std::vector<std::vector<Point> > TargetDetector::contour(Mat input) {
    std::vector<std::vector<Point> > contours;

    findContours(input, contours, CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE);
    return contours;
}

double TargetDetector::angle(cv::Point p1, cv::Point p2, cv::Point p0) {
    double dx1 = p1.x - p0.x;
    double dy1 = p1.y - p0.y;
    double dx2 = p2.x - p0.x;
    double dy2 = p2.y - p0.y;
    return atan(dy1/dx1)-atan(dy2/dx2); //in rad
}

std::vector<Point> TargetDetector::filterContours(std::vector<std::vector<Point> > contours) {

    Mat thirdTime(Size(500,500), CV_8UC1, Scalar( rand()&255, rand()&255, rand()&255 ));

    for(unsigned int j = 0; j < contours.size(); j++)
    {
        std::vector<Point> outputContour;
        std::vector<std::vector<Point> > pointless;
        approxPolyDP(contours[j], outputContour, (cv::arcLength(cv::Mat(contours.at(j)), true) * 0.01), true);


        if (contourArea(outputContour) > 100 && outputContour.size() == 8) { //&& isContourConvex(outputContour)) {
            double maxCosine = 0;
            for(int j = 2; j <=4; j++)
            {
                double cosine;
                try {
                    cosine = fabs(cos(angle(outputContour.at(j%4), outputContour.at(j-2), outputContour.at(j-1))));
                }
                catch(std::exception e){
                    std:: cout << e.what();
                }
                maxCosine = MAX(maxCosine, cosine);
            }
            //filters out contours that don't have only 90deg anlges
            if(maxCosine < .2)

            {
                pointless.push_back(outputContour);
                Scalar color(0,0,0);
                drawContours(secretImage, pointless, 0, color, 10);
                return outputContour;
            }

        }
        //
    }


    return std::vector<Point>();
}
