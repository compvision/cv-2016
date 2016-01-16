#include "VideoDevice.hpp"
#include <opencv2/opencv.hpp>
using namespace cv;

VideoDevice::VideoDevice(){
    //does absolutely nothing
}

void VideoDevice::startCapture(int id){
    camera = VideoCapture(id);
}

Mat VideoDevice:: getImage(){
    takeImage();
    return image;
}

void VideoDevice::takeImage(){
    camera >> image;
}
