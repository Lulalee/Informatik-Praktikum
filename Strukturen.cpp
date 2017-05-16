/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVII
// Versuch 1.2: Strukturen
//
// Datei:  Strukturen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

int main()
{
	struct Person
	{
		std::string sNachname;
		std::string sVorname;
		int iGeburtsjahr;
		int iAlter;
	};

	Person nBenutzer;
	std::cout << "Bitte geben Sie nacheinander Nachname, Vorname, Geburtsjahr und Alter an." << std::endl;
	std::cin >>nBenutzer.sNachname;
	std::cin >>nBenutzer.sVorname;
	std::cin >>nBenutzer.iGeburtsjahr;
	std::cin >>nBenutzer.iAlter;

	std::cout <<"Name: " << nBenutzer.sVorname << " " << nBenutzer.sNachname << std::endl;
	std::cout <<"Geburtsjahr: " << nBenutzer.iGeburtsjahr << std::endl;
	std::cout <<"Alter: " <<nBenutzer.iAlter <<std::endl;

	Person nKopieEinzeln;
	nKopieEinzeln.sNachname = nBenutzer.sNachname;
	nKopieEinzeln.sVorname = nBenutzer.sVorname;
	nKopieEinzeln.iGeburtsjahr = nBenutzer.iGeburtsjahr;
	nKopieEinzeln.iAlter = nBenutzer.iAlter;

	Person nKopieGesamt;
	nKopieGesamt = nBenutzer;

	std::cout <<"Name: " << nKopieEinzeln.sVorname << " " << nKopieEinzeln.sNachname << std::endl;
	std::cout <<"Geburtsjahr: " << nKopieEinzeln.iGeburtsjahr << std::endl;
	std::cout <<"Alter: " <<nKopieEinzeln.iAlter <<std::endl;

	std::cout <<"Name: " << nKopieGesamt.sVorname << " " << nKopieGesamt.sNachname << std::endl;
	std::cout <<"Geburtsjahr: " << nKopieGesamt.iGeburtsjahr << std::endl;
	std::cout <<"Alter: " <<nKopieGesamt.iAlter <<std::endl;

	return 0;
	
}
