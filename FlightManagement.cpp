#include "FlightManagement.h"

void FlightManagement::selectFlight() {
	SACommand select(&DatabaseConnection::getInstance()->con, _TSA("SELECT * FROM ChuyenBay")); // create command object
	select.Execute();

	while (select.FetchNext())
	{
		SAString maChuyenBay = select.Field("MaChuyenBay").asString();
		SADateTime ngayGioBay = select.Field("NgayGioBay").asDateTime();
		SADateTime ngayGioDen = select.Field("NgayGioDen").asDateTime();
		int giaGoc = select.Field("GiaGoc").asLong();

		ChuyenBay* chuyenBay = new ChuyenBay(string(maChuyenBay),
			Date(ngayGioBay.GetMinute(), ngayGioBay.GetHour(), ngayGioBay.GetDay(), ngayGioBay.GetMonth(), ngayGioBay.GetYear()),
			Date(ngayGioDen.GetMinute(), ngayGioDen.GetHour(), ngayGioDen.GetDay(), ngayGioDen.GetMonth(), ngayGioDen.GetYear()), giaGoc);

		SAString maSanBayDi = select.Field("MaSanBayDi").asString();
		int posLeaveAirPort = searchAirPortCode(string(maSanBayDi));
		sanBay[posLeaveAirPort]->addLeaveFlight(chuyenBay);

		SAString maSanBayDen = select.Field("MaSanBayDen").asString();
		int posArrivalAirPort = searchAirPortCode(string(maSanBayDen));
		sanBay[posArrivalAirPort]->addArrivalFlight(chuyenBay);

		SAString soHieuMayBay = select.Field("SoHieuMayBay").asString();
		int posAirCraft = searchAirCraftCode(string(soHieuMayBay));
		mayBay[posAirCraft]->addChuyenBay(chuyenBay);
	}
}

void FlightManagement::selectAirCraft() {
	SACommand cmd(&DatabaseConnection::getInstance()->con);
	cmd.setCommandText(_TSA("Select * from MayBay"));
	cmd.Execute();

	while (cmd.FetchNext())
	{
		SAString SoHieuMB = cmd.Field("SoHieuMayBay").asString();
		SAString HangKhaiThac = cmd.Field("HangKhaiThac").asString();
		int SoGhe = cmd.Field("SoGhe").asShort();
		MayBay* _mayBay = new MayBay(string(SoHieuMB), string(HangKhaiThac), SoGhe);
		mayBay.push_back(_mayBay);
	}
}

void FlightManagement::selectAirPort() {
	SACommand cmd(&DatabaseConnection::getInstance()->con);
	cmd.setCommandText(_TSA("Select * from SanBay"));
	cmd.Execute();

	while (cmd.FetchNext())
	{
		SAString maSanBay = cmd.Field("MaSanBay").asString();
		SAString tenSanBay = cmd.Field("TenSanBay").asString();
		SAString thanhPho = cmd.Field("ThanhPho").asString();
		SAString quocGia = cmd.Field("QuocGia").asString();
		SanBay* _sanBay = new SanBay(string(maSanBay), string(tenSanBay), string(thanhPho), string(quocGia));
		sanBay.push_back(_sanBay);
	}
}

void FlightManagement::selectPassenger() {
	SACommand select(&DatabaseConnection::getInstance()->con, _TSA("select * from hanhkhach"));
	select.Execute();

	while (select.FetchNext()) {
		SAString maHanhKhach = select.Field("MaHanhKhach").asString();
		SAString tenHanhKhach = select.Field("HoTen").asString();
		SAString CMND = select.Field("CMND").asString();
		bool gioiTinh = select.Field("GioiTinh").asBool();
		SAString SDT = select.Field("SoDienThoai").asString();
		SAString Email = select.Field("Email").asString();
		SAString maSoThe = select.Field("MaSoThe").asString();
		HanhKhach* _hanhKhach = new HanhKhach(string(maHanhKhach), string(tenHanhKhach), string(CMND),
			gioiTinh, string(SDT), string(Email), string(maSoThe));
		hanhKhach.push_back(_hanhKhach);
	}
}

