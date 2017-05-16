/**
 * @file test.cpp
 *
 * Provides a function for testing the program and some other functions in order to provide this.
 */

#include "test.h"
#include "config.h"

#include <iostream>


extern void show_field(const int field[SIZE_Y][SIZE_X]);
extern int winner(const int field[SIZE_Y][SIZE_X]);
extern bool turn_valid(const int field[SIZE_Y][SIZE_X],  const int player, const int pos_x, const int pos_y);
extern void execute_turn(int field[SIZE_Y][SIZE_X], const int player, const int pos_x, const int pos_y);
extern int possible_turns(const int field[SIZE_Y][SIZE_X], const int player);
/**
 * @brief Funktion, um die Gewinner-Funktion (winner) zu testen
 *
 * Diese Funktion testet die winner-Funktion, indem sie den Rueckgabewert der zu testenden Funktion
 * mit dem erwarteten Wert (valid) vergleicht
 *
 * @param field das Feld auf dem getestet wird
 * @param winner_code das erwartete Ergebnis
 * @return das Ergebnis true (Test passed!) oder false (Test failed!)
 */
bool test_winner(const int field[SIZE_Y][SIZE_X], const int winner_code)
{
	std::cout << "Running test for 'winner'..." << std::endl;
	std::cout << "----------------------------" << std::endl;
	show_field(field);
	std::cout << "Checking who wins" << std::endl;

	//Call winner-function
	if(winner_code==winner(field))
	{
		std::cout << "Test passed!" <<std::endl;
		return true;
	}
	else
	{
		std::cout << "Test failed!" <<std::endl;
		return false;
	}

}
/**
 * @brief Funktion, um die turn_valid-Funktion zu testen
 *
 * Diese Funktion testet die turn_valid-Funktion, indem sie den Rueckgabewert der zu testenden Funktion
 * mit dem erwarteten Wert (winner_code) vergleicht
 *
 * @param field das Feld auf dem getestet wird
 * @param player der Spieler (1/2)
 * @param pos_x x-Position des zu pruefenden Zuges
 * @param pos_y y-Position des zu pruefenden Zuges
 * @param valid das erwartete Ergebnis
 * @return das Ergebnis true (Test passed!) oder false (Test failed!)
 */
bool test_turn_valid(const int field[SIZE_Y][SIZE_X], const int player, const int pos_x,
					 const int pos_y, const bool valid)
{
	// check for a given field whether a turn is valid
	std::cout << "Running test for 'turn_valid'..." << std::endl;
		std::cout << "----------------------------" << std::endl;
		show_field(field);
		std::cout << "Next turn: (y:"<<pos_y+1<<",x:"<<pos_x+1<<")" << std::endl;
		std::cout << "Checking if the next turn is valid" << std::endl;

		//Call winner-function
		if(valid==turn_valid(field,player,pos_x,pos_y))
		{
			std::cout << "Test passed!" <<std::endl;
			return true;
		}
		else
		{
			std::cout << "Test failed!" <<std::endl;
			return false;
		}
}
/**
 * @brief Funktion, um die execute_turn-Funktion zu testen
 *
 * Diese Funktion testet die execute_turn-Funktion, indem sie das Feld nach dem ausgefuehrten Zug mit dem
 * erwarteten Feld (output) elementweise vergleicht.
 *
 * @param input das Feld auf dem getestet wird und der Zug ausgefuehrt wird
 * @param output das erwartete Feld, auf dem der Zug schon ausgefuehrt wurde
 * @param player Spieler (1/2)
 * @param pos_x x-Position des zu auszufuehrenden Zuges
 * @param pos_y y-Position des zu auszufuehrenden Zuges
 *
 * @return das Ergebnis true (Test passed!) oder false (Test failed!)
 */
bool test_execute_turn(int input[SIZE_Y][SIZE_X], const int output[SIZE_Y][SIZE_X],
					   const int player, const int pos_x, const int pos_y)
{
	// check for a given field whether the execution of a turn is valid
	std::cout << "Running test for 'execute_turn'..." << std::endl;
			std::cout << "----------------------------" << std::endl;
			show_field(input);
			std::cout << "Next turn: (y:"<<pos_y+1<<",x:"<<pos_x+1<<")" << std::endl;
			std::cout <<"Player: "<<player <<std::endl;

			execute_turn(input,player,pos_x,pos_y);
			show_field(input);
			for(int j=0;j<SIZE_Y;j++)
			{
				for(int i=0;i<SIZE_X;i++)
				{
					if(output[j][i]==input[j][i])
					{
						std::cout << "Test passed!" <<std::endl;
						return true;
					}
					else
					{
						std::cout << "Test failed!" <<std::endl;
						return false;
					}
				}
			}
}

