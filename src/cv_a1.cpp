/**
This an amazing main
**/

#include "VideoDevice.hpp"
#include "TargetDetector.hpp"
#include "Target.hpp"
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;

int main(){
    VideoDevice camera;
    camera.startCapture(0);
    Mat img = camera.getImage();
    TargetDetector detector;
    Target* tar = detector.processImage(img);
    std::cout<<"yay no errors";
}
