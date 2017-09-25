#include "Kundendaten.h"
#include "Funktionen.h"
#include <iostream>
#include <string>

using namespace std;




int main() {

	
	typedef enum  Menue { AddMA, EditMa, Anschauen, Löschen, Beenden }Menue;
	system("color 0a");
	Funktionen a;
	
	
	int Datensätze=0;
	string menueauswahl;

	std::vector<string> Menue_Punkt_Einseingabe;
	Kundendaten *maptr[10];
	

	while (true) {
		a.Hauptmenue(menueauswahl);

		if (menueauswahl == "AddMA") {
			system("cls");
			Menue_Punkt_Einseingabe = a.Input();
			maptr[Datensätze] = new Kundendaten(Menue_Punkt_Einseingabe.at(1), Menue_Punkt_Einseingabe.at(0), Menue_Punkt_Einseingabe.at(2), Menue_Punkt_Einseingabe.at(3),Datensätze+1);
			Datensätze++;

			continue;

		}else if(menueauswahl == "EditMA") {

		}
		else if (menueauswahl == "ShowMA") {
			if (Datensätze == 0) {
				cout << "keine daten vorhanden"; break;
			}
			else {
				cout << "das ist name: " << maptr[0]->getname() << " und Personalnummer: " << maptr[0]->getid();
				cout << "das ist name: " << maptr[1]->getname() << " und Personalnummer: " << maptr[1]->getid();
			}
		}
		else {
			cout << "programm wird beendet";
		}
		
		
	}
	
	

	system("pause");
}

