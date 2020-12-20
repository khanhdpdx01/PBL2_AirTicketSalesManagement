#include "DatVe.h"

DatVe::DatVe(string maDatVe, int hangGheNgang, int hangGheDoc, Date thoiGianDatVe, double tongTien) {
	this->maDatVe = maDatVe;
	this->hangGheNgang = hangGheNgang;
	this->hangGheDoc = hangGheDoc;
	this->thoigianDatVe = thoiGianDatVe;
	this->tongTien = tongTien;
}

string DatVe::getMaDatVe()
{
	return this->maDatVe;
}

void DatVe::setMaDatVe(string maDV) {
	this->maDatVe = maDV;
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

//void DatVe::reserveTicket()
//{
//	string startAddress, finishAddress, startDay, finishDay;
//	DatVe *datve = new DatVe;
//	int choose;
//	bool flag = false;
//
//	//thong tin hanh khach
//	/*cin.ignore();
//	cout << "Nhap ma khach hang: "; getline(cin,dv.MaHanhKhach); 
//	if (!(new HanhKhach)->checkPassenger(dv.MaHanhKhach)) {
//		HanhKhach hk;
//		cin >> hk;
//		(new HanhKhach)->Insert(hk);
//	}*/
//	cout << "\n------------------DAT VE--------------------\n";
//	cout << "\nLua chon loai ve: \n1.Khu hoi \n2.Mot chieu\n";
//
//	while (!flag)
//	{
//		cin >> choose;
//		switch (choose)
//		{
//		case 1:
//			cin.ignore();
//			cout << "\nLua chon dia diem khoi hanh: ";
//			getline(cin, startAddress);
//			cout << "\nLua chon dia diem den: ";
//			getline(cin, finishAddress);
//
//			cout << "\nNhap ngay khoi hanh: ";
//			getline(cin, startDay);
//			cout << "\nNhap ngay ve: ";
//			getline(cin, finishDay);
//
//			cout << "\nLua chon chuyen bay chieu di: ";
//			cout << "\nLua chon chuyen bay chieu ve: ";
//			(new ChuyenBay)->getFlightFromTo(startAddress, finishAddress, startDay);
//
//			cout << "\nChon chuyen bay ma ban muon dat ve: ";
//			getline(cin, dv.MaChuyenBay);
//			cout << "\nChuyen bay bao gom cac hang ve: \n";
//			(new HangVe)->Select();
//			cout << "\nChon hang ve ma ban muon mua: ";
//			getline(cin, dv.MaHangVe);
//			flag = true;
//			break;
//		case 2:
//
//			cin.ignore();
//			cout << "\nChon dia diem di: ";
//			getline(cin, startAddress);
//			cout << "Chon dia diem den: ";
//			getline(cin, finishAddress);
//
//			cout << "Nhap ngay di: ";
//			getline(cin, startDay);
//
//			(new ChuyenBay)->getFlightFromTo(startAddress, finishAddress, startDay);
//
//			cout << "\nChon chuyen bay ma ban muon dat ve: ";
//			getline(cin, dv.MaChuyenBay);
//			cout << "\nChuyen bay bao gom cac hang ve: \n";
//			(new HangVe)->Select();
//			cout << "\nChon hang ve ma ban muon mua: ";
//			getline(cin, dv.MaHangVe);
//			flag = true;
//			break;
//		default:
//			cout << "Quy khach lua chon sai. Moi ban nhap lai: ";
//			break;
//		}
//	}
//
//	/*cout << "\nThong tin cac chuyen bay di tu " << startAddress << " den " << finishAddress << ":\n";*/
//	////chon cho ngoi theo hang ve
//	//chooseSeat(Ox, Oy);
//	////Dat ve
//	//Insert(new DatVe);
//}
//
//void DatVe::Select() {}
