#include "Target.hpp"
#include "TargetProcessor.hpp"
#include <math.h>

TargetProcessor::TargetProcessor()
{
    objectWidth = 1.6667; //feet
    focalLength = 480; //varies by camera
    horizCenter = 320; //aslo varies by camera
    vertCenter = 240;

} //constructor

void TargetProcessor::loadTarget(Target* target)
{
    imageTarWidth = target->getWidth();
    //double imageHeight = target->getHeight();
    imageTarCenter = target->getCenter();
}

double TargetProcessor::calculateDistance()
{
    return objectWidth*focalLength/imageTarWidth; //returns the distance
}

double TargetProcessor::calculateAzimuth()
{
    double offset = fabs(imageTarCenter.x / horizCenter);
    double distance = calculateDistance();
    return atan(offset/distance);
}
