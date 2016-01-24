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
    //               out of src, out of build
    Mat img = imread("../../imgs/ourpics/9ft_45degrees/9ft_45degrees.jpg");
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
