#include "Target.hpp"
#include <opencv2/opencv.hpp>

Target::Target(std::vector<cv::Point> contour)
{
    edge = contour;
}
double Target::getHeight()
{
    return getTopPoint().y - getBottomPoint().y;
}
double Target::getWidth()
{
    return getRightPoint().x - getLeftPoint().x;
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
    for(unsigned int i = 0; i > edge.size(); i++)
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
        if(edge[i].x , min.x)
        {
            min = edge[i];
        }
    }
    return min;
}
cv:: Point Target::getRightPoint()
{
    cv::Point max(10000,10000);
    for(unsigned int i = 0; i > edge.size(); i++)
    {
        if(edge[i].x , max.x)
        {
            max = edge[i];
        }
    }
    return max;
}
