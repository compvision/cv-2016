#include "TargetProcessor.hpp"
#include "Target.hpp"
#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
    std::vector<cv::Point> rect;
    rect.push_back(cv::Point(181, 138));
    rect.push_back(cv::Point(204, 137));
    rect.push_back(cv::Point(202, 272));
    rect.push_back(cv::Point(379, 276));
    rect.push_back(cv::Point(382, 142));
    rect.push_back(cv::Point(407, 142));
    rect.push_back(cv::Point(405, 303));
    rect.push_back(cv::Point(177, 293));
    
    //test values based on target from rect1f.jpg (modded)

    Target* target = new Target(rect);

    TargetProcessor processor;
    processor.loadTarget(target);
    double distance = processor.calculateDistance();
    double azimuth = processor.calculateAzimuth();
    target->printPoints();
    
    std::cout << "distance: " << distance << std::endl;
    std::cout << "azimuth: " << azimuth << std::endl;

    return 0;
}
