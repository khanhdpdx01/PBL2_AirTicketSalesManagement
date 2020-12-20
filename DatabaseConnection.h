#ifndef _DATABASECONNECTION_H
#define _DATABASECONNECTION_H

#include <SQLAPI.h>
class DatabaseConnection
{
private:
	static DatabaseConnection *_Instance;
	DatabaseConnection();

public:
	SAConnection con;
	static DatabaseConnection *getInstance();
	~DatabaseConnection();
};

#endif // !_DATABASECONNECTION_H
