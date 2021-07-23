#pragma once
#include "zamestnanec.h"


class Manager : public Zamestanec 
{
protected:
	std::string vzdelanie;
	string uroven_anglictiny;
	int skusenosti;
	int pracovne_uspechy;
	
public:
	int pocet_deti;
	Manager(int id_nove);
	void setMzda(float mzda, float bonus = 30);
	void setVzdelanie(string vzdelanie);
	float getMzda();
	int get_skusenosti();
	string get_uroven_anglictiny();
	string getVzdelanie() {return vzdelanie;}
	void set_Pracovene_uspechy(int pocet);
	int get_Pracovne_uspechy();
	Manager operator + (Manager m);
};
