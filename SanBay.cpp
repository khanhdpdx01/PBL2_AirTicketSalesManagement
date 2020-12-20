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

//unordered_map<string, string> SanBay::getAircraftInfo()
//{
//	unordered_map<string, string> sbay;
//	SACommand select(&db->con, _TSA("SELECT * FROM SanBay")); // create command object
//	select.Execute();
//
//	SanBay *sanBay = new SanBay;
//	while (select.FetchNext())
//	{
//		sanBay->maSanBay = select.Field("MaSanBay").asString();
//		sanBay->thanhPho = select.Field("ThanhPho").asString();
//
//		sbay.insert(pair<string, string>(sanBay->maSanBay, sanBay->thanhPho));
//	}
//	return sbay;
//}

void SanBay::addArrivalFlight(ChuyenBay *chuyenBay)
{
	this->chuyenBayDen.push_back(chuyenBay);
}

void SanBay::addLeaveFlight(ChuyenBay *chuyenBay)
{
	this->chuyenBayDi.push_back(chuyenBay);
}

ostream& operator<<(ostream& out, const SanBay& sanBay) {
	out << "\nMa san bay: " << sanBay.maSanBay;
	out << "\nTen san bay: " << sanBay.tenSanBay;
	out << "\nThanh pho: " << sanBay.thanhPho;
	out << "\nQuoc gia: " << sanBay.quocGia;
	return out;
}

vector<ChuyenBay*> SanBay::getArrivalFlight() {
	return this->chuyenBayDen;
}

vector<ChuyenBay*> SanBay::getLeaveFlight() {
	return this->chuyenBayDi;
}