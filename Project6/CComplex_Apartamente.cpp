#include "CComplex_Apartamente.h"
#include"CAdministrator.h"
void CComplex_Apartamente::Add_Apartament( CApartament&& apartament)
{
	Apartamente.push_back(move(apartament));
	nr_apartamenete++;
}

void CComplex_Apartamente::Get_description()
{
	cout << endl;
	cout << "Acesta este complexul de apartamente " << this->Nume << " de " << this->Clasificare << " stele si are incluse urmatoarele mese: ";
	for (auto i : Mese)
	{
		if (i == mic_dejun)
			cout << "mic_dejun ";
		if (i == pranz)
			cout << "pranz ";
		if (i == cina)
			cout << "cina ";
	}
	cout << "\n";
	for (auto& i : Apartamente)
	{
		cout << "\t";
		i.print_cazare();
	}

	this->print_recenzii();

	cout << endl;

}

int CComplex_Apartamente::get_max_gap()
{
	CData max_global, min_global(99, 99, 9999);

	for (auto& i : Apartamente)
	{

		CData max_local, min_local(99, 99, 9999);
		for (auto& j : i.get_date_rezervate())
		{
			if (j.first < min_local)
				min_local = j.first;

			if (j.second >= max_local)
				max_local = j.second;
		}

		if (max_local >= max_global)
			max_global = max_local;

		if (min_local < min_global)
			min_global = min_local;
	}

	return CAdministrator::get_instance().calculate_nr_days(min_global, max_global);
}
