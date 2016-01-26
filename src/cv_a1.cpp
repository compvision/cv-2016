/**
This an amazing main
**/

#include "VideoDevice.hpp"
#include "TargetDetector.hpp"
#include "Target.hpp"
#include <opencv2/opencv.hpp>
using namespace cv;

int main()
{
    VideoDevice camera;
    //camera.startCapture(1);
    //Uncomment each line individually to test each image
    Mat img = imread("../../imgs/ourpics/9ft_tilted/9ft_tilted.jpg");
    //Mat img = imread("../../imgs/ourpics/9ft_45degrees/9ft_45degrees.jpg");
    //Mat img = imread("../../imgs/ourpics/1m/1meter.jpg");
    imshow("Image", img);
    waitKey(0);
    TargetDetector detector;
    detector.processImage(img);


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
