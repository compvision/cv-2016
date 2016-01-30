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
        double calculateAzimuth();
        double calculateAltitude();

    private:

        const double imageTarWidth;
        //double imageHeight;
        const double objectWidth;
        //double objectHeight;
        //only need width or height, not both.
        cv::Point imageTarCenter;
        const double focalLength; 
        const double horizCenter;
        //center horizontal point of the picture
        const double vertCenter;
        //center vertical point

};

#endif
