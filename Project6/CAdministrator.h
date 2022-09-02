#pragma once
#include<iostream>
#include<list>
#include<map>
#include"COras.h"
#include"CCreate_orase.h"
#include"CCreate_unitati_cazare.h"
#include"CUser.h"
#include"CCreate_time.h"

using namespace std;

class CAdministrator
{
	static CAdministrator* instance;
	string data;
	list<COras*> lista_orase;
	list<CUser*>users;
	CData check_in_accept, check_out_accept;

	CAdministrator() { CCreate_unitati_cazare::get_instance().Create_list(); CCreate_orase::get_instance().create_orase(); CCreate_time::get_instance().Create_an();}

public:

	static CAdministrator& get_instance();

	list<COras*>& get_lista_orase() { return lista_orase; }
	CData& get_check_in_accept() { return check_in_accept; }
	CData& get_check_out_accept() { return check_out_accept; }
	void Add_orase();
	void Add_cazare(string oras, IUnitate_Cazare* unitate_cazare);
	void Add_oras(string nume_oras);
	void print_orase();
	bool search_username(string user);
	bool search_password(string pass);
	CUser* search_user(string username,string password);
	void add_user(CUser *user);
	bool accept_rezervare(string filename,CCazare *& cazare,IUnitate_Cazare * unitate_cazare);
	void sort_orase();
	void get_top_orase(int top_nr);
	void get_top_cazari(int top_nr);
	bool get_top_cazari_oras(int top_nr, string oras);
	double get_grad_ocupare(string nume_cazare);
	void get_statistici();
	int calculate_nr_days(CData Check_in, CData Check_out);
};

