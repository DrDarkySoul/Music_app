//
//  main.cpp
//  Client
//
//  Created by Rishat Valitov on 12.11.16.
//  Copyright © 2016 Rishat Valitov. All rights reserved.
//
#include <iostream>
#include <string.h>

#include <boost/asio.hpp>

using namespace std;
using namespace boost;

int main(int argc, const char * argv[])
{
    cout << "Client is running\n";
    
    try
    {
        asio::io_service io;
        asio::ip::tcp::socket socket(io);
        asio::ip::tcp::endpoint endPoint(asio::ip::address::from_string("127.0.0.1"), 9090);
        system::error_code err;
        
        socket.connect(endPoint, err);
        
        if(err)
        {
            throw system::system_error(err);
        }
        else
        {
            cout << "Connection established\n";
        }
        
        asio::streambuf sbuf;
        asio::read_until(socket, sbuf, "!");
        
        cout << &sbuf << endl;
        socket.close();
    }
    catch(std::exception& e)
    {
        cout << "Exception was occured: " << e.what() << endl;
    }
    return 0;
}
