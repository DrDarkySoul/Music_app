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
#include "json.hpp"

using namespace std;
using namespace boost;
using namespace nlohmann;

//-----------------------------------------------
template <typename T>
std::string toString(T val)
{
    std::ostringstream oss;
    oss<< val;
    return oss.str();
}

template<typename T>
T fromString(const std::string& s)
{
    std::istringstream iss(s);
    T res;
    iss >> res;
    return res;
}
//-----------------------------------------------




class Music{
public:
    int id;
    string title;
    string artist;
    string album;
    float duration;
    string photo;
    vector<int> otherSongs;
    
    Music(int _id, string _title, float _duration, string _photo, vector<int> _otherSongs){
        this->id = _id;
        this->title = _title;
        
        this->duration = _duration;
        this->photo = _photo;
        this->otherSongs = _otherSongs;
    }
};

class User{
public:
    int id;
    string login;
    string password;
    string email;
    string nickname;
    string photo;
    
    User(int _id, string _login, string _password, string _email, string _nickname, string _photo){
        id = _id;
        login = _login;
        password = _password;
        email = _email;
        nickname = _nickname;
        photo = _photo;
    }
};


int main(int argc, char *argv[])
{
    //------Тест Музыки
//    vector<Music> myMusic;
//
//    vector<int> otherSongs;
//    otherSongs.push_back(2);
//    otherSongs.push_back(3);
//    otherSongs.push_back(4);
//    Music music = Music(1, "Song 1", 3.45, "C:\\usr\\img1.jpg", otherSongs);
//    myMusic.push_back(music);
//    otherSongs.clear();
//    
//    otherSongs.push_back(1);
//    otherSongs.push_back(5);
//    otherSongs.push_back(9);
//    music = Music(2, "Song 2", 2.27, "C:\\usr\\img2.jpg", otherSongs);
//    myMusic.push_back(music);
    
//    json j2;
//    json mainJson;
//    for(int i=0; i<myMusic.size(); i++) {
//        j2["id"] = myMusic[i].id;
//        j2["title"] = myMusic[i].title;
//        j2["duration"] = myMusic[i].duration;
//        j2["img"] = myMusic[i].photo;
//        for(int j=0;j < myMusic[i].otherSongs.size();  j++){
//            j2["otherSongs"].push_back({"id", myMusic[i].otherSongs[j] });
//        }
//        mainJson.push_back(j2);
//        j2.clear();
//    }
    
    //------Тест Юзеров
    vector<User> result;
    result.push_back(User(1, "ChairMan", "qwerty", "chairman@mail.ru", "ChairMan", "C:\\usr\\user1.jpg"));
    result.push_back(User(2, "teist", "123456", "testme@mail.ru", "teist", "C:\\usr\\user2.jpg"));

    json tmpjson;
    json usersJson;
    for (int i=0; i<result.size(); i++) {
        tmpjson["id"] = result[i].id;
        tmpjson["login"] = result[i].login;
        tmpjson["password"] = result[i].password;
        tmpjson["email"] = result[i].email;
        tmpjson["nickname"] = result[i].nickname;
        tmpjson["photo"] = result[i].photo;
        usersJson.push_back(tmpjson);
        tmpjson.clear();
    }
    
    string str = usersJson.dump();
    
    
    cout << "Server is running\n";
    
    try
    {
        asio::io_service io;
        asio::ip::tcp::acceptor acceptor(io, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), 9090));
        
        while(true)
        {
            asio::ip::tcp::socket socket(io);
            acceptor.accept(socket);
            
            //Для отправки на клиент 
            asio::write(socket, asio::buffer(str));
            
            //Получение от клиента
//            asio::streambuf sbuf;
//            asio::read_until(socket, sbuf, "\0");
//            cout << &sbuf << endl;
        }
    }
    
    catch(std::exception& e)
    {
        cout << e.what() << endl;
    }
    return 0;
}












