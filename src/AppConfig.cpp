#include <cstdlib>
#include <string>

#include "AppConfig.hpp"

AppConfig::AppConfig() :
    deviceID(0),
    isFile(0),
    isDevice(0),
    isHeadless(0),
    isNetworking(1),
    isDebug(0)
{
}

// Getters
std::string AppConfig::getFileName()
{
    return fileName;
}

int AppConfig::getDeviceID()
{
    return deviceID;
}

int AppConfig::getIsFile()
{
    return isFile;
}

int AppConfig::getIsDevice()
{
    return isDevice;
}

int AppConfig::getIsHeadless()
{
    return isHeadless;
}

int AppConfig::getIsNetworking()
{
    return isNetworking;
}

int AppConfig::getIsDebug()
{
    return isDebug;
}

// Setters
void AppConfig::setFileName(std::string inputFileName)
{
    fileName = inputFileName;
}

void AppConfig::setDeviceID(int inputDeviceID)
{
    deviceID = inputDeviceID;
}

void AppConfig::setIsFile(int inputIsFile)
{
    isFile = inputIsFile;
}

void AppConfig::setIsDevice(int inputIsDevice)
{
    isDevice = inputIsDevice;
}

void AppConfig::setIsHeadless(int inputIsHeadless)
{
    isHeadless = inputIsHeadless;
}

void AppConfig::setIsNetworking(int inputIsNetworking)
{
    isNetworking = inputIsNetworking;
}

void AppConfig::setIsDebug(int debug)
{
    isDebug = debug;
}
