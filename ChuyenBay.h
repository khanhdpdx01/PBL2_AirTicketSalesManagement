#ifndef _CHUYENBAY_H
#define _CHUYENBAY_H

#include <iostream>
#include "DatabaseConnection.h"
#include "Date.h"
#include <vector>
#include <unordered_map>
#include <utility>
#include <string>

using namespace std;
class ChuyenBay
{
private:
	string maChuyenBay;
	Date ngayGioBay;
	Date ngayGioDen;
	double giaGoc;

public:
	string getMaChuyenBay();
	void setMaChuyenBay(string);

	Date getNgayGioBay();
	void setNgayGioBay(const Date &);

	Date getNgayGioDen();
	void setNgayGioDen(const Date &);

	double getGiaGoc();
	void setGiaGoc(double);

	//vector<DatVe*> getListDatVe();

	ChuyenBay(string = "", Date = NULL, Date = NULL, double = 0);
	/*vector<ChuyenBay*> getRoute(string startAddress, string finishAddress);*/
	/*vector<ChuyenBay *> getOneWayFlight(string startAddress, string finishAddress, string startDay);*/
	//vector<ChuyenBay*> getRoundTripFlight(string startAddress, string finishAddress, string startDay, string finishDay);
	friend ostream &operator<<(ostream &, const ChuyenBay &);
};

#endif // !_CHUYENBAY_H
