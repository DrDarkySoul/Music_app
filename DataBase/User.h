#pragma once
#include "CMySql.h"
#include "Observer.h"
class User :
	public CMySql,Observer
{
public:
	void Registrate(Subject *mod){ baseRegistrate(mod); }
	void update(pair<int, int> val){
		cout << "User"<< endl;
	}
	int id;
	string login;
	string password;
	string email;
	string nickname;
	string photo;

	string registrateAction(string user_login, string user_password, string user_email, string user_nickname, string user_photo);
	string deleteUser(int id,Subject * subj);
	User getUserAction(int id);
	vector<User> getUsersAction(int begin, int end);
	User();
	~User();
};

