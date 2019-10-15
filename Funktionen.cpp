#include "Funktionen.h"
#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

Funktionen::Funktionen() {};

void Funktionen::Auswahl(const int &auswahl,const int& n) const //n for show current workers
{
	for (size_t i = 0; i < menuauswahl.size(); i++) {

		if (auswahl == i) {
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
	char bestätigung;			//save Y/N?
	std::vector<string>rückgabe; //for data return

	while (wiederholen == true) {

		cout << "Bitte gebe den Namen ein: \n";
		cin >> name;
		rückgabe.push_back(name);
		cout << "Bitte Telefonnummer eingeben: \n";
		cin >> name;
		rückgabe.push_back(name);
		cout << "Bitte Abteilung eingeben: \n";
		cin >> name;
		rückgabe.push_back(name);
		cout << "Bitte Alter eingeben: \n";
		cin >> name;
		rückgabe.push_back(name);

		cout << "Alle daten wurden eingegeben!\n";
		system("pause");
		system("cls");
		cout << "Ihr eingegebenen Daten: \n\n";

		for (size_t s = 0; s < rückgabe.size(); s++) {
			cout << "Eingabe: " << rückgabe.at(s) << std::endl;
		}

		cout << "\nDaten bestätigen? Y/N: ";
		cin >> bestätigung;
		switch (bestätigung) {

		case  'y' : wiederholen = false; cout << "\nEingabe wird nun gespeichert.\nEs wird zum Hauptmenue zurueckgekehrt!\n"; system("pause"); system("cls"); break;
		case  'Y': wiederholen = false;  cout << "Eingabe wird nun gespeichert.\nEs wird zum Hauptmenue zurueckgekehrt!\n"; system("pause"); system("cls"); break;

		default: rückgabe.clear(); system("cls"); cout << "\nEingabe wird geloescht...Abfrage wird wiederholt!\n"; break;
		}
	}
	return rückgabe;
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

void Funktionen::AnzeigeMA(int &datensätze,  Personaldaten *mptr[] ) {

	
	system("cls");
	
	cout << " PERSONAL ID\tNAME\tABTEILUNG\n\n";
	for (int i = 0; i < datensätze; i++) {
		if (mptr[i] != NULL) {
			cout << i + 1 << ". " << mptr[i]->getid() << "\t\t" << mptr[i]->getname() << "\t" << mptr[i]->getAbteilung() << "\n\n";
		}
		}
}


int Funktionen::MAlöschen(std::string userinput, int &Datensätze, Personaldaten *mptr[]) {

	for (int s = 0; s < Datensätze; s++) {

		if (mptr[s]->getid() == userinput) {
			cout << "\nMitarbeiter " << mptr[s]->getname() << " wurde erfolgreich gekuendigt :D !\n";
			mptr[s] = NULL;
			Datensätze--; 
		}
	}

	return Datensätze;
}


void Funktionen::MA_in_Datei(int &Datensätze, Personaldaten *mptr[]) { //ma speichern in asci datei
	ofstream ziel;
	
	ziel.open("c:\\users\\sven\\desktop\\Datenbank.asc");

	if (!ziel) {
		cerr << "fehler beim schreiben der datei!\n";
		exit(-1);
	}
	else {

		for (int i = 0; i < Datensätze; i++) {
			if (mptr != NULL) {
				ziel << mptr[i]->getid() << " " << mptr[i]->getname() << " " << mptr[i]->getAbteilung()
					<< " " << mptr[i]->getalter() << " #\n";
			}
			}

		ziel.close();
	}
}


int Funktionen::Daten_Laden(int& Datensätze,Personaldaten *mptr[]) {
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
