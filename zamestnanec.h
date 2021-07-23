#pragma once
#include<string>


using namespace std;

class Zamestanec
{
public:
	Zamestanec(int id_nove);
	int ID;
	int vek;
	std::string meno;
	std::string priezvisko;
	std::string telefone_cislo;
	float plat;
};
