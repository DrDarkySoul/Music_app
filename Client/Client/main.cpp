//
//  main.cpp
//  Client
//
//  Created by Rishat Valitov on 12.11.16.
//  Copyright © 2016 Rishat Valitov. All rights reserved.
//
#include <iostream>
#include <string.h>
#include "json.hpp"
#include <boost/asio.hpp>


using namespace std;
using namespace boost;
using namespace nlohmann;


int main(int argc, const char * argv[])
{
    try
    {
        asio::io_service io;
        asio::ip::tcp::socket socket(io);
        asio::ip::tcp::endpoint endPoint(asio::ip::address::from_string("35.166.168.206"), 80);
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
        
        //asio::streambuf sbuf;
        //Получение сообщения от сервера
        //asio::read_until(socket, sbuf, "\0");
        //cout << &sbuf << endl;
        
        string str = "Hello";
        
        //Отправка соощения на сервер
        asio::write(socket, asio::buffer(str));
        
        socket.close();
    }
    catch(std::exception& e)
    {
        cout << "Exception was occured: " << e.what() << endl;
    }
    return 0;
}
