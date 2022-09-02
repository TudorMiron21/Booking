#pragma once
#include"CCazare.h"
class CRoom:public CCazare 
{
	static int nr;
public:

	CRoom(int nr_locuri);
	CRoom(int nr_locuri, int price);
	CRoom(CRoom&& room);
	CRoom(const CRoom& room);
	static int& get_nr() { return nr; }
	virtual void print_cazare()override;
	
};

