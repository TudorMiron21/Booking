#pragma once
#include "CUnitate_Cazare.h"
#include"CVila.h"
class CComplex_Vile :
    public CUnitate_Cazare
{

    vector<CVila> Vile;
    int nr_vile;

public:
    CComplex_Vile(string nume, int clasificare, set<type_masa> mese) :CUnitate_Cazare(nume, clasificare, mese) { nr_vile = 0; CVila::get_nr() = 0; CApartament::get_nr() = 0; CRoom::get_nr() = 0; }
    void Add_Vila( CVila&& vila)override;
    virtual void Add_Camera(CRoom&& room)override { throw CEroare("eroare aplicatie"); }
    virtual void Add_Apartament(CApartament&&)override {throw CEroare("eroare aplicatie");
    }
    virtual type_cazare get_type_cazare()const override { return Complex_vile; }
    virtual void Get_description()override;
    virtual vector<CRoom>& get_list_camere() override{ throw CEroare("eroare aplicatie"); }
    virtual vector<CApartament>& get_list_apartamente()override { throw CEroare("eroare aplicatie"); }
    virtual vector<CVila>& get_list_vile() override { return Vile; }
    virtual int get_max_gap()override;

};

