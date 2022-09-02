#define _CRT_SECURE_NO_WARNINGS
#include "CData.h"

string CData::stringify_data()const
{
	char zi[3], luna[3], an[5];
	string zi_str = _itoa(this->zi, zi, 10);
	string luna_str= _itoa(this->luna, luna, 10);
	string an_str = _itoa(this->an, an, 10);
	return zi_str + "." + luna + "." + an_str;
}

int CData::make_comparable_date()const
{

	int copy_day = zi, copy_month = luna;

	int comparable = an;

	return (comparable * 100 + copy_month) * 100 + copy_day;
}

bool CData::operator!=(const CData& obj)
{
	if (this->an != obj.an || this->luna != obj.luna || this->zi != obj.zi)
		return true;
	return false;
}

bool CData::operator<(const CData& obj)
{
	return this->make_comparable_date() < obj.make_comparable_date();
}

bool CData::operator>=(const CData& obj)
{
	return this->make_comparable_date() >= obj.make_comparable_date();
}

ostream& operator<<(ostream& out, const CData& date)
{
	out << date.name_zi<<"  " << date.zi << "/" << date.luna << "/" << date.an << endl;
	return out;
}
