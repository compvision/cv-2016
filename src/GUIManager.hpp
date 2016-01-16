#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <ctime>
#ifndef GUIManager_hpp
#define GUIManager_hpp

#include <string>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

class GUIManager
{
    public:
        GUIManager(); // Constructor
        void init(); // Initialize GUI
        void setImage(cv::Mat image);
        void setImageText(std::string imageText);
        //void show(const std::vector<std::vector<cv::Point> > &allRectangles,
        //    const std::vector<std::vector<cv::Point> > &finalRectangles); // Show Image
        void show(bool isFile); // Show Image

    private:
        cv::Mat image;
};

#endif /* GUIManager_hpp */	
