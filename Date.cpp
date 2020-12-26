#include "Date.h"
Date::Date(int day, int month, int year, int minute, int hour)
{
	this->minute = minute;
	this->hour = hour;
	this->day = day;
	this->month = month;
	this->year = year;
}

Date::Date(string date)
{
	string *str = split(date, '/');
	this->day = atoi(str[0].c_str());
	this->month = atoi(str[1].c_str());
	this->year = atoi(str[2].c_str());
	this->minute = 1;
	this->hour = 1;
}

ostream &operator<<(ostream &out, const Date &time)
{
	string Time = "" + to_string(time.hour) + ':' + to_string(time.minute) + ' ' + to_string(time.day) + '/' + to_string(time.month) + '/' + to_string(time.year);
	out << Time;
	return out;
}

Date::~Date() {}

int Date::getMinute() {
	return this->minute;
}

void Date::setMinute(int minute) {
	this->minute = minute;
}

int Date::getHour() {
	return this->hour;
}

void Date::setHour(int hour) {
	this->hour = hour;
}

int Date::getDay()
{
	return day;
}

void Date::setDay(int day)
{
	this->day = day;
}

int Date::getMonth()
{
	return month;
}

void Date::setMonth(int month)
{
	this->month = month;
}

int Date::getYear()
{
	return year;
}

void Date::setYear(int year)
{
	this->year = year;
}

bool Date::checkLeafYear()
{
	if ((this->year % 4 == 0 && year % 100 != 0) && this->year % 4 == 0)
	{
		return true;
	}

	return false;
}

string *Date::split(string date, char token)
{
	string *temp = new string[3];
	temp[0] = temp[1] = temp[2] = "";

	int c = 0;
	for (unsigned int i = 0; i < date.length(); ++i)
	{
		if (date[i] != token)
			temp[c] += date[i];
		else
			c++;
	}
	return temp;
}

Date Date::validateDate()
{
	string _date;
	bool flag = 0;

	while (!flag)
	{
		cout << "day nhan (Nhap theo dinh dang mm/DD/yyyy): ";
		getline(cin, _date);
		Date date(_date);
		try
		{
			if (date.month < 0 || date.month > 12)
			{
				throw invalid_argument("Thang la khong hop le.\n");
			}
			if (date.year > 2020 || date.year < 1900)
			{
				throw invalid_argument("Nam la khong hop le.\n");
			}
			if (date.getDayNumber() < date.day || date.day < 0)
			{
				throw invalid_argument("Ngay la khong hop le.\n");
			}
			flag = 1;
		}
		catch (invalid_argument &exception)
		{
			cout << exception.what() << endl;
			flag = 0;
		}
	}
	return Date(_date);
}

int Date::getDayNumber()
{
	int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (this->month == 2 && checkLeafYear())
		return day[this->month - 1] + 1;
	return day[this->month - 1];
}

bool Date::operator==(const Date& date) {
	if (this->day == date.day && this->month == date.month && this->year == year) return true;
	return false;
}