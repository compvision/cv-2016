#include "TargetProcessor.hpp"
#include "Target.hpp"
#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
    std::vector<cv::Point> rect;
    rect.push_back(cv::Point(-100, -100));
    rect.push_back(cv::Point(-100, 100));
    rect.push_back(cv::Point(100, -100));
    rect.push_back(cv::Point(100, 100));

    Target* target = new Target(rect);

    TargetProcessor processor;
    processor.loadTarget(target);
    double distance = processor.calculateDistance();
    
    std::cout << distance << std::endl;

    return 0;
}
