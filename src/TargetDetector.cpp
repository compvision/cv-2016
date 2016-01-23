#include "TargetDetector.hpp"
#include "Target.hpp"
//public methods

TargetDetector::TargetDetector() 
{
    //do derpy things
}

Target* TargetDetector::processImage(Mat input) 
{
    input = thresholdImage(input, 180, 220);
    input = canny(input);
    std::vector<std::vector<Point> > contours = contour(input);
    std::vector<Point> finalContour = filterContours(contours);
    Target toReturn(finalContour);
    return &toReturn;
}

//private methods

Mat TargetDetector::canny(Mat input)
{
    Canny(input, input, 0, 20, 3);
    return input;
}

Mat TargetDetector::thresholdImage(Mat input, int min, int max)
{
    Mat hImg;
    cvtColor(input, hImg, CV_BGR2HSV);

    std::vector<Mat> hsv_images;
    split(hImg, hsv_images);

    // To threshold from min to max
    for (int j = 0; j < 2; j++)
    {
        imshow("IDK", hsv_images.at(j));
    }

    Mat hueOrig = hsv_images.at(2).clone();
    Mat threshLower, threshUpper;
    Mat result;

    // If current pixel > min, set pixel to 255, else set to 0
    threshold(hueOrig, threshLower, min, 100, CV_THRESH_BINARY);

    // If current pixel < max, set pixel to 255, else set to 0
    threshold(hueOrig, threshUpper, max, 140, CV_THRESH_BINARY_INV);

    result = threshLower & threshUpper; // Binary AND operation on pixels
    //imshow("Lower", threshLower);
    //imshow("Upper", threshUpper);
    return result;
}

std::vector<std::vector<Point> > TargetDetector::contour(Mat input)
{
    std::vector<std::vector<Point> > contours;
    dilate(input, input, Mat());
    findContours(input, contours, CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE);
    return contours;
}

double TargetDetector::angle(cv::Point p1, cv::Point p2, cv::Point p0)
{
    double dx1 = p1.x - p0.x;
    double dy1 = p1.y - p0.y;
    double dx2 = p2.x - p0.x;
    double dy2 = p2.y - p0.y;
    return atan(dy1/dx1)-atan(dy2/dx2); //in rad 
//alt return (in deg)
//(dx1 * dx2 + dy1 * dy2)/
//sqrt((dx1 * dx1 + dy1 * dy1) * (dx2 * dx2 + dy2 * dy2) + 1e-10);
}

std::vector<Point> TargetDetector::filterContours(std::vector<std::vector<Point> > contours)
{
    for(int j = 0; j < contours.size(); j++)
    {
        std::vector<Point> outputContour;
        approxPolyDP(contours[j], outputContour, (cv::arcLength(cv::Mat(contours.at(j)), true) * 0.02), true);
        //filteers shapes that doen't have 8 points, aren't 50 big, and are concave
        if (outputContour.size() == 8 && contourArea(outputContour) > 50
            && isContourConvex(outputContour)) 
        {
            double maxCosine = 0;
            for(int j = 2; j <=4; j++)
            {
                double cosine = fabs(cos(angle(outputContour.at(j%4),
                outputContour.at(j-2), outputContour.at(j-1))));
                maxCosine = MAX(maxCosine, cosine);
            }
            //filters out contours that don't have only 90deg anlges
            if(maxCosine < .2)

            {
                return outputContour;
            }
        }
    }

    return std::vector<Point>();
}
