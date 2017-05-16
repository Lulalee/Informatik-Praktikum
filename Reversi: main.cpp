* @file main.cpp
 *
 * Provides functions for the game Reversi
 */

/**
* @mainpage Reversi
*
* Dokumentation des Spiels Reversi im Rahmen des Praktikums Informatik 1.
*
*/

/**Defines the type of a player */
#define HUMAN 1
#define COMPUTER 2

#include "test.h"
#include "config.h"
#include "Reversi_KI.h"
#include <iostream>
#include <stdlib.h>

/**
 * @brief Function providing first initialization of a new field
 *
 * This function fills an existing field with zeros and creates the starting pattern.
 *
 * @param field The field which will be initialized
 */
void initialize_field(int field[SIZE_Y][SIZE_X])
{
	for (int j = 0; j < SIZE_Y; j++)
		{
			for(int i = 0; i < SIZE_X; i++)
			{
				field[j][i] = 0;
			}
		}
		field[SIZE_Y / 2 - 1][SIZE_X / 2 - 1] = 1;
		field[SIZE_Y / 2][SIZE_X / 2 - 1] = 2;
		field[SIZE_Y / 2 - 1][SIZE_X / 2] = 2;
		field[SIZE_Y / 2][SIZE_X / 2] = 1;
}



/**
* @brief Prints the playing field to the console.
*
* This function gets the current playing field as parameter (two dimensional array)
* with entries of 0 (field is empty), 1 (field belongs to player 1), 2 (field belongs to player 2).
* <br>The function prints the playing field, grid included, to the console.
* Crosses symbolize player 1 while circles symbolize player 2.
*
*  @param field  The field which is going to be printed
*/
void show_field(const int field[SIZE_Y][SIZE_X])
{
	std::cout << "  ";

//Start at ASCII 65 = A
	for (int j = 65; j < 65 + SIZE_Y; j++)
		std::cout << ((char) j) << " " ;

	std::cout << std::endl;

	for (int j = 0; j < SIZE_Y; j++)
	{
		std::cout << j + 1;
		for (int i = 0; i < SIZE_X; i++)
		{
			switch (field[j][i])
			{
				case 0:
					std::cout << "  " ;
					break;
				case 1:
					std::cout << " X";
					break;
				case 2:
					std::cout << " O";
					break;
				default:
					std::cout << "Inconsistent data in field!" << std::endl;
					std::cout << "Aborting .... " << std::endl;
					exit(0);
					break;
			}
		};//for i
		std::cout << std::endl;
	}//for j
}

/**
 * @brief Funktion, um den Gewinner zu ermitteln
 *
 * Diese Funktion ermittelt den Gewinner, indem das ganze Feld abgelaufen wird
 * und dabei die Anzahl der "Steine" von den einzelnen Spielern gezhlt werden.
 *
 * @param field Das Feld am Ende des Spiels
 * @return Der Gewinner (Player 1 oder Player 2) oder Unentschieden (Rueckgabewert 0)
 */

int winner(const int field[SIZE_Y][SIZE_X])
{
	int count_p1 = 0;
	int count_p2 = 0;

	for (int j = 0; j < SIZE_Y; j++)
	{
		for (int i = 0; i < SIZE_X; i++)
		{
			if(field[j][i]==1)
			{
				count_p1++;
			}
			if(field[j][i]==2)
			{
				count_p2++;
			}
			//loop through all fields + counting of X (1) and O (2)
		}
	}
	if (count_p1==count_p2) // Unentschieden
	{
		return 0;
	}
	if (count_p1<count_p2)
	{
		return 2;
	}
	else
	{
		return 1;
	}
}
/**
 * @brief Funktion testet, ob der nchste Zug moeglich ist
 *
 * Diese Funktion prueft, ob der Zug, den der Spieler machen moechte moeglich ist.
 * Zuerst wird ueberprueft, ob das Feld, auf das der Spieler setzen moechte ueberhaupt frei ist.
 * Dannach wird ein benachbarter gegnerischer Stein gesucht und von da werden die gegnerischen Steine bis zum
 * Stein vom Mitspieler verfolgt. Wenn kein Stein vom Spieler kommt oder das Feld zu Ende ist,
 * bricht die Schleife ab
 *
 * @param field Das Feld auf dem gespielt wird
 * @param player Spieler (1/2)
 * @param pos_x x-Position von dem Zug, den der Spieler setzten moechte
 * @param pos_y y-Position von dem Zug, den der Spieler setzten moechte
 * @return false (wenn kein Zug moeglich ist), true (wenn ein moeglicher Zug gefunden wird)
 */
