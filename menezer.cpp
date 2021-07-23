#include "menezer.h"
#include<iostream>

using namespace std;


Manager::Manager(int id_nove) : Zamestanec(id_nove)
{
	cout<<"Uroven anglictiny: ";
	cin>>uroven_anglictiny;
	cout<<"Pocet odpracovanych rokov: ";
	cin>>skusenosti;
	getchar();
	cout<<"Vzdelanie: ";
	getline(cin,vzdelanie);
	cout<<"Pocet deti: ";
	cin>>pocet_deti;
}

void Manager::setMzda(float mzda, float bonusNadcas)
{
	plat = mzda + bonusNadcas;	
}

float Manager::getMzda()
{
	return plat;
}

void Manager::setVzdelanie(string Kvzdelanie)
{
	vzdelanie = Kvzdelanie;
}

void Manager::set_Pracovene_uspechy(int pocet)
{
	pracovne_uspechy = pocet;
}

int Manager::get_Pracovne_uspechy()
{
	return pracovne_uspechy;
}

string Manager::get_uroven_anglictiny()
{
	return uroven_anglictiny;
}

int Manager::get_skusenosti()
{
	return skusenosti;
}

