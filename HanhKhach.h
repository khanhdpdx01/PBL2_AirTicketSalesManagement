#ifndef _HANHKHACH_H
#define _HANHKHACH_H

#include <iostream>
#include <SQLAPI.h>
#include <string>
#include <vector>
#include "DatVe.h"
#include "DatabaseConnection.h"
using namespace std;
class HanhKhach
{
private:
	string maHanhKhach;
	string hoTen;
	string CMND;
	bool gioiTinh;
	string SDT;
	string Email;
	string maSoThe;
	vector<DatVe *> datVe;

public:
	HanhKhach();
	HanhKhach(string MaHK, string HoTen, string CMND, bool GioiTinh, string SDT, string Email, string MaSoThe);
	~HanhKhach();

	string getMaHanhKhach();
	void setMaHanhKhach(string);

	string getHoTen();
	void setHoTen(string);

	string getCMND();
	void setCMND(string);

	bool getGioiTinh();
	void setGioiTinh(bool);

	string getSDT();
	void setSDT(string);

	string getEmail();
	void setEmail(string);

	string getMaSoThe();
	void setMaSoThe(string);

	void addTicketClass(DatVe*);
	friend ostream &operator<<(ostream &, const HanhKhach &);
	friend istream &operator>>(istream &, HanhKhach &);
};

#endif // !_HANHKHACH_H
