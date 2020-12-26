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
	int maDatVe;
	int hangGheNgang;
	int hangGheDoc;
	double tongTien;

public:
	DatVe(int = 0, int = 0, int = 0, double = 0.0);
	int getMaDatVe();

	int getHangGheNgang();
	void setHangGheNgang(int hangGheNgang);

	int getHangGheDoc();
	void setHangGheDoc(int hangGheDoc);
	/*void reserveTicket();*/
};

#endif // !_DATVE_H
