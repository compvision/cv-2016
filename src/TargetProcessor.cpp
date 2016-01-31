#include "Target.hpp"
#include "TargetProcessor.hpp"
#include <math.h>

TargetProcessor::TargetProcessor()
{
    objectWidth = 0.508; //meters
    focalLength = 480; //varies by camera
    horizCenter = 320; //aslo varies by camera (center horizontal point on video)
    vertCenter = 240; //center vertical point on video

} //constructor

void TargetProcessor::loadTarget(Target* target)
{
    imageTarWidth = target->getWidth();
    //double imageHeight = target->getHeight();
    imageTarCenter = target->getCenter();
}

double TargetProcessor::calculateDistance()
{
    return objectWidth*focalLength/imageTarWidth; //returns the distance (m)
}

double TargetProcessor::calculateAzimuth() //unsure if this is working properly, but is returning a reasonable looking value
{
    double offset = imageTarCenter.x - horizCenter;
    double distance = calculateDistance();
    return (atan(offset/focalLength))*(180/M_PI); //in degrees
}

double TargetProcessor::calculateAltitude() //same comment as calculateAzimuth()
{
    int cameraAngle = 0; //angle the camera is pointing up from the horizon; assumes camera is level
    double offset =  vertCenter - imageTarCenter.y;
    double distance = calculateDistance();
    return (atan(offset/focalLength))*(180/M_PI) + cameraAngle; //in degrees
}
