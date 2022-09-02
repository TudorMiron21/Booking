#include "CApartament.h"

int CApartament::nr = 0;

CApartament::CApartament(const CApartament& obj)
{
	//cout << "copy Apartament" << endl;
	this->is_disponibil = obj.is_disponibil;
	this->nr_camere = obj.nr_camere;
	this->nr_cazare = obj.nr_cazare;
	this->nr_locuri = obj.nr_locuri;
	this->price =obj.price;

	for (const auto& i : obj.camere)
		camere.push_back(move(i));

}

CApartament::CApartament(CApartament&& obj)
{
	//cout << "move Apartament" << endl;
	this->is_disponibil = obj.is_disponibil;
	this->nr_camere = obj.nr_camere;
	this->nr_cazare = obj.nr_cazare;
	this->nr_locuri = obj.nr_locuri;
	this->price = obj.price;

	for ( auto& i : obj.camere)
		camere.push_back(move(i));

	obj.is_disponibil = false;
	obj.nr_camere = -1;
	obj.nr_cazare = -1;
	obj.nr_locuri = -1;
	obj.price = -1;

	obj.camere.clear();
}

CApartament CApartament::Add_camera(CRoom&& room)
{
	camere.push_back(room);
	nr_locuri += camere.back().get_nr_locuri();
	nr_camere++;
	return *this;
}

void CApartament::print_cazare()
{
	cout << "Apartamentul " << this->nr_cazare << " are " << this->nr_camere<<" camere";
	if (this->price)
		cout << " , iar pretul este " << price<<" lei";
	if (date_rezervate.size())
	{
		cout << ": perioade rezervate ";
		for (const auto& i : date_rezervate)
			cout << i.first.stringify_data() << "--->" << i.second.stringify_data() << "  ";
	}
	cout << endl;
	for (auto& i : camere)
	{
		cout << "\t\t";
		i.print_cazare();
	}
}