void FlightManagement::addPassenger()
{
	HanhKhach* _hanhKhach = new HanhKhach;
	cin >> *_hanhKhach;

	SACommand insert(&DatabaseConnection::getInstance()->con);
	insert.setCommandText( _TSA("INSERT INTO HanhKhach VALUES (:HoTen, :CMND, :SDT, :GioiTinh, :SoDienThoai, :Email, :MaSoThe"));
	insert.Param("HoTen").setAsString() = _hanhKhach->getHoTen().c_str();
	insert.Param("CMND").setAsString() = _hanhKhach->getHoTen().c_str();
	insert.Param("SDT").setAsString() = _hanhKhach->getHoTen().c_str();
	insert.Param("GioiTinh").setAsBool() = _hanhKhach->getGioiTinh();
	insert.Param("SoDienThoai").setAsString() = _hanhKhach->getHoTen().c_str();
	insert.Param("Email").setAsString() = _hanhKhach->getHoTen().c_str();
	insert.Param("MaSoThe").setAsString() = _hanhKhach->getHoTen().c_str();
	insert.Execute();
}

void FlightManagement::selectTicketClass() {
	SACommand cmd(&DatabaseConnection::getInstance()->con);
	cmd.setCommandText(_TSA("Select * from HangVe"));
	cmd.Execute();

	while (cmd.FetchNext())
	{
		SAString maHangVe = cmd.Field("MaHangVe").asString();
		SAString tenHangVe = cmd.Field("TenHangVe").asString();
		double tiLeHangVe = cmd.Field("TiLeHangVe").asDouble();
		HangVe* _hangVe = new HangVe(string(maHangVe), string(tenHangVe), tiLeHangVe);
		hangVe.push_back(_hangVe);
	}
}

//void FlightManagement::addReserveTicket() {
//	/*
//	----- MÔ TẢ QUÁ TRÌNH ĐẶT VÉ -------
//	1. Lựa chọn loại vé muốn mua (Khứ hồi, một chiều)
//	2. Lựa chọn địa điểm khởi hành và địa điểm đến
//	+ Xuat tren man hinh cac dia diem va lua chon
//	+ 
//	3. Lựa chọn ngày khởi hành hoặc ngày về (nếu là vé khứ hồi)
//	4. Nhập số lượng vé muốn mua: (người già, người lớn, trẻ em)
//	5. Lựa chọn các chuyến bay phù hợp với hạng vé
//	6. Nhập thông tin tất cả khách hàng mua vé
//	7. Lựa chọn hàng ghế phù hợp với hạng vé
//	8. Lựa chọn hình thức thanh toán hoặc muốn đặt vé giữ chỗ
//	   + Thời gian giữ chỗ sẽ là khác nhau đối với từng hạng vé
//	*/
//	string startAddress, finishAddress, startDay, finishDay;
//	HanhKhach* hanhKhach = new HanhKhach;
//
//	DatVe* datve = new DatVe;
//	char choose;
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
//	cout << "\n\tQuy khach vui long lua chon loai ve: \n\t1.Khu hoi\n\t2.Mot chieu\n";
//
//	while (!flag)
//	{
//		cin >> choose;
//		switch (choose)
//		{
//		case '1':
//			cout << "\n------- DAT VE KHU HOI ---------\n";
//			cin.ignore();
//			cout << "\nDiem khoi hanh: ";
//			getline(cin, startAddress);
//			cout << "\nDia diem den: ";
//			getline(cin, finishAddress);
//
//			cout << "\nNgay khoi hanh: ";
//			getline(cin, startDay);
//			cout << "\nNgay ve: ";
//			getline(cin, finishDay);
//
//			cout << "\nThong tin cac chuyen bay chieu di: ";
//			cout << "";
//			cout << "\nChuyen bay chieu di: ";
//			
//			cout << "\nThong tin cac chuyen bay chieu ve: ";
//			cout << "\nChuyen bay chieu ve: ";
//			
//			cout << "\nThong tin khach hang: ";
//			cin >> *hanhKhach;
//
//			cout << "\nThong tin cac hang ve: ";
//			
//			flag = true;
//			break;
//		case '2':
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
//
//}

void FlightManagement::selectPayment() {

}

void FlightManagement::selectReserveTicket() {

}

