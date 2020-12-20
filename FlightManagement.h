#pragma once
#include "SanBay.h"
#include "MayBay.h"
#include "ChuyenBay.h"
#include "HangVe.h"
#include "HanhKhach.h"
#include <set>
#include <utility>

class FlightManagement
{
private:
	vector<SanBay*> sanBay;
	vector<MayBay*> mayBay;
	vector<HangVe*> hangVe;
	vector<HanhKhach*> hanhKhach;
public:
	void selectFlight();
	void selectAirCraft();
	void selectAirPort();

	void selectPassenger();
	void addPassenger();

	void selectTicketClass();

	/*void addReserveTicket();*/

	void selectPayment();
	void selectReserveTicket();

	int searchAirPortCode(string);
	int searchAirCraftCode(string);
	int searchPassenger(string);

	//unordered_map<ChuyenBay*,int> searchFlightArrival(string diaDiemDen,Date ngayKhoiHanh);
	unordered_map<ChuyenBay*, int> searchFlightHasAddress(string diaDiemDi, string diaDiemDen, Date ngayGioBay);

	set<string> selectCity();
	void read();
};

