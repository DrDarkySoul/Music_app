#pragma once
#include "CMySql.h"
class User :
	public CMySql
{
public:
	int id;
	string login;
	string password;
	string email;
	string nickname;
	string photo;

	string registrateAction(string user_login, string user_password, string user_email, string user_nickname, string user_photo);
	string deleteUser(int id);
	User getUserAction(int id);
	vector<User> getUsersAction(int begin, int end);
	User();
	~User();
};

