#include "CAn.h"

CAn CAn::Add_luna(int size)
{
	if (an.size() <= 12)
		an.push_back(size);
	else
		throw "exceptie";
	return *this;
}
