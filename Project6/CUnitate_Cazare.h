#pragma once
#include"IUnitate_Cazare.h"
#include"CEroare.h"

#include<iostream>
#include<set>
#include<list>

using namespace std;
enum type_masa { mic_dejun, pranz, cina };


class CUnitate_Cazare :
	public IUnitate_Cazare
{

protected:
	
	string Nume;
	int Clasificare;
	set<type_masa> Mese;
	list<string> Recenzii;
	int indice_popularitate;

public:
	
	CUnitate_Cazare(string nume, int clasificare, set<type_masa> mese);
	virtual string Get_nume_cazare()const override { return Nume; }
	virtual void Add_recenzie(string recenzie)override;
	virtual int& get_indice_popularitate()override { return indice_popularitate; }
	void print_recenzii();
	
};

