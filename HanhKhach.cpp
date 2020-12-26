#include "HanhKhach.h"

#define db DatabaseConnection::getInstance()

HanhKhach::HanhKhach(int MaHK, string HoTen, string CMND, bool GioiTinh, string SDT, string Email, Date ngaySinh)
{
	this->maHanhKhach = MaHK;
	this->hoTen = HoTen;
	this->CMND = CMND;
	this->gioiTinh = GioiTinh;
	this->SDT = SDT;
	this->Email = Email;
	this->ngaySinh = ngaySinh;
}

HanhKhach::~HanhKhach() {}

int HanhKhach::getMaHanhKhach() const
{
	return this->maHanhKhach;
}

void HanhKhach::setMaHanhKhach(int maHanhKhach)
{
	this->maHanhKhach = maHanhKhach;
}

string HanhKhach::getHoTen() const
{
	return hoTen;
}
void HanhKhach::setHoTen(string hoTen)
{
	this->hoTen = hoTen;
}

string HanhKhach::getCMND() const
{
	return this->CMND;
}
void HanhKhach::setCMND(string CMND)
{
	this->CMND = CMND;
}

bool HanhKhach::getGioiTinh() const
{
	return gioiTinh;
}

void HanhKhach::setGioiTinh(bool gioiTinh)
{
	this->gioiTinh = gioiTinh;
}

string HanhKhach::getSDT() const
{
	return this->SDT;
}
void HanhKhach::setSDT(string SDT)
{
	this->SDT = SDT;
}

string HanhKhach::getEmail() const
{
	return this->Email;
}

void HanhKhach::setEmail(string Email)
{
	this->Email = Email;
}

Date HanhKhach::getNgaySinh() const {
	return this->ngaySinh;
}

void HanhKhach::setNgaySinh(Date ngaySinh) {
	this->ngaySinh = ngaySinh;
}

void HanhKhach::validatePassenger(string& GioiTinh) {
	regex number("[0-9]+");
	regex email("[a-z0-9._%+-]+@[a-z0-9.-]+\\.[a-z]{2,4}");
	regex character("[a-zA-Z]");
	if (this->getHoTen() == "") throw string("\t\t\t\tVui long nhap ho ten");
	if (regex_match(this->getHoTen(), character)) throw string("\t\t\t\tHo ten khong duoc dung ki tu dac biet hoac so");
	if (this->getCMND().length() != 9 || !regex_match(this->getCMND(), number)) throw string("\t\t\t\tSo CMND phai co dung 9 chu so");
	if (GioiTinh.compare("1") != 0 && GioiTinh.compare("0") != 0)  throw string("\t\t\t\tGioi tinh khong hop le");
	if (this->getSDT().length() != 10 || !regex_match(this->getSDT(), number)) throw string("\t\t\t\tSo dien thoai phai co dung 10 chu so");
	if (!regex_match(this->getEmail(), email)) throw string("\t\t\t\tEmail khong hop le");
	if (this->getNgaySinh().getMonth() < 0 || this->getNgaySinh().getMonth() > 12)
	{
		throw string("\t\t\t\tThang la khong hop le.");
	}
	if (this->getNgaySinh().getYear() > 2020 || this->getNgaySinh().getYear() < 1900)
	{
		throw string("\t\t\t\tNam la khong hop le.");
	}
	if (this->getNgaySinh().getDayNumber() < this->getNgaySinh().getDay() || this->getNgaySinh().getDay() < 0)
	{
		throw string("\t\t\t\tNgay la khong hop le.");
	}
	
}

ostream& operator<<(ostream& o, const HanhKhach& hk)
{
	cout << std::left << setw(5) << hk.maHanhKhach << "|" << setw(30) <<  hk.hoTen << "|" << setw(10) << hk.CMND << "|" << setw(9) << (hk.gioiTinh == 1 ? "Nam" : "Nu") << "|" << setw(11) << hk.SDT << "|" << setw(30) << hk.Email << "|" << setw(30) << hk.ngaySinh << endl;
	return o;
}

istream& operator>>(istream& in, HanhKhach& hk)
{
	bool flag = 0;
	while (!flag) {
		try {
			cout << "\t\t\t\tHo ten: ";
			getline(in, hk.hoTen);
			cout << "\t\t\t\tCMND: ";
			getline(in, hk.CMND);
			cout << "\t\t\t\tGioi tinh: ";
			string GioiTinh;
			getline(in, GioiTinh);
			cout << "\t\t\t\tSDT: ";
			getline(in, hk.SDT);
			cout << "\t\t\t\tEmail: ";
			getline(in, hk.Email);
			cout << "\t\t\t\tNgay sinh: ";
			string ngaySinh;
			getline(in, ngaySinh);
			hk.ngaySinh = Date(ngaySinh);
			hk.validatePassenger(GioiTinh);
			hk.gioiTinh = atoi(GioiTinh.c_str());
			flag = 1;
		}
		catch (string e) {
			cout << e << endl;
		}
	}
	return in;
}

void HanhKhach::addTicketClass(DatVe* _datVe) {
	this->datVe.push_back(_datVe);
}


