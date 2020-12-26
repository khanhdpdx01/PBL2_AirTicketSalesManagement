#include "TicketAirlineManagement.h"
#include "MayBay.h"
#include <cstdlib>
#include <iomanip>
#include <Windows.h>

void menu(TicketAirlineManagement* manage);

int main()
{
	DatabaseConnection *db = DatabaseConnection::getInstance();
	
	TicketAirlineManagement* manage = new TicketAirlineManagement;
	manage->selectAirPort();
	manage->selectAirCraft();
	manage->selectFlight();
	manage->selectTicketClass();
	manage->selectPassenger();
	menu(manage);
	delete db;
	return 0;
}

void menu(TicketAirlineManagement* manage)
{
	
	char choose;
	bool flag = 0;
	while (!flag)
	{
		cout <<"\n\t\t\t\t++++++++++++++++++++++++++++++++++++++++++\n";
		cout << "\t\t\t\t+         QUAN LI BAN VE MAY BAY         +\n";
		cout << "\t\t\t\t++++++++++++++++++++++++++++++++++++++++++\n";
		cout << "\t\t\t\t+                                        +\n";
		cout << "\t\t\t\t+  (1) - Quan li khach hang              +\n";
		cout << "\t\t\t\t+  (2) - Quan li thong tin ve            +\n";
		cout << "\t\t\t\t+  (3) - Quan li san bay                 +\n";
		cout << "\t\t\t\t+  (4) - Quan li may bay                 +\n";
		cout << "\t\t\t\t+  (5) - Quan li hang ve                 +\n";
		cout << "\t\t\t\t+  (6) - Thoat                           +\n";
		cout << "\t\t\t\t+                                        +\n";
		cout << "\t\t\t\t++++++++++++++++++++++++++++++++++++++++++\n";
		cout << "\n\t\t\t\tLua chon: ";
		cin >> choose;
		switch (choose)
		{
		case '1':
			manage->passengerManagement();
			break;
		case '2':
			manage->ticketManagement();
			break;
		case '3':
			manage->airPortManagement();
			break;
		case '4':
			manage->airCraftManagement();
			break;
		/*case '5':
			manage->flightManagement();
			break;*/
		case '5':
			manage->ticketClassManagement();
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