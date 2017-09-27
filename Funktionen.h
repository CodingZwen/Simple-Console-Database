#include <string>
#include <vector>
#include "Personaldaten.h"

#pragma once

using namespace std;

class Funktionen
{
	
public:
	Funktionen();
	void Hauptmenue(string& menueauswahl, int& n)const;
	void Auswahl(const int &auswahl,const int& n)const;
	void Funktionen::AnzeigeMA(int &datens�tze, Personaldaten *mptr[]);
	int Funktionen::MAl�schen(std::string userinput, int &Datens�tze, Personaldaten *mptr[]);
	void Funktionen::MA_in_Datei(int &Datens�tze, Personaldaten *mptr[]);
	int Funktionen::Daten_Laden(int& Datens�tze, Personaldaten *mptr[]);

	std::vector<string>Input();

	~Funktionen();

private:
	
	vector<std::string> menuauswahl = { " Mitarbeiter hinzufuegen",  " Mitarbeiter Exportieren"," Mitarbeiter Anzeigen", " Mitarbeiter Kuendigen"," Mitarbeiter in Textdatei Speichern"};
};

