#pragma once

#include<vector>
class CAn
{
	std::vector<int> an;
	int max_size;

public:

	CAn() { max_size = 12; }
	CAn Add_luna(int size);
	std::vector<int>& get_an() { return an; }
};

