#pragma once
#include "HangVe.h"
#define db DatabaseConnection::getInstance()

HangVe::HangVe(string maHV, string tenHV, double tiLeHV)
{
	this->maHangVe = maHV;
	this->tenHangVe = tenHV;
	this->tiLeHangVe = tiLeHV;
}

HangVe::~HangVe() {}

//void HangVe::Select()
//{
//	SACommand select(&db->con, _TSA("SELECT * FROM HangVe")); // create command object
//	select.Execute();
//
//	HangVe hv;
//	while (select.FetchNext())
//	{
//		hv.maHangVe = select.Field("MaHangVe").asString();
//		hv.tenHangVe = select.Field("TenHangVe").asString();
//		hv.tiLeHangVe = select.Field("TiLeHangVe").asDouble();
//
//		cout << hv;
//	}
//}
//void HangVe::Insert(const HangVe &hv)
//{
//	SACommand insert(&db->con, _TSA("INSERT INTO HangVe VALUES (:1,:2,:3)"));
//	insert << hv.maHangVe.c_str() << hv.tenHangVe.c_str() << hv.tiLeHangVe;
//	insert.Execute();
//}

string HangVe::getMaHangVe() {
	return this->maHangVe;
}

void HangVe::setMaHangVe(string maHangVe) {
	this->maHangVe = maHangVe;
}

string HangVe::getTenHangVe() {
	return this->tenHangVe;
}

void HangVe::setTenHangVe(string tenHangVe) {
	this->tenHangVe = tenHangVe;
}

double HangVe::getTiLeHangVe() {
	return this->tiLeHangVe;
}

void HangVe::setTiLeHangVe(double tiLeHangVe) {
	this->tiLeHangVe = tiLeHangVe;
}

void HangVe::addTicketClass(DatVe* _datVe) {
	this->datVe.push_back(_datVe);
}

ostream& operator<<(ostream& o, const HangVe& hv)
{
	o << hv.maHangVe << "\t" << hv.tenHangVe << "\t" << hv.tiLeHangVe << endl;
	return o;
}