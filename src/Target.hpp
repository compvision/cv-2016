#ifndef TARGET_CLASS_H
#define TARGET_CLASS_H
#include <opencv2/opencv.hpp>
using namespace cv;

class Target
{
public:
    Target(std::vector<Point> contour);
    double getHeight();
    double getWidth();
    void printPoints();
    Point getCenter();
    //bool isInitialized();
    //int crow;
private:
    Point getTopPoint();
    Point getBottomPoint();
    Point getLeftPoint();
    Point getRightPoint();
    std::vector<Point> edge;
};

#endif
