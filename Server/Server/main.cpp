//
//  main.cpp
//  Server
//
//  Created by Rishat Valitov on 12.11.16.
//  Copyright © 2016 Rishat Valitov. All rights reserved.
//
#include <functional>
#include <iostream>
#include <string.h>

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/thread.hpp>

using namespace std;
using namespace boost;

int main(int argc, char *argv[])
{
    cout << "Server is running\n";
    
    try
    {
        asio::io_service io;
        asio::ip::tcp::acceptor acceptor(io, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), 9090));
        
        string str = "String from server!";
        
        while(true)
        {
            asio::ip::tcp::socket socket(io);
            acceptor.accept(socket);
            
            cout << "Client has been accepted\n";
            
            asio::write(socket, asio::buffer(str));
        }
    }
    
    catch(std::exception& e)
    {
        cout << e.what() << endl;
    }
    return 0;
}












