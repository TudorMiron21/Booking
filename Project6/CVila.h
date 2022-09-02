#pragma once
#include "CCazare.h"
#include"CApartament.h"
using namespace std;
class CVila :
    public CCazare
{
    static int nr;
    list<CApartament> etaje;
    int nr_etaje;

public:

    CVila(int price) :CCazare(price, ++nr, 0) { nr_etaje = 0; }
    CVila(const CVila& obj);
    CVila(CVila&& obj);
    static int& get_nr() { return nr; }
    CVila Add_apartment(CApartament&& apartament);
    virtual void print_cazare()override;
    list<CApartament>& get_list_apartamente() { return etaje; }
    
};

