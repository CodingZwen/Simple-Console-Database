#include "Personaldaten.h"
#include "Funktionen.h"
#include <iostream>
#include <string>

using namespace std;

int main() {

	typedef enum  Menue { AddMA, EditMa, Anschauen, L�schen, Beenden }Menue;
	system("color 0a");
	Funktionen Funktion;
	
	string idl�schen;
	int Datens�tze=0;
	string Roterfaden;

	std::vector<string> Menue_Punkt_Einseingabe;
	std::vector<string> zwischenspeicher;
	Personaldaten *maptr[10];
	

	while (true) {
		Funktion.Hauptmenue(Roterfaden,Datens�tze);

		if (Roterfaden == "AddMA") {
			system("cls");
			Menue_Punkt_Einseingabe = Funktion.Input();
			maptr[Datens�tze] = new Personaldaten(Menue_Punkt_Einseingabe.at(1), Menue_Punkt_Einseingabe.at(0), Menue_Punkt_Einseingabe.at(2), Menue_Punkt_Einseingabe.at(3),Datens�tze+1);
			Datens�tze++;	continue;

		}else if(Roterfaden == "ExportMA") { //Export data
		
			
			system("pause");
			Datens�tze=Funktion.Daten_Laden(Datens�tze,maptr);
		}
		else if (Roterfaden == "ShowMA" && Datens�tze != 0) {
			Funktion.AnzeigeMA(Datens�tze, maptr);
			system("pause");
			system("cls");
		}
		else if (Roterfaden == "DeleteMA" && Datens�tze != 0) {
			system("cls");
			Funktion.AnzeigeMA(Datens�tze, maptr);
			cout << "\nBitte Personal ID des zu loeschenden Mitarbeiters\nBestaetigen mit Enter: ";
			
			cin >> idl�schen;
			Funktion.AnzeigeMA(Datens�tze, maptr);
			cout << "\nIhre Eingabe: " << idl�schen << std::endl;
			Datens�tze=Funktion.MAl�schen(idl�schen, Datens�tze, maptr);
			system("pause");
			system("cls");

		}
		else if (Roterfaden == "PrintMA" && Datens�tze != 0) {
			system("cls");
			cout << "Daten werden eingespeichert!\n";
			Funktion.MA_in_Datei(Datens�tze, maptr);
			system("pause");
			system("cls");
		}

		else {
			
			system("cls");
		}		
	}
	system("pause");
}

