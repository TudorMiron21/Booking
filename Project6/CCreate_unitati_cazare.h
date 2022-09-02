#pragma once
#include<iostream>
#include<vector>
#include"IUnitate_Cazare.h"
#include"CFactory_unitate_cazare.h"
using namespace std;
class CCreate_unitati_cazare
{
	static CCreate_unitati_cazare* instance;
	vector<IUnitate_Cazare*> list_unitati_cazare;
	CCreate_unitati_cazare(){}

public:

	CCreate_unitati_cazare(const CCreate_unitati_cazare&) = delete;
	void operator=(const CCreate_unitati_cazare&) = delete;
	static CCreate_unitati_cazare& get_instance();
	vector<IUnitate_Cazare*>& get_list() { return list_unitati_cazare; }
	vector<IUnitate_Cazare*> get_list_ro()const { return list_unitati_cazare; }
	void Create_list();
	void Add_unitate_cazare(IUnitate_Cazare*& cazare);
	void print();
	void sort_list_cazari();
};

