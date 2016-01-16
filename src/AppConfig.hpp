#ifndef AppConfig_hpp
#define AppConfig_hpp

#include <string>

class AppConfig
{
    public:
        AppConfig();
        void setFileName(std::string fileName);
        void setDeviceID(int deviceID);
        void setIsFile(int isFile);
        void setIsDevice(int isDevice);
        void setIsHeadless(int isHeadless);
        void setIsNetworking(int isNetworking);
        void setIsDebug(int debug);
        int getDeviceID();
        int getIsFile();
        int getIsDevice();
        int getIsHeadless();
        int getIsNetworking();
        int getIsDebug();
        std::string getFileName();
    private:
        std::string fileName;
        int deviceID;
        int isFile;
        int isDevice;
        int isHeadless;
        int isNetworking;
        int isDebug;
};

#endif /* AppConfig_hpp */
