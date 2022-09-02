#pragma once
#include<iostream>
#include"CAdministrator.h"
#include"CUser.h"
#include"CCreate_time.h"
#include"IExceptie.h"
#include"CAlerta.h"
#include"CEroare.h"
#include"CRezervare.h"
class CMenu
{
public:

	static void menu();
	static void user();
	static void administrator();
};

