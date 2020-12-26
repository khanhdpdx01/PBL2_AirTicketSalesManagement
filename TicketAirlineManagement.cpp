#include "TicketAirlineManagement.h"

void TicketAirlineManagement::passengerManagement() {
	char choose;
	cout << "\n\t\t\t\t++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "\t\t\t\t+         QUAN LI HANH KHACH             +\n";
	cout << "\t\t\t\t++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "\t\t\t\t+                                        +\n";
	cout << "\t\t\t\t+  (1) - Xem thong tin hanh khach        +\n";
	cout << "\t\t\t\t+  (2) - Them moi hanh khach             +\n";
	cout << "\t\t\t\t+  (3) - Sua thong tin hanh khach        +\n";
	cout << "\t\t\t\t+  (4) - Xoa thong tin hanh khach        +\n";
	cout << "\t\t\t\t+  (5) - Tim kiem hanh khach             +\n";
	cout << "\t\t\t\t+  (6) - Sap xep hanh khach              +\n";
	cout << "\t\t\t\t+                                        +\n";
	cout << "\t\t\t\t++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "\n\t\t\t\tLua chon: ";
	cin >> choose;
	switch (choose) {
	case '1':
		findAllPassenger();
		break;
	case '2':
	{
		cin.ignore();
		HanhKhach* _hanhKhach = new HanhKhach;
		cin >> *_hanhKhach;
		addPassenger(_hanhKhach);
		break;
	}
	case '3':
	{
		string hoTen, CMND;
		cin.ignore();
		cout << "\n\t\t\t\tHo ten: ";
		getline(cin, hoTen);
		cout << "\n\t\t\t\tCMND: ";
		getline(cin, CMND);
		int pos = searchPassenger(hoTen, CMND);
		if (pos == -1) cout << "\n\t\t\t\tKhong tim thay hanh khach.\n";
		else {
			updatePassenger(hanhKhach[pos]);
		}
		break;
	}
	case '4':
	{
		string hoTen, CMND;
		cin.ignore();
		cout << "\n\t\t\t\tHo ten: ";
		getline(cin, hoTen);
		cout << "\n\t\t\t\tCMND: ";
		getline(cin, CMND);
		int pos = searchPassenger(hoTen, CMND);
		if (pos == -1) cout << "\n\t\t\t\tKhong tim thay hanh khach.\n";
		else deletePassenger(hanhKhach[pos]);
		break;
	}
	case '5':
	{
		string hoTen, CMND;
		cin.ignore();
		cout << "\n\t\t\t\tHo ten: ";
		getline(cin, hoTen);
		cout << "\n\t\t\t\tCMND: ";
		getline(cin, CMND);
		int pos = searchPassenger(hoTen, CMND);
		cout << std::left << setw(5) << "Ma HK" << setw(31) << "|Ho Ten" << setw(10) << "|CMND" << setw(10) << " |Gioi Tinh" << setw(12) << "|SDT" << setw(31) << "|Email" << "|Ngay sinh\n";
		cout << "-----+------------------------------+----------+---------+-----------+------------------------------+--------------+\n";
		if (pos == -1) cout << "\nKhong tim thay hanh khach.\n";
		else cout << *hanhKhach[pos];
		break;
	}
	case '6':
		bool flag = 0;
		char choice;
		while (!flag) {
			cout << "\n\t\t\t\t1.Sap xep giam \t2. Sap xep tang \n\t\t\t\tLua chon: "; cin >> choice;
			switch(choice) {
			case '1':
				quickSortPassenger(0, 11,&TicketAirlineManagement::downCustomers); flag = 1;
				break;
			case '2':
				quickSortPassenger(0, 11, &TicketAirlineManagement::upCustomers); flag =1 ;
				break;
			default:
				cout << "\n\t\t\t\tLua chon sai. Nhap lai: ";
				break;
			}
		}
		break;
	}
}
void TicketAirlineManagement::ticketManagement() {
	char choose;
	cout << "\n\t\t\t\t+++++++++++++++++++++++++++++++++++++++++\n";
	cout << "\t\t\t\t+         QUAN LI THONG TIN VE           +\n";
	cout << "\t\t\t\t++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "\t\t\t\t+                                        +\n";
	cout << "\t\t\t\t+  (1) - Ban ve                          +\n";
	cout << "\t\t\t\t+  (2) - Xem thong tin ve                +\n";
	cout << "\t\t\t\t+  (3) - Sua thong tin ve                +\n";
	cout << "\t\t\t\t+  (4) - Xoa thong tin ve                +\n";
	cout << "\t\t\t\t+                                        +\n";
	cout << "\t\t\t\t++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "\n\t\t\t\tLua chon: ";
	cin >> choose;
	switch (choose) {
	case '1':
		cin.ignore();
		addReserveTicket();
		break;
	case '2':
	{
		int maVe;
		cout << "\n\t\t\t\tMa ve: ";
		cin >> maVe;
		searchReserveTicket(maVe);
		break;
	}
	case '3':
	{
		int maVe;
		cout << "\n\t\t\t\tMa ve: ";
		cin >> maVe;
		cin.ignore();
		updateTicket(maVe);
		break;
	}
	case '4':
	{
		int maVe;
		cout << "\n\t\t\t\tMa ve: ";
		cin >> maVe;
		deleteTicket(maVe);
		break;
	}
	}
}
void TicketAirlineManagement::airPortManagement() {
	char choose;
	cout << "\n\t\t\t\t+++++++++++++++++++++++++++++++++++++++++\n";
	cout << "\t\t\t\t+         QUAN LI SAN BAY                +\n";
	cout << "\t\t\t\t++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "\t\t\t\t+                                        +\n";
	cout << "\t\t\t\t+  (1) - Xem thong tin san bay           +\n";
	cout << "\t\t\t\t+  (2) - Them moi san bay                +\n";
	cout << "\t\t\t\t+  (3) - Sua thong tin san bay           +\n";
	cout << "\t\t\t\t+  (4) - Xoa thong tin san bay           +\n";
	cout << "\t\t\t\t+  (5) - Tim kiem san bay                +\n";
	cout << "\t\t\t\t+                                        +\n";
	cout << "\t\t\t\t++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "\n\t\t\t\tLua chon: ";
	cin >> choose;
	switch (choose) {
	case '1':
		findAllAirPort();
		break;
	case '2':
	{
		cin.ignore();
		SanBay* _sanBay = new SanBay;
		cin >> *_sanBay;
		addAirPort(_sanBay);
		break;
	}
	case '3':
	{
		cin.ignore();
		string maSanBay;
		cout << "\n\t\t\t\tMa san bay: ";
		getline(cin, maSanBay);
		int pos = searchAirPortCode(maSanBay);
		if (pos == -1) cout << "\n\t\t\t\tKhong co san bay.";
		else updateAirPort(sanBay[pos]);
		break;
	}
	case '4':
	{
		cin.ignore();
		string maSanBay;
		cout << "\n\t\t\t\tMa san bay: ";
		getline(cin, maSanBay);
		int pos = searchAirPortCode(maSanBay);
		if (pos == -1) cout << "\n\t\t\t\tKhong co san bay.";
		else deleteAirport(sanBay[pos]);
		break;
	}
	case '5':
	{
		cin.ignore();
		string maSanBay;
		cout << "\n\t\t\t\tMa san bay: ";
		getline(cin, maSanBay);
		int pos = searchAirPortCode(maSanBay);
		cout << std::left << setw(10) << "Ma san bay" << "|" << setw(30) << "Ten san bay" << "|" << setw(30) << "Thanh pho" << "|" << setw(30) << "Quoc gia" << endl;
		cout << "----------+------------------------------+------------------------------+------------------------------\n";
		if (pos == -1) cout << "\nKhong co san bay.";
		else cout << *sanBay[pos];
		break;
	}
	}
}
void TicketAirlineManagement::airCraftManagement() {
	char choose;
	cout << "\n\t\t\t\t+++++++++++++++++++++++++++++++++++++++++\n";
	cout << "\t\t\t\t+         QUAN LI MAY BAY                +\n";
	cout << "\t\t\t\t++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "\t\t\t\t+                                        +\n";
	cout << "\t\t\t\t+  (1) - Xem thong tin may bay           +\n";
	cout << "\t\t\t\t+  (2) - Them moi may bay                +\n";
	cout << "\t\t\t\t+  (3) - Sua thong tin may bay           +\n";
	cout << "\t\t\t\t+  (4) - Xoa thong tin may bay           +\n";
	cout << "\t\t\t\t+  (5) - Tim kiem may bay                +\n";
	cout << "\t\t\t\t+                                        +\n";
	cout << "\t\t\t\t++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "\n\t\t\t\tLua chon: ";
	cin >> choose;
	switch (choose) {
	case '1':
		findAllAirCraft();
		break;
	case '2':
	{
		cin.ignore();
		MayBay* _mayBay = new MayBay;
		cin >> *_mayBay;
		addAirCraft(_mayBay);
		break;
	}
	case '3':
	{
		cin.ignore();
		string maMayBay;
		cout << "\n\t\t\t\tSo hieu may bay: "; getline(cin, maMayBay);
		int pos = searchAirCraftCode(maMayBay);
		if (pos == -1) cout << "\n\t\t\t\tKhong co may bay.";
		else updateAirCraft(mayBay[pos]);
		break;
	}
	case '4':
	{
		cin.ignore();
		string maMayBay;
		cout << "\n\t\t\t\tSo hieu may bay: "; getline(cin, maMayBay);
		int pos = searchAirCraftCode(maMayBay);
		if (pos == -1) cout << "\n\t\t\t\tKhong co may bay.";
		else deleteAirCraft(mayBay[pos]);
		break;
	}
	case '5':
	{
		cin.ignore();
		string maMayBay;
		cout << "\n\t\t\t\tSo hieu may bay: "; getline(cin, maMayBay);
		int pos = searchAirCraftCode(maMayBay);
		cout << endl << std::left << setw(20) << "So hieu may bay" << "|" << setw(6) << "So ghe" << "|" << setw(10) << "Hang khai thac" << endl;
		cout << "--------------------+------+----------------\n";
		if (pos == -1) cout << "\nKhong co may bay.";
		else cout << *mayBay[pos];
		break;
	}
	}

}
void TicketAirlineManagement::flightManagement() {
	char choose;
	cout << "\n\t\t\t\t+++++++++++++++++++++++++++++++++++++++++\n";
	cout << "\t\t\t\t+         QUAN LI CHUYEN BAY             +\n";
	cout << "\t\t\t\t++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "\t\t\t\t+                                        +\n";
	cout << "\t\t\t\t+  (1) - Xem thong tin chuyen bay        +\n";
	cout << "\t\t\t\t+  (2) - Them moi chuyen bay             +\n";
	cout << "\t\t\t\t+  (3) - Sua thong tin chuyen bay        +\n";
	cout << "\t\t\t\t+  (4) - Xoa thong tin chuyen bay        +\n";
	cout << "\t\t\t\t+  (5) - Tim kiem chuyen bay             +\n";
	cout << "\t\t\t\t+                                        +\n";
	cout << "\t\t\t\t++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "\n\t\t\t\tLua chon: ";
	cin >> choose;
	switch (choose) {
	case '1':
		findAllFlight();
		break;
	}
}

