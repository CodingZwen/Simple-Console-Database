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
	void Funktionen::AnzeigeMA(int &datensätze, Personaldaten *mptr[]);
	int Funktionen::MAlöschen(std::string userinput, int &Datensätze, Personaldaten *mptr[]);
	void Funktionen::MA_in_Datei(int &Datensätze, Personaldaten *mptr[]);
	int Funktionen::Daten_Laden(int& Datensätze, Personaldaten *mptr[]);

	std::vector<string>Input();

	~Funktionen();

private:
	
	vector<std::string> menuauswahl = { " Mitarbeiter hinzufuegen",  " Mitarbeiter Exportieren"," Mitarbeiter Anzeigen", " Mitarbeiter Kuendigen"," Mitarbeiter in Textdatei Speichern"};
};

