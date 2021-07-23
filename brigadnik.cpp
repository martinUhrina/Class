#include "brigadnik.h"
#include<iostream>

Brigadnik::Brigadnik(int Kmzda,int id_nove) 
			: Eletrikar(Kmzda, id_nove)
{
	mzda = Kmzda;
}
string Brigadnik::getOdbor(){
	return skolsky_odbor;
}
string Brigadnik::getSkola(){
	return skola;
}

int Brigadnik::getRocnik(){
	return rocnik;
}

void Brigadnik::setSkola(){
	cout<<"Skolsky odbor: ";
	getline(cin,skolsky_odbor);
	cout<<"Skola: ";
	getline(cin,skola);
	cout<<"Rocnik: ";
	cin>>rocnik;
	getchar();
}
