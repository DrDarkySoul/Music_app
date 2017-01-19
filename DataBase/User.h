#pragma once
#include "CMySql.h"
class CUser :
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
	CUser getUserAction(int id);
	vector<CUser> getUsersAction(int begin, int end);
	CUser();
	~CUser();
};

