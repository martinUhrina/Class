#pragma once
#include"eletrikar.h"
#include "menezer.h"
#include<string>

class Brigadnik : public Eletrikar
{
protected:
	int rocnik;
	string skola;
	std::string skolsky_odbor;
	
public:
	friend float Manager::getMzda();
	void setSkola();
	string getOdbor();
	string getSkola();
	int getRocnik();
	Brigadnik(int Kmzda,int id_nove);
};


