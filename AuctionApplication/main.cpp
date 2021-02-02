// AuctionApplication.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "DataBase.h"
//#include "User.h"

int main()
{
    const char* dir = "C:\\Users\\luqbrain\\source\\repos\\AuctionApplication\\AuctionApplication\\auction.db";
    //DataBase::createDataBase(dir);
   // DataBase::createTable(dir, "users");
    //DataBase::createTable(dir, "auctions");
   
    DataBase::AddInfo();
    
    //DataBase::insertVal(dir, "users","citylive","'Sosnowiec'", "'Luki'");
    //DataBase::selectData(dir, "users");
    std::cout << "Hello World!\n";
}