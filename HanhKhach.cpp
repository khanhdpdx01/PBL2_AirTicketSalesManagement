#include "HanhKhach.h"

#define db DatabaseConnection::getInstance()
HanhKhach::HanhKhach()
{
	this->maHanhKhach = "";
	this->hoTen = "";
	this->CMND = "";
	this->gioiTinh = 0;
	this->SDT = "";
	this->Email = "";
	this->maSoThe = "";
}
HanhKhach::HanhKhach(string MaHK, string HoTen, string CMND, bool GioiTinh, string SDT, string Email, string MaSoThe)
{
	this->maHanhKhach = MaHK;
	this->hoTen = HoTen;
	this->CMND = CMND;
	this->gioiTinh = 0;
	this->SDT = SDT;
	this->Email = Email;
	this->maSoThe = MaSoThe;
}

string HanhKhach::getMaHanhKhach()
{
	return this->maHanhKhach;
}

void HanhKhach::setMaHanhKhach(string maHanhKhach)
{
	this->maHanhKhach = maHanhKhach;
}

string HanhKhach::getHoTen()
{
	return hoTen;
}
void HanhKhach::setHoTen(string hoTen)
{
	this->hoTen = hoTen;
}

string HanhKhach::getCMND()
{
	return this->CMND;
}
void HanhKhach::setCMND(string CMND)
{
	this->CMND = CMND;
}

bool HanhKhach::getGioiTinh()
{
	return gioiTinh;
}

void HanhKhach::setGioiTinh(bool gioiTinh)
{
	this->gioiTinh = gioiTinh;
}

string HanhKhach::getSDT()
{
	return this->SDT;
}
void HanhKhach::setSDT(string SDT)
{
	this->SDT = SDT;
}

string HanhKhach::getEmail()
{
	return this->Email;
}

void HanhKhach::setEmail(string Email)
{
	this->Email = Email;
}

string HanhKhach::getMaSoThe()
{
	return this->maSoThe;
}

void HanhKhach::setMaSoThe(string maSoThe)
{
	this->maSoThe = maSoThe;
}

HanhKhach::~HanhKhach() {}

ostream &operator<<(ostream &o, const HanhKhach &hk)
{
	cout << hk.maHanhKhach
		 << hk.hoTen
		 << hk.CMND
		 << hk.gioiTinh
		 << hk.Email
		 << hk.maSoThe << endl;
	return o;
}

istream &operator>>(istream &in, HanhKhach &hk)
{
	cout << "Nhap MaHK: ";
	in >> hk.maHanhKhach;
	cout << "Nhap ho ten: ";
	in >> hk.hoTen;
	cout << "Nhap CMND: ";
	in >> hk.CMND;
	cout << "Nhap gioi tinh: ";
	in >> hk.gioiTinh;
	cout << "Nhap SDT: ";
	in >> hk.SDT;
	cout << "Nhap email: ";
	in >> hk.Email;
	cout << "Nhap ma so the: ";
	in >> hk.maSoThe;
	return in;
}

void HanhKhach::addTicketClass(DatVe* _datVe) {
	this->datVe.push_back(_datVe);
}


