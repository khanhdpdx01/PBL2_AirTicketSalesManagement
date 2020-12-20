#ifndef _DATE_H
#define _DATE_H

#include <iostream>
#include <SQLAPI.h>
#include <string>
using namespace std;

class Date
{
private:
	int minute;
	int hour;
	int day;
	int month;
	int year;

public:
	Date(int = 1, int = 1, int = 1, int = 1, int = 1);
	Date(string);
	~Date();
	int getMinute();
	void setMinute(int minute);

	int getHour();
	void setHour(int hour);

	int getDay();
	void setDay(int day);

	int getMonth();
	void setMonth(int month);

	int getYear();
	void setYear(int year);

	bool checkLeafYear();
	string *split(string, char);
	Date validateDate();
	int getDayNumber();
	friend ostream &operator<<(ostream &, const Date &);
	bool operator==(const Date&);
};

#endif // !_DATE_H
