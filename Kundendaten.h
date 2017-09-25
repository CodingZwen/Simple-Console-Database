#include <string>
#include <vector>
#pragma once




class Kundendaten
{
public:	
	Kundendaten();
	Kundendaten(std::string tel, std::string name_, std::string abt, std::string alter_,int einträge);
	
	std::string getalter();
	std::string getname();
	std::string getid();
	
	~Kundendaten();

private:

	std::string telefonnr;
	std::string alter;
	std::string personal_id;

	

	std::string name;
	std::string Abteilung;
	
};

