#include "CMenu.h"
#include<string>
#include"CFactory_unitate_cazare.h"
#include"CCreate_unitati_cazare.h"
#define clear() printf("\033[H\033[J")


void CMenu::menu()
{
	
	cout << "\t\t\t\t* * * * * * * * * * * * * * * * * * * * *\n";
	cout << "\t\t\t\t*\t\t\t\t\t*\n";
	cout << "\t\t\t\t*\tBINE ATI VENIT PE SITE-UL\t*\n\t\t\t\t* \t\t MTA BOOKING\t\t*\n";
	cout << "\t\t\t\t*\t\t\t\t\t*\n";
	cout << "\t\t\t\t* * * * * * * * * * * * * * * * * * * * *\n";

	start:
	cout << "\nSunteti un utilizator sau administrator? apassati indicele aferent.\n1.User\n2.Administrator\n";
	cout << "pentru a iesi din program apasati tasta '0'\n";
	int index;
	start1:
	cin >> index;

	if (index == 1)
	{
		CMenu::user();
		goto start;
	}
	else
		if (index == 2) {

			CMenu::administrator();
			goto start;
		}
		else if(index==3)
		{
			cout << "indice inexistent. mai incercati odata\n";
			goto start1;
		}
		else
			if (!index)
				return;
			
	

}

void CMenu::user()
{
	cout << "\n******************************************\n";

 start:
	cout << "Alegeti din urmatoarele optiuni disponibile(selectati indexul):\n1.Creati un cont\n2.Autentificare in contul curent\n3.Log out\n";
	int index;
	cin >> index;
	CUser* user = nullptr;
	if (index == 1)
	{
		cout << "Acesta este modalitatea de creeare a unui cont:\n";
		user = CUser::create_account();
		goto start;
	}
	else
		if (index == 2)
		{
			cout << "Acesta este modalitatea de log in intr-un cont:\n";
			user = CUser::log_in();
			user->choose_options();
			goto start;
		}

		else

			if (index == 3)
			{
				clear();
				return;
			}
}

