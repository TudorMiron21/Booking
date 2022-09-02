#pragma once
#include<vector>
#include"COras.h"
#include"CCreate_unitati_cazare.h"
class CCreate_orase
{
	static CCreate_orase* instance;
	vector<COras*> list_orase;
	CCreate_orase(){}

public:

	static CCreate_orase& get_instance();
	CCreate_orase(const CCreate_orase&) = delete;
	void operator=(const CCreate_orase&) = delete;
	vector<COras*>& get_list_orase() { return list_orase; }
	void create_orase();

};

