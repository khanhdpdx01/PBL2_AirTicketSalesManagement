#include "DatabaseConnection.h"
#include <iostream>
using namespace std;

DatabaseConnection *DatabaseConnection::_Instance = nullptr;

DatabaseConnection::DatabaseConnection()
{
    try
    {
        con.Connect(_TSA("TicketAirlineManagement"), _TSA("sa"), _TSA("123"), SA_SQLServer_Client);
    }
    catch (SAException &x)
    {
        con.Rollback();
        cout << x.ErrText().GetMultiByteChars() << endl;
    }
}

DatabaseConnection::~DatabaseConnection()
{
    con.Disconnect();
}

DatabaseConnection *DatabaseConnection::getInstance()
{
    if (_Instance == nullptr)
    {
        _Instance = new DatabaseConnection();
    }
    return _Instance;
}