bool turn_valid(const int field[SIZE_Y][SIZE_X], const int player, const int pos_x, const int pos_y)
{
	// Process all possible directions
	int opponent = 3 - player; // the same as: if player = 1 -> opponent = 2 else
							   // if player = 2 -> opponent = 1

	if (field[pos_y][pos_x] != 0) //check if field is currently empty
	{
		return false;
	}

	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{

			if(field[pos_y+j][pos_x+i]==opponent)
			{
				int new_pos_x = pos_x +i+i;
				int new_pos_y = pos_y +j+j;
				int next=0;

				while(new_pos_x>=0 && new_pos_x<8 && new_pos_y>=0 && new_pos_y<8)
				{
					next=field[new_pos_y][new_pos_x];

					if(next==player)
					{
						return true;
					}
					if(next==0)
					{
						break;
					}
					new_pos_x +=i;
					new_pos_y +=j;
				}
			}
		}
	}
	return false;
}
/**
 * @brief Die Funktion fuehrt einen Zug aus
 *
 * Diese Funktion fuehrt einen Zug aus, indem sie zuerst den moeglichen Zug sucht und dann die
 * gegnerischen Steine wechselt. Der moegliche Zug wird gesucht, indem die benachbarten gegnerischen
 * Steine verfolgt werden (s.turn_valid). Wenn ein passender Zug ermittelt wurde, wird die Variable
 * changeSymbol auf true gesetzt, der Weg nochmal abgelaufen und dabei die gegnerischen Steine in
 * die Steine vom Spieler verwandelt.
 *
 * @param field Das Feld auf dem gespielt wird
 * @param player Spieler (1/2)
 * @param pos_x x-Position von dem Zug, den der Spieler setzten moechte
 * @param pos_y y-Position von dem Zug, den der Spieler setzten moechte
 */
void execute_turn(int field[SIZE_Y][SIZE_X], const int player, const int pos_x, const int pos_y)
{

	int opponent = 3 - player; // the same as: if player = 1 -> opponent = 2 else
							   // if player = 2 -> opponent = 1

	field[pos_y][pos_x]=player;
		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				if(field[pos_y+j][pos_x+i]==opponent)
				{
					int new_pos_x = pos_x +i+i;
					int new_pos_y = pos_y +j+j;
					int next=0;
					bool changeSymbol=false;

					while(new_pos_x>=0 && new_pos_x<8 && new_pos_y>=0 && new_pos_y<8)
					{

						next=field[new_pos_y][new_pos_x];

						if(next==player)
						{
							changeSymbol = true;

						}
						if(next==0)
						{
							break;
						}
						new_pos_x +=i;
						new_pos_y +=j;
					}
					if(changeSymbol)
					{
						int steps_x=i;
						int steps_y=j;

						while((pos_x+steps_x)>=0 && (pos_x+steps_x)<8 && (pos_y+steps_y)>=0 && (pos_y+steps_y)<8)
						{
							next=field[pos_y+steps_y][pos_x+steps_x];

							if(next==player)
							{
								break;
							}
							field[pos_y+steps_y][pos_x+steps_x]=player;
							steps_x +=i;
							steps_y +=j;

						}
					}
			}
		}
	}

}
/**
 * @brief Die Funktion zhlt die moeglichen Zuege
 *
 * Diese Funktion laeuft das ganze Feld ab und ueberprueft bei jeden Feld, ob der Zug moeglich waere.
 * Wenn dies so ist, wird eine Zaehlervariable um eins erhoeht.
 *
 * @param field Das Feld auf dem gespielt wird
 * @param player Spieler (1/2)
 * @return n Anzahl der moeglichen Zuege
 */
int possible_turns(const int field[SIZE_Y][SIZE_X], const int player)
{
	int n=0;
	for(int i=0;i<SIZE_Y;i++)
	{
		for(int j=0;j<SIZE_X;j++)
		{
			if(turn_valid(field,player,i,j))
			{
				n++;
			}
		}
	}
	return  n;
}
/**
 * @brief Die Funktion fuehrt einen menschlichen Zug aus
 *
 * Diese Funktion fuehrt einen Zug aus, der vom Menschen gespielt wird.
 * Zuerst wird ueberprueft, ob der Spieler ueberhaupt moegliche Zuege hat.
 * Danach wird so lange nach einem Spielzuf gefragt, bis ein moeglicher eingegeben wird.
 * Dieser wird dann durch execute_turn ausgefuehrt.
 *
 * @param field Das Feld auf dem gespielt wird
 * @param player Spieler (1/2)
 * @return false (kein eingegebender Zug moeglich und keiner ausgefuehrt), true (Zug moeglich und ausgefuehrt)
 */
