#include <string>
#include <vector>

#pragma once

using namespace std;

class Funktionen
{
	
public:
	Funktionen();
	void Hauptmenue(string& menueauswahl);
	void Auswahl(int auswahl);
	std::vector<string>Input();
	

	
	~Funktionen();

private:
	
	
	vector<std::string> menuauswahl = { " Mitarbeiter hinzufuegen",  " Mitarbeiter Bearbeiten"," Mitarbeiter anschauen"," Mitarbeiter loeschen"," Programm beenden" };
	
};

