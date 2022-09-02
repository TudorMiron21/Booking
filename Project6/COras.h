#pragma once
#include"IUnitate_Cazare.h"
#include<list>
#include<iostream>
using namespace std;

class COras
{
	string Nume;
	list<IUnitate_Cazare*> Cazari_list;
	int indice_popularitate;

public:

	COras(string Nume):Nume(Nume),indice_popularitate(0) {}
	void Add_cazare_in_oras( IUnitate_Cazare*& obj);
	int& get_indice_popularitate() { return indice_popularitate; }
	list<IUnitate_Cazare*>& get_Cazari_list() { return Cazari_list; }
	void sort_list_cazari();
	void print_oras();
	string get_nume_oras()const { return Nume; }
};