void TicketAirlineManagement::ticketClassManagement() {
	char choose;
	cout << "\n\t\t\t\t+++++++++++++++++++++++++++++++++++++++++\n";
	cout << "\t\t\t\t+         QUAN LI HANG VE                +\n";
	cout << "\t\t\t\t++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "\t\t\t\t+                                        +\n";
	cout << "\t\t\t\t+  (1) - Xem thong tin hang ve           +\n";
	cout << "\t\t\t\t+  (2) - Them moi hang ve                +\n";
	cout << "\t\t\t\t+  (3) - Sua thong tin hang ve           +\n";
	cout << "\t\t\t\t+  (4) - Xoa thong tin hang ve           +\n";
	cout << "\t\t\t\t+  (5) - Tim kiem hang ve                +\n";
	cout << "\t\t\t\t+                                        +\n";
	cout << "\t\t\t\t++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "\n\t\t\t\tLua chon: ";
	cin >> choose;
	switch (choose) {
	case '1':
		findAllTicketClass();
		break;
	case '2':
	{
		cin.ignore();
		HangVe* _hangVe = new HangVe;
		cin >> *_hangVe;
		addTicketClass(_hangVe);
		break;
	}
	case '3':
	{
		cin.ignore();
		string maHangVe;
		cout << "\n\t\t\t\tMa hang ve: "; getline(cin, maHangVe);
		int pos = searchTicketClass(maHangVe);
		if (pos == -1) cout << "\n\t\t\t\tKhong co hang ve.";
		else updateTicketClass(hangVe[pos]);
		break;
	}
	case '4':
	{
		cin.ignore();
		string maHangVe;
		cout << "\n\t\t\t\tMa hang ve: "; getline(cin, maHangVe);
		int pos = searchTicketClass(maHangVe);
		if (pos == -1) cout << "\n\t\t\t\tKhong co hang ve.";
		else deleteTicketClass(hangVe[pos]);
		break;
	}
	case '5':
	{
		cin.ignore();
		string maHangVe;
		cout << "\n\t\t\t\tMa hang ve: "; getline(cin, maHangVe);
		int pos = searchTicketClass(maHangVe);
		cout << std::left << setw(10) << "Ma hang ve" << setw(30) << "|Ten hang ve" << setw(15) << " |Ti le hang ve\n";
		cout << "----------+------------------------------+---------------+\n";
		if (pos == -1) cout << "\nKhong co hang ve.";
		else cout << *hangVe[pos];
		break;
	}
	}
}
void TicketAirlineManagement::selectFlight() {
	try {
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
	catch (SAException e) {
		cout << e.ErrText().GetMultiByteChars() << endl;
	}
}

void TicketAirlineManagement::addFlight(ChuyenBay* _chuyenBay) {
	try {
		string tenSanBayDi, tenSanBayDen, soHieuMayBay, ngayGioBay, ngayGioDen;
		double giaGoc = 0;
		cout << "\n\t\t\t\tTen san bay di: "; getline(cin, tenSanBayDi);
		cout << "\n\t\t\t\tTen san bay den: "; getline(cin, tenSanBayDen);
		cout << "\n\t\t\t\tSo hieu may bay: "; getline(cin, soHieuMayBay);
		cout << "\n\t\t\t\tNgay gio bay: "; getline(cin, ngayGioBay);
		cout << "\n\t\t\t\tNgay gio den: "; getline(cin, ngayGioDen);
		cout << "\n\t\t\t\tGia goc: "; cin >> giaGoc;
		SACommand insert(&DatabaseConnection::getInstance()->con);
		insert.setCommandText(_TSA("INSERT INTO ChuyenBay VALUES(:MaChuyenBay,:MaSanBayDi,:MaSanBayDen,:SoHieuMayBay,:NgayGioBay,:NgayGioDen,:GiaGoc)"));
		insert.Param("MaChuyenBay").setAsString() = _chuyenBay->getMaChuyenBay().c_str();
		insert.Param("MaSanBayDi").setAsString() = tenSanBayDi.c_str();
		insert.Param("MaSanBayDen").setAsString() = tenSanBayDen.c_str();
		insert.Param("SoHieuMayBay").setAsString() = soHieuMayBay.c_str();
		insert.Param("NgayGioBay").setAsString() = ngayGioBay.c_str();
		insert.Param("NgayGioDen").setAsString() = ngayGioDen.c_str();
		insert.Param("GiaGoc").setAsDouble() = giaGoc;
		insert.Execute();
	}
	catch (SAException e) {
		cout << e.ErrText().GetMultiByteChars() << endl;
	}
}

void TicketAirlineManagement::findAllFlight() {
	try {
		SACommand select(&DatabaseConnection::getInstance()->con);
		select.setCommandText(_TSA("select ChuyenBay.MaChuyenBay as MaCB, SanBayDi.TenSanBay as MaSBDi, SanBayDen.TenSanBay as MaSBDen, ChuyenBay.SoHieuMayBay as SoHieuMB, NgayGioBay, NgayGioDen, GiaGoc "
			"from ChuyenBay "
			"inner join SanBay as SanBayDi on SanBayDi.MaSanBay = ChuyenBay.MaSanBayDi "
			"inner join SanBay as SanBayDen on SanBayDen.MaSanBay = ChuyenBay.MaSanBayDen "
			"inner join MayBay on ChuyenBay.SoHieuMayBay = MayBay.SoHieuMayBay")); // create command object
		select.Execute();

		while (select.FetchNext()) {
			SAString maCB = select.Field("MaCB").asString();
			SAString tenSBDi = select.Field("MaSBDi").asString();
			SAString tenSBDen = select.Field("MaSBDen").asString();
			SAString soHieuMB = select.Field("SoHieuMB").asString();
			SADateTime ngayGioBay = select.Field("NgayGioBay").asDateTime();
			SADateTime ngayGioDen = select.Field("NgayGioDen").asDateTime();
			double giaGoc = select.Field("GiaGoc").asDouble();

			cout << "\n\t\t\t\t" << string(maCB) << " " << string(tenSBDi) << " " << string(tenSBDen) << " " << string(soHieuMB) << " "
				<< Date(ngayGioBay.GetDay(), ngayGioBay.GetMonth(), ngayGioBay.GetYear()) << " "
				<< Date(ngayGioDen.GetDay(), ngayGioDen.GetMonth(), ngayGioDen.GetYear()) << " " << giaGoc;
		}
	}
	catch (SAException e) {
		cout << e.ErrText().GetMultiByteChars() << endl;
	}
}

void TicketAirlineManagement::updateFlight() {
	string maChuyenBayDi, maChuyenBayDen, soHieuMayBay, ngayGioBay, ngayGioDen;
	double giaGoc = 0;

	cout << "\n\t\t\t\tTen san bay di: "; getline(cin, maChuyenBayDi);
	cout << "\n\t\t\t\tTen san bay den: "; getline(cin, maChuyenBayDen);
	cout << "\n\t\t\t\tSo hieu may bay: "; getline(cin, soHieuMayBay);
	cout << "\n\t\t\t\tNgay gio bay: "; getline(cin, ngayGioBay);
	cout << "\n\t\t\t\tNgay gio den: "; getline(cin, ngayGioDen);
	cout << "\n\t\t\t\tGia goc: "; cin >> giaGoc;
}

void TicketAirlineManagement::deleteFlight() {

}

void TicketAirlineManagement::selectPassenger() {
	try {
		SACommand select(&DatabaseConnection::getInstance()->con, _TSA("select * from HanhKhach"));
		select.Execute();

		while (select.FetchNext()) {
			int maHanhKhach = select.Field("MaHanhKhach").asLong();
			SAString tenHanhKhach = select.Field("HoTen").asString();
			SAString CMND = select.Field("CMND").asString();
			bool gioiTinh = select.Field("GioiTinh").asBool();
			SAString SDT = select.Field("SoDienThoai").asString();
			SAString Email = select.Field("Email").asString();
			SADateTime ngaySinh = select.Field("NgaySinh").asDateTime();
			HanhKhach* _hanhKhach = new HanhKhach(maHanhKhach, string(tenHanhKhach), string(CMND),
				gioiTinh, string(SDT), string(Email), Date(ngaySinh.GetDay(), ngaySinh.GetMonth(), ngaySinh.GetYear()));
			hanhKhach.push_back(_hanhKhach);
		}
	}
	catch (SAException e) {
		cout << e.ErrText().GetMultiByteChars() << endl;
	}
}

void TicketAirlineManagement::findAllPassenger() {
	cout << std::left << setw(5) << "Ma HK" << setw(31) << "|Ho Ten" << setw(10) << "|CMND" << setw(10) << " |Gioi Tinh" << setw(12) << "|SDT" << setw(31) << "|Email" << "|Ngay sinh\n";
	for (unsigned int i = 0; i < hanhKhach.size(); ++i) {
		cout << "-----+------------------------------+----------+---------+-----------+------------------------------+--------------+\n";
		cout << *hanhKhach[i];
	}
}

void TicketAirlineManagement::addPassenger(HanhKhach* _hanhKhach)
{
	int pos = 0;
	SADateTime NgaySinh(_hanhKhach->getNgaySinh().getYear(), _hanhKhach->getNgaySinh().getMonth(), _hanhKhach->getNgaySinh().getDay());
	try {
		SACommand insert(&DatabaseConnection::getInstance()->con);
		insert.setCommandText(_TSA("INSERT INTO HanhKhach VALUES(:HoTen, :CMND, :GioiTinh, :SoDienThoai, :Email, :NgaySinh)"));
		insert.Param("HoTen").setAsString() = _hanhKhach->getHoTen().c_str();
		insert.Param("CMND").setAsString() = _hanhKhach->getCMND().c_str();
		insert.Param("SoDienThoai").setAsString() = _hanhKhach->getSDT().c_str();
		insert.Param("GioiTinh").setAsBool() = _hanhKhach->getGioiTinh();
		insert.Param("Email").setAsString() = _hanhKhach->getEmail().c_str();
		insert.Param("NgaySinh").setAsDateTime() = NgaySinh;
		insert.Execute();

		//set maHanhKhach
		SACommand cmd(&DatabaseConnection::getInstance()->con);
		cmd.setCommandText(_TSA("SELECT IDENT_CURRENT('HanhKhach') as res"));
		cmd.Execute();
		while (cmd.FetchNext()) {
			pos = cmd.Field("res").asLong();
		}
		_hanhKhach->setMaHanhKhach(pos);

		hanhKhach.push_back(_hanhKhach);
		cout << "\n\t\t\t\tThem hanh khach thanh cong !\n";
	}
	catch (string str) {
		cout << str << endl;
	}
	catch (SAException e) {
		cout << e.ErrText().GetMultiByteChars() << endl;
	}
}



void TicketAirlineManagement::updatePassenger(HanhKhach* _hanhKhach) {
	cin >> *_hanhKhach;
	SADateTime NgaySinh(_hanhKhach->getNgaySinh().getYear(), _hanhKhach->getNgaySinh().getMonth(), _hanhKhach->getNgaySinh().getDay());

	try {
		SACommand update(&DatabaseConnection::getInstance()->con);
		update.setCommandText(_TSA("UPDATE HanhKhach "
			"SET HoTen = :HoTen, CMND = :CMND, SoDienThoai = :SDT, GioiTinh = :GioiTinh, Email = :Email, NgaySinh = :NgaySinh "
			"WHERE MaHanhKhach = :MaHanhKhach"));
		update.Param("MaHanhKhach").setAsLong() = _hanhKhach->getMaHanhKhach();
		update.Param("HoTen").setAsString() = _hanhKhach->getHoTen().c_str();
		update.Param("CMND").setAsString() = _hanhKhach->getCMND().c_str();
		update.Param("SDT").setAsString() = _hanhKhach->getSDT().c_str();
		update.Param("GioiTinh").setAsBool() = _hanhKhach->getGioiTinh();
		update.Param("Email").setAsString() = _hanhKhach->getEmail().c_str();
		update.Param("NgaySinh").setAsDateTime() = NgaySinh;
		update.Execute();

		cout << "\n\t\t\t\tCap nhat thong tin hanh khach thanh cong.\n";
	}
	catch (SAException e) {
		cout << e.ErrText().GetMultiByteChars() << endl;
	}
}

void TicketAirlineManagement::deletePassenger(HanhKhach* _hanhKhach) {
	int index = this->searchPassenger(_hanhKhach->getMaHanhKhach());
	hanhKhach.erase(hanhKhach.begin() + index);
	try {
		SACommand remove(&DatabaseConnection::getInstance()->con);
		remove.setCommandText(_TSA("DELETE FROM HanhKhach "
			"WHERE MaHanhKhach = :MaHanhKhach"));
		remove.Param("MaHanhKhach").setAsLong() = _hanhKhach->getMaHanhKhach();
		remove.Execute();
		cout << "\n\t\t\t\tXoa thong tin hanh khach thanh cong.\n";
	}
	catch (SAException e) {
		cout << e.ErrText().GetMultiByteChars() << endl;
	}
	delete _hanhKhach;
}

void TicketAirlineManagement::selectAirPort() {
	try {
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
	catch (SAException e) {
		cout << e.ErrText().GetMultiByteChars() << endl;
	}
}

void TicketAirlineManagement::addAirPort(SanBay* _sanBay) {
	try {
		SACommand insert(&DatabaseConnection::getInstance()->con);
		insert.setCommandText(_TSA("INSERT INTO SanBay "
			"VALUES(:MaSanBay,:TenSanBay,:ThanhPho,:QuocGia)"));
		insert.Param("MaSanBay").setAsString() = _sanBay->getMaSanBay().c_str();
		insert.Param("TenSanBay").setAsString() = _sanBay->getTenSanBay().c_str();
		insert.Param("ThanhPho").setAsString() = _sanBay->getThanhPho().c_str();
		insert.Param("QuocGia").setAsString() = _sanBay->getQuocGia().c_str();
		insert.Execute();
		sanBay.push_back(_sanBay);
		cout << "\n\t\t\t\tThem san bay thanh cong.\n";
	}
	catch (SAException e) {
		cout << e.ErrText().GetMultiByteChars() << endl;
	}
}

void TicketAirlineManagement::findAllAirPort() {
	cout << std::left << setw(10) << "Ma san bay" << "|" << setw(30) << "Ten san bay" << "|" << setw(30) << "Thanh pho" << "|" << setw(30) << "Quoc gia" << endl;
	for (unsigned int i = 0; i < sanBay.size(); ++i) {
		cout << "----------+------------------------------+------------------------------+------------------------------\n";
		cout << *sanBay[i];
	}
}

void TicketAirlineManagement::updateAirPort(SanBay* _sanBay) {
	string maSanBayCu = _sanBay->getMaSanBay();
	cin >> *_sanBay;

	try {
		SACommand update(&DatabaseConnection::getInstance()->con);
		update.setCommandText(_TSA("UPDATE SanBay "
			"SET MaSanBay = :MaSanBay,TenSanBay = :TenSanBay, ThanhPho = :ThanhPho,QuocGia =:QuocGia "
			"WHERE MaSanBay = :MaSanBayCu"));
		update.Param("MaSanBay").setAsString() = _sanBay->getMaSanBay().c_str();
		update.Param("TenSanBay").setAsString() = _sanBay->getTenSanBay().c_str();
		update.Param("ThanhPho").setAsString() = _sanBay->getThanhPho().c_str();
		update.Param("QuocGia").setAsString() = _sanBay->getQuocGia().c_str();
		update.Param("MaSanBayCu").setAsString() = maSanBayCu.c_str();
		update.Execute();
		cout << "\n\t\t\t\tCap nhat du lieu san bay.\n";
	}
	catch (SAException e) {
		cout << e.ErrText().GetMultiByteChars() << endl;
	}
}

void TicketAirlineManagement::deleteAirport(SanBay* _sanBay) {
	int index = this->searchAirPortCode(_sanBay->getMaSanBay());
	sanBay.erase(sanBay.begin() + index);

	try {
		SACommand remove(&DatabaseConnection::getInstance()->con);
		remove.setCommandText(_TSA("DELETE FROM SanBay "
			"WHERE MaSanBay = :MaSanBay"));
		remove.Param("MaSanBay").setAsString() = _sanBay->getMaSanBay().c_str();
		remove.Execute();
		cout << "\n\t\t\t\tXoa du lieu san bay thanh cong.";
	}
	catch (SAException e) {
		cout << e.ErrText().GetMultiByteChars() << endl;
	}
	delete _sanBay;
}

void TicketAirlineManagement::selectAirCraft() {
	try {
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
	catch (SAException e) {
		cout << e.ErrText().GetMultiByteChars() << endl;
	}
}

void TicketAirlineManagement::addAirCraft(MayBay* _mayBay) {
	try {
		SACommand insert(&DatabaseConnection::getInstance()->con);
		insert.setCommandText(_TSA("INSERT INTO MayBay "
			"VALUES(:SoHieuMayBay,:SoGhe, :HangKhaiThac)"));
		insert.Param("SoHieuMayBay").setAsString() = _mayBay->getSoHieuMayBay().c_str();
		insert.Param("SoGhe").setAsLong() = _mayBay->getSoGhe();
		insert.Param("HangKhaiThac").setAsString() = _mayBay->getHangKhaiThac().c_str();
		insert.Execute();
		mayBay.push_back(_mayBay);
		cout << "\n\t\t\t\tThem may bay thanh cong.\n";
	}
	catch (SAException e) {
		cout << e.ErrText().GetMultiByteChars() << endl;
	}
}

void TicketAirlineManagement::findAllAirCraft() {
	cout << std::left << setw(20) << "So hieu may bay" << "|" << setw(6) << "So ghe" << "|" << setw(10) << "Hang khai thac" << endl;
	for (unsigned int i = 0; i < mayBay.size(); ++i) {
		cout << "--------------------+------+----------------\n";
		cout << *mayBay[i];
	}
}

void TicketAirlineManagement::updateAirCraft(MayBay* _mayBay) {
	string soHieuMBCu = _mayBay->getSoHieuMayBay();
	cin >> *_mayBay;
	try {
		SACommand update(&DatabaseConnection::getInstance()->con);
		update.setCommandText(_TSA("UPDATE MayBay "
			"SET SoHieuMayBay = :SoHieuMayBay,SoGhe = :SoGhe, HangKhaiThac = :HangKhaiThac "
			"WHERE SoHieuMayBay = :SoHieuMayBayCu"));
		update.Param("SoHieuMayBay").setAsString() = _mayBay->getSoHieuMayBay().c_str();
		update.Param("SoGhe").setAsLong() = _mayBay->getSoGhe();
		update.Param("HangKhaiThac").setAsString() = _mayBay->getHangKhaiThac().c_str();
		update.Param("SoHieuMayBayCu").setAsString() = soHieuMBCu.c_str();
		update.Execute();
		cout << "\n\t\t\t\tCap nhat thong tin may bay thanh cong.\n";
	}
	catch (SAException e) {
		cout << e.ErrText().GetMultiByteChars() << endl;
	}
}

void TicketAirlineManagement::deleteAirCraft(MayBay* _mayBay) {
	int index = searchAirCraftCode(_mayBay->getSoHieuMayBay());
	mayBay.erase(mayBay.begin() + index);
	try {
		SACommand remove(&DatabaseConnection::getInstance()->con);
		remove.setCommandText(_TSA("DELETE FROM MayBay "
			"WHERE SoHieuMayBay = :SoHieuMayBay"));
		remove.Param("SoHieuMayBay").setAsString() = _mayBay->getSoHieuMayBay().c_str();
		remove.Execute();
		cout << "\n\t\t\t\tXoa thong tin may bay thanh cong.\n";
	}
	catch (SAException e) {
		cout << e.ErrText().GetMultiByteChars() << endl;
	}
	delete _mayBay;
}

void TicketAirlineManagement::selectTicketClass() {
	try {
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
	catch (SAException e) {
		cout << e.ErrText().GetMultiByteChars() << endl;
	}
}

void TicketAirlineManagement::addTicketClass(HangVe* _hangVe) {
	try {
		SACommand insert(&DatabaseConnection::getInstance()->con);
		insert.setCommandText(_TSA("INSERT INTO HangVe VALUES(:MaHangVe, :TenHangVe, :TiLeHangVe)"));
		insert.Param("MaHangVe").setAsString() = _hangVe->getMaHangVe().c_str();
		insert.Param("TenHangVe").setAsString() = _hangVe->getTenHangVe().c_str();
		insert.Param("TiLeHangVe").setAsDouble() = _hangVe->getTiLeHangVe();
		insert.Execute();
		cout << "\n\t\t\t\tThem hang ve thanh cong !\n";
		hangVe.push_back(_hangVe);
	}
	catch (string str) {
		cout << str << endl;
	}
	catch (SAException e) {
		cout << e.ErrText().GetMultiByteChars() << endl;
	}
}
void TicketAirlineManagement::findAllTicketClass() {
	cout << std::left << setw(10) << "Ma hang ve" << setw(30) << "|Ten hang ve" << setw(15) << " |Ti le hang ve\n";
	for (unsigned int i = 0; i < hangVe.size(); ++i) {
		cout << "----------+------------------------------+---------------+\n";
		cout << *hangVe[i];
	}
}

void TicketAirlineManagement::updateTicketClass(HangVe* _hangVe) {
	string maHangVeCu = _hangVe->getMaHangVe();
	cin >> *_hangVe;
	try {
		SACommand update(&DatabaseConnection::getInstance()->con);
		update.setCommandText(_TSA("UPDATE HangVe "
			"SET MaHangVe = :MaHangVe,TenHangVe = :TenHangVe, TiLeHangVe =:TiLeHangVe "
			"WHERE MaHangVe = :MaHangVeCu"));
		update.Param("MaHangVe").setAsString() = _hangVe->getMaHangVe().c_str();
		update.Param("TenHangVe").setAsString() = _hangVe->getTenHangVe().c_str();
		update.Param("TiLeHangVe").setAsDouble() = _hangVe->getTiLeHangVe();
		update.Param("MaHangVeCu").setAsString() = maHangVeCu.c_str();
		update.Execute();
		cout << "\n\t\t\t\tCap nhat hang ve thanh cong.\n";
	}
	catch (SAException e) {
		cout << e.ErrText().GetMultiByteChars() << endl;
	}
}
void TicketAirlineManagement::deleteTicketClass(HangVe* _hangVe) {
	int index = searchTicketClass(_hangVe->getMaHangVe());
	hangVe.erase(hangVe.begin() + index);
	try {
		SACommand remove(&DatabaseConnection::getInstance()->con);
		remove.setCommandText(_TSA("DELETE FROM HangVe "
			"WHERE MaHangVe = :MaHangVe"));
		remove.Param("MaHangVe").setAsString() = _hangVe->getMaHangVe().c_str();
		remove.Execute();
		cout << "\n\t\t\t\tXoa hang ve thanh cong.\n";
	}
	catch (SAException e) {
		cout << e.ErrText().GetMultiByteChars() << endl;
	}
	delete _hangVe;
}

int TicketAirlineManagement::searchTicketClass(string maHangVe) {
	for (unsigned int i = 0; i < hangVe.size(); ++i) {
		if (maHangVe == hangVe[i]->getMaHangVe()) {
			return i;
		}
	}
	return -1;
}
void TicketAirlineManagement::addReserveTicket() {
	/*
	----- MÔ TẢ QUÁ TRÌNH ĐẶT VÉ -------
	1. Lựa chọn loại vé muốn mua (Khứ hồi, một chiều)
	2. Lựa chọn địa điểm khởi hành và địa điểm đến
	+ Xuat tren man hinh cac dia diem va lua chon
	+
	3. Lựa chọn ngày khởi hành hoặc ngày về (nếu là vé khứ hồi)
	4. Nhập số lượng vé muốn mua: (người già, người lớn, trẻ em)
	5. Lựa chọn các chuyến bay phù hợp với hạng vé
	6. Nhập thông tin tất cả khách hàng mua vé
	7. Lựa chọn hàng ghế phù hợp với hạng vé
	8. Lựa chọn hình thức thanh toán hoặc muốn đặt vé giữ chỗ
	   + Thời gian giữ chỗ sẽ là khác nhau đối với từng hạng vé
	*/
	
	string startAddress, finishAddress, startDay, check1, check2;
	int indexFlight, indexTicketClass, gheHangDoc, gheHangNgang;
	HanhKhach* _hanhKhach = new HanhKhach;
	vector<ChuyenBay*> chuyenBay;
	DatVe* datVe = new DatVe;
	bool flag = 0,flag_1 = 0, flag_2 = 0;

	cout << "\n\t\t\t\t------------------DAT VE--------------------\n";
	cout << "\n\t\t\t\tThong tin hanh khach:\n";
	cin >> *_hanhKhach;
	if (searchPassenger(_hanhKhach->getHoTen(), _hanhKhach->getCMND()) == -1) {
		addPassenger(_hanhKhach);
	}

	while (!flag) {
		// 2. Lựa chọn địa điểm khởi hành và địa điểm đến
		cout << "\n\t\t\t\tDiem khoi hanh: ";
		getline(cin, startAddress);
		cout << "\n\t\t\t\tDia diem den: ";
		getline(cin, finishAddress);

		// 3. Lựa chọn ngày khởi hành hoặc ngày về (nếu là vé khứ hồi)
		cout << "\n\t\t\t\tNgay khoi hanh - (Dinh dang dd/MM/yyyy): ";
		getline(cin, startDay);

		// 4. Lựa chọn các chuyến bay phù hợp với hạng vé
		cout << "\n\t\t\t\tThong tin cac chuyen bay chieu di:\n ";
		chuyenBay = getFlightHasRoute(startAddress, finishAddress, Date(startDay));
		showVector<ChuyenBay>(chuyenBay);
		if (!chuyenBay.size()) cout << "\t\t\t\tThong bao: Khong co chuyen bay nao phu hop voi lo trinh tren.";
		else {
			while (!flag_1) {
				cout << "\n\t\t\t\tLua chon chuyen bay chieu di: ";
				getline(cin, check1); 
				if(!regex_match(check1,regex("[0-9]+")) || atoi(check1.c_str()) > chuyenBay.size() - 1)
					cout << "\n\t\t\t\tLua chon khong hop le.";
				else {
					indexFlight = atoi(check1.c_str());
					flag_1 = 1;
				}
			}

			cout << "\n\t\t\t\tThong tin cac hang ve:\n ";
			findAllTicketClass();
			while (!flag_2) {
				cout << "\n\t\t\t\tLua chon hang ve: ";
				getline(cin, check1);
				if (!regex_match(check1, regex("[0-9]+")) || atoi(check1.c_str()) > hangVe.size() - 1)
					cout << "\n\t\t\t\tLua chon khong hop le.";
				else {
					indexTicketClass = atoi(check1.c_str());
					flag_2 = 1;
				}
			}

			cout << "\n\t\t\t\tGhe ngoi chieu di:\n ";
			getSeatOfFlight(chuyenBay[indexFlight]->getMaChuyenBay(), gheHangDoc, gheHangNgang);
			datVe->setHangGheDoc(gheHangDoc); datVe->setHangGheNgang(gheHangNgang);

			try {
				SACommand insert(&DatabaseConnection::getInstance()->con);
				insert.setCommandText(_TSA("INSERT INTO DatVe "
					"VALUES(:MaHanhKhach, :MaChuyenBay, :MaHangVe,:GheHangDoc,:GheHangNgang,:TongTien)"));
				insert.Param("MaHanhKhach").setAsLong() = _hanhKhach->getMaHanhKhach();
				insert.Param("MaChuyenBay").setAsString() = chuyenBay[indexFlight]->getMaChuyenBay().c_str();
				insert.Param("MaHangVe").setAsString() = hangVe[indexTicketClass]->getMaHangVe().c_str();
				insert.Param("GheHangDoc").setAsLong() = datVe->getHangGheDoc();
				insert.Param("GheHangNgang").setAsLong() = datVe->getHangGheNgang();
				insert.Param("TongTien").setAsLong() = 0;
				insert.Execute();

				searchFlight(startAddress, chuyenBay[indexFlight]->getMaChuyenBay())->addDatVe(datVe);
				cout << "\n\t\t\t\tDAT VE THANH CONG!";
				flag = 1;
			}
			catch (SAException e) {
				cout << e.ErrText().GetMultiByteChars() << endl;
			}
		}
	}
}

void TicketAirlineManagement::updateTicket(int maVe) {
	try {
		string startAddress, finishAddress, startDay, check1, check2;
		int indexFlight, indexTicketClass, gheHangDoc, gheHangNgang;
		vector<ChuyenBay*> chuyenBay;
		DatVe* datVe = new DatVe;
		bool flag = 0, flag_1 = 0, flag_2 = 0;

		while (!flag) {
			// 2. Lựa chọn địa điểm khởi hành và địa điểm đến
			cout << "\n\t\t\t\tDiem khoi hanh: ";
			getline(cin, startAddress);
			cout << "\n\t\t\t\tDia diem den: ";
			getline(cin, finishAddress);

			// 3. Lựa chọn ngày khởi hành hoặc ngày về (nếu là vé khứ hồi)
			cout << "\n\t\t\t\tNgay khoi hanh - (Dinh dang dd/MM/yyyy): ";
			getline(cin, startDay);

			// 4. Lựa chọn các chuyến bay phù hợp với hạng vé
			cout << "\n\t\t\t\tThong tin cac chuyen bay chieu di:\n ";
			chuyenBay = getFlightHasRoute(startAddress, finishAddress, Date(startDay));
			showVector<ChuyenBay>(chuyenBay);
			if (!chuyenBay.size()) cout << "\t\t\t\tThong bao: Khong co chuyen bay nao phu hop voi lo trinh tren.";
			else {
				while (!flag_1) {
					cout << "\n\t\t\t\tLua chon chuyen bay chieu di: ";
					getline(cin, check1);
					if (!regex_match(check1, regex("[0-9]+")) || atoi(check1.c_str()) > chuyenBay.size() - 1)
						cout << "\n\t\t\t\tLua chon khong hop le.";
					else {
						indexFlight = atoi(check1.c_str());
						flag_1 = 1;
					}
				}

				cout << "\n\t\t\t\tThong tin cac hang ve:\n ";
				showVector<HangVe>(hangVe);
				while (!flag_2) {
					cout << "\n\t\t\t\tLua chon hang ve: ";
					getline(cin, check1);
					if (!regex_match(check1, regex("[0-9]+")) || atoi(check1.c_str()) > hangVe.size() - 1)
						cout << "\n\t\t\t\tLua chon khong hop le.";
					else {
						indexTicketClass = atoi(check1.c_str());
						flag_2 = 1;
					}
				}

				cout << "\n\t\t\t\tGhe ngoi chieu di:\n ";
				getSeatOfFlight(chuyenBay[indexFlight]->getMaChuyenBay(), gheHangDoc, gheHangNgang);
				datVe->setHangGheDoc(gheHangDoc); datVe->setHangGheNgang(gheHangNgang);

				try {
					SACommand cmd(&DatabaseConnection::getInstance()->con);
					cmd.setCommandText("Update DatVe set MaChuyenBay = :MaChuyenBay, MaHangVe = :MaHangVe, GheHangDoc = :GheHangDoc, GheHangNgang = :GheHangNgang where MaVe = :maVe");
					cmd.Param("maVe").setAsLong() = maVe;
					cmd.Param("MaChuyenBay").setAsString() = chuyenBay[indexFlight]->getMaChuyenBay().c_str();
					cmd.Param("MaHangVe").setAsString() = hangVe[indexTicketClass]->getMaHangVe().c_str();
					cmd.Param("GheHangDoc").setAsLong() = datVe->getHangGheDoc();
					cmd.Param("GheHangNgang").setAsLong() = datVe->getHangGheNgang();
					cmd.Execute();
					cout << "\n\t\t\t\tDoi ve thanh cong.\n";
					flag = 1;
				}
				catch (SAException e) {
					cout << e.ErrText().GetMultiByteChars() << endl;
				}
			}
		}
	}
	catch (SAException e) {
			cout << e.ErrText().GetMultiByteChars() << endl;
	}
}

void TicketAirlineManagement::searchReserveTicket(int maVe) {
	try {
		bool flag = 0;
		SACommand cmd(&DatabaseConnection::getInstance()->con);
		cmd.setCommandText(_TSA("Select * from DatVe where MaVe = :maVe"));
		cmd.Param("maVe").setAsLong() = maVe;
		cmd.Execute();

		while (cmd.FetchNext())
		{
			int maHanhKhach = cmd.Field("MaHanhKhach").asLong();
			cout << "\n\t\t\t\tHo ten: " << hanhKhach[searchPassenger(maHanhKhach)]->getHoTen() << endl;
			SAString maChuyenBay = cmd.Field("MaChuyenBay").asString();
			cout << "\n\t\t\t\tChuyen bay: " << string(maChuyenBay) << endl;
			SAString _hangVe = cmd.Field("MaHangVe").asString();
			cout << "\n\t\t\t\tHang ve: " << hangVe[searchTicketClass(string(_hangVe))]->getTenHangVe() << endl;
			cout << "\n\t\t\t\tGhe hang doc: " << cmd.Field("GheHangDoc").asLong() << endl;
			cout << "\n\t\t\t\tGhe hang ngang: " << cmd.Field("GheHangNgang").asLong() << endl;
			cout << "\n\t\t\t\tGia ve: " << setprecision(3) << fixed << cmd.Field("TongTien").asDouble() << endl;
			flag = 1;
		}
		if (!flag) cout << "\n\t\t\t\tMa ve khong hop le.\n";
	}
	catch (SAException e) {
		cout << e.ErrText().GetMultiByteChars() << endl;
	}
}

void TicketAirlineManagement::deleteTicket(int maVe) {
	try {
		SACommand remove(&DatabaseConnection::getInstance()->con);
		remove.setCommandText(_TSA("Delete FROM DatVe WHERE MaVe = :MaVe "));
		remove.Param("MaVe").setAsLong() = maVe;
		remove.Execute();
		cout << "\n\t\t\t\tHuy ve thanh cong.\n";
	}
	catch (SAException e) {
		cout << e.ErrText().GetMultiByteChars() << endl;
	}
}

int TicketAirlineManagement::searchAirPortCode(string maSanBay)
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

int TicketAirlineManagement::searchAirCraftCode(string soHieuMayBay) {
	for (unsigned int i = 0; i < mayBay.size(); ++i)
	{
		if (soHieuMayBay == mayBay[i]->getSoHieuMayBay())
		{
			return i;
		}
	}
	return -1;
}

int TicketAirlineManagement::searchPassenger(string hoTen, string CMND)
{
	for (unsigned int i = 0; i < hanhKhach.size(); ++i) {
		if (hoTen == hanhKhach[i]->getHoTen() && CMND == hanhKhach[i]->getCMND()) {
			return i;
		}
	}
	return -1;
}

int TicketAirlineManagement::searchPassenger(int maHanhKhach) {
	for (unsigned int i = 0; i < hanhKhach.size(); ++i) {
		if (hanhKhach[i]->getMaHanhKhach() == maHanhKhach) {
			return i;
		}
	}
	return -1;
}

vector<ChuyenBay*> TicketAirlineManagement::getFlightHasRoute(string diaDiemDi, string diaDiemDen, Date ngayKhoiHanh) {
	vector<ChuyenBay*> result;
	string ngayKH = to_string(ngayKhoiHanh.getYear()) + "-" + to_string(ngayKhoiHanh.getMonth()) + "-" + to_string(ngayKhoiHanh.getDay());
	try {
		SACommand cmd(&DatabaseConnection::getInstance()->con);
		cmd.setCommandText(_TSA("select ChuyenBay.MaChuyenBay as MaCB,SanBayDi.MaSanBay as MaSB "
			"from ChuyenBay "
			"inner join SanBay as SanBayDi on SanBayDi.MaSanBay = ChuyenBay.MaSanBayDi "
			"inner join SanBay as SanBayDen on SanBayDen.MaSanBay = ChuyenBay.MaSanBayDen "
			"where SanBayDi.ThanhPho = :diaDiemDi and SanBayDen.ThanhPho = :diaDiemDen "
			"and CAST(ChuyenBay.NgayGioBay as DATE) = :ngayKhoiHanh"));
		cmd.Param("diaDiemDi").setAsString() = diaDiemDi.c_str();
		cmd.Param("diaDiemDen").setAsString() = diaDiemDen.c_str();
		cmd.Param("ngayKhoiHanh").setAsString() = ngayKH.c_str();
		cmd.Execute();
		while (cmd.FetchNext()) {
			SAString maChuyenBay = cmd.Field("MaCB").asString();
			SAString maSanBay = cmd.Field("MaSB").asString();
			int pos = searchAirPortCode(string(maSanBay));
			vector<ChuyenBay*> temp = sanBay[pos]->getLeaveFlight();
			for (unsigned int i = 0; i < temp.size(); ++i) {
				if (!temp[i]->getMaChuyenBay().compare(string(maChuyenBay))) result.push_back(temp[i]);
			}
		}
	}
	catch (SAException e) {
		cout << e.ErrText().GetMultiByteChars() << endl;
	}
	return result;
}

void TicketAirlineManagement::getSeatOfFlight(string maChuyenBay, int& _gheHangDoc, int& _gheHangNgang) {
	int soGhe = 0, row = 0, col = 0;
	string check1, check2;
	string** seat;
	bool flag = 0, flag1 = 0;
	try {
		SACommand cmd(&DatabaseConnection::getInstance()->con);
		cmd.setCommandText(_TSA("select SoGhe "
			"from ChuyenBay "
			"inner join MayBay on ChuyenBay.SoHieuMayBay = MayBay.SoHieuMayBay "
			"where MaChuyenBay = :maChuyenBay"));
		cmd.Param("maChuyenBay").setAsString() = maChuyenBay.c_str();
		cmd.Execute();
		while (cmd.FetchNext()) {
			soGhe = cmd.Field("SoGhe").asLong();
		}

		if (soGhe == 0) throw string("\n\t\t\t\tChuyen bay khong hop le");

		row = soGhe % 10 == 0 ? soGhe / 10 : soGhe / 10 + 1;
		col = 10;
		seat = new string * [row + 1];
		for (int i = 0; i <= row; ++i) seat[i] = new string[col + 1];

		for (int i = 0; i <= row; ++i) {
			int colm;
			if (i == row && soGhe % 10) colm = soGhe % 10;
			else colm = col;
			for (int j = 0; j <= colm; ++j) {
				if (i == 0) seat[i][j] = to_string(j);
				else if (j == 0) seat[i][j] = to_string(i);
				else seat[i][j] = "*";
			}
		}

		SACommand select(&DatabaseConnection::getInstance()->con);
		select.setCommandText(_TSA("select * from DatVe where MaChuyenBay = :maChuyenBay"));
		select.Param("maChuyenBay").setAsString() = maChuyenBay.c_str();
		select.Execute();

		while (select.FetchNext())
		{
			SAString maHangVe = select.Field("MaHangVe").asString();
			int gheHangDoc = select.Field("GheHangDoc").asLong();
			int gheHangNgang = select.Field("GheHangNgang").asLong();
			seat[gheHangDoc][gheHangNgang] = 'X';
		}

		for (int i = 0; i <= row; ++i) {
			cout << "\t\t\t\t";
			for (int j = 0; j <= col; ++j) {
				cout << setw(2) << seat[i][j] << " ";
			}
			cout << "\n\n";
		}
		cout << "\n\t\t\t\t'X': ghe da duoc dat\t\t'*': ghe con trong";

		while (!flag) {
			cout << "\n\t\t\t\tGhe ngang: "; getline(cin, check1);
			cout << "\n\t\t\t\tGhe doc: "; getline(cin, check2);
			if (!regex_match(check1, regex("[0-9]+"))) {
				cout << "\n\t\t\t\tGhe hang ngang khong le.";
			}
			else if (!regex_match(check2, regex("[0-9]+"))) {
				cout << "\n\t\t\t\tGhe hang doc khong le.";
			}
			else {
				_gheHangNgang = atoi(check1.c_str());
				_gheHangDoc = atoi(check2.c_str());
				if (_gheHangNgang < 0 || _gheHangNgang > row) cout << "\n\t\t\t\tGhe hang ngang khong he le.";
				else if (_gheHangDoc < 0 || _gheHangDoc > col) cout << "\n\t\t\t\tGhe hang doc khong he le.";
				else if (_gheHangNgang == row && soGhe % 10 && soGhe % 10 < _gheHangNgang) cout << "\n\t\t\t\tGhe hang ngang khong he le.";
				else if (seat[_gheHangNgang][_gheHangDoc] == "X") cout << "\n\t\t\t\tGhe da duoc dat";
				else flag = 1;
			}
		}
		
	}
	catch (string e) {
		cout << e << endl;
	}
	catch (SAException e) {
		cout << e.ErrText().GetMultiByteChars() << endl;
	}
	catch (...) {
		cout << "Loi";
	}
}


int TicketAirlineManagement::searchAirPortCodeHasCity(string city) {
	for (unsigned int i = 0; i < sanBay.size(); ++i) {
		if (!sanBay[i]->getThanhPho().compare(city)) return i;
	}
	return -1;
}

ChuyenBay* TicketAirlineManagement::searchFlight(string thanhPho, string maChuyenBay) {
	for (unsigned int i = 0; i < sanBay.size(); ++i) {
		if (!sanBay[i]->getThanhPho().compare(thanhPho)) {
			vector<ChuyenBay*> temp = sanBay[i]->getLeaveFlight();
			for (unsigned int j = 0; j < temp.size(); ++j) {
				if (temp[j]->getMaChuyenBay().compare(maChuyenBay)) {
					ChuyenBay* _chuyenBay = temp[j];
					return _chuyenBay;
				}
			}
		}
	}
	return nullptr;
}

template<class T>
void TicketAirlineManagement::showVector(vector<T*> t) {
	int size = t.size();
	for (int i = 0; i < size; ++i) {
		cout << "\t" << i << " " << *t[i] << endl;
	}
}

void TicketAirlineManagement::quickSortPassenger(int left, int right, bool (TicketAirlineManagement::*temp)(string,string)) {
	if (left <= right)
	{
		// Create a Key/Pivot Element
		string key = hanhKhach[(left + right) / 2]->getHoTen();

		// Create temp Variables to loop through array
		int i = left;
		int j = right;

		while (i <= j)
		{
			while ((this->*temp)(hanhKhach[i]->getHoTen(),key))
				i++;
			while (!(this->*temp)(hanhKhach[j]->getHoTen(), key))
				j--;

			if (i <= j)
			{
				HanhKhach* temp1 = hanhKhach[i];
				HanhKhach* temp2 = hanhKhach[j];
				hanhKhach[i] = temp2;
				hanhKhach[j] = temp1;
			}
			i++;
			j--;
		}

		// Recursion to the smaller partition in the array after sorted above

		if (left < j)
			quickSortPassenger(left, j,temp);
		if (right > i)
			quickSortPassenger(i, right,temp);
	}
}


bool TicketAirlineManagement::downCustomers(string s1, string s2) {
	return s1.compare(s2) > 0 ? 1 : 0;
}

bool TicketAirlineManagement::upCustomers(string s1, string s2) {
	return s1.compare(s2) > 0 ? 0 : 1;
}