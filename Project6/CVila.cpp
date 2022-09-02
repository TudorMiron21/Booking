#include "CVila.h"

int CVila::nr = 0;

CVila::CVila(const CVila& obj)
{
	
	//cout << "copy Vila" << endl;
	this->is_disponibil = obj.is_disponibil;
	this->nr_cazare = obj.nr_cazare;
	this->nr_etaje = obj.nr_etaje;
	this->nr_locuri = obj.nr_locuri;
	this->price = obj.price;

	for (auto& i : obj.etaje)
		this->etaje.push_back(i);
}

CVila::CVila(CVila&& obj)
{
	//cout << "move Vila" << endl;
	this->is_disponibil = obj.is_disponibil;
	this->nr_cazare = obj.nr_cazare;
	this->nr_etaje = obj.nr_etaje;
	this->nr_locuri = obj.nr_locuri;
	this->price = obj.price;

	for ( auto& i : obj.etaje)
		this->etaje.push_back(move(i));

	obj.is_disponibil = false;
	obj.nr_cazare = -1;
	obj.nr_etaje=-1;
	obj.nr_locuri=-1;
	obj.price=-1;
	obj.etaje.clear();
}

CVila CVila::Add_apartment(CApartament&& apartament)
{
	nr_locuri += apartament.get_nr_locuri();
	etaje.push_back(apartament);
	nr_etaje++;
	return *this;
}

void CVila::print_cazare()
{
	cout << "Vila " << this->nr_cazare << " are " << this->nr_etaje << " etaje";
	if (price)
		cout << ", iar pretul este " << price<<" lei";

	if (date_rezervate.size())
	{
		cout << ": perioade rezervate ";
		for (const auto& i : date_rezervate)
			cout << i.first.stringify_data() << "--->" << i.second.stringify_data() << "  ";
	}
	cout << endl;
	for (auto& i : etaje)
	{
		cout << "\t\t";
		i.print_cazare();
	}
}
