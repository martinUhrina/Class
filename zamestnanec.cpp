#include<iostream>
#include "zamestnanec.h"

Zamestanec::Zamestanec(int id_nove){
	cout<<"Zadajte meno: ";
	cin>>meno;
		cout<<"Zadajte priezvisko: ";
	cin>>priezvisko;
		cout<<"Zadajte vek: ";
	cin>>vek;
		cout<<"Zadajte telefone cislo: ";
	cin>>telefone_cislo;
	ID = id_nove;
}
