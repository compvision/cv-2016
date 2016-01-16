#include "Target.hpp"
#include "TargetProcessor.hpp"

TargetProcessor::TargetProcessor()
{
    objectWidth = 1.0; //temporary value. put real object size here later
    focalLength = 640; //temporary value again

} //constructor

void TargetProcessor::loadTarget(Target* target)
{
    imageWidth = target->getWidth();
    //double imageHeight = target->getHeight();
}

double TargetProcessor::calculateDistance()
{
    return (focalLength*objectWidth)/imageWidth; //returns a distance
}