/**
 * @brief Funktion, um die possible_turns-Funktion zu testen
 *
 * Diese Funktion testet die possible_turns-Funktion, indem sie den zu erwartenden Wert mit dem von
 * der Funktion berechneten Wert vergleicht.
 *
 * @param field das Feld, auf dem die moeglichen Zuege gezaehlt werden
 * @param player Spieler (1/2)
 * @param count_possible_turns erwartetes Ergebnis
 *
 * @return das Ergebnis true (Test passed!) oder false (Test failed!)
 */

bool test_possible_turns(const int field[SIZE_Y][SIZE_X], const int player,
						 const int count_possible_turns)
{
	std::cout << "Running test for 'possible_turns'..." << std::endl;
				std::cout << "----------------------------" << std::endl;
				show_field(field);
				std::cout <<"Player: "<<player <<std::endl;

				if(count_possible_turns == possible_turns(field,player))
				{
					std::cout << "Test passed!" <<std::endl;
					return true;
				}
				else
				{
					std::cout << "Test failed!" <<std::endl;
					return false;
				}
}
/**
 * @brief Funktion, um alle Tests durchzufuehren
 *
 * Diese Funktion fuehrt nacheinander alle Tests der einzelnen Funktionen aus.
 * Dabei werden bespielhaft Spielfelder und Spielsituationen entworfen, um diese zu testen.
 * Ist nur ein Test falsch, gibt die Funktion wieder, dass der Test nicht bestanden wurde.
 *
 *
 * @return result das Ergebnis true (alle Tests bestanden) oder false (mindestens einen Test nicht bestanden)
 */
bool run_full_test(void)
{
	bool result = true;


// ---------- CHECK WINNER ---------- //

	int winner_matrix[5][8][8]= {
			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 1, 0, 1, 0, 1, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},
			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 2, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 2, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 2, 0, 0, 0, 2, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 1, 0, 0, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 0, 2, 2, 2, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0} //winner_code=2
			},
			{
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 1, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 1, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0} //winner_code=1
			},
			{
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 2, 1, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0} //winnder_code=0
			}
		};

	int winner_code[5] = {1,2,2,1,0};

	for (int i = 0; i < 5; i++)
	{
		if(!test_winner(winner_matrix[i],winner_code[i]))
		{
			std::cout <<(i+1)<<". erwarteter Gewinner: "<<winner_code[i]<<"; berechneter Gewinner: "<<winner(winner_matrix[i])<<std::endl;
			result=false;
		}
		else
		{
		std::cout <<(i+1)<<". Gewinner: " <<winner_code[i] <<std::endl;
		}
	}


// ---------- CHECK TURN VALID ---------- //

	int turnvalid_matrix[6][8][8] = {
			{   {1, 0, 2, 0, 0, 1, 1, 1},
				{0, 0, 2, 0, 0, 0, 0, 1},
				{0, 0, 0, 0, 0, 1, 2, 2},
				{2, 2, 0, 2, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 2, 2, 0},
				{0, 0, 0, 2, 1, 1, 0, 2},
				{1, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 1, 0, 1}
			},

			{   {1, 0, 2, 0, 0, 1, 1, 1},
				{0, 0, 2, 0, 0, 1, 0, 0},
				{0, 0, 2, 0, 0, 2, 1, 1},
				{0, 0, 0, 2, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 2, 2, 0},
				{0, 0, 0, 2, 1, 1, 0, 2},
				{1, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 1, 0, 1}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 1, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 2, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 1, 0, 0, 2, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 1, 0},
				{2, 0, 1, 2, 0, 2, 0, 0},
				{0, 2, 0, 2, 2, 2, 2, 2},
				{0, 0, 0, 0, 0, 0, 0, 1},
				{1, 0, 0, 0, 0, 2, 2, 2},
				{0, 2, 0, 0, 0, 0, 0, 0},
				{0, 1, 0, 1, 1, 1, 0, 0}
			},

			{   {2, 1, 0, 0, 2, 1, 1, 1},
				{0, 2, 0, 0, 0, 0, 0, 0},
				{1, 0, 0, 2, 0, 0, 0, 1},
				{0, 1, 1, 1, 0, 1, 0, 0},
				{1, 0, 0, 1, 1, 0, 0, 2},
				{0, 0, 0, 0, 0, 0, 0, 1},
				{1, 1, 0, 0, 0, 0, 2, 0},
				{1, 1, 2, 0, 0, 2, 2, 1}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 0, 0, 1, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			}
		};

	int turnvalid_player[6] = {1, 2, 2, 1, 2, 1};
	int turnvalid_pos[6][2] = { {2, 3}, {0, 3}, {4, 3}, {3, 4}, {3, 5}, {3, 4} };
	bool turnvalid_valid[6] = {0, 0, 0, 1, 1, 0};

	for (int i = 0; i < 6; i++)
	{
		if(test_turn_valid(turnvalid_matrix[i],turnvalid_player[i],turnvalid_pos[i][0],turnvalid_pos[i][1],turnvalid_valid[i]))
				{
					std::cout <<(i+1)<<". Ergebnis: " <<turnvalid_valid[i] <<std::endl;
				}
				else
				{
				std::cout <<(i+1)<<". erwartetes Ergebnis: "<<turnvalid_valid[i]<<"; berechnetes Ergebnis: "<<turn_valid(turnvalid_matrix[i],turnvalid_player[i],turnvalid_pos[i][0],turnvalid_pos[i][1])<<std::endl;
				result=false;
				}
	}