bool human_turn(int field[SIZE_Y][SIZE_X], const int player)
{
	if (possible_turns(field, player) == 0)
	{
		return false;
	}

	int px;
	int py;
	bool repeat=false;

	while (true)
	{
		std::string input;
		input.reserve(50);
		std::cout << std::endl << "Your move (e.g. A1): " ;
		input.erase(input.begin(), input.end());
		std::cin >> input;
		px = ((int) input.at(0) ) - 65;
		py = ((int) input.at(1) ) - 49;

		if (turn_valid(field, player, px, py))
		{
			std::cout << "Player: "<<player << std::endl;
			//accept turn;
			break;
		}
		else
		{
			std::cout << std::endl << "Invalid input !" << std::endl;
		}
	}

	execute_turn(field, player, px, py);

	return true;
}
/**
 * @brief Die Funktion fuehrt allgemein einen Zug aus
 *
 * Diese Funktion testet, ob ein Computer oder ein Mensch spielt und ruft je nachdem die passenden
 * Funktionen human_turn oder computer_turn auf.
 * Dabei wird ueberprueft, ob der Zug moeglich ist und ausgefuehrt werden kann.
 *
 * @param field Das Feld auf dem gespielt wird
 * @param player_typ Typ vom Spieler: HUMAN (=1) oder COMPUTER (=2)
 * @param player Spieler (1/2)
 * @return turn_possible false(kein moeglicher Zug), true (moeglicher Zug wird ausgefuehrt)
 */
bool turn(int field[SIZE_Y][SIZE_X],int player_typ, int player)
{
	bool turn_possible =false;
	if(player_typ==HUMAN && possible_turns(field,player)>0)
	{
		turn_possible=human_turn(field,player);
		show_field(field);
	}

	if(player_typ==COMPUTER && possible_turns(field,player)>0)
	{

		turn_possible=computer_turn(field,player);
		show_field(field);

	}
	return turn_possible;
}
/**
 * @brief Die Funktion leitet das Spiel
 *
 * Diese Funktion spielt das Spiel, in dem abwechselnt Spieler 1 und Spieler 2 spielen.
 * Wenn die Funktion turn bei beiden Spielern ein false wiedergibt, d.h. kein Spieler hat mehr moeglicher Zuege,
 * ist das Spiel zu Ende und der Gewinner wird ermittelt.
 *
 *@param player_typ[2] In dem Feld werden die Arten (HUMAN oder COMPUTER) der Spieler gespeichert
 */
void game(const int player_typ[2])
{

	int field[SIZE_Y][SIZE_X];

	//Create starting pattern
	initialize_field(field);

	show_field(field);

	while(true)
	{
		bool turn_player1 =turn(field,player_typ[0],1);
		bool turn_player2=turn(field,player_typ[1],2);

		if(turn_player1==false && turn_player2 == false)
			{
				break;
			}


	}
	switch(winner(field))
	{
	case 1:
		std::cout <<"The winner is: Player 1" <<std::endl;
		break;
	case 2:
		std::cout <<"The winner is: Player 2" <<std::endl;
		break;
	case 0:
		std::cout <<"Draw!" <<std::endl;
		break;
	}
}
/**
 * @brief Main-Funktion
 *
 * In der Main-Funktion wird der gesamte Test durchgefuehrt.
 * Danach wird das Feld initialisiert, nach den Spieler-Typen gefragt und das Spiel (game) gestartet.
 *
 */
int main(void)
{
	if (TEST == 1)
	{
		bool result = run_full_test();
		if (result == true)
		{
			std::cout << "ALL TESTS PASSED!" << std::endl;
		}
		else
		{
			std::cout << "TEST FAILED!" << std::endl;
		}
	}

	int field[SIZE_Y][SIZE_X];

	initialize_field(field);

	show_field(field);
	std::cout << "Who is going to play? HUMAN (=1) or COMPUTER (=2) ?" <<std::endl;
	int player1;
	std::cin >> player1;
	std::cout << "Who is the second player? HUMAN (=1) or COMPUTER (=2) ?" <<std::endl;
	int player2;
	std::cin >> player2;
	int player_type[2] = { player1, player2 };  //Contains information whether players are HUMAN(=1) or COPMUTER(=2)
	game(player_type);
	return 0;
}

