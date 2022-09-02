#define _CRT_SECURE_NO_WARNINGS
#include "CUser.h"
#include<conio.h>
#include<string>
#include<chrono>
#include"CCreate_time.h"
#include"CAdministrator.h"
#include"CRezervare.h"
#include"CAlerta.h"

CUser::CUser(string username, string password) :Username(username), Password(password), personal_file(Username + ".txt"),is_logat(false),nr_rezervari(0),fidelitate(0)
{
}

void CUser::choose_options()
{
	sstart:
	cout << "Puteti alege din urmatoarele optiuni(tatstati indexul):\n1.Lasa rcenzie\n2.Fa o rezervare\n";
	cout << "pentru a iesi din aceasta stare a programului apasati tasta '0'\n";
	int choice;
	cin >> choice;

	if(choice==1)
	{
		string nume_cazare, recenzie;
		cout << "introduceti numele cazarii la care doriti sa lasati o recenzie\n";
		cin.ignore();
		getline(cin, nume_cazare);
		for (auto i : nume_cazari)
		{
			if (i == nume_cazare)
			{
				cout << "introduceti recenzia\n";
				getline(cin, recenzie);
				this->lasa_recenzie(nume_cazare, recenzie);
				return;
			}
		}
		cout << "Nu puteti lasa recenzie la o unitate de cazare la care nu ati facut o rezervare \n";
		goto sstart;

	}else
		if (choice == 2) {
			cout << "Puteti alege din orasele urmatoare:" << endl;
			for (const auto& i : CAdministrator::get_instance().get_lista_orase())
				cout << i->get_nume_oras() << endl;

			cout << "Pentru a alege Orasul in care vreti sa calatoriti, tastati numele acestuia" << endl;

			string oras_chosen;
			cin.ignore();
		start1:
			
			getline(cin, oras_chosen);

			int flag1 = 0;

			for (auto& i : CAdministrator::get_instance().get_lista_orase())
				if (oras_chosen == i->get_nume_oras())
				{
					flag1 = 1;
					COras*& Oras = i;
					Oras->get_indice_popularitate()++;
					CAdministrator::get_instance().sort_orase();
					cout << "puteti alege din unitatile de cazare urmatoare:" << endl;

					for (auto& j : Oras->get_Cazari_list())
						cout << j->Get_nume_cazare() << endl;

					cout << "Pentru a alege unitatea de cazare in care vreti sa stati, tastati numele acesteia" << endl;
					string nume_cazare;

				start:
					getline(cin, nume_cazare);

					int flag2 = 0;
					for (auto& j : Oras->get_Cazari_list())
					{
						if (nume_cazare == j->Get_nume_cazare())
						{
							flag2 = 1;

							IUnitate_Cazare*& chosen_cazare = j;
							chosen_cazare->get_indice_popularitate()++;
							Oras->sort_list_cazari();
							chosen_cazare->Get_description();

							vector<CRoom>* list_pointer1 = nullptr;
							vector<CApartament>* list_pointer2 = nullptr;
							vector<CVila>* list_pointer3 = nullptr;


							if (chosen_cazare->get_type_cazare() == IUnitate_Cazare:: Hotel)
								list_pointer1 = &chosen_cazare->get_list_camere();
							else
								if (chosen_cazare->get_type_cazare() == IUnitate_Cazare::Complex_apartamente)
									list_pointer2 = &chosen_cazare->get_list_apartamente();
								else
									if (chosen_cazare->get_type_cazare() == IUnitate_Cazare::Complex_vile)
										list_pointer3 = &chosen_cazare->get_list_vile();



							cout << "pentru a alege cazarea in care vreti sa stati apasati pe tasta corespondenta indicelui acesteia";
							int index;

							cin >> index;

							if (list_pointer1)
							{
								if (index > list_pointer1->size())
									throw CRezervare("eroare rezervare");
								else
								{
									CCazare* cazare = &(*list_pointer1)[index - 1];
									this->choose_data(cazare);
									cout << "User: " << this->Username << " veti sedea " << CAdministrator::get_instance().calculate_nr_days(check_in, check_out) << " zile la cazarea aleasa de dumneavoastra. pretul pe care trebuie sa il achitati este:" << endl;
									cout << this->calculate_price(cazare, CAdministrator::get_instance().calculate_nr_days(check_in, check_out)) << endl;
									if (nr_rezervari)
										cout << "Ati beneficiat de o reducere de " << fidelitate * 100 << "% pentru gradul dumneavoastra de fidelitate" << endl;
									cout << "Rezervarea cazarii cu nr" << (*list_pointer1)[index - 1].get_nr_cazare() << " din unitatea de cazare " << chosen_cazare->Get_nume_cazare() << " a fost trimisa catre administrator" << endl;

									if (CAdministrator::get_instance().accept_rezervare(personal_file, cazare,chosen_cazare))
									{
										this->nume_cazari.insert(chosen_cazare->Get_nume_cazare());
										if (!nr_rezervari)
										{
											fidelitate += (double)2 / 100;
										}
										else
											if (fidelitate < (double)18 / 100)
											{
												fidelitate += (double)4 / 100;
											}
										nr_rezervari++;
									}
									return;
								}
							}
							else
								if (list_pointer2)
								{


									if (index > list_pointer2->size())
										throw CRezervare("eroare rezervare");
									else
									{
										CCazare* cazare = &(*list_pointer2)[index - 1];
										this->choose_data(cazare);
										cout << "User: " << this->Username << " veti sedea " << CAdministrator::get_instance().calculate_nr_days(check_in, check_out) << " zile la cazarea aleasa de dumneavoastra. pretul pe care trebuie sa il achitati este:" << endl;
										cout << this->calculate_price(cazare, CAdministrator::get_instance().calculate_nr_days(check_in, check_out)) << endl;
										if (nr_rezervari)
											cout << "Ati beneficiat de o reducere de " << fidelitate * 100 << "% pentru gradul dumneavoastra de fidelitate" << endl;
										cout << "Rezervarea cazarii cu nr" << (*list_pointer2)[index - 1].get_nr_cazare() << " din unitatea de cazare " << chosen_cazare->Get_nume_cazare() << " a fost trimisa catre administrator" << endl;

										if (CAdministrator::get_instance().accept_rezervare(personal_file, cazare,chosen_cazare))
										{
											this->nume_cazari.insert(chosen_cazare->Get_nume_cazare());
											if (!nr_rezervari)
											{
												fidelitate += (double)2 / 100;
											}
											else
												if (fidelitate < (double)18 / 100)
												{
													fidelitate += (double)4 / 100;
												}
											nr_rezervari++;
										}
										return;
									}
								}
								else
									if (list_pointer3)
									{
										if (index > list_pointer3->size())
											throw CRezervare("eroare rezervare");
										else
										{
											CCazare* cazare = &(*list_pointer3)[index - 1];
											this->choose_data(cazare);
											cout << "User: " << this->Username << " veti sedea " << CAdministrator::get_instance().calculate_nr_days(check_in, check_out) << " zile la cazarea aleasa de dumneavoastra. pretul pe care trebuie sa il achitati este:" << endl;
											cout << this->calculate_price(cazare, CAdministrator::get_instance().calculate_nr_days(check_in, check_out)) << endl;
											if (nr_rezervari)
												cout << "Ati beneficiat de o reducere de " << fidelitate * 100 << "% pentru gradul dumneavoastra de fidelitate" << endl;
											cout << "Rezervarea cazarii cu nr" << (*list_pointer3)[index - 1].get_nr_cazare() << " din unitatea de cazare " << chosen_cazare->Get_nume_cazare() << " a fost trimisa catre administrator" << endl;


											if (CAdministrator::get_instance().accept_rezervare(personal_file, cazare,chosen_cazare))
											{
												this->nume_cazari.insert(chosen_cazare->Get_nume_cazare());
												if (!nr_rezervari)
												{
													fidelitate += (double)2 / 100;
												}
												else
													if (fidelitate < (double)18 / 100)
													{
														fidelitate += (double)4 / 100;
													}
												nr_rezervari++;
											}

											return;
										}
									}


						}
					}
					if (!flag2)
					{
						cout << "Ati tastat gresit numele cazarii sau aceasta nu exista in lista de cazari a programului.Introduceti alt nume" << endl;
						goto start;
					}

				}

			if (!flag1) {
				cout << "Ati tastat gresit numele orasului sau acesta nu exista in lista de orase a programului. Introduceti alt nume" << endl;
				goto start1;
			}
		}
		else
		if(!choice)
			return;
}

