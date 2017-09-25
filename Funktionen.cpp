#include "Funktionen.h"
#include <iostream>
#include <conio.h>


using namespace std;

Funktionen::Funktionen() {};

void Funktionen::Auswahl(int auswahl)
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
		else {
			cout << menuauswahl.at(i) << "\n\n";
		}
	}

	cout << "\n\nProduced by SuperhackerMega Zwen :D";
}



std::vector<string> Funktionen::Input(){

	
	bool wiederholen = true;
	string name;
	char best�tigung;
	std::vector<string>r�ckgabe;

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

		cout << "Daten best�tigen? Y/N: \n";
		cin >> best�tigung;
		switch (best�tigung) {

		case  'y' : wiederholen = false; cout << "Eingabe wird nun gespeichert.\nEs wird zum Hauptmenue zurueckgekehrt!\n"; system("pause"); system("cls"); break;
		case  'Y': wiederholen = false;  cout << "Eingabe wird nun gespeichert.\nEs wird zum Hauptmenue zurueckgekehrt!\n"; system("pause"); system("cls"); break;

		default: r�ckgabe.clear(); system("cls"); cout << "\nEingabe wird gel�scht...Abfrage wird wiederholt!\n"; break;
		}

	}

	return r�ckgabe;

}



void Funktionen::Hauptmenue(std::string& menueauswahl) {

	unsigned int durchgaenge = 0;
	char einzeichen;
	Funktionen funktion;
	funktion.Auswahl(0);
	bool running = true;

	while (running == true) {

		fflush(stdin);
		einzeichen = getch();

		//pfeiltastenabfrage		
		switch (einzeichen) {
		
		case 's': system("cls"); 
				if (durchgaenge < 4) {
					durchgaenge++;
				} funktion.Auswahl(durchgaenge); fflush(stdin); break;
		
		case 'w': system("cls"); if (durchgaenge > 0) { durchgaenge--; }funktion.Auswahl(durchgaenge); fflush(stdin); break;
		 case 0x0D: 
			switch (durchgaenge) {
			case 0: menueauswahl = { "AddMA" }; running = false; break;
			case 1: menueauswahl = { "EditMA" }; running = false; break;
			case 2: menueauswahl = { "ShowMA" }; running = false; break;
			case 3: menueauswahl = { "DeleteMA" }; running = false; break;

			default: cout << "fail"; break;
		}
		default: continue;
		}		
	}
}

Funktionen::~Funktionen()
{
}
