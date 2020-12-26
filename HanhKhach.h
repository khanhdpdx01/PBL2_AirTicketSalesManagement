#ifndef _HANHKHACH_H
#define _HANHKHACH_H

#include <iostream>
#include <SQLAPI.h>
#include <string>
#include <vector>
#include "DatVe.h"
#include "DatabaseConnection.h"
#include <regex>
#include <iomanip>

using namespace std;
class HanhKhach
{
private:
	int maHanhKhach;
	string hoTen;
	string CMND;
	bool gioiTinh;
	string SDT;
	string Email;
	Date ngaySinh;
	vector<DatVe *> datVe;

public:
	HanhKhach(int = 1, string = "", string = "", bool = 1, string = "", string = "", Date = NULL);
	~HanhKhach();

	int getMaHanhKhach() const;
	void setMaHanhKhach(int);

	string getHoTen() const;
	void setHoTen(string);

	string getCMND() const;
	void setCMND(string);

	bool getGioiTinh() const;
	void setGioiTinh(bool);

	string getSDT() const;
	void setSDT(string);

	string getEmail() const;
	void setEmail(string);

	Date getNgaySinh() const;
	void setNgaySinh(Date);

	void addTicketClass(DatVe*);
	friend ostream &operator<<(ostream &, const HanhKhach &);
	friend istream &operator>>(istream &, HanhKhach &);
	void validatePassenger(string&);
};

#endif // !_HANHKHACH_H
