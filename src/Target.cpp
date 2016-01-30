#include "Target.hpp"
#include <opencv2/opencv.hpp>
#include <math.h>
#include <iostream>

Target::Target(std::vector<cv::Point> contour)
{
    edge = contour;
    //crap
    std::cout << "EDGE" << edge.size();

    //crow = 1415;
}

double Target::getHeight()
{
    return fabs(getTopPoint().y - getBottomPoint().y);
}

double Target::getWidth()
{
    return fabs(getRightPoint().x - getLeftPoint().x);
}

/*
bool Target::isInitialized()
{
    std::cout << "EDGE" << edge;
    if (edge.size() == 0) {
        return false;
    }
    return true;
}
*/

void Target::printPoints() //debugging
{
    std::cout << "TopPoint: " << getTopPoint() << std::endl;
    std::cout << "BottomPoint: " << getBottomPoint() << std::endl;
    std::cout << "LeftPoint: " << getLeftPoint() << std::endl;
    std::cout << "RightPoint: " << getRightPoint() << std::endl;
}

cv::Point Target::getCenter()//finds center point of target
{
    cv::Point center(0, 0);

    int x = 0;
    for(; x < edge.size(); x++)
    {
        center += edge.at(x);
    }
    //center /= x;
    center.x /= x;
    center.y /= x;
    //will discuss better changes next time we meet
    return center;
}

cv::Point Target::getTopPoint()
{
    cv::Point max(0,0);
    for(unsigned int i = 0; i < edge.size(); i++)
    {
        if(edge[i].y > max.y)
        {
            max = edge[i];
        }
    }
    return max;
}
cv::Point Target::getBottomPoint()
{
    cv::Point min(10000,10000);
    for(unsigned int i = 0; i < edge.size(); i++)
    {
        if(edge[i].y < min.y)
        {
            min = edge[i];
        }
    }
    return min;
}
cv::Point Target::getLeftPoint()
{
    cv::Point min(0,0);
    for(unsigned int i = 0; i < edge.size(); i++)
    {
        if(edge[i].x > min.x)
        {
            min = edge[i];
        }
    }
    return min;
}
cv:: Point Target::getRightPoint()
{
    cv::Point max(10000,10000);
    for(unsigned int i = 0; i < edge.size(); i++)
    {
        if(edge[i].x < max.x)
        {
            max = edge[i];
        }
    }
    return max;
}