void CMenu::administrator()
{
	cout << "\n******************************************\n";
	start:
	cout << "Alegeti din urmatoarele optiuni disponibile:\n1.Adaugare orase\n2.Adaugare unitate de cazare\n3.Afiseaza statistici\n";
	cout << "pentru a iesi din aceasta stare a programului apasati tasta '0'\n";
	int index;

	cin >> index;

	if (index == 1)
	{
		cout << "1.Introduceti numele orasului.\n";
		string Nume_oras;
		cin.ignore();
		getline(cin, Nume_oras);
		CAdministrator::get_instance().Add_oras(Nume_oras);
		goto start;
	}
	else
		if (index == 2)
		{
			cout << "1.Care este orasul in care doriti sa adaugati unitatea de cazare?\n";

			int count = 0;
			for (const auto& i : CAdministrator::get_instance().get_lista_orase())
			{
				cout << ++count << "." << i->get_nume_oras()<<"\n";
			}
			cin.ignore();
			start1:
			cout << "introduceti numele orasului dorit\n";
			string Nume_oras;
			getline(cin, Nume_oras);
			COras* oras = nullptr;
			for (const auto& i : CAdministrator::get_instance().get_lista_orase())
			{
				if (i->get_nume_oras() == Nume_oras) {
					oras = i;
				}
			}

			if (oras == nullptr)
			{
				cout << "Acest oras nu exista in lista de orase. Introduceti alt oras\n";
				goto start1;
			}
			else
			{
				int index2;
				start2:
				cout << "2.Alegeti tipul de unitate de cazare(slectati indexul):\n1.Hotel\n2.Complex Aparatamente\n3.Complex Vile\n";
				cin >> index2;
				if (index2 == 1)
				{

					cout << "1.introduceti numele hotelului:\n";
					string nume_hotel;
					cin.ignore();
					getline(cin, nume_hotel);
					start3:
					cout << "2.introduceti clasificarea hotelului(maxim 5 stele):\n";
					int clasificare;
					cin >> clasificare;
					if (clasificare > 5)
					{
						cout << "clasificare gresita\n";
						goto start3;
					}
					start4:
					cout << "3.introduceti nr de mese incluse in pretul hotelului(maxim 3):\n";
					int nr_mese;
					cin >> nr_mese;
					if (nr_mese > 3)
					{
						cout << "numar mese gresit\n";
						goto start4;
					}
					cout << "\n";
					if (nr_mese)
					cout << "4.introduceti mesele din lista urmatoare de mese disponibile(selctati indexul):\n1.mic dejun\n2.pranz\n3.cina\n";

					set<type_masa> mese;
					int index_mese;
					
					while(nr_mese) {
						cin >> index;
						if (index == 1)
							mese.insert(mic_dejun);
						else
							if (index == 2)
								mese.insert(pranz);
							else
								if (index == 3)
									mese.insert(cina);
						nr_mese--;
					}
					IUnitate_Cazare * hotel= CFactory_unitate_cazare::create_Unitate_cazare(IUnitate_Cazare::Hotel,nume_hotel,clasificare,mese);

					

					cout << "5.Introduceti numarul de camere pe care vreti sa il adaugati\n";
					int nr_camere;
					cin >> nr_camere;
					int count_camere = 0;
					int price, nr_locuri;
					while (nr_camere--)
					{
						cout << "introdu numarul de locuri si pretul camerei cu nr " << ++count_camere<<"\n";
						cin >> nr_locuri>>price;
						hotel->Add_Camera(CRoom(nr_locuri, price));
					}
					oras->Add_cazare_in_oras(hotel);
					//CCreate_unitati_cazare::get_instance().Add_unitate_cazare(hotel);


				}else
					if (index2 == 2)
					{
						cout << "1.introduceti numele complexului de apartamente:\n";
						string nume_complex;
						cin.ignore();
						getline(cin, nume_complex);
						start6:
						cout << "2.introduceti clasificarea complexului de apartamente:\n";
						int clasificare;
						cin >> clasificare;
						if (clasificare > 5)
						{
							cout << "clasificare gresita\n";
							goto start6;
						}

						start5:
						cout << "3.introduceti nr de mese incluse in pretul complexului de apartamente(maxim 3):\n";
						int nr_mese;
						cin >> nr_mese;
						if (nr_mese > 3)
						{
							cout << "numar mese gresit\n";
							goto start5;
						}
						cout << "\n";
						if (nr_mese)
						cout << "4.introduceti mesele din lista urmatoare de mese disponibile(selectati indexul):\n1.mic dejun\n2.pranz\n3.cina\n";
						set<type_masa> mese;
						int index_mese;

						while (nr_mese) {
							cin >> index;
							if (index == 1)
								mese.insert(mic_dejun);
							else
								if (index == 2)
									mese.insert(pranz);
								else
									if (index == 3)
										mese.insert(cina);
							nr_mese--;
						}
						IUnitate_Cazare* Complex_ap = CFactory_unitate_cazare::create_Unitate_cazare(IUnitate_Cazare::Complex_apartamente, nume_complex, clasificare, mese);

						int nr_apartamente;
						cout << "5.Introduceti numarul de apartamente pe care vreti sa il adaugati\n";
						cin >> nr_apartamente;
						int count_ap = 0;
						while (nr_apartamente--) {

							cout << "Introduceti  numarul de camere si pretul din apartamentul cu nr " << ++count_ap<<"\n";
							int nr_camere,price;

							cin >> nr_camere>>price;

							int count_camere = 0;
							Complex_ap->Add_Apartament(CApartament(price));
							while (nr_camere--)
							{
								cout << "introdu numarul de locuri din camera " << ++count_camere <<" din apartamentul cu nr"<<count_ap<<"\n";
								int nr_locuri;
								cin >> nr_locuri;
								Complex_ap->get_list_apartamente().back().Add_camera(CRoom(nr_locuri));
							}
						}
						oras->Add_cazare_in_oras(Complex_ap);
						//CCreate_unitati_cazare::get_instance().Add_unitate_cazare(Complex_ap);

					}else
						if (index2 == 3) 
						{
							cout << "1.introduceti numele complexului de vile:\n";
							string nume_hotel;
							cin.ignore();
							getline(cin, nume_hotel);
							start8:
							cout << "2.introduceti clasificarea complexului de vile(maxim 5):\n";
							int clasificare;
							cin >> clasificare;
							if (clasificare > 5)
							{
								cout << "clasificare gresita\n";
								goto start8;
							}
							cout << "3.introduceti nr de mese incluse in pretul complexului de vile(maxim 3):\n";
							int nr_mese;

							start9:
							cin >> nr_mese;
							if (nr_mese > 3)
							{
								cout << "numar mese gresit\n";
								goto start9;
							}
							cout << "\n";
							if(nr_mese)
							cout << "4.introduceti mesele din lista urmatoare de mese disponibile(selectati indexul):\n1.mic dejun\n2.pranz\n3.cina\n";

							set<type_masa> mese;
							int index_mese;

							while (nr_mese) {
								cin >> index;
								if (index == 1)
									mese.insert(mic_dejun);
								else
									if (index == 2)
										mese.insert(pranz);
									else
										if (index == 3)
											mese.insert(cina);
								nr_mese--;
							}
							IUnitate_Cazare* Complex_v = CFactory_unitate_cazare::create_Unitate_cazare(IUnitate_Cazare::Complex_vile, nume_hotel, clasificare, mese);


							cout << "5.Introduceti numarul de vile pe care vreti sa il adaugati\n";
							int nr_vile;
							cin >> nr_vile;
							int count_vile = 0;
							while (nr_vile--)
							{
								int nr_etaje,price;
								cout << "Introduceti numarul de etaje si pretul pe care vreti sa il aiba vila cu nr " << ++count_vile<<"\n";
								cin >> nr_etaje >> price;
								Complex_v->Add_Vila(CVila(price));
								int count_ap = 0;
								while (nr_etaje--)
								{
									int nr_camere;
									cout << "Introduceti nr de camere pe care vreti sa le aiba etajul cu nr "<< ++count_ap <<" din vila "<<count_vile << "\n";
									cin >> nr_camere;
									Complex_v->get_list_vile().back().Add_apartment(CApartament());
									int count_camera = 0;
									while (nr_camere--)
									{
										int nr_locuri;
										cout << "Introduceti nr de locuri pe care vreti sa le aiba camera cu nr " << ++count_camera <<" de la etajul "<<count_ap<<" din vila cu nr "<< count_vile<< "\n";
										cin >> nr_locuri;
										Complex_v->get_list_vile().back().get_list_apartamente().back().Add_camera(CRoom(nr_locuri));
									}
								}

							}
							oras->Add_cazare_in_oras(Complex_v);
							//CCreate_unitati_cazare::get_instance().Add_unitate_cazare(Complex_v);
							
						}
						else
						{
							cout << "acest index nu este unul diponibil\n";
							goto start2;
						}
			}
		}
		else
			if (index == 3)
			{
				CAdministrator::get_instance().get_statistici();
			}
			else
				if (!index)
					return;
}
