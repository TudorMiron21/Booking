#pragma once
#include "ICazare.h"
#include"CData.h"
#include<list>
#include<vector>
#include<iostream>

using namespace std;
class CCazare :
    public ICazare
{
protected:

    vector<pair<CData,CData>> date_rezervate;
    bool is_disponibil;
    int nr_cazare;
    double price;
    int nr_locuri;
    
public:

    CCazare(double price, int nr_cazare, int nr_locuri) :price(price), nr_cazare(nr_cazare), is_disponibil(true), nr_locuri(nr_locuri){  }
    CCazare(){}

    bool& get_is_disponibil() { return is_disponibil; }
    const double& get_price() { return price; }
    int& get_nr_locuri() { return nr_locuri; }
    int& get_nr_cazare() { return nr_cazare; }
    vector<pair<CData, CData>>& get_date_rezervate() { return date_rezervate; }
    pair<CData, CData> get_maxim_checkout();
    pair<CData, CData> get_minim_checkin();
    int get_year_difference() { return 1 + this->get_maxim_checkout().second.get_an() - get_minim_checkin().first.get_an(); }
};

