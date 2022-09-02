#pragma once
#include "IExceptie.h"
class CAlerta :
    public IExceptie
{
public:
    CAlerta(std::string mesaj) :IExceptie(mesaj, Alerta) {}
};

