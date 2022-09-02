#include "COras.h"

void COras::Add_cazare_in_oras(IUnitate_Cazare*& obj)
{
	Cazari_list.push_back(obj);
	obj = nullptr;
}

void COras::sort_list_cazari()
{
	auto lambda = [](IUnitate_Cazare*& a, IUnitate_Cazare*& b) {return a->get_indice_popularitate() > b->get_indice_popularitate(); };
	Cazari_list.sort(lambda);
}

void COras::print_oras()
{
	cout << "Orasul " << this->Nume << " are urmatoarele unitati de cazare:" << endl;
	for (const auto& i : Cazari_list)
		i->Get_description();
}
