#include "Funktionen.h"
#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

Funktionen::Funktionen() {};

void Funktionen::Auswahl(const int &auswahl,const int& n) const //n for show current workers
{
	for (size_t i = 0; i < menuauswahl.size(); i++) {

		if (auswahl == 0 && i == 0) {
			cout << ">" << menuauswahl.at(i) << "\n\n";

		}
		else if (auswahl == 1 && i == 1) {

			cout << ">" << menuauswahl.at(i) << "\n\n";

		}
		else if (auswahl == 2 && i == 2) {
			cout << ">" << menuauswahl.at(i) << "\n\n";

		}
		else if (auswahl == 3 && i == 3) {
			cout << ">" << menuauswahl.at(i) << "\n\n";
		}
		else if (auswahl == 4 && i == 4) {
			cout << ">" << menuauswahl.at(i) << "\n\n";
		}
		else if (auswahl == 5 && i == 5) {
			cout << ">" << menuauswahl.at(i) << "\n\n";
		}

		else {
			cout << menuauswahl.at(i) << "\n\n";
		}
	}

	cout << "\n\nProduced by SuperhackerMega Zwen :D\n\nAngelegte Mitarbeiter: " << n;
}



std::vector<string> Funktionen::Input(){

	bool wiederholen = true;
	string name;				//Variable for userinput
	char best�tigung;			//save Y/N?
	std::vector<string>r�ckgabe; //for data return

	while (wiederholen == true) {

		cout << "Bitte gebe den Namen ein: \n";
		cin >> name;
		r�ckgabe.push_back(name);
		cout << "Bitte Telefonnummer eingeben: \n";
		cin >> name;
		r�ckgabe.push_back(name);
		cout << "Bitte Abteilung eingeben: \n";
		cin >> name;
		r�ckgabe.push_back(name);
		cout << "Bitte Alter eingeben: \n";
		cin >> name;
		r�ckgabe.push_back(name);

		cout << "Alle daten wurden eingegeben!\n";
		system("pause");
		system("cls");
		cout << "Ihr eingegebenen Daten: \n\n";

		for (size_t s = 0; s < r�ckgabe.size(); s++) {
			cout << "Eingabe: " << r�ckgabe.at(s) << std::endl;
		}

		cout << "\nDaten best�tigen? Y/N: ";
		cin >> best�tigung;
		switch (best�tigung) {

		case  'y' : wiederholen = false; cout << "\nEingabe wird nun gespeichert.\nEs wird zum Hauptmenue zurueckgekehrt!\n"; system("pause"); system("cls"); break;
		case  'Y': wiederholen = false;  cout << "Eingabe wird nun gespeichert.\nEs wird zum Hauptmenue zurueckgekehrt!\n"; system("pause"); system("cls"); break;

		default: r�ckgabe.clear(); system("cls"); cout << "\nEingabe wird geloescht...Abfrage wird wiederholt!\n"; break;
		}
	}
	return r�ckgabe;
}


void Funktionen::Hauptmenue(std::string& menueauswahl,int& n)const {

	unsigned int durchgaenge = 0;	//rows to get the selected menuepoint
	char pfeiltaste;		//controllinput by user
	Funktionen funktion;
	funktion.Auswahl(0,n); //n is to get the used memory for used employes to show in "auswahl"
	bool running = true;

	while (running == true) {

		fflush(stdin);
		pfeiltaste = _getch();

		//pfeiltastenabfrage		
		switch (pfeiltaste) {
		
		case 's': system("cls"); 
				if (durchgaenge < 4) {
					durchgaenge++;
				} funktion.Auswahl(durchgaenge,n); fflush(stdin); break;
		
		case 'w': system("cls"); if (durchgaenge > 0) { durchgaenge--; }funktion.Auswahl(durchgaenge,n); fflush(stdin); break;
		 case 0x0D: 
			switch (durchgaenge) {
			case 0: menueauswahl = { "AddMA" }; running = false; break; 
			case 1: menueauswahl = { "ExportMA" }; running = false; break;
			case 2: menueauswahl = { "ShowMA" }; running = false; break;
			case 3: menueauswahl = { "DeleteMA" }; running = false; break;
			case 4: menueauswahl = { "PrintMA" }; running = false; break;
			default: cout << "fail"; break;
		}
		default: continue;
		}		
	}
}

void Funktionen::AnzeigeMA(int &datens�tze,  Personaldaten *mptr[] ) {

	
	system("cls");
	
	cout << " PERSONAL ID\tNAME\tABTEILUNG\n\n";
	for (int i = 0; i < datens�tze; i++) {
		if (mptr[i] != NULL) {
			cout << i + 1 << ". " << mptr[i]->getid() << "\t\t" << mptr[i]->getname() << "\t" << mptr[i]->getAbteilung() << "\n\n";
		}
		}
}


int Funktionen::MAl�schen(std::string userinput, int &Datens�tze, Personaldaten *mptr[]) {

	for (int s = 0; s < Datens�tze; s++) {

		if (mptr[s]->getid() == userinput) {
			cout << "\nMitarbeiter " << mptr[s]->getname() << " wurde erfolgreich gekuendigt :D !\n";
			mptr[s] = NULL;
			Datens�tze--; 
		}
	}

	return Datens�tze;
}


void Funktionen::MA_in_Datei(int &Datens�tze, Personaldaten *mptr[]) { //ma speichern in asci datei
	ofstream ziel;
	
	ziel.open("c:\\users\\sven\\desktop\\Datenbank.asc");

	if (!ziel) {
		cerr << "fehler beim schreiben der datei!\n";
		exit(-1);
	}
	else {

		for (int i = 0; i < Datens�tze; i++) {
			if (mptr != NULL) {
				ziel << mptr[i]->getid() << " " << mptr[i]->getname() << " " << mptr[i]->getAbteilung()
					<< " " << mptr[i]->getalter() << " #\n";
			}
			}

		ziel.close();
	}
}


int Funktionen::Daten_Laden(int& Datens�tze,Personaldaten *mptr[]) {
	system("cls");
	ifstream file("c://users//sven//desktop//Datenbank.asc");
	
	string bb;
	int durchgaenge = 0;
	vector<string> current_data;
	vector<string> Personen;

	if (file.is_open()) {
		while (!file.eof()) {
			file >> bb;
			
			current_data.push_back(bb);
			if (bb == "#") {
				
				mptr[durchgaenge] = new Personaldaten(current_data.at(0), current_data.at(1), current_data.at(2), current_data.at(3), durchgaenge + 100);
			current_data.clear();
			durchgaenge++;
			bb.clear();
			}			
		}
	}
	file.close();
	
	return durchgaenge;

}

Funktionen::~Funktionen()
{
}
