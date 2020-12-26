#include "DatVe.h"

DatVe::DatVe(int maDatVe, int hangGheNgang, int hangGheDoc, double tongTien) {
	this->maDatVe = maDatVe;
	this->hangGheNgang = hangGheNgang;
	this->hangGheDoc = hangGheDoc;
	this->tongTien = tongTien;
}

int DatVe::getMaDatVe()
{
	return this->maDatVe;
}

int DatVe::getHangGheNgang() {
	return this->hangGheNgang;
}

void DatVe::setHangGheNgang(int hangGheNgang) {
	this->hangGheNgang = hangGheNgang;
}

int DatVe::getHangGheDoc() {
	return this->hangGheDoc;
}

void DatVe::setHangGheDoc(int hangGheDoc) {
	this->hangGheDoc = hangGheDoc;
}

