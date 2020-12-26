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

vector<ChuyenBay*> MayBay::getChuyenBay() {
	return this->chuyenBay;
}
ostream& operator<<(ostream& out, const MayBay& mayBay) {
	cout << std::left << setw(20) << mayBay.soHieuMayBay << "|" << setw(6) << mayBay.soGhe << "|" <<  setw(10) << mayBay.hangKhaiThac << endl;
	return out;
}

istream& operator>>(istream& in, MayBay& _mayBay) {
	cout << "\n\t\t\t\tSo hieu may bay: "; getline(in, _mayBay.soHieuMayBay);
	cout << "\n\t\t\t\tHang khai thac: "; getline(in, _mayBay.hangKhaiThac);
	cout << "\n\t\t\t\tSo ghe: "; in >>  _mayBay.soGhe;
	return in;
}