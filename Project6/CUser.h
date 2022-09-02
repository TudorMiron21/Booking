#pragma once
#include<iostream>
using namespace std;
#include"CCreate_unitati_cazare.h"
#include"CCreate_orase.h"
#include"CData.h"

class CUser
{
	string Username;
	string Password;
	string personal_file;
	CData check_in, check_out;
	set<string> nume_cazari;
	bool is_logat;
	int nr_rezervari;
	double fidelitate;


	void choose_data(CCazare*& cazare);
	double calculate_price(CCazare*& cazare,int nr_zile);

public:

	string get_username()const { return Username; }
	string get_password()const { return Password; }
	bool &get_is_logat(){return is_logat;}
	CUser(string username,string password);
	void choose_options();
	static CUser* log_in();
	
	void lasa_recenzie(string Nume_cazare, string Recenzie);
	static CUser *create_account();
};

