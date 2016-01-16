#include <iostream>
#include <opencv2/opencv.hpp>
#include <boost/lexical_cast.hpp>

#include "CmdLineInterface.hpp"
#include"AppConfig.hpp"
#include "NetworkController.hpp"
#include "VideoDevice.hpp"
#include "GUIManager.hpp"
int main(int argc, char* argv[])
{
    // Create all the necessary objects (calls the default constructor for each)
    
    NetworkController networkController;
	//CmdLineInterface interface(argc, argv);		
	//AppConfig config = interface.getConfig();
	//GUIManager gui;

    //init networking
    //if(config.getIsNetworking())
        networkController.startServer();

    //if(!config.getIsHeadless())
     //   gui.init();
    //if(config.getIsDebug())
	// std::cout << "Im debugging! :D\n";

    while(true)
    {
        networkController.waitForPing();

        bool foundTarget = true; 

        if(foundTarget)
        {
            double distance = 10.0;

            networkController.sendMessage("true;" +
                boost::lexical_cast<std::string> (distance));
                
            std::cout << "Target Found! Distance: " << distance;
        }
        else
        {
            networkController.sendMessage("false;");
        }
    }

    return 0;
}
