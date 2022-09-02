#pragma once
#include<iostream>

enum type_exceptie{Eroare,Alerta,Rezervare};
class IExceptie
{
protected:

	std::string mesaj;
	type_exceptie type;

public:

	IExceptie(std::string mesaj, type_exceptie type):mesaj(mesaj),type(type){}
	type_exceptie get_type_excpetie()const { return type; }
};

