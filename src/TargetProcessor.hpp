#ifndef TARGET_PROCESSOR_H
#define TARGET_PROCESSOR_H

#include <opencv2/opencv.hpp>
#include "Target.hpp"

class TargetProcessor
{
    public:

        TargetProcessor();
        void loadTarget(Target* target);
        double calculateDistance();

    private:

        double imageWidth;
       // double imageHeight;
        double objectWidth;
       // double objectHeight;
    //only need width or height, not both.
        double focalLength; 

};

#endif
