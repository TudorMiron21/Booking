#define _CRT_SECURE_NO_WARNINGS
#include "CCreate_time.h"
#include<chrono>
#include<time.h>

CCreate_time* CCreate_time::instance = nullptr;

vector<day> CCreate_time::week;

CCreate_time& CCreate_time::get_instance()
{
    if (instance == nullptr)
        instance = new CCreate_time;
    return *instance;
}

void CCreate_time::Create_week()
{
    week.push_back(Luni);
    week.push_back(Marti);
    week.push_back(Miercuri);
    week.push_back(Joi);
    week.push_back(Vineri);
    week.push_back(Sambata);
    week.push_back(Duminica);
}

void CCreate_time::Create_an()
{
    CCreate_time::Create_week();
    an.Add_luna(31);
    an.Add_luna(29);
    an.Add_luna(31);
    an.Add_luna(30);
    an.Add_luna(31);
    an.Add_luna(30);
    an.Add_luna(31);
    an.Add_luna(31);
    an.Add_luna(30);
    an.Add_luna(31);
    an.Add_luna(30);
    an.Add_luna(31);
}

CData CCreate_time::Get_date_from_time(time_t timp)
{
    string time_str = ctime(&timp);
    char time_copy[30];

    strcpy(time_copy, time_str.c_str());

    char* token = strtok(time_copy, " ");
    CData date;
    
    int count = 0;
    while (token)
    {
        if (count == 0)
        {
            if (!strcmp(token, "Mon"))
                date.get_name_zi() = Luni;
            if (!strcmp(token, "Tue"))
                date.get_name_zi() = Marti;
            if (!strcmp(token, "Wed"))
                date.get_name_zi() = Miercuri;
            if (!strcmp(token, "Thu"))
                date.get_name_zi() = Joi;
            if (!strcmp(token, "Fri"))
                date.get_name_zi() = Vineri;
            if (!strcmp(token, "Sat"))
                date.get_name_zi() = Sambata;
            if (!strcmp(token, "Sun"))
                date.get_name_zi() = Duminica;
                                       
        }
        if (count == 1) {

            int month;
            if (!strcmp(token, "Jan"))
                date.get_luna() = 1;
            if (!strcmp(token, "Feb"))
                date.get_luna() = 2;
            if (!strcmp(token, "Mar"))
                date.get_luna() = 3;
            if (!strcmp(token, "Apr"))
                date.get_luna() = 4;
            if (!strcmp(token, "May"))
                date.get_luna() =5;
            if (!strcmp(token, "Jun"))
                date.get_luna() = 6;
            if (!strcmp(token, "Jul"))
                date.get_luna() = 7;
            if (!strcmp(token, "Aug"))
                date.get_luna() = 8;
            if (!strcmp(token, "Sep"))
                date.get_luna() = 9;
            if (!strcmp(token, "Oct"))
                date.get_luna() = 10;
            if (!strcmp(token, "Nov"))
                date.get_luna() = 11;
            if (!strcmp(token, "Dec"))
                date.get_luna() = 12;
            
        }
        else
            if (count == 2)
            {
                date.get_zi() = atoi(token);
            }
            else
                if (count == 4)
                {
                    date.get_an() = atoi(token);
                }

        count++;
        token = strtok(NULL, " ");
    }

    return date;
}

time_t CCreate_time::Get_time_from_date(const CData& date)
{
    auto timp = std::chrono::time_point<std::chrono::system_clock>{};

    timp += (date.get_an_const() - 1970) * 365 * std::chrono::hours(24);
    int nr_an_bis = (date.get_an_const()-1970)/4;

    timp += nr_an_bis * std::chrono::hours(24);
        timp += (date.get_zi_const()) * std::chrono::hours(24);
    int count = 0;
    for (const auto& i : an.get_an())
    {
        if (count == date.get_luna_const()-1)
            break;
        if (count == 1)
        {
            if (date.get_an_const() % 4 == 0)
                timp += 29 * std::chrono::hours(24);
            else
                timp += 28 * std::chrono::hours(24);
        }
        else
            timp+=i * std::chrono::hours(24);
        count++;
    }
   // return  std::chrono::system_clock::to_time_t(timp);
    //std::chrono::duration_cast<std::chrono::hours>(timp.time_since_epoch())

    return std::chrono::system_clock::to_time_t(timp);
}

