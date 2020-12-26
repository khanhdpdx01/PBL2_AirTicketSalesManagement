#ifndef _HANGVE_H
#define _HANGVE_H

#include <iostream>
#include <SQLAPI.h>
#include <string>
#include <vector>
#include "DatVe.h"
#include "DatabaseConnection.h"
#include <iomanip>

using namespace std;
class HangVe
{
private:
	string maHangVe;
	string tenHangVe;
	double tiLeHangVe;
	vector<DatVe *> datVe;

public:
	HangVe(string = "", string ="", double = 0.0);
	~HangVe();

	string getMaHangVe();
	void setMaHangVe(string);

	string getTenHangVe();
	void setTenHangVe(string);

	double getTiLeHangVe();
	void setTiLeHangVe(double);

	void addTicketClass(DatVe*);
	friend ostream &operator<<(ostream &, const HangVe &);
	friend istream& operator>>(istream&, HangVe&);
};

#endif // !_HANGVE_H
