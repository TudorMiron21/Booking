#pragma once
#include"CRoom.h"
#include"CApartament.h"
#include"CVila.h"
#include<vector>




class IUnitate_Cazare
{
public:
	enum type_cazare { Hotel, Complex_apartamente, Complex_vile };

	virtual string Get_nume_cazare()const = 0;

	virtual void Add_Camera( CRoom &&) = 0;
	virtual void Add_Apartament( CApartament&&) = 0;
	virtual void Add_Vila(CVila &&) = 0;


	virtual void Get_description() = 0;
	virtual type_cazare get_type_cazare()const = 0;
	virtual void Add_recenzie(string)=0;
	virtual int& get_indice_popularitate() = 0;

	virtual vector<CRoom>& get_list_camere() = 0;
	virtual vector<CApartament>& get_list_apartamente() = 0;
	virtual vector<CVila>& get_list_vile() = 0;


	virtual int get_max_gap()=0;
};

