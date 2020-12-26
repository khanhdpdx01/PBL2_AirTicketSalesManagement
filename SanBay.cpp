#pragma once
#include "SanBay.h"

#define db DatabaseConnection::getInstance()

SanBay::SanBay(string maSanBay, string tenSanBay, string thanhPho, string quocGia)
{
	this->maSanBay = maSanBay;
	this->tenSanBay = tenSanBay;
	this->thanhPho = thanhPho;
	this->quocGia = quocGia;
}

string SanBay::getMaSanBay()
{
	return this->maSanBay;
}

void SanBay::setMaSanBay(string maSanBay)
{
	this->maSanBay = maSanBay;
}

string SanBay::getTenSanBay()
{
	return tenSanBay;
}

void SanBay::setTenSanBay(string tenSanBay)
{
	this->tenSanBay = tenSanBay;
}

string SanBay::getThanhPho()
{
	return thanhPho;
}

void SanBay::setThanhPho(string thanhPho)
{
	this->thanhPho = thanhPho;
}

string SanBay::getQuocGia()
{
	return this->quocGia;
}

void SanBay::setQuocGia(string quocGia)
{
	this->quocGia = quocGia;
}

void SanBay::addArrivalFlight(ChuyenBay *chuyenBay)
{
	this->chuyenBayDen.push_back(chuyenBay);
}

void SanBay::addLeaveFlight(ChuyenBay *chuyenBay)
{
	this->chuyenBayDi.push_back(chuyenBay);
}

ostream& operator<<(ostream& out, const SanBay& sanBay) {
	out << std::left << setw(10) << sanBay.maSanBay << "|" << setw(30) << sanBay.tenSanBay << "|" << setw(30) << sanBay.thanhPho << "|" << setw(30) << sanBay.quocGia << endl;
	return out;
}

vector<ChuyenBay*> SanBay::getArrivalFlight() {
	return this->chuyenBayDen;
}

vector<ChuyenBay*> SanBay::getLeaveFlight() {
	return this->chuyenBayDi;
}

istream& operator>>(istream& in, SanBay& _sanBay) {
	cout << "\n\t\t\t\tMa san bay: "; getline(in,_sanBay.maSanBay);
	cout << "\n\t\t\t\tTen san bay: "; getline(in,_sanBay.tenSanBay);
	cout << "\n\t\t\t\tThanh pho: "; getline(in,_sanBay.thanhPho);
	cout << "\n\t\t\t\tQuoc gia: "; getline(in,_sanBay.quocGia);
	return in;
}