#pragma once
#include"IUnitate_Cazare.h"
#include"CComplex_Apartamente.h"
#include"CComplex_Vile.h"
#include"CHotel.h"
class CFactory_unitate_cazare
{
public:

	static IUnitate_Cazare* create_Unitate_cazare(IUnitate_Cazare::type_cazare cazare, string Nume, int Clasificare, set<type_masa> mese);
};

