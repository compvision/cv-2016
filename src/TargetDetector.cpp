#include "TargetDetector.hpp"
#include "Target.hpp"
//public methods

TargetDetector::TargetDetector() {
    //do derpy things
}

Target* TargetDetector::processImage(Mat input) {
    input = thresholdImage(input, 48, 100);
    secretImage = input;
    input = canny(input);
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


Mat TargetDetector::thresholdImage(Mat input, int min, int max){
    Mat hImg;
    cvtColor(input, hImg, CV_BGR2HSV);

    std::vector<Mat> hsv_images;
    split(hImg, hsv_images);

    // To threshold from min to max
    for (int j = 0; j < 2; j++){
        imshow("IDK", hsv_images.at(j));
    }
    Mat hueOrig = hsv_images.at(0).clone();
    Mat threshLower, threshUpper;
    Mat result;

    // If current pixel > min, set pixel to 255, else set to 0
    threshold(hueOrig, threshLower, min, 255, CV_THRESH_BINARY);

    // If current pixel < max, set pixel to 255, else set to 0
    threshold(hueOrig, threshUpper, max, 255, CV_THRESH_BINARY_INV);

    result = threshLower & threshUpper; // Binary AND operation on pixels
    //imshow("Lower", threshLower);
    //imshow("Upper", threshUpper);
    return result;
}

std::vector<std::vector<Point> > TargetDetector::contour(Mat input){
    std::vector<std::vector<Point> > contours;
    dilate(input, input, Mat());
    findContours(input, contours, CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE);
    return contours;
}

std::vector<Point> TargetDetector::filterContours(std::vector<std::vector<Point> > contours){
    for(int j = 0; j < contours.size(); j++){
        std::vector<Point> outputContour;
        approxPolyDP(contours[j], outputContour, (cv::arcLength(cv::Mat(contours.at(j)), true) * 0.02), true);

        if (outputContour.size() == 4 && contourArea(outputContour) > 100){//&& isContourConvex(outputContour)) {

            return outputContour;

        }
    }

    return std::vector<Point>();
}