CUser* CUser::log_in()
{
	CUser* current_user = nullptr;
	cout << "Bine ati venit pe site-ul booking.com.Pentru a va inregistra trebuie sa va logati in contul dumneavoastra:" << endl;

	int ok;
	int tries=3;
	do {
		ok = 0;
		string user;
		cout << "introduceti username-ul:" << endl;
		cin >> user;

		char password[80];
		cout << "introduceti parola:" << endl;

		for (int i = 0;;)
		{
			char a = _getch();
			if (a == '\b' && i >= 1)
			{
				char c = 8;
				cout << c << c;
				i--;
			}
			if (a == '\r')
			{
				password[i] = '\0';
				cout << endl;
				break;
			}
			else
			{
				password[i] = a;
				i++;
				cout << "*";
			}
		}
		string pass = password;

		current_user = CAdministrator::get_instance().search_user(user, password);

		if (current_user==nullptr)
		{
			ok = 1;
			cout << "Parola sau Usernameul introduse sunt gresite. Mai aveti "<<--tries<<" incercari" << endl;
		}
	} while (ok && tries);

	if (!tries)
		throw CAlerta("eroare autentificare");

	if (!ok)
	{ 
	//	cout << "Buna ziua " << current_user->get_username() << ".\n";
	//	cout << "Pentru a ramane logat pe contul dumneavoastra apasati tasta 'd', in caz contrar apasati tasta 'n'";
	//	char c;
	//start:
	//	cin >> c;
	//	if (c == 'd')
	//		current_user->get_is_logat() = true;
	//	else
	//		if (c == 'n')
	//			current_user->get_is_logat() = false;
	//		else
	//		{
	//			cout << "NU ati introdus una din optiunile de mai sus. Incercati din nou" << endl;
	//			goto start;
	//		}

		return current_user;
	}
}

