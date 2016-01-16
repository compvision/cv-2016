#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>

#include <boost/asio.hpp>

#include "NetworkController.hpp"

NetworkController::NetworkController()
{
    portNumber = 3341;
    isInitialized = false;
}

NetworkController::~NetworkController()
{
    if(isInitialized)
    {
        delete socket;
        delete acceptor;
        delete io_service;
    }
}

void NetworkController::startServer()
{
    try
    {
        io_service = new boost::asio::io_service();
        acceptor = new boost::asio::ip::tcp::acceptor(*io_service,
                boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(),
                                               portNumber));
        socket = new boost::asio::ip::tcp::socket(*io_service);
        acceptor->accept(*socket);
        boost::asio::socket_base::keep_alive option(true);
        socket->set_option(option);
        isInitialized = true;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void NetworkController::waitForPing()
{
    std::vector<char> buffer(256);
    socket->read_some(boost::asio::buffer(buffer), error);
    if (error == boost::asio::error::eof)
        exit(EXIT_SUCCESS);
    else if (error)
        throw boost::system::system_error(error);
}

void NetworkController::sendMessage(std::string message)
{
    boost::asio::write(*socket, boost::asio::buffer(message
                       + std::string("\n")), ignored_error);
}
