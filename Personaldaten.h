#include <string>
#include <vector>
#pragma once

class Personaldaten
{
public:	
	Personaldaten();
	Personaldaten(std::string &tel, std::string &name_, std::string &abt, std::string &alter_,int einträge);
	
	std::string getalter()const;
	std::string getname()const;
	std::string getid()const;
	std::string getAbteilung()const;
	std::string getTel()const;

	~Personaldaten();

private:

	std::string telefonnr;
	std::string alter;
	std::string personal_id;
	std::string name;
	std::string Abteilung;
	
};

