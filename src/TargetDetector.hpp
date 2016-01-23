#ifndef TARGET_DETECTOR_H
#define TARGET_DETECTOR_H

#include "Target.hpp"
#include <opencv2/opencv.hpp>
using namespace cv;

class TargetDetector
{
    public:
        TargetDetector();
        Target* processImage(Mat input);
        //thresholds, cannies, contours, filters contours
    private:
        Mat canny(Mat input);
        Mat thresholdImage(Mat input, int min, int max);
        double angle(cv::Point p1, cv::Point p2, cv::Point p0);
        std::vector<std::vector<Point> >  contour(Mat input);
        std::vector<Point> filterContours(std::vector<std::vector<Point> > contours);
};

#endif
