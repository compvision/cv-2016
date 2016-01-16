#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <ctime>
#include <vector>
#include <set>

#include "GUIManager.hpp"

// Public Functions
GUIManager::GUIManager()
{
}

void GUIManager::init()
{
    cv::namedWindow("FRC Team 3341 Targeting", 0);
}

void GUIManager::setImage(cv::Mat inputImage)
{
    image = inputImage;
}

void GUIManager::setImageText(std::string imageText)
{
    cv::putText(image, imageText, cv::Point(0, image.rows - 5),
                cv::FONT_HERSHEY_COMPLEX_SMALL, 0.8, cv::Scalar(0.0, 0.0, 255.0, 0.0),
                1);
}

void GUIManager::show(bool isFile)
{
    //isFile determines if image should be shown indefinitely
    //in File Mode, the main loop only runs once rather than continuously
    cv::imshow("FRC Team 3341 Targeting", image);
    if(isFile)
        cv::waitKey(0);
    else
        cv::waitKey(10);
}
