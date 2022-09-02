#pragma once
#include<iostream>
#include"CAn.h"
#include"CData.h"
#include<vector>
using namespace std;
class CCreate_time
{
	static CCreate_time* instance;
	CAn an;
	static vector<day> week;
	CCreate_time(){}

public:

	static CCreate_time& get_instance();
	CCreate_time(const CCreate_time&) = delete;
	void operator =(const CCreate_time&) = delete;
	
	static void Create_week();
	void Create_an();
	CAn& get_an() { return an; }
	CData Get_date_from_time(time_t timp);
	time_t Get_time_from_date(const CData& date);

};

