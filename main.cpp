//#include <iostream>  // for printf
//#include <SQLAPI.h> // main SQLAPI++ header
//using namespace std;
//int main() {
//    SAConnection con; // connection object to connect to database
//
//    try {
//        con.Connect(_TSA("FlightManagement"), _TSA("sa"), _TSA("123"), SA_SQLServer_Client);
//        cout << "We are connected!\n";
//
//        /*
//        The example of selecting
//        */
//        SACommand select(&con, _TSA("SELECT * FROM HangVe")); // create command object
//        SACommand select(&con, _TSA("select * from hanhkhach"));
//        select.Execute();
//
//        while (select.FetchNext()) {
//            SAString MaHV = select.Field("MaHangVe").asString();
//            SAString TenHV = select.Field("TenHangVe").asString();
//            double TiLeHV = select.Field("TiLeHangVe").asDouble();
//            cout << (string)MaHV << (string)TenHV << TiLeHV << endl;
//        }
//
//        while (select.FetchNext()) {
//            SAString MaHK = select.Field("MaHanhKhach").asString();
//            SAString TenHK = select.Field("HoTen").asString();
//            SAString CMND = select.Field("CMND").asString();
//            bool GT = select.Field("GioiTinh").asBool();
//            SAString SDT = select.Field("SoDienThoai").asString();
//            SAString Email = select.Field("Email").asString();
//            SAString MaSoThe = select.Field("MaSoThe").asString();
//            cout << (string)MaHK << (string)TenHK << (string)CMND <<  GT <<"\t" << (string)SDT << "\t" << (string)Email << (string)MaSoThe << endl;
//        }
//
//
//        /*
//        The example of inserting
//        */
//        SACommand insert(&con, _TSA("INSERT INTO HanhKhach VALUES (:1,:2,:3,:4,:5,:6,:7)"));
//
//        /*insert << _TSA("HK0011") << _TSA("Le Thi Li") << _TSA("206232353") << _TSA("False") << _TSA("0265253256") << _TSA("leli@gmail.com") << _TSA("NULL");*/
//        insert.Param(1).setAsString() ;
//        insert.Execute();
//
//        /*
//        The example of updating
//        */
//        SACommand cmd(
//            &con,
//            _TSA("UPDATE HanhKhach SET HoTen = :hoten WHERE MaHanhKhach = :mahk"));
//        cmd.Param(_TSA("hoten")).setAsString() = "Roy Mann";
//        cmd.Param(_TSA("mahk")).setAsString() = "HK0010";
//        cmd.Execute();
//
//
//        /*
//        The example of deleting
//        */
//        SACommand cmd(
//            &con,
//            _TSA("DELETE FROM HanhKhach WHERE MaHanhKhach = :mahk"));
//        cmd.Param(_TSA("mahk")).setAsString() = "HK0011";
//        cmd.Execute();
//
//        con.Commit();
//
//        con.Disconnect();
//        cout << "We are disconnected!\n";
//    }
//    catch(SAException &x) {
//        con.Rollback();
//        cout << x.ErrText().GetMultiByteChars() << endl;
//    }
//
//    return 0;
//}

#include "FlightManagement.h"
#include "MayBay.h"
#include <cstdlib>
#include <iomanip>
#include <Windows.h>

void menu();

int main()
{
	DatabaseConnection *db = DatabaseConnection::getInstance();
	
	menu();
	delete db;
	return 0;
}

void menu()
{
	FlightManagement* manage = new FlightManagement;
	char choose;
	bool flag = 0;
	while (!flag)
	{
		cout <<"\n\t+++++++++++++++++++++++++++++++++++++++++\n";
		cout << "\t+         QUAN LI BAN VE MAY BAY         +\n";
		cout << "\t++++++++++++++++++++++++++++++++++++++++++\n";
		cout << "\t+                                        +\n";
		cout << "\t+  (1) - Ban ve khu hoi                  +\n";
		cout << "\t+  (2) - Ban ve mot chieu                +\n";
		cout << "\t+  (3) - Hien thi danh sach chuyen bay   +\n";
		cout << "\t+  (4) - Lap lich chuyen bay             +\n";
		cout << "\t+  (5) - Giu cho chuyen bay              +\n";
		cout << "\t+  (6) - Thong ke doanh thu              +\n";
		cout << "\t+  (7) - Thoat                           +\n";
		cout << "\t+                                        +\n";
		cout << "\t++++++++++++++++++++++++++++++++++++++++++\n";
		cout << "\n\tLua chon: ";
		cin >> choose;
		switch (choose)
		{
		case '1':
			manage->selectAirPort();
			manage->selectAirCraft();
			manage->selectFlight();
			manage->read();
			/*(new DatVe)->reserve()*/;
			break;
		case '4':
			break;
		case '5':
			manage->selectAirPort();
			break;
		case '6':
			flag = 1;
			break;
		default:
			cout << "Quy khach lua chon sai. Moi ban nhap lai: ";
			break;
		}
	}
}

/*  ChuyenBay cb;
	  vector<ChuyenBay> cbay = cb.getRoute("Da Nang", "Ho Chi Minh");

	  for (int i = 0; i < cbay.size(); ++i) {
		  cout << cbay[i];
	  }*/
	  /*MayBay* mb = new MayBay;
		mb->Select();*/

		/*DatVe* dv = new DatVe;
		  dv->reserve();*/

		  /*HangVe* hv = new HangVe;
			hv->Select();*/

			//SACommand cmd(&db->con);
			//cmd.setCommandText(_TSA("Select * from MayBay"));

			//// this instructs the library to allocate a buffer for 100 rows
			//// and, using respective native API, request data from server in pages of 100 rows
			//

			//cmd.Execute();
			//while (cmd.FetchNext())
			//{
			//	SAString SoHieuMB = cmd.Field("SoHieuMayBay").asString();
			//	SAString HangKhaiThac = cmd.Field("HangKhaiThac").asString();
			//	int SoGhe = cmd.Field("SoGhe").asShort();
			//	cout << (string)SoHieuMB << "\t" << (string)HangKhaiThac << "\t" << SoGhe << endl;
			//}
