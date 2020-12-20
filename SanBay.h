
#pragma once
#ifndef _SANBAY_H
#define _SANBAY_H

#include <iostream>
#include "DatabaseConnection.h"
#include "ChuyenBay.h"
using namespace std;

class SanBay
{
private:
	string maSanBay;
	string tenSanBay;
	string thanhPho;
	string quocGia;
	vector<ChuyenBay*> chuyenBayDi;
	vector<ChuyenBay*> chuyenBayDen;

public:
	SanBay(string = "", string = "", string = "", string = "");

	string getMaSanBay();
	void setMaSanBay(string maSanBay);

	string getTenSanBay();
	void setTenSanBay(string quocGia);

	string getThanhPho();
	void setThanhPho(string thanhPho);

	string getQuocGia();
	void setQuocGia(string quocGia);

	/*unordered_map<string, string> getAircraftInfo();*/
	void addArrivalFlight(ChuyenBay *);
	void addLeaveFlight(ChuyenBay *);

	vector<ChuyenBay*> getArrivalFlight();
	vector<ChuyenBay*> getLeaveFlight();
	friend ostream& operator<<(ostream&,const SanBay&);
};

#endif // !_SANBAY_H