CUser* CUser::create_account()
{
	cout << "Bine ati venit pe site-ul booking.com.Pentru a va creea un cont trebuie sa:" << endl;
	string user;
	cout << "introduceti username-ul dorit :" << endl;

	start1:
	cin >> user;
	
	if (CAdministrator::get_instance().search_username(user) == true)
	{
		cout << "Ne pare rau, dar acest username a fost ales de alt user. Introduceti alt username"<<endl;
		goto start1;
	}


	char password[80];
	
	cout << "introduceti parola dorita. trebuie sa aiba minim 5 caractere:" << endl;
	start:
	int i = 0;
	for (;;)
	{
		char a = _getch();
		if (a == '\b' && i >= 1)
		{
			char c = 8;
			cout << c << c;
			i--;
		}
		if (a == '\r')
		{
			password[i] = '\0';
			cout << endl;
			break;
		}
		else
		{
			password[i] = a;
			i++;
			cout << "*";
		}
	}
	if (i < 5)
	{
		cout << "parola nu are minim 5 caractere. Va rugam introduceti alta parola" << endl;
		goto start;
	}
	else
	{
		
		if (CAdministrator::get_instance().search_password(password)==true)
		{
			cout << "aceasta parola e folosita de alt user .Va rugam introduceti alta parola"<<endl;
			goto start;
		}
	}
	CUser* new_user = new CUser(user, password);
	CAdministrator::get_instance().add_user(new_user);
	return new_user;
}

