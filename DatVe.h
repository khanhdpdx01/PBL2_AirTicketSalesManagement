#ifndef _DATVE_H
#define _DATVE_H

#include <iostream>
#include "Date.h"
#include <string>
#include <SQLAPI.h>

using namespace std;
class DatVe
{
private:
	string maDatVe;
	int hangGheNgang;
	int hangGheDoc;
	Date thoigianDatVe;
	double tongTien;

public:
	DatVe(string = "", int = 0, int = 0, Date = NULL, double = 0.0);
	string getMaDatVe();
	void setMaDatVe(string maDV);

	int getHangGheNgang();
	void setHangGheNgang(int hangGheNgang);

	int getHangGheDoc();
	void setHangGheDoc(int hangGheDoc);
	/*void reserveTicket();*/
};

#endif // !_DATVE_H
