#pragma once
#include <sqlite3.h>
#include <iostream>
#include "User.h"
#include "sqlite_orm.h"
using namespace sqlite_orm;

class DataBase  // management of Database, library used to manage
{
public:
	static int createDataBase(const char* s)
	{
		sqlite3* DB;
		int exit = 0;
		exit = sqlite3_open(s, &DB);
		sqlite3_close(DB);
		return 0;

	}
	static int createTable(const char* s, std::string name)
	{
		sqlite3* DB;
		std::string sql = "CREATE TABLE " + name +  "("
			"ID INTEGER PRIMARY KEY AUTOINCREMENT);";
		try
		{
			int exit = 0;
			exit = sqlite3_open(s, &DB);

			char* messageError;
			exit = sqlite3_exec(DB, sql.c_str(), callback, 0, &messageError);

			if (exit != SQLITE_OK)
			{
				std::cerr << "Error Create Table" << std::endl;
				sqlite3_free(messageError);
			}
			else
			{
				std::cout << "Table created Succesfully" << std::endl;
			}
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what();
		}
		return 0;
	}
	static int selectData(const char* s, std::string table)
	{
		sqlite3* DB;

		int exit = sqlite3_open(s, &DB);

		std::string sql = "SELECT * FROM " + table +" ;";
		sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);
		return 0;
	}
	static int selectDataCon(const char* s, std::string table, std::string where)
	{
		sqlite3* DB;

		int exit = sqlite3_open(s, &DB);

		std::string sql = "SELECT * FROM " + table + " WHERE " + where +";";
		sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);
		return 0;
	}
	static int insertColumn(const char* s, std::string table, std::string column_name, std::string datatype )
	{
		sqlite3* DB;

		int exit = sqlite3_open(s, &DB);

		std::string sql = "ALTER TABLE " + table + " ADD " + column_name + datatype + ";";
		sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);
		return 0;
	}
	static int insertVal(const char* s, std::string table,std::string column,std::string values, std::string login)
	{
		sqlite3* DB;
		int exit = sqlite3_open(s, &DB);
		std::string sql = "UPDATE " + table + " SET " + column + " = " + values + " WHERE login = "+ login +" ;";   // stworzyæ funkcje pojedyncz¹ aby mi pojedynczo elementy wskkiwa³y, i podzielic na rejestracje i poxniejsze uzupelnienie elementow
		sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);		
		return 0;
	}
	static int callback(void* NotUsed, int argc, char** argv, char** azColName)
	{
		for (int i = 0; i < argc; i++)
		{
			std::cout  << argv[i] << std::endl;
		}
		std::cout << std::endl;
		return 0;
	}
	static void AddInfo()
	{
		
		User user{1,"John","Doe"};
		auto storage = make_storage("aucoiton.db",
			make_table("user",
				make_column("id", &User::id, autoincrement(), primary_key()),
				make_column("first_name", &User::first_name),
				make_column("last_name", &User::second_name)));
		auto insertedId = storage.insert(user);
		std::cout << "insertedId = " << insertedId << std::endl;      //  insertedId = 8
	}

	
};


 