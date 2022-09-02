#pragma once
#include<iostream>
using namespace std;

enum day { Luni=1, Marti=2, Miercuri=3, Joi=4, Vineri=5, Sambata=6, Duminica=7 };

class CData
{
	int zi, luna, an;
	day name_zi;

public:

	CData(int zi,int luna ,int an,day name_zi):zi(zi),luna(luna),an(an),name_zi(name_zi) {}
	CData(int zi, int luna, int an) :zi(zi), luna(luna), an(an) {}
	CData():zi(0), luna(0), an(0) {}
	string stringify_data()const;
	int make_comparable_date()const;
	int& get_zi() { return zi; }
	int& get_luna() { return luna;}
	int& get_an() { return an; }
	day& get_name_zi() { return name_zi; }
	int get_zi_const()const  { return zi; }
	int get_luna_const()const { return luna; }
	int get_an_const()const { return an; }
	day get_name_zi_const()const { return name_zi; }
	bool operator !=(const CData& obj);
	bool operator<(const CData& obj);
	bool operator>=(const CData& obj);
	friend ostream& operator<<(ostream& out, const CData& date);
};

