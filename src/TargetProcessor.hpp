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

        double imageTarWidth;
        //double imageHeight;
        double objectWidth;
        //double objectHeight;
        //only need width or height, not both.
        cv::Point imageTarCenter;
        double focalLength; 
        double horizCenter;
        //center horizontal point of the picture
        double vertCenter;
        //center vertical point

};

#endif
