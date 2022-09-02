#include"CMenu.h"
#include<iostream>

int main(){

	CAdministrator& instance = CAdministrator::get_instance();
	instance.Add_orase();
	try {

		CMenu::menu();
	}
	catch (CEroare& exceptie) { cout << "eroare la nivelul aplicatiei a fost prinsa cu cod " << exceptie.get_type_excpetie() << endl; }
	catch (CAlerta& exceptie) { cout << "eroare la nivelul inregistrarii utilizatorilor a fost prinsa cu cod " << exceptie.get_type_excpetie()<<endl; }
	catch (CRezervare& exceptie) { cout << "eroare la nivelul rezervarii a fost prinsa cu cod" << exceptie.get_type_excpetie(); }
	catch (IExceptie& exceptie) { cout << "eroare a fost prinsa cu cod" << exceptie.get_type_excpetie(); }
	catch (...) { cout << "eroare generala a fost prinsa"; }
}