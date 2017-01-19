#include "User.h"
#include "CMySql.h"
string CUser::registrateAction(string user_login, string user_password, string user_email, string user_nickname, string user_photo)
{
	return base_add("User(login,password,email,photo,nickname)","\""+user_login+"\",\""+user_password+"\",\""+user_email+"\",\""+user_nickname+"\",\""+user_photo+"\"");
}
string CUser::deleteUser(int id)
{
	char buf[255];
	itoa(id, buf, 10);
	string str_id = buf;
	return base_del("User",str_id);
}
CUser CUser::getUserAction(int id)
{
	char buf[255];
	itoa(id, buf, 10);
	string str_id = buf;
	res = getBaseAction("User", str_id);
	CUser total;
	if (res->next() == NULL){
		total.id = NULL;
		total.login = "";
		total.password = "";
		total.email = "";
		total.nickname = "";
		total.photo = "";
		return total;
	}
	total.id = res->getInt(1);
	total.login = res->getString(2);
	total.password = res->getString(3);
	total.email = res->getString(4);
	total.nickname = res->getString(5);
	total.photo = res->getString(6);
	return total;
}
vector<CUser> CUser::getUsersAction(int begin, int end)
{
	char buf[255];
	itoa(begin, buf, 10);
	string str_begin = buf;
	itoa(end, buf, 10);
	string str_end = buf;
	res = getBasesAction("User", str_begin, str_end);
	vector<CUser> Total;
	CUser total;
	if (res->next() == NULL){
		total.id = NULL;
		total.login = "";
		total.password = "";
		total.email = "";
		total.nickname = "";
		total.photo = "";
		Total.push_back(total);
		return Total;
	}
	for (;;){
		total.id = res->getInt(1);
		total.login = res->getString(2);
		total.password = res->getString(3);
		total.email = res->getString(4);
		total.nickname = res->getString(5);
		total.photo = res->getString(6);
		Total.push_back(total);
		if (res->next() == NULL) return Total;
	}
}
CUser::CUser()
{
}


CUser::~CUser()
{
}
