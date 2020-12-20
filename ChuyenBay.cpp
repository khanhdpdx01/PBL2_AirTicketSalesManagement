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
//
//vector<DatVe*> ChuyenBay::getListDatVe() {
//	return datVe;
//}

//vector<ChuyenBay *> ChuyenBay::getRoute(string startAddress, string finishAddress, string Day)
//{
//	vector<SanBay *> sanBay = (new SanBay)->select();
//
//	unordered_map<string, string> sanBay = (new SanBay)->getAircraftInfo();
//	SACommand select(&db->con, _TSA("SELECT * FROM ChuyenBay")); // create command object
//	select.Execute();
//
//	/*ChuyenBay* cb = new ChuyenBay;
//	while (select.FetchNext()) {
//		cb->maChuyenBay = select.Field("MaChuyenBay").asString();
//		cb->ngayGioBay = select.Field("NgayGioBay").asDateTime();
//		cb->ngayGioDen = select.Field("NgayGioDen").asDateTime();
//		cb->giaGoc = select.Field("GiaGoc").asLong();
//
//		if (startAddress == sanBay[cb->maSanBayDi]
//			&& finishAddress == sanBay[cb->maSanBayDen]
//			) chuyenBay.push_back(cb);
//
//	}*/
//
//	return chuyenBay;
//}

//vector<ChuyenBay *> ChuyenBay::getRoundTripFlight(string startAddress, string finishAddress, string startDay, string finishDay)
//{
//
//	vector<ChuyenBay *> chuyenBay = getRoute(startAddress, finishAddress);
//	vector<ChuyenBay *> chuyenBayKhuHoi;
//
//	Date startday(startDay);
//	Date finishday(finishDay);
//
//	int size = chuyenBay.size();
//	for (int i = 0; i < size; ++i)
//	{
//		if (chuyenBay[i]->ngayGioBay.GetDay() == startday.getDay() && chuyenBay[i]->ngayGioBay.GetMonth() == startday.getMonth() && chuyenBay[i]->ngayGioBay.GetYear() == startday.getYear() && chuyenBay[i]->ngayGioDen.GetDay() == finishday.getDay() && chuyenBay[i]->ngayGioDen.GetMonth() == finishday.getMonth() && chuyenBay[i]->ngayGioDen.GetYear() == finishday.getYear())
//		{
//		}
//	}
//
//	return chuyenBayKhuHoi;
//}
//
//vector<ChuyenBay *> ChuyenBay::getOneWayFlight(string startAddress, string finishAddress, string startDay)
//{
//	vector<ChuyenBay *> chuyenBay = getRoute(startAddress, finishAddress);
//	vector<ChuyenBay *> chuyenBayMotChieu;
//
//	Date startday(startDay);
//
//	int size = chuyenBay.size();
//	for (int i = 0; i < size; ++i)
//	{
//		if (chuyenBay[i]->ngayGioBay.GetDay() == startday.getDay() && chuyenBay[i]->ngayGioBay.GetMonth() == startday.getMonth() && chuyenBay[i]->ngayGioBay.GetYear() == startday.getYear())
//		{
//		}
//	}
//
//	return chuyenBayMotChieu;
//}

ostream &operator<<(ostream &o, const ChuyenBay &cb)
{
	cout << cb.maChuyenBay << "\t" << cb.ngayGioBay << "\t" << cb.ngayGioDen << endl;
	return o;
}
