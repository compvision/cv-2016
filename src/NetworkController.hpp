#ifndef NetworkController_hpp
#define NetworkController_hpp

#include <boost/asio.hpp>

class NetworkController
{
    public:
        NetworkController();
        ~NetworkController();
        void startServer();
        void waitForPing();
        void sendMessage(std::string message);
    private:
        int portNumber;
        bool isInitialized;
        boost::asio::io_service *io_service;
        boost::asio::ip::tcp::acceptor *acceptor;
        boost::asio::ip::tcp::socket *socket;
        boost::system::error_code ignored_error;
        boost::system::error_code error;
};

#endif /* NetworkController_hpp  */
