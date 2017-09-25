#include "Kundendaten.h"


using namespace std;

Kundendaten::Kundendaten() {}

Kundendaten::Kundendaten(std::string tel, std::string name_, std::string abt, std::string alter_,int einträge)
	: telefonnr{ tel }, alter{ alter_ }, name{ name_ }, Abteilung{ abt } {
	
	int psid= einträge+100;
	personal_id = to_string(psid);
}



std::string Kundendaten::getalter() {
	return alter;
}

std::string Kundendaten::getid() {

	return personal_id;
}


std::string Kundendaten::getname() {
	return name;
}

Kundendaten::~Kundendaten()
{

}
