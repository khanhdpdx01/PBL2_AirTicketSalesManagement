#ifndef _MAYBAY_H
#define _MAYBAY_H

#include <SQLAPI.h>
#include "DatabaseConnection.h"
#include "ChuyenBay.h"
using namespace std;

class MayBay
{
private:
	string soHieuMayBay;
	string hangKhaiThac;
	int soGhe;
	vector<ChuyenBay *> chuyenBay;

public:
	MayBay(string = "", string = "", int = 0);
	string getSoHieuMayBay();
	void setSoHieuMayBay(string);

	string getHangKhaiThac();
	void setHangKhaiThac(string);

	int getSoGhe();
	void setSoGhe(int);

	void addChuyenBay(ChuyenBay*);

	friend ostream& operator<<(ostream&, const MayBay&);
};

#endif // !_MAYBAY_H
