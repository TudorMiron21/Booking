#include "CFactory_unitate_cazare.h"

IUnitate_Cazare* CFactory_unitate_cazare::create_Unitate_cazare(IUnitate_Cazare::type_cazare cazare, string Nume, int Clasificare, set<type_masa> mese)
{
    IUnitate_Cazare* obj = nullptr;

    if (cazare == IUnitate_Cazare::Hotel)
        return new CHotel(Nume, Clasificare, mese);
    else
        if (cazare == IUnitate_Cazare::Complex_apartamente)
            return new CComplex_Apartamente(Nume, Clasificare, mese);
        else
            if (cazare == IUnitate_Cazare::Complex_vile)
                return new CComplex_Vile(Nume, Clasificare, mese);
    return obj;

}
