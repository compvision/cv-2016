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

double TargetProcessor::calculateAzimuth() //unsure if this is working properly, but is returning a reasonable looking value
{
    double offset = imageTarCenter.x / horizCenter;
    double distance = calculateDistance();
    return (atan(offset/distance))*(180/M_PI); //in degrees
}

double TargetProcessor::calculateAltitude() //same comment as calculateAzimuth()
{
    double offset = imageTarCenter.y / vertCenter;
    double distance = calculateDistance();
    return (atan(offset/distance))*(180/M_PI); //in degrees
}
