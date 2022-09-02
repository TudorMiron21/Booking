#pragma once
#include "IExceptie.h"
class CEroare :
    public IExceptie
{
public:
    CEroare(std::string mesaj) :IExceptie(mesaj,Eroare) {}
};

