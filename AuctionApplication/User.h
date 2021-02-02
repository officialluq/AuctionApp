#pragma once
#include <string>

class User
{
private:



public:
	int id;
	std::string password;
	std::string login;
	int age;
	std::string adress;
	std::string citylive;
	std::string birthdate;
	std::string first_name;
	std::string second_name;
	std::string mail;
	int post_code;
	int number_phone;
	User();
	User(int id, std::string password, std::string mail);
	User(std::string login, std::string passoword, std::string first_name, std::string second_name, std::string birthdate, std::string citylive,  std::string adress, int post_code, std::string mail, int number_phone ); // constructor
	std::string Change_Password(std::string login, std::string passoword, std::string new_password);
	bool Check_Login(std::string login, std::string passoword);

protected:




};
