#pragma once
#include "zamestnanec.h"



class Eletrikar : public Zamestanec 
{
protected:
	int paragraf = 0;
	int prax;
	float mzda;
	void set_mzda(float _mzda, float bonus = 50){
		mzda = _mzda + bonus;
	}
	bool naradie = false;
	
public:
	Eletrikar(int Kmzda,int id_nove);
	void setNaradie();
	bool getNaradie();
	float getMzda();
	bool kontrola_paragrafu(int paragraf);
	void setParagraf(int paragrafik);
	int getPrax();
	int getParagraf();
};

