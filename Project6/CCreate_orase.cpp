#include "CCreate_orase.h"

CCreate_orase* CCreate_orase::instance = nullptr;

CCreate_orase& CCreate_orase::get_instance()
{
	if (instance == nullptr)
		instance = new CCreate_orase();
	return *instance;
}

void CCreate_orase::create_orase()
{
	list_orase.push_back(new COras("Suceava"));
	list_orase.back()->Add_cazare_in_oras(CCreate_unitati_cazare::get_instance().get_list_ro()[1]);
	list_orase.back()->Add_cazare_in_oras(CCreate_unitati_cazare::get_instance().get_list_ro()[2]);



	list_orase.push_back(new COras("Brasov"));
	list_orase.back()->Add_cazare_in_oras(CCreate_unitati_cazare::get_instance().get_list_ro()[0]);
	list_orase.back()->Add_cazare_in_oras(CCreate_unitati_cazare::get_instance().get_list_ro()[4]);


	list_orase.push_back(new COras("Bucuresti"));
	list_orase.back()->Add_cazare_in_oras(CCreate_unitati_cazare::get_instance().get_list_ro()[3]);
	list_orase.back()->Add_cazare_in_oras(CCreate_unitati_cazare::get_instance().get_list_ro()[5]);
	
}
