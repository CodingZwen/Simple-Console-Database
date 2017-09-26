#include "Personaldaten.h"


using namespace std;

Personaldaten::Personaldaten() {}

Personaldaten::Personaldaten(std::string &tel, std::string &name_, std::string &abt, std::string &alter_,int einträge)
	: telefonnr{ tel }, alter{ alter_ }, name{ name_ }, Abteilung{ abt } {
	
	int psid= einträge+100;
	personal_id = to_string(psid);
}



std::string Personaldaten::getalter() const {
	return alter;
}

std::string Personaldaten::getid()const  {

	return personal_id;
}


std::string Personaldaten::getname()const {
	return name;
}


std::string Personaldaten::getAbteilung() const {


	return Abteilung;
}

Personaldaten::~Personaldaten()
{

}