int FlightManagement::searchAirPortCode(string maSanBay)
{
	for (unsigned int i = 0; i < sanBay.size(); ++i)
	{
		if (maSanBay == sanBay[i]->getMaSanBay())
		{
			return i;
		}
	}
	return -1;
}

int FlightManagement::searchAirCraftCode(string soHieuMayBay) {
	for (unsigned int i = 0; i < mayBay.size(); ++i)
	{
		if (soHieuMayBay == mayBay[i]->getSoHieuMayBay())
		{
			return i;
		}
	}
	return -1;
}

int FlightManagement::searchPassenger(string maHanhKhach)
{
	for (int i = 0; i < hanhKhach.size(); ++i) {
		if (maHanhKhach == hanhKhach[i]->getMaHanhKhach()) {
			return i;
		}
	}
	return -1;
}

set<string> FlightManagement::selectCity() {
	set<string> city;

	for (int i = 0; i < sanBay.size(); ++i) {
		city.insert(sanBay[i]->getThanhPho());
	}
	return city;
}

//unordered_map<ChuyenBay*, int> FlightManagement::searchFlightArrival(string diaDiemDen, Date ngayKhoiHanh) {
//	unordered_map<ChuyenBay*, int> chuyenBay;
//	vector<ChuyenBay*> chuyenBayDen;
//	for (int i = 0; i < sanBay.size(); ++i) {
//		chuyenBayDen = sanBay[i]->getArrivalFlight();
//		for (int j = 0; j < chuyenBay.size(); ++j)
//			if (sanBay[i]->getThanhPho() == diaDiemDen && chuyenBayDen[j]->getNgayGioDen() == ngayKhoiHanh)
//				chuyenBay.insert(pair<ChuyenBay*, int>(chuyenBayDen[j], j));
//		chuyenBayDen.clear();
//	}
//	return chuyenBay;
//}
//
//unordered_map<ChuyenBay*, int> FlightManagement::searchFlightLeave(string diaDiemDi, Date ngayVe) {
//	unordered_map<ChuyenBay*, int> chuyenBay;
//	vector<ChuyenBay*> chuyenBayDi;
//	for (int i = 0; i < sanBay.size(); ++i) {
//		chuyenBayDi = sanBay[i]->getLeaveFlight();
//		for (int j = 0; j < chuyenBay.size(); ++j)
//			if (sanBay[i]->getThanhPho() == diaDiemDi && chuyenBayDi[j]->getNgayGioBay() == ngayVe)
//				chuyenBay.insert(pair<ChuyenBay*, int>(chuyenBayDi[j], j));
//		chuyenBayDi.clear();
//	}
//	return chuyenBay;
//}

unordered_map<ChuyenBay*, int> FlightManagement::searchFlightHasAddress(string diaDiemDi, string diaDiemDen, Date ngayGioBay) {
	unordered_map<ChuyenBay*, int> chuyenBay;
	vector<ChuyenBay*> chuyenBayDi;
	vector<ChuyenBay*> chuyenBayDen;
	vector<ChuyenBay*> temp;

	for (int i = 0; i < sanBay.size(); ++i) {
		if(sanBay[i]->getThanhPho() == diaDiemDi) {
			chuyenBayDi = sanBay[i]->getLeaveFlight();

			for (int j = 0; j < chuyenBayDi.size(); ++j)
				if (chuyenBayDi[j]->getNgayGioBay() == ngayGioBay)
					temp.push_back(chuyenBayDi[j]);
			break;
		}
	}


	for (int i = 0; i < sanBay.size(); ++i) {
		if (sanBay[i]->getThanhPho() == diaDiemDen) {
			chuyenBayDen = sanBay[i]->getLeaveFlight();

			for (int j = 0; j < chuyenBayDen.size(); ++j)
				for (int k = 0; k < temp.size(); ++k) {
					if (chuyenBayDen[i]->getMaChuyenBay() == temp[j]->getMaChuyenBay()) chuyenBay.insert(pair<ChuyenBay*,int>(temp[j],j));
				}
		}
	}

	return chuyenBay;
}

void FlightManagement::read() {
	for (int i = 0; i < sanBay.size(); ++i) {
		vector<ChuyenBay*> temp = sanBay[i]->getArrivalFlight();
		for (int j = 0; j < temp.size(); ++j) {
			cout << *temp[j];
		}
	}
}