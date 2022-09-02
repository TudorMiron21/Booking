#define _CRT_SECURE_NO_WARNINGS
#include "CAdministrator.h"
#include<fstream>
#include<string>

CAdministrator* CAdministrator::instance = nullptr;

CAdministrator& CAdministrator::get_instance()
{
    if (instance == nullptr)
        instance = new CAdministrator;
    return *instance;
}

void CAdministrator::Add_orase()
{
    for (const auto& i : CCreate_orase::get_instance().get_list_orase())
        lista_orase.push_back(i);
}

void CAdministrator::Add_cazare(string oras, IUnitate_Cazare * unitate_cazare)
{
    for (auto& i : lista_orase)
        if (i->get_nume_oras() == oras)
            i->get_Cazari_list().push_back(unitate_cazare);
}

void CAdministrator::Add_oras(string nume_oras)
{
    COras* oras = new COras(nume_oras);
    lista_orase.push_back(oras);
    CCreate_orase::get_instance().get_list_orase().push_back(oras);
}

void CAdministrator::print_orase()
{
    for (const auto& i : lista_orase)
        i->print_oras();
}

bool CAdministrator::search_username(string user)
{
    for (const auto& i : users)
        if (user == i->get_username())
            return true;
    return false;   
}

bool CAdministrator::search_password(string pass)
{
    for (const auto& i : users)
        if (pass == i->get_password())
            return true;
    return false;
}

CUser * CAdministrator::search_user(string username, string password)
{
    for (const auto &it : users)
        if (password == it->get_password())
        {
            if (it->get_username() == username)
                return it;
            return nullptr;
        }
         
    return nullptr;


}

void CAdministrator::add_user(CUser * user)
{
    users.push_back(user);
}

bool CAdministrator::accept_rezervare(string filename,CCazare *& cazare, IUnitate_Cazare* unitate_cazare)
{
    CData C;
    time_t curr_time = time(NULL);
    if (check_in_accept != C && check_out_accept != C)
    {
        cout << "Domnule administrator, doriti sa acceptati rezervarea urmatoare:";
        cout << check_in_accept.get_zi() << "/" << check_in_accept.get_luna() << "/" << check_in_accept.get_an() << "--->" << check_out_accept.get_zi() << "/" << check_out_accept.get_luna() << "/" << check_out_accept.get_an()<<endl;
    start:
        cout << "pentru a accepta rezervarea apasati tastati 'da' sau 'nu'";
        string yes_or_not;
        ofstream f;
        f.open(filename,std::ios_base::app);
        cin >> yes_or_not;
        if (yes_or_not == "da")
        {
            f << "Rezerarea dumneavoastra la unitatea de cazare " << unitate_cazare->Get_nume_cazare() << " din data : ";
            f << check_in_accept.get_zi() << "/" << check_in_accept.get_luna() << "/" << check_in_accept.get_an() << "--->" << check_out_accept.get_zi() << "/" << check_out_accept.get_luna() << "/" << check_out_accept.get_an();
            f << " a fost acceptata de catre administrator in data "<<ctime(&curr_time) << endl;
            cazare->get_date_rezervate().push_back({ check_in_accept,check_out_accept });
            return true;
        }
        else
            if (yes_or_not == "nu")
            {
                f << "Rezerarea dumneavoastra la unitatea de cazare "<< unitate_cazare->Get_nume_cazare() << " din data : ";
                f << check_in_accept.get_zi() << "/" << check_in_accept.get_luna() << "/" << check_in_accept.get_an() << "--->" << check_out_accept.get_zi() << "/" << check_out_accept.get_luna() << "/" << check_out_accept.get_an();
                f << " NU a fost acceptata de catre administrator in data "<< ctime(&curr_time)<<endl;
                return false;
            }
            else
            {
                goto start;
            }
        f.close();
    }
    else
        cout << "Domnule administrator, nu aveti nicio rezervare de acceptat " << endl;
}

void CAdministrator::sort_orase()
{
    auto lambda = [](COras*& a, COras*& b) {return a->get_indice_popularitate() > b->get_indice_popularitate(); };
    lista_orase.sort(lambda);
}

void CAdministrator::get_top_orase(int top_nr)
{
    int count = 0;

    cout << "Top " << top_nr << " al oraselor alese de utilizatori este:"<<endl;
    for (const auto& it : lista_orase)
    {
        if (count == top_nr)
            break;
        cout << count+1 << "." << it->get_nume_oras()<<endl;
        count++;
    }
    cout << endl;
}

