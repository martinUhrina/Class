#include<iostream>
#include<windows.h>
#include<fstream>
#include<queue>


#include "zamestnanec.h"
#include "zamestnanec.cpp"
#include "menezer.h"
#include "menezer.cpp"
#include "eletrikar.h"
#include "eletrikar.cpp"
#include "brigadnik.h"
#include "brigadnik.cpp"

using namespace std;

void menu();
void vypis();
void hladaj(string id);
void odstranit();
void novyZamestnanec();
void zapis(Manager a1);
void zapis(Eletrikar a2);
void zapis(Brigadnik a3);


const int manazer = 1;
const int eletriakar = 2;
const int brigadnik = 3;


int main(){
	short volba = 0;
	do{
		menu();
		cin>>volba;
		getchar();
		switch(volba)
		{
			case 0:;break;
			case 1:novyZamestnanec();break;
			case 2:vypis();break;
			case 3:odstranit();break;
			default:cout<<"NESPRAVNA VOLBA";getchar();break;
		}
		
	}while(volba!=0);
	
	return 0;
}


void menu(){
	system("cls");
	cout<<"			**Zoznam zamestnancov**"<<endl<<endl;
	cout<<"	1. Pridat zamestnanca"<<endl;
	cout<<"	2. Zobrazit zamestnancov"<<endl;
	cout<<"	3. Odstranit zamestnanca"<<endl;
	cout<<"	0. Koniec"<<endl;
	cout<<endl<<"Volba: ";		
}


void novyZamestnanec(){
	system("cls");
	short volba = 0;
	cout<<"		**Novy zamestnanec**"<<endl<<endl;
	do
	{	
		cout<<"Prosim, vyberte poziciu noveho zamestnanca: "<<endl;
		cout<<endl<<"	1. menezer"<<endl;
		cout<<"	2. eletrikar"<<endl;
		cout<<"	3. brigadnik"<<endl;
		cin>>volba;
		getchar();
	}while(volba < 1 || volba > 3);
	
	if(volba == 1){
		Manager a1(manazer);
		a1.setMzda(950);
		zapis(a1);
		getchar();
	}
	
	else if(volba == 2)
	{
		char naradie_pomoc;
		Eletrikar a2(850,eletriakar);
		while (!a2.kontrola_paragrafu(a2.getParagraf())){
			cout<<"Prosim zadajte este raz pragraf (20-24) ";
			int novy_paragraf;
			cin>>novy_paragraf;
			a2.setParagraf(novy_paragraf);
		}
		cout<<"Dostal naradie (A/N):";
		cin>>naradie_pomoc;
		if(naradie_pomoc == 'A' || naradie_pomoc == 'a') a2.setNaradie();
		zapis(a2);
		getchar();
	}
	
	else 
	{
		Brigadnik a3(555, brigadnik);
		a3.setSkola();
		while (!a3.kontrola_paragrafu(a3.getParagraf())){
			cout<<"Prosim zadajte este raz pragraf (20-24) ";
			int novy_paragraf;
			cin>>novy_paragraf;
			a3.setParagraf(novy_paragraf);
		}
		zapis(a3);
		getchar();
	} 
}

void zapis(Manager a1)
{
		ofstream file1("ZOZNAM.txt",ios::app);
		file1<<endl;
		file1<<endl<<endl<<manazer<<endl;
		file1<<"Meno: "<<a1.meno<<endl;
		file1<<"Priezvisko: "<<a1.priezvisko<<endl;
		file1<<"Vek: "<<a1.vek<<endl;
		file1<<"Telefone cislo: "<<a1.telefone_cislo<<endl;
		file1<<"Uroven anglictiny: "<<a1.get_uroven_anglictiny()<<endl;
		file1<<"Mzda: "<<a1.getMzda()<<endl;
		file1<<"Skusenosti: "<<a1.get_skusenosti()<<" rokov"<<endl;
		file1<<"Vzdelanie: "<<a1.getVzdelanie()<<endl;
		file1<<"Pocet deti: "<<a1.pocet_deti<<endl;
		file1.close();
		cout<<endl<<"Novy menezer bol uspesne zaregistrovany do zoznamu";
		getchar();
}