void CUser::choose_data(CCazare*& cazare)
{
	cout << endl << "alegeti data de check in si data de check out dupa modelul urmator zz/ll/aaaa:"<<endl;
	
	int ok;
	
	

	do {
		ok = 0;

		char c = _getch();
		int zi1, zi2, luna1, luna2, an1, an2;
	start1:
		cin >> zi1;
		cin >> c;
		cin >> luna1;
		cin>> c;
		cin >> an1;
		cout << "--->";

		if (luna1 > 12)
		{
			cout << "data de check in este gresita.Introduceti alta" << endl;
			goto start1;
		}
		
		
		if (zi1 > CCreate_time::get_instance().get_an().get_an()[luna1-1])
		{
				cout << "data de check in este gresita.Introduceti alta" << endl;
				goto start1;
		}
		if(luna1==2 && an1%4 && zi1>28)
		{
			cout << "data de check in este gresita.Introduceti alta" << endl;
			goto start1;
		}


		start2:
		cin >> zi2;
		cin >> c;
		cin >> luna2;
		cin >> c;
		cin >> an2;
		cout << endl;

		if (luna2 > 12)
		{
			cout << "data de check in este gresita.Introduceti alta" << endl;
			goto start2;
		}
		
		
		if (zi2 > CCreate_time::get_instance().get_an().get_an()[luna2 - 1])
		{
				cout << "data de check in este gresita.Introduceti alta" << endl;
				goto start2;
		}
		
		if (luna2 == 2 && an2 % 4 && zi2 > 28)
		{
			cout << "data de check in este gresita.Introduceti alta" << endl;
			goto start2;
		}

		if (zi1 == zi2 && luna1 == luna2 && an1 == an2)

		{
			cout << "data de check out este identica cu cea de check in. Va rugam introduceti o alta data de check out" << endl;
			goto start2;
		}
		
		time_t checkin = CCreate_time::get_instance().Get_time_from_date(CData(zi1, luna1, an1));
		time_t checkout=CCreate_time::get_instance().Get_time_from_date(CData(zi2, luna2, an2));



		if (cazare->get_date_rezervate().size())
		{

			for (auto& i : cazare->get_date_rezervate())
				if ((checkin < CCreate_time::get_instance().Get_time_from_date(i.second)) && (checkin > CCreate_time::get_instance().Get_time_from_date(i.first)) || (checkout < CCreate_time::get_instance().Get_time_from_date(i.second)) && (checkout > CCreate_time::get_instance().Get_time_from_date(i.first)))
				{

					ok = 1;
					cout << "Ne pare rau ati introdus o perioada care coinicide cu alte perioade rezervate. Introduceti o alta data" << endl;
					//throw CRezervare("eroare rezervare");
				}
				else
				{
					
					
					const auto p1 = std::chrono::system_clock::now();
					
					if (checkin < std::chrono::system_clock::to_time_t(p1) || checkin > checkout)
					{
						ok = 1;
						cout << "Ne pare rau, nu se poate introduce aceasta data. Introduceti o alta data" << endl;
						//throw CRezervare("eroare rezervare");
					}
					else
					{
						this->check_in = CCreate_time::get_instance().Get_date_from_time(checkin- 24 * 3600);
						this->check_out = CCreate_time::get_instance().Get_date_from_time(checkout- 24 * 3600);
						CAdministrator::get_instance().get_check_in_accept() = CCreate_time::get_instance().Get_date_from_time(checkin- 24 * 3600);
						CAdministrator::get_instance().get_check_out_accept() = CCreate_time::get_instance().Get_date_from_time(checkout- 24 * 3600);
						
					}


				}
		}
		else
		{
			const auto p1 = std::chrono::system_clock::now();
		
			if (checkin < std::chrono::system_clock::to_time_t(p1) || checkin > checkout)
			{
				ok = 1;
				cout << "Ne pare rau, nu se poate introduce aceasta data. Introduceti o alta data" << endl;
				//throw CRezervare("eroare rezervare");
			}
			else

			{

				this->check_in = CCreate_time::get_instance().Get_date_from_time(checkin- 24 * 3600);
				this->check_out = CCreate_time::get_instance().Get_date_from_time(checkout- 24 * 3600);
				CAdministrator::get_instance().get_check_in_accept() = CCreate_time::get_instance().Get_date_from_time(checkin- 24 * 3600);
				CAdministrator::get_instance().get_check_out_accept() = CCreate_time::get_instance().Get_date_from_time(checkout- 24 * 3600);
				
			}

		}


	} while (ok);

	cin.ignore();
}

void CUser::lasa_recenzie(string Nume_cazare, string Recenzie)
{
	for (auto& i : CCreate_unitati_cazare::get_instance().get_list())
	{
		if (i->Get_nume_cazare() == Nume_cazare)
			i->Add_recenzie(Recenzie);
	}
}

double CUser::calculate_price(CCazare*& cazare,int nr_zile)
{

	double price = 0;
	int rest = nr_zile % 7;
	int nr_sapt = nr_zile / 7;
	int price_per_week=5 * cazare->get_price() + 2 * (cazare->get_price() + cazare->get_price() / 4);
	if(nr_sapt)
		price += nr_sapt* price_per_week;

	if (rest)
	{
	
		price+= rest* cazare->get_price();
		if (check_in.get_name_zi_const() + rest > 7)
		{
			price += cazare->get_price() / 2;
		}
		if (check_in.get_name_zi_const() + rest == 7)
		{
			price += cazare->get_price() / 4;
		}
	}
	return price-(price*fidelitate);
}