void CAdministrator::get_top_cazari(int top_nr)
{

    for ( auto& i : lista_orase)
    {
        for (auto& j : i->get_Cazari_list())
        {
            int ok = 0;
            for (auto& k : CCreate_unitati_cazare::get_instance().get_list())
            {
                if (j->Get_nume_cazare() == k->Get_nume_cazare())
                {
                    ok = 1;
                }
            }
            if (!ok)
            {
                CCreate_unitati_cazare::get_instance().Add_unitate_cazare(j);
            }
        }
    }
    CCreate_unitati_cazare::get_instance().sort_list_cazari();
    int count = 0;
    cout << "Top " << top_nr << " al unitatilor de cazare alese de utilizatori este:" << endl;
    for (const auto& it : CCreate_unitati_cazare::get_instance().get_list())
    {
        if (count == top_nr)
            break;
        cout << count + 1 << "." << it->Get_nume_cazare()<<endl;
        count++;
    }
    cout << endl;
}

bool CAdministrator::get_top_cazari_oras(int top_nr, string oras)
{
    
    for ( auto& i : lista_orase)
    {
        if (i->get_nume_oras() == oras)
        {

            cout << "Top " << top_nr << " al unitatilor de cazare alese de utilizatori este:" << endl;
            int count = 0;
            for (const auto& j : i->get_Cazari_list())
            {
                if (count == top_nr)
                    break;
                cout << count + 1 << "." << j->Get_nume_cazare()<<endl;
                count++;
            }
            return true;
        }
    }
    return false;
    cout << endl;
}

double CAdministrator::get_grad_ocupare(string nume_cazare)
{
    for (const auto& i : CCreate_unitati_cazare::get_instance().get_list())
    {
        if (nume_cazare == i->Get_nume_cazare())
        {
            if (i->get_type_cazare() == IUnitate_Cazare::Hotel)
            {

                int nr_max_zile = i->get_max_gap() * i->get_list_camere().size();
                double nr_zile = 0;
                for ( auto& j : i->get_list_camere())
                {
                    for (const auto &k : j.get_date_rezervate())
                    {
                        nr_zile += this->calculate_nr_days(k.first, k.second);
                    }
                }
                return nr_zile / nr_max_zile;
            }
            else
                if (i->get_type_cazare() == IUnitate_Cazare::Complex_apartamente)
                {
                    int nr_max_zile = i->get_max_gap() * i->get_list_camere().size();
                    double nr_zile = 0;
                    for (auto& j : i->get_list_camere())
                    {
                        for (const auto &k : j.get_date_rezervate())
                        {
                            nr_zile += this->calculate_nr_days(k.first, k.second);
                        }
                    }
                    return nr_zile / nr_max_zile;
                }
                else
                    if (i->get_type_cazare() == IUnitate_Cazare::Complex_vile) {

                        int nr_max_zile = i->get_max_gap() * i->get_list_vile().size();
                       double nr_zile = 0;
                        for (auto& j : i->get_list_vile())
                        {
                            for (const auto &k : j.get_date_rezervate())
                            {
                                nr_zile += this->calculate_nr_days(k.first, k.second);
                            }
                        }
                        return nr_zile / nr_max_zile;
                    }

        }
    }
    return -1;
}

void CAdministrator::get_statistici()
{
    int top_nr;
    cout << "Administratorul site-ului a creeat anumite statistici:"<<endl;

    cout << "pentru a vedea topul oraselor scrieti nr de orase pe care vreti sa le vedeti in top:";
    cin >> top_nr;
    this->get_top_orase(top_nr);

    cout << "pentru a vedea topul unitatilor de cazare scrieti nr de cazari pe care vreti sa le vedeti in top:";
    cin >> top_nr;
    this->get_top_cazari(top_nr);

    cout << "pentru a vedea topul unitatilor dintr-un anumit oras de cazare scrieti nr de cazari pe care vreti sa le vedeti in top si numele orasului ales:";
    cin >> top_nr;
    string oras;

    cin.ignore();
start:
    getline(cin, oras);
    if (!this->get_top_cazari_oras(top_nr, oras))
    {
        cout << "Acest oras nu exista in lista " << endl;
        goto start;
    }

    cout << "Pentru a vedea gradul de ocupare al unei unitati de cazare tastati numele acesteia:";
    string nume_cazare;
start2:
    getline(cin, nume_cazare);

    if (this->get_grad_ocupare(nume_cazare) < 0)
    {
        cout << "\nAceasta cazare nu exista in lista de cazari. Introduceti alta cazare " << endl;
        goto start2;
    }
    else
       cout << "gradul de ocupare al unitatii de cazare " << nume_cazare << " este " << this->get_grad_ocupare(nume_cazare) * 100 << "%" << endl;  
}

int CAdministrator::calculate_nr_days(CData Check_in, CData Check_out)
{
    return((CCreate_time::get_instance().Get_time_from_date(Check_out)- CCreate_time::get_instance().Get_time_from_date(Check_in)) / (24*3600));
}
