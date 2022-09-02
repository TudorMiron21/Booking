#pragma once
#include "CCazare.h"
#include"CRoom.h"
using namespace std;
class CApartament :
    public CCazare
{
    static int nr;
    list<CRoom> camere;
    int nr_camere;
public:

    CApartament(int price) :CCazare(price, ++nr, 0) { nr_camere = 0; }
    CApartament() :CCazare(0, ++nr, 0) { nr_camere = 0; }
    CApartament(const CApartament&);
    CApartament(CApartament&&);
    static int& get_nr() { return nr; }
    CApartament Add_camera(CRoom && room);
    virtual void print_cazare()override;
};

