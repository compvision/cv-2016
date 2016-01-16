#ifndef VIDEO_DEVICE_H
#define VIDEO_DEVICE_H

#include <opencv2/opencv.hpp>
using namespace cv;

class VideoDevice
{
    public:
        VideoDevice();
        void startCapture(int id);
        Mat getImage();
    private:
        void takeImage();

        //data
        VideoCapture camera;
        Mat image;
        int isFinished;
        int isReady;
        bool isInitialized;

};

#endif
