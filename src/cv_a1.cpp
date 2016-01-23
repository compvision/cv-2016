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
    //camera.startCapture(1);

    Mat img = imread("Images/1meter/1meter.jpg");
    imshow("Image", img);
    waitKey(0);
    TargetDetector detector;
    detector.processImage(img);

    imshow("Thresholded", detector.getSecrets());

    /*
    while (waitKey(30) != 0) {
        Mat img = camera.getImage();
        TargetDetector detector;
        Target* tar = detector.processImage(img);
        imshow("IMAGES OMFG", img);

    }
    */

    std::cout<<"yay no errors";
    waitKey(0);

}
