//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVII
// Versuch 02
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>

// 2.2.2.3 korrigierte Version
unsigned long long int fib(int n)
{
	unsigned long long int prevFib = 0;
	unsigned long long int currFib = 1;
	unsigned long long int newFib;
	if(n == 0)
	{
		return 0;
	}
	if(n == 1)
	{
		return 1;
	}
	for (int i = 2; i <= n; i++)
	{
		newFib = prevFib + currFib ;
		prevFib = currFib ;
		currFib = newFib ;
	}
	return newFib;
}

int main ()
{
	std :: cout << " Fibonacci - Zahlen :" << std :: endl ;
	for (int i = 0; i <= 93 ; i ++)
	{
		std :: cout << "f(" << i << ") = " << fib (i) << std :: endl ;
	}
	return 0;
}

/* 2.2.2.4 mit n=42 dauert das Program mit der rekursiven Berechnung eindeutig langsamer als
die iterative Berechnung*/

/* 2.2.2.5 Ab der 47-ten Fibonacci-Zahl ist der int-Bereich zu Ende. Dies kann man
 beheben, indem man den Wertebereich zu long int, unsigned int und/oder noch unsigned long long int ändert
 Die größte mit diesem Programm berechenbare Fibonacci-Zahl ist 93. */