// ---------- CHECK EXECUTE TURN ---------- //

	int executeturn_matrix_in[9][8][8] = {
			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 1, 2, 2},
				{2, 2, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 2, 1, 1},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 1, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 2, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 1, 0},
				{0, 0, 0, 2, 0, 2, 0, 0},
				{0, 0, 0, 2, 2, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 2, 0, 0, 0, 0},
				{0, 0, 0, 1, 0, 1, 0, 0},
				{0, 0, 0, 1, 1, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 0, 0, 1, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 1, 0},
				{0, 0, 0, 2, 0, 2, 0, 0},
				{0, 0, 0, 2, 2, 0, 0, 0},
				{0, 1, 2, 0, 2, 2, 1, 0},
				{0, 0, 0, 2, 2, 0, 0, 0},
				{0, 0, 0, 1, 0, 1, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 2, 0, 0},
				{0, 0, 0, 0, 1, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 0, 1, 1, 1, 1, 0},
				{0, 0, 1, 0, 0, 0, 0, 0},
				{0, 0, 2, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 1, 0, 0, 0, 0, 0, 0},
				{0, 1, 0, 0, 0, 0, 2, 1},
				{1, 0, 1, 1, 2, 0, 0, 0},
				{0, 0, 1, 0, 0, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			}
		};

	int executeturn_matrix_out[9][8][8] {
			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 2, 2, 2, 2},
				{2, 2, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 1, 1, 1, 1},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 1, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 2, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0} //test failed
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 1, 0},
				{0, 0, 0, 2, 0, 1, 0, 0},
				{0, 0, 0, 2, 1, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 2, 0, 0, 0, 0},
				{0, 0, 0, 2, 0, 1, 0, 0},
				{0, 0, 0, 2, 1, 0, 0, 0},
				{0, 0, 0, 2, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 0, 0, 1, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}//test failed
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 1, 0},
				{0, 0, 0, 1, 0, 1, 0, 0},
				{0, 0, 0, 1, 1, 0, 0, 0},
				{0, 1, 1, 1, 1, 1, 1, 0},
				{0, 0, 0, 1, 1, 0, 0, 0},
				{0, 0, 0, 1, 0, 1, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 2, 0, 0},
				{0, 0, 0, 0, 2, 0, 0, 0},
				{0, 0, 0, 2, 0, 0, 0, 0},
				{0, 0, 2, 1, 1, 1, 1, 0},
				{0, 0, 2, 0, 0, 0, 0, 0},
				{0, 0, 2, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 1, 0, 0, 0, 0, 0, 0},
				{0, 1, 0, 0, 0, 0, 2, 1},
				{1, 2, 2, 2, 2, 0, 0, 0},
				{0, 0, 1, 0, 0, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			}
		};

	int executeturn_player[9]={2,1,2,1,2,2,1,2,2};
	int executeturn_pos[9][2]={	{4,2},
					{4,2},
					{3,2},
					{3,4},
					{3,5},
					{1,1},
					{3,4},
					{2,4},
					{1,4}};

	for (int i = 0; i < 9; i++)
	{
		if(!test_execute_turn(executeturn_matrix_in[i],executeturn_matrix_out[i],executeturn_player[i],executeturn_pos[i][0],executeturn_pos[i][1]))
			{
				result=false;
			}
	}


// ---------- CHECK POSSIBLE TURNS ---------- //

	int possibleturns_matrix[2][8][8] {
			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 1, 2, 0, 0, 0},
				{0, 0, 0, 2, 1, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 2, 1, 0, 0, 0},
				{0, 0, 0, 2, 1, 1, 0, 0},
				{0, 0, 0, 2, 1, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			}
		};

	int possibleturns_player[2] = {1, 1};
	int possibleturns_count[2] = {4, 5};

	for (int i = 0; i < 2; i++)
	{
		if(test_possible_turns(possibleturns_matrix[i],possibleturns_player[i],possibleturns_count[i]))
				{
					std::cout <<(i+1)<<". Ergebnis: " <<possibleturns_count[i] <<std::endl;
				}
				else
				{
				std::cout <<(i+1)<<". erwartetes Ergebnis: "<<possibleturns_count[i]<<"; berechnetes Ergebnis: "<<possible_turns(possibleturns_matrix[i],possibleturns_player[i])<<std::endl;
				result=false;
				}
	}

	return result;
}
