/*
 * main.cpp
 *
 *  Created on: 02.05.2017
 *      Author: leaha
 */

#include <iostream>

char verschluesselung(char pZeichen1,char pTabelle[2][26])
{
	int n=0;
	for(int i=0;i<26;i++)
	{
		if(pZeichen1==pTabelle[0][i])
		{
			break;
		}
		n++;
	}
	return pTabelle[1][n];
}

char entschluesselung(char pZeichen1,char pTabelle[2][26])
{
	int n=0;
	for(int i=0;i<26;i++)
	{
		if(pZeichen1==pTabelle[1][i])
		{
			break;
		}
		n++;
	}
	return pTabelle[0][n];
}

int main()
{
	char tabelle[2][26]={{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'},{'Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y'}};
	std::cout <<"Bitte geben Sie ein Zeichen ein"<< std::endl;
	char zeichen1;
	std::cin >>zeichen1;
	char zeichen2 = verschluesselung(zeichen1,tabelle);
	std::cout << "Das entschlüsselte Zeichen von " <<zeichen1 << " ist: " << zeichen2 << std::endl;

	std::cout << "Bitte geben Sie ein Wort ein." << std::endl;
	std::string wort1;
	std:: cin >> wort1;
	std::string wort2="";

	for(int i=0;i<wort1.length();i++)
	{
		wort2 +=verschluesselung(wort1[i],tabelle);
	}
	std::cout << "Klartext: " << wort1 << "; Verschlüsselung: " <<wort2 << std::endl;

	std::cout << "Bitte geben Sie ein verschlüsseltes Wort ein." << std::endl;
	std::string wort3;
	std:: cin >> wort3;
	std::string wort4="";


	for(int i=0;i<wort3.length();i++)
		{
			wort4 +=entschluesselung(wort3[i],tabelle);
		}
		std::cout << "Klartext: " << wort3 << "; Entschlüsselung: " <<wort4 << std::endl;

	return 0;
}
