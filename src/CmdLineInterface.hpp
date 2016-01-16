#ifndef CmdLineInterface_hpp
#define CmdLineInterface_hpp

#include "AppConfig.hpp"

class CmdLineInterface
{
    private:
        //void printUsage(std::string name);
        AppConfig config;
    public:
        CmdLineInterface(int argc, char *argv[]);
        AppConfig getConfig();
};

#endif /* CmdLineInterface_hpp */
