#pragma once
#include "CUnitate_Cazare.h"
#include"CRoom.h"

using namespace std;
class CHotel :
    public CUnitate_Cazare
{
    vector<CRoom> Camere;
    int nr_camere;

public:

    CHotel(string Nume, int Clasificare, set<type_masa> mese) :CUnitate_Cazare(Nume, Clasificare, mese) { nr_camere = 0; CRoom::get_nr() = 0; }
    virtual void Add_Camera(CRoom&& room)override;
    virtual void Add_Apartament( CApartament&&)override { throw CEroare("eroare aplicatie"); }
    virtual void Add_Vila(CVila&&)override { throw CEroare("eroare aplicatie"); }
    virtual type_cazare get_type_cazare()const override { return Hotel; }
    virtual void Get_description()override;
    virtual vector<CRoom>& get_list_camere()override { return Camere; }
    virtual vector<CApartament>& get_list_apartamente()override { throw CEroare("eroare aplicatie"); };
    virtual vector<CVila>& get_list_vile() override { throw CEroare("eroare aplicatie"); };

    virtual int get_max_gap()override;

};

