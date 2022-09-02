#include "CRoom.h"

int CRoom::nr = 0;

CRoom::CRoom(int nr_locuri):CCazare(0,++nr,nr_locuri){}

CRoom::CRoom(int nr_locuri, int price) :
	CCazare(price, ++nr, nr_locuri)
	{}

CRoom::CRoom(CRoom && room)
{
	//cout << "move Room" << endl;
	this->is_disponibil = room.is_disponibil;
	this->nr_cazare = room.nr_cazare;
	this->price = room.price;
	this->nr_locuri = room.nr_locuri;
	
	room.is_disponibil = false;
	room.nr_cazare = -1;
	room.nr_locuri = -1;
	room.price = -1;
}

CRoom::CRoom(const CRoom& room)
{
	//cout << "copy Room" << endl;
	this->is_disponibil = room.is_disponibil;
	this->nr_cazare = room.nr_cazare;
	this->price = room.price;
	this->nr_locuri = room.nr_locuri;
}

void CRoom::print_cazare()
{
	cout << "\tCamera " << this->nr_cazare << " are " << this->nr_locuri << " de locuri";
	if (this->price)
		cout << ", iar pretul este " << price<<" lei";
	if (date_rezervate.size())
	{
		cout << ": perioade rezervate  ";
		for (const auto& i : date_rezervate)
			cout << i.first.stringify_data() << "--->" << i.second.stringify_data() << "  ";
	}
	cout << endl;
}
