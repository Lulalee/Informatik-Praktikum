//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVII
// Versuch 1.1: Datentypen und Typumwandlung
//
// Datei:  Variablen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

int main()
{
	std::cout << "Bitte gib eine Zahl ein." << std::endl;
	int iErste; 											//Deklaration der ersten Zahl
	std::cin >> iErste;										//Zuweisung der eingegebenen Zahl der Variable Erste
	std::cout << "Bitte gib eine zweite Zahl ein." << std:: endl;
	int iZweite;
	std::cin >> iZweite;

	//1.7.1.1
	int iSumme =iErste + iZweite; 							//Deklaration und Initialisierung von iSumme mit der Summe von iErste und iZweite
	int iQuotient = iErste / iZweite;						//Deklaration und Initialisierung von iQuotient mit dem Quotient von iErste und iZweite

	//1.7.1.2
	double dSumme =iErste +iZweite;
	double dQuotient = iErste / iZweite;

	//1.7.1.3
	double dSummeCast = (double)iErste + (double)iZweite;
	double dQuotientCast = (double)iErste / (double)iZweite;

	//1.7.1.4
	std::cout << "Summe(int) der beiden Zahlen(int): " << iSumme <<"; Quotient(int) der beiden Zahlen(int): " <<iQuotient << std::endl; //Ausgabe der Summe und des Quotienten
	std::cout << "Summe(double) der beiden Zahlen(int): " << dSumme <<"; Quotient(double) der beiden Zahlen(int): " <<dQuotient << std::endl; //Ausgabe der Summe und des Quotienten
	std::cout << "Summe(double) der beiden Zahlen(double) ist: " << dSummeCast <<"; Quotient(double) der beiden Zahlen(double): " <<dQuotientCast << std::endl; //Ausgabe der Summe und des Quotienten

	std::cout <<"Bitte gib deinen Vornamen ein." << std::endl;
	std:: string sVorname;
	std::cin >> sVorname;

	std::cout <<"Bitte gib deinen Nachnamen ein." << std::endl;
	std:: string sNachname;
	std::cin >> sNachname;

	std:: string sVornameName = sVorname + " " + sNachname;
	std:: string sNameVorname = sVorname + ", " + sNachname;
	std::cout << sVornameName << std::endl;
	std::cout << sNameVorname << std::endl;

	//1.7.1.5
	{
		int iFeld[2] = {1,2};
		// Die Werte kann man ansprechen durch iFeld[0] und iFeld[1]
		int spielfeld[2][3] = {{1,2,3},{4,5,6}};
		//Die Werte spricht man mit spielfeld[0][0] an. Dies ist der 1. Wert in der 1.Spalte und der 1.Zeile
		std::cout << "Elemente des 1.Feldes: "<< iFeld[0] << " " << iFeld[1] << std::endl;
		std::cout << "Elemente des 2.Feldes: \n " <<spielfeld[0][0] <<" " <<spielfeld[0][1] << " " << spielfeld[0][2] << "\n"<< spielfeld[1][0] << " " << spielfeld[1][1] << " " << spielfeld[1][2] << std::endl;
		const int iZweite =1; //Initialisierung der Integer-Variable iZweite mit 1
		std:: cout << "Variable im Block: " << iZweite << std::endl;
	}
	std:: cout << "Variable außerhalb des Blocks: "<< iZweite << std::endl;

	//1.7.1.6
	char iName1 =sVorname[0];
	char iName2 =sVorname[1];
	std :: cout << "1. Buchstabe laut ASCII-Tabelle: " <<iName1 << std::endl;
	std:: cout << "2. Buchstabe laut ASCII-Tabelle: " <<iName2 << std::endl;

	int buchstabe1;
	int buchstabe2;

	if(iName1<97)
		{
			buchstabe1 = (iName1+1)%65; // Addition von 1, da Modulo bei Rest =0 beginnt, der erste Buchstabe aber =1 ist
		}
		else
		{
			buchstabe1 = (iName1+1)%97;
		}

	if(iName2<97)
		{
			buchstabe2 = (iName2+1)%65; // Addition von 1, da Modulo bei Rest =0 beginnt, der erste Buchstabe aber =1 ist
		}
		else
		{
			buchstabe2 = (iName2+1)%97;
		}

	std::cout << "Die Stelle vom 1.Buchstabe ist: " << buchstabe1 << std::endl;
	std::cout << "Die Stelle vom 2.Buchstabe ist: " << buchstabe2 << std::endl;

	return 0;
	
}