void zapis(Eletrikar a2)
{
		ofstream file1("ZOZNAM.txt",ios::app);
		file1<<endl;
		file1<<endl<<endl<<eletriakar<<endl;
		file1<<"Meno: "<<a2.meno<<endl;
		file1<<"Priezvisko: "<<a2.priezvisko<<endl;
		file1<<"Vek: "<<a2.vek<<endl;
		file1<<"Telefone cislo: "<<a2.telefone_cislo<<endl;
		file1<<"Mzda: "<<a2.getMzda()<<endl;
		file1<<"Paragraf: "<<a2.getParagraf()<<endl;
		file1<<"Prax: "<<a2.getPrax()<<endl;
		file1<<"Naradie: ";
		if(a2.getNaradie()){
			file1<<"Ano"<<endl;
		}
		else file1<<"Nie"<<endl;
		file1.close();
		cout<<endl<<"Novy eletrikar bol uspesne zaregistrovany do zoznamu";
		getchar();
}

void zapis(Brigadnik a3)
{
		ofstream file1("ZOZNAM.txt",ios::app);
		file1<<endl;
		file1<<endl<<endl<<brigadnik<<endl;
		file1<<"Meno: "<<a3.meno<<endl;
		file1<<"Priezvisko: "<<a3.priezvisko<<endl;
		file1<<"Vek: "<<a3.vek<<endl;
		file1<<"Telefone cislo: "<<a3.telefone_cislo<<endl;
		file1<<"Mzda: "<<a3.getMzda()<<endl;
		file1<<"Paragraf: "<<a3.getParagraf()<<endl;
		file1<<"Prax: "<<a3.getPrax()<<endl;
		file1<<"Skola: "<<a3.getSkola()<<endl;
		file1<<"Odbor: "<<a3.getOdbor()<<endl;
		file1<<"Rocnik: "<<a3.getRocnik()<<endl;
		file1.close();
		cout<<endl<<"Novy brigadnik bol uspesne zaregistrovany do zoznamu";
		getchar();
}


void vypis(){
	system("cls");
	short volba;
	cout<<"			**Vypis zozanemu zamestnancov**"<<endl<<endl;
	cout<<" Vyberte prosim zoznam pracovnikov"<<endl<<endl;
	cout<<"	1. Menezeri"<<endl;
	cout<<"	2. Eletrikari"<<endl;
	cout<<"	3. Brigadnici"<<endl;
	cout<<"	Volba: ";
	cin>>volba;
	if(volba == 1) hladaj("1");
	else if (volba == 2) hladaj("2");
	else hladaj("3");
}

void hladaj(string id)
{
	ifstream file("ZOZNAM.txt");
	string text;
	queue <string> g;
	bool tisicky_najomnych_bytov_rocne = false;
	int pomoc = 2;
	while(getline (file, text))
	{
		if(text == id){
			tisicky_najomnych_bytov_rocne = true;
			continue;
		}
		if (tisicky_najomnych_bytov_rocne)
		{
			if(pomoc > 0){
				g.push(text);
				pomoc--;
				
			}
			if(pomoc == 0){
				tisicky_najomnych_bytov_rocne = false;
				pomoc = 2;
			} 				
		}
	}
	cout<<endl;
	for (int i = 0;!g.empty();i++) {
		if(i == 2){
			cout<<endl;
			i = 0;
		}
        cout<<g.front()<<endl;
        g.pop();
    }
    file.close();
    getchar();
    getchar();
}

void odstranit(){
	system("cls");
	string meno, priezvisko, text;
	bool M =false, P =false;
	bool nenasiel_sa = true;
	bool kontrola =true;
	int a = 0, p1,p2;
	queue <string> g;
	cout<<"			**Odstranenie zamestnanca**"<<endl<<endl;
	cout<<"Zadajte meno zamestnanca: ";
	cin>>meno;
	cout<<"Priezvisko: ";
	cin>>priezvisko;
	ifstream file("ZOZNAM.txt");
	while(getline(file, text))
	{
		a++;
		if(text == "Meno: " + meno){
			M =true;
			p1 = a-2;
			}
		if(text == "Priezvisko: " + priezvisko){
			P =true;
			p2 = a-2;
		}
		if(M&&P){
			M = false;
			P = false;
			kontrola = false;
			nenasiel_sa = false;
		}
		if(text == "")kontrola  = true;
		if(kontrola){
			g.push(text);
		}
	}
	file.close();
	ofstream myFile;
	myFile.open("ZOZNAM.txt");
	for(int i = 0;!g.empty();i++) {
		if(i == p1 || i ==p2)
		{
			g.pop();
		}
		else {
			myFile<<"\n";
        	myFile<<g.front();	
        	g.pop();
    	}
    }
    myFile.close();
    if(!nenasiel_sa){
    	cout<<meno<<" "<<priezvisko<<" bol odstraneny";
	}
	else cout<<meno<<" "<<priezvisko<<" sa nenasiel"; 
    getchar();
    getchar();
}
