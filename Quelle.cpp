#include "Personaldaten.h"
#include "Funktionen.h"
#include <iostream>
#include <string>

using namespace std;

int main() {

	typedef enum  Menue { AddMA, EditMa, Anschauen, Löschen, Beenden }Menue;
	system("color 0a");
	Funktionen Funktion;
	
	string idlöschen;
	int Datensätze=0;
	string Roterfaden;

	std::vector<string> Menue_Punkt_Einseingabe;
	std::vector<string> zwischenspeicher;
	Personaldaten *maptr[10];
	

	while (true) {
		Funktion.Hauptmenue(Roterfaden,Datensätze);

		if (Roterfaden == "AddMA") {
			system("cls");
			Menue_Punkt_Einseingabe = Funktion.Input();
			maptr[Datensätze] = new Personaldaten(Menue_Punkt_Einseingabe.at(1), Menue_Punkt_Einseingabe.at(0), Menue_Punkt_Einseingabe.at(2), Menue_Punkt_Einseingabe.at(3),Datensätze+1);
			Datensätze++;	continue;

		}else if(Roterfaden == "ExportMA") { //Export data
		
			
			system("pause");
			Datensätze=Funktion.Daten_Laden(Datensätze,maptr);
		}
		else if (Roterfaden == "ShowMA" && Datensätze != 0) {
			Funktion.AnzeigeMA(Datensätze, maptr);
			system("pause");
			system("cls");
		}
		else if (Roterfaden == "DeleteMA" && Datensätze != 0) {
			system("cls");
			Funktion.AnzeigeMA(Datensätze, maptr);
			cout << "\nBitte Personal ID des zu loeschenden Mitarbeiters\nBestaetigen mit Enter: ";
			
			cin >> idlöschen;
			Funktion.AnzeigeMA(Datensätze, maptr);
			cout << "\nIhre Eingabe: " << idlöschen << std::endl;
			Datensätze=Funktion.MAlöschen(idlöschen, Datensätze, maptr);
			system("pause");
			system("cls");

		}
		else if (Roterfaden == "PrintMA" && Datensätze != 0) {
			system("cls");
			cout << "Daten werden eingespeichert!\n";
			Funktion.MA_in_Datei(Datensätze, maptr);
			system("pause");
			system("cls");
		}

		else {
			
			system("cls");
		}		
	}
	system("pause");
}

