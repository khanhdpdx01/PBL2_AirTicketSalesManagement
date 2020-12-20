#include "MayBay.h"

#define db DatabaseConnection::getInstance()

MayBay::MayBay(string soHieuMayBay, string hangKhaiThac, int soGhe) {
	this->soHieuMayBay = soHieuMayBay;
	this->hangKhaiThac = hangKhaiThac;
	this->soGhe = soGhe;
}

string MayBay::getSoHieuMayBay()
{
	return this->soHieuMayBay;
}
void MayBay::setSoHieuMayBay(string soHieuMayBay)
{
	this->soHieuMayBay = soHieuMayBay;
}

string MayBay::getHangKhaiThac()
{
	return this->hangKhaiThac;
}
void MayBay::setHangKhaiThac(string hangKhaiThac)
{
	this->hangKhaiThac = hangKhaiThac;
}

int MayBay::getSoGhe()
{
	return this->soGhe;
}

void MayBay::setSoGhe(int soGhe) {
	this->soGhe = soGhe;
}

void MayBay::addChuyenBay(ChuyenBay* chuyenBay) {
	this->chuyenBay.push_back(chuyenBay);
}

ostream& operator<<(ostream& out, const MayBay& mayBay) {
	out << mayBay.soHieuMayBay << mayBay.hangKhaiThac << mayBay.soGhe << endl;
	return out;
}