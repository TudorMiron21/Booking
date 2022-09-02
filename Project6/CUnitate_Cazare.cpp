#include"CUnitate_Cazare.h"

CUnitate_Cazare::CUnitate_Cazare(string nume, int clasificare, set<type_masa> mese):Nume(nume),Clasificare(clasificare),indice_popularitate(0)
{
	for (auto i : mese)
		Mese.insert(i);
}

void CUnitate_Cazare::Add_recenzie(string recenzie)
{
	Recenzii.push_back(recenzie);
}

void CUnitate_Cazare::print_recenzii()
{
	cout << endl << "Unitatea de cazare " << this->Nume << " are urmatoarele recenzii:" << endl;
	for (auto i : Recenzii)
		cout << i << endl;
}
