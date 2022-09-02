#pragma once

#include "CUnitate_Cazare.h"
#include"CApartament.h"

class CComplex_Apartamente :
    public CUnitate_Cazare
{
    vector<CApartament> Apartamente;
    int nr_apartamenete;

public:
    CComplex_Apartamente(string nume, int clasificare, set<type_masa> mese) :CUnitate_Cazare(nume, clasificare, mese) { nr_apartamenete = 0; CApartament::get_nr() = 0; CRoom::get_nr() = 0; }
    virtual void Add_Apartament( CApartament&& apartament)override;
    virtual void Add_Camera(CRoom&&room)override { throw CEroare("eroare aplicatie"); }
    virtual void Add_Vila(CVila&&)override { throw CEroare("eroare aplicatie"); }
    virtual type_cazare get_type_cazare()const override { return Complex_apartamente; }
    virtual void Get_description()override;
    virtual vector<CRoom>& get_list_camere()override { throw CEroare("eroare aplicatie"); };
    virtual vector<CApartament>& get_list_apartamente()override { return Apartamente; };
    virtual vector<CVila>& get_list_vile() override { throw CEroare("eroare aplicatie"); };

    virtual int get_max_gap()override;
};


