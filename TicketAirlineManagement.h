#pragma once
#include "SanBay.h"
#include "MayBay.h"
#include "ChuyenBay.h"
#include "HangVe.h"
#include "HanhKhach.h"
#include <set>
#include <utility>
#include <regex>
#include <iomanip>

class TicketAirlineManagement
{
public:
	vector<SanBay*> sanBay;
	vector<MayBay*> mayBay;
	vector<HangVe*> hangVe;
	vector<HanhKhach*> hanhKhach;
public:
	void passengerManagement();
	void ticketManagement();
	void airPortManagement();
	void airCraftManagement();
	void flightManagement();
	void ticketClassManagement();

	//Passenger management
	void selectPassenger();
	void addPassenger(HanhKhach*);
	void findAllPassenger();
	void updatePassenger(HanhKhach*);
	void deletePassenger(HanhKhach*);
	int searchPassenger(string , string );
	int searchPassenger(int);
	

	// Airport management
	void selectAirPort();
	void addAirPort(SanBay*);
	void findAllAirPort();
	void updateAirPort(SanBay*);
	void deleteAirport(SanBay*);
	int searchAirPortCode(string);
	int searchAirPortCodeHasCity(string);
	/*void validateAirPortBeforeInsert(const SanBay*);*/

	//Flight management
	void selectFlight();
	void addFlight(ChuyenBay*);
	void findAllFlight();
	void updateFlight();
	void deleteFlight();
	
	//Ticket class management
	void selectTicketClass();
	void addTicketClass(HangVe*);
	void findAllTicketClass();
	void updateTicketClass(HangVe*);
	void deleteTicketClass(HangVe*);
	int searchTicketClass(string);
	/*void addTicketClass();*/

	//Reserve ticket management
	void addReserveTicket();
	void searchReserveTicket(int);
	void updateTicket(int);
	void deleteTicket(int);

	//Aircraft management
	void selectAirCraft();
	void addAirCraft(MayBay*);
	void findAllAirCraft();
	void updateAirCraft(MayBay*);
	void deleteAirCraft(MayBay*);
	int searchAirCraftCode(string);
	
	void quickSortPassenger(int , int, bool (TicketAirlineManagement::* temp)(string, string));
	ChuyenBay* searchFlight(string, string);
	vector<ChuyenBay*> getFlightHasRoute(string , string , Date );
	void getSeatOfFlight(string , int& , int& );

	template<class T>
	void showVector(vector<T*> );
	bool downCustomers(string,string);
	bool upCustomers(string,string);
};



