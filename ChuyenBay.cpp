#include "ChuyenBay.h"

#define db DatabaseConnection::getInstance()

ChuyenBay::ChuyenBay(string maChuyenBay, Date ngayGioBay, Date ngayGioDen, double giaGoc)
{
	this->maChuyenBay = maChuyenBay;
	this->ngayGioBay = ngayGioBay;
	this->ngayGioDen = ngayGioDen;
	this->giaGoc = giaGoc;
}

string ChuyenBay::getMaChuyenBay()
{
	return this->maChuyenBay;
}

void ChuyenBay::setMaChuyenBay(string maChuyenBay)
{
	this->maChuyenBay = maChuyenBay;
}

Date ChuyenBay::getNgayGioBay()
{
	return this->ngayGioBay;
}

void ChuyenBay::setNgayGioBay(const Date &ngayGioBay)
{
	this->ngayGioBay = ngayGioBay;
}

Date ChuyenBay::getNgayGioDen()
{
	return this->ngayGioDen;
}

void ChuyenBay::setNgayGioDen(const Date &ngayGioDen)
{
	this->ngayGioDen = ngayGioDen;
}

double ChuyenBay::getGiaGoc()
{
	return this->giaGoc;
}

void ChuyenBay::setGiaGoc(double giaGoc)
{
	this->giaGoc = giaGoc;
}

void ChuyenBay::addDatVe(DatVe* _datVe) {
	this->datVe.push_back(_datVe);
}

vector<DatVe*> ChuyenBay::getListDatVe() {
	return datVe;
}

ostream &operator<<(ostream &o, const ChuyenBay &cb)
{
	cout <<"\t\t\t\t"<< cb.maChuyenBay << "\t" << cb.ngayGioBay << "\t" << cb.ngayGioDen << endl;
	return o;
}
