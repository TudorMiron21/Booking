#include "CCreate_unitati_cazare.h"
#include<algorithm>

CCreate_unitati_cazare* CCreate_unitati_cazare::instance = nullptr;

CCreate_unitati_cazare& CCreate_unitati_cazare::get_instance()
{
	if (instance == nullptr)
		instance = new CCreate_unitati_cazare();
	return *instance;
}

void CCreate_unitati_cazare::Create_list()
{

	////lista de hoteluri
	
	list_unitati_cazare.push_back(CFactory_unitate_cazare::create_Unitate_cazare(IUnitate_Cazare::Hotel, "Balada", 3, { mic_dejun,pranz }));
	list_unitati_cazare.back()->Add_Camera(CRoom(4, 120));
	list_unitati_cazare.back()->Add_Camera(CRoom(3, 90));
	list_unitati_cazare.back()->Add_Camera(CRoom(2, 60));

	list_unitati_cazare.push_back(CFactory_unitate_cazare::create_Unitate_cazare(IUnitate_Cazare::Hotel, "Bucovina",4 , { pranz }));
	list_unitati_cazare.back()->Add_Camera(CRoom(4, 300));
	list_unitati_cazare.back()->Add_Camera(CRoom(2, 200));
	list_unitati_cazare.back()->Add_Camera(CRoom(2, 4));

	////lista de hoteluri

	////lista de Complexe de apartamente
	list_unitati_cazare.push_back(CFactory_unitate_cazare::create_Unitate_cazare(IUnitate_Cazare::Complex_apartamente, "Arinis", 4, { cina }));
	list_unitati_cazare.back()->Add_Apartament(CApartament(600).Add_camera(CRoom(2)).Add_camera(CRoom(3)).Add_camera(CRoom(1)));

	list_unitati_cazare.push_back(CFactory_unitate_cazare::create_Unitate_cazare(IUnitate_Cazare::Complex_apartamente, "Humor", 5, { cina }));
	list_unitati_cazare.back()->Add_Apartament(CApartament(800).Add_camera(CRoom(4)).Add_camera(CRoom(3)));
	////lista de Complexe de apartamente

	////lista de Complexe de vile

	list_unitati_cazare.push_back(CFactory_unitate_cazare::create_Unitate_cazare(IUnitate_Cazare::Complex_vile, "Vile Deluxe", 5, { mic_dejun,pranz,cina }));
	list_unitati_cazare.back()->Add_Vila(CVila(2000).Add_apartment(CApartament().Add_camera(CRoom(6)).Add_camera(CRoom(2))).Add_apartment(CApartament().Add_camera(CRoom(3)).Add_camera(CRoom(3))));

	list_unitati_cazare.push_back(CFactory_unitate_cazare::create_Unitate_cazare(IUnitate_Cazare::Complex_vile, "Vile OK", 3, { }));
	list_unitati_cazare.back()->Add_Vila(CVila(1000).Add_apartment(CApartament().Add_camera(CRoom(4)).Add_camera(CRoom(2))).Add_apartment(CApartament().Add_camera(CRoom(2)).Add_camera(CRoom(2))));
}

void CCreate_unitati_cazare::Add_unitate_cazare(IUnitate_Cazare*& cazare)
{
	list_unitati_cazare.push_back(cazare);
}

void CCreate_unitati_cazare::print()
{
	for (const auto& i : list_unitati_cazare)
		i->Get_description();
}

void CCreate_unitati_cazare::sort_list_cazari()
{
	auto lambda = [](IUnitate_Cazare*& a, IUnitate_Cazare*& b) {return a->get_indice_popularitate() > b->get_indice_popularitate(); };
	sort(list_unitati_cazare.begin(), list_unitati_cazare.end(),lambda);
}
