#pragma once
#include "IExceptie.h"
class CRezervare :
    public IExceptie
{
public:
    CRezervare(std::string mesaj) :IExceptie(mesaj,Rezervare){}
};

