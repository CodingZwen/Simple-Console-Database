#include <string>
#include <vector>
#include "Personaldaten.h"

#pragma once

using namespace std;

class Funktionen
{
	
public:
	Funktionen();
	void Hauptmenue(string& menueauswahl)const;
	void Auswahl(const int &auswahl)const;
	std::vector<string>Input();
	void Funktionen::AnzeigeMA(int &datensätze, Personaldaten *mptr[]);
	int Funktionen::MAlöschen(std::string userinput, int &Datensätze, Personaldaten *mptr[]);

	void Funktionen::MA_in_Datei(int &Datensätze, Personaldaten *mptr[]);
	void Funktionen::Daten_Laden();
	
	~Funktionen();

private:
	
	
	vector<std::string> menuauswahl = { " Mitarbeiter hinzufuegen",  " Mitarbeiter Bearbeiten"," Mitarbeiter Anzeigen", " Mitarbeiter Kuendigen"," Mitarbeiter in Textdatei Speichern"};
	
};

