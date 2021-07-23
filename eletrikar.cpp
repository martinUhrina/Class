#include "eletrikar.h"
#include<iostream>

Eletrikar::Eletrikar(int Kmzda,int id_nove): Zamestanec(id_nove)
{	
	cout<<"Paragraf: ";
	cin>>paragraf;
	getchar();
	if(kontrola_paragrafu(paragraf))	
	{
		paragraf = paragraf;
	}		
	cout<<"Prax v odbore: ";
	cin>>prax;
	getchar();
	set_mzda(Kmzda);
				
}
int Eletrikar::getParagraf(){
	return paragraf;
}

int Eletrikar::getPrax(){
	return prax;
}

float Eletrikar::getMzda(){
	return mzda;
}

bool Eletrikar::kontrola_paragrafu(int paragraf)
{
	if (paragraf >= 20 && paragraf <= 24) return true;
	else return false;
}

void Eletrikar::setParagraf(int paragrafik)
{
	paragraf = paragrafik;
}

void Eletrikar::setNaradie(){
	naradie = true;
}

bool Eletrikar::getNaradie(){
	return naradie;
}

