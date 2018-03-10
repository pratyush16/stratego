#include "functions.h"
using namespace std;

void header()
//header
{
	cout << "----------------------------------------------" << endl;
        cout << "Pratyush Potu        (PratyushPotu@my.unt.edu)" << endl;
        return;
}

void rules()
//introductory rules message for stratego game
{
        cout << "------------------------------------------------------------------------" << endl;
        cout << "This program will set up a 5x5 game board for a smaller version of the game" << endl;
        cout << "of Stratego. One player will compete against the computer, each assigned" << endl;
        cout << "10 total pieces consisting of the following:" << endl;
        cout << " 1 FLAG (F)" << endl;
        cout << " 3 BOMB (B)" << endl;
        cout << " 1 MARSHAL (1) or GENERAL (2)" << endl;
        cout << " 3 COLONEL (3), MAJOR (4), CAPTAIN (5), LIEUTENANT (6), or SERGEANT (7)" << endl;
        cout << " 1 MINER (8)" << endl;
        cout << " 1 SPY (S)" << endl;

        cout << "GENERAL RULES:" << endl;
        cout << "--------------" << endl;
        cout << "For the most part, the game will follow the standard Stratego rules, although" << endl;
        cout << "there are some exceptions." << endl;
        cout << "1. Both players (BLUE and RED) will have all of their 10 game pieces as-" << endl;
        cout << " signed randomly with the only requirement being that the FLAG must be" << endl;
        cout << " placed in the back row. RED will start the game first." << endl;
        cout << "2. Higher ranked pieces can capture lower ranked pieces in the following" << endl;
        cout << " order: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> S, meaning that 1 (the" << endl;
        cout << " MARSHAL) can remove 2 (the GENERAL) and so forth. The MINER (8) piece" << endl;
        cout << " may strike a BOMB and remove it to occupy the now unoccupied space. A" << endl;
        cout << " SPY (S), although the lowest ranked piece, may remove the MARSHAL (1)" << endl;
        cout << " or the GENERAL (2). When pieces have equal rank, both will be removed."<< endl;
        cout << "3. The FLAG and BOMBs are not moveable while all of the other pieces may" << endl;
        cout << " move one square at a time forward, backward, or sideward, but not di-" << endl;
        cout << " agonally to an open square." << endl;
        cout << "4. A player must either move or strike on his/her turn." << endl;
        cout << "5. The game ends when a player strikes his/her opponent's flag." << endl;
        cout << "------------------------------------------------------------------------" << endl;
        return;
}
       
void initializeBoard(piece **a, int size)
/*
============================================================================
Function: initializeBoard
Parameters : array of pieces, and the array size
Return : no return because void
Description : This function intializes the stratego board from the struct
with corresponding pieces and colors.
============================================================================
*/
{
        //initializing pieces
        for (int i=0; i < size; i++)
        {
                for (int j=0; j < size; j++)
                {
                        a[i][j].type = NOTHING;
                }
        }

        //initializing colors
        for (int i=0; i < size; i++)
        {
                for (int j=0; j < size; j++)
                {
                        a[i][j].col = NONE;
                }
        }

	//initializing moveability
	for (int i=0; i < size; i++)
        {
                for (int j=0; j < size; j++)
                {
                        a[i][j].moveable = true;
                }
        }
	
        return;
}

void assignBoard(piece **a, int size)
/*
============================================================================
Function: assignBoard
Parameters : array of pieces, and the array size
Return : no return because void
Description : This function assigns pieces to the stratego board from the
struct with corresponding pieces and colors.
============================================================================
*/
{
        srand(time(NULL));
        //Blue Assignments
        //Pieces
        int FlagB; //index for blue flag
        FlagB = rand() % 5;
        a[0][FlagB].type = FLAG; //assigning blue flag
	for (int i = 0; i < 3; i++)
        {
                int BombBC = rand() % 5; //index for blue bomb column
                int BombBR = rand() % 2; //index for blue bomb row
                do
                {
                        BombBC = rand() % 5; //index for blue bomb column
                        BombBR = rand() % 2; //index for blue bomb row
                }while(!isspace(a[BombBR][BombBC].type));
                a[BombBR][BombBC].type = BOMB;
        }

        int leaderBC = rand() % 5; //index for blue marshal or general column
        int leaderBR = rand() % 2; //index for blue marshal or general row
        do
        {
                leaderBC = rand() % 5; //index for blue marshal or general column
                leaderBR = rand() % 2; //index for blue marshal or general row
        }while(!isspace(a[leaderBR][leaderBC].type));

        int leaderB = rand() % 2;//choosing marshal or general
        if (leaderB == 0)
        {
                a[leaderBR][leaderBC].type = MARSHAL;
        }
        else
        {
                a[leaderBR][leaderBC].type = GENERAL;
        }

        int minerBC = rand() % 5; //index for blue miner column
        int minerBR = rand() % 2; //index for blue miner row
        do
        {
                minerBC = rand() % 5; //index for blue miner column
                minerBR = rand() % 2; //index for blue miner row
        }while(!isspace(a[minerBR][minerBC].type));
        a[minerBR][minerBC].type = MINER;

        int spyBC = rand() % 5; //index for blue spy column
        int spyBR = rand() % 2; //index for blue spy row
        do
        {
                spyBC = rand() % 5; //index for blue spy column
                spyBR = rand() % 2; //index for blue spy row
        }while(!isspace(a[spyBR][spyBC].type));
        a[spyBR][spyBC].type = SPY;

        for (int i = 0; i < 3; i++)
        {
                int otherBC = rand() % 5; //index for blue COLONEL, MAJOR, CAPTAIN, LIEUTENTANT, or SERGEANT column
                int otherBR = rand() % 2; //index for blue COLONEL, MAJOR, CAPTAIN, LIEUTENTANT, or SERGEANT row
                do
                {
                        otherBC = rand() % 5; //index for blue COLONEL, MAJOR, CAPTAIN, LIEUTENTANT, or SERGEANT column
                        otherBR = rand() % 2; //index for blue COLONEL, MAJOR, CAPTAIN, LIEUTENTANT, or SERGEANT row
                }while(!isspace(a[otherBR][otherBC].type));


                int otherB = rand() % 5;//choosing COLONEL, MAJOR, CAPTAIN, LIEUTENTANT, or SERGEANT
                if (otherB == 0)
                {
                        a[otherBR][otherBC].type = COLONEL;
                }
                else if (otherB == 1)
                {
                        a[otherBR][otherBC].type = MAJOR;
                }
                else if (otherB == 2)
                {
                        a[otherBR][otherBC].type = CAPTAIN;
                }
                else if (otherB == 3)
                {
                        a[otherBR][otherBC].type = LIEUTENTANT;
                }
                else
                {
                        a[otherBR][otherBC].type = SERGEANT;
                }
        }

        //Colors
        for(int i = 0; i < 2; i++)
        {
                for (int j = 0; j < size; j++)
                {
                        a[i][j].col = BLUE;
                }
        }

	//Moveability
	for(int i = 0; i < 3; i++)
        {
                for (int j = 0; j < size; j++)
                {
                        a[i][j].moveable = false;
		}
        }

        //Red Assignments
        //Pieces
        int randFR; //index for flag
        randFR = rand() % 5;
        a[4][randFR].type = FLAG; //assigning flag
        for (int i = 0; i < 3; i++)
        {
                int BombRC = rand() % 5; //index for red bomb column
                int BombRR = rand() % 2 + 3; //index for red bomb row
                do
                {
                        BombRC = rand() % 5; //index for red bomb column
                        BombRR = rand() % 2 + 3; //index for red bomb row
                }while(!isspace(a[BombRR][BombRC].type));
                a[BombRR][BombRC].type = BOMB;
        }

        int leaderRC = rand() % 5; //index for red marshal or general column
        int leaderRR = rand() % 2 + 3; //index for red marshal or general row
        do
        {
                leaderRC = rand() % 5; //index for red marshal or general column
                leaderRR = rand() % 2 + 3; //index for red marshal or general row
        }while(!isspace(a[leaderRR][leaderRC].type));

        int leaderR = rand() % 2;
        if (leaderR == 0)
        {
                a[leaderRR][leaderRC].type = MARSHAL;
        }
        else
        {
                a[leaderRR][leaderRC].type = GENERAL;
        }

        int minerRC = rand() % 5; //index for red miner column
        int minerRR = rand() % 2 + 3; //index for red miner row
        do
        {
                minerRC = rand() % 5; //index for red miner column
                minerRR = rand() % 2 + 3; //index for red miner row
        }while(!isspace(a[minerRR][minerRC].type));
        a[minerRR][minerRC].type = MINER;

        int spyRC = rand() % 5; //index for red spy column
        int spyRR = rand() % 2 + 3; //index for red spy row
        do
        {
                spyRC = rand() % 5; //index for red spy column
                spyRR = rand() % 2 + 3; //index for red spy row
        }while(!isspace(a[spyRR][spyRC].type));
        a[spyRR][spyRC].type = SPY;

        for (int i = 0; i < 3; i++)
        {
                int otherRC = rand() % 5; //index for red COLONEL, MAJOR, CAPTAIN, LIEUTENTANT, or SERGEANT column
                int otherRR = rand() % 2 + 3; //index for red COLONEL, MAJOR, CAPTAIN, LIEUTENTANT, or SERGEANT row
                do
                {
                        otherRC = rand() % 5; //index for red COLONEL, MAJOR, CAPTAIN, LIEUTENTANT, or SERGEANT column
                        otherRR = rand() % 2 + 3; //index for red COLONEL, MAJOR, CAPTAIN, LIEUTENTANT, or SERGEANT row
                }while(!isspace(a[otherRR][otherRC].type));


                int otherR = rand() % 5;//choosing COLONEL, MAJOR, CAPTAIN, LIEUTENTANT, or SERGEANT
                if (otherR == 0)
                {
                        a[otherRR][otherRC].type = COLONEL;
                }
                else if (otherR == 1)
                {
                        a[otherRR][otherRC].type = MAJOR;
                }
                else if (otherR == 2)
                {
                        a[otherRR][otherRC].type = CAPTAIN;
                }
                else if (otherR == 3)
                {
                        a[otherRR][otherRC].type = LIEUTENTANT;
                }
                else
                {
                        a[otherRR][otherRC].type = SERGEANT;
                }
        }

        //Colors
        for(int i = 3; i < 5; i++)
        {
                for (int j = 0; j < size; j++)
                {
                        a[i][j].col = RED;
                }
        }

	//moveability
	for(int i = 3; i < 5; i++)
        {
                for (int j = 0; j < size; j++)
                {
                        if (a[i][j].type == FLAG || a[i][j].type == BOMB || a[i][j].type == NOTHING)
                        {
                                a[i][j].moveable = false;
                        }
                        else
                        {
                                a[i][j].moveable = true;
                        }
                }
        }

        return;
}

void displayBoard(piece **a, int size, bool reveal)
/*
============================================================================
Function : displayBoard
Parameters : array of pieces, the size, and a boolean to show pieces or not
Return : no return because void
Description : This function displays the stratego board from the struct
with corresponding pieces and colors.
============================================================================
*/
{
        cout << "    1 2 3 4 5  " << endl;
        cout << "  +-----------+" << endl;
        for (int i=0; i < size; i++)
        {
                cout << static_cast<char>(i+65) << " | ";
                for (int j=0; j < size; j++)
                {
                        if (a[i][j].col == BLUE)//printing blue
                        {
				if(reveal == false)
				{
					printf("\033[1;34m%c\033[0m%s", static_cast<char>('X'), " ");
				}
				else
				{
                                	printf("\033[1;34m%c\033[0m%s", static_cast<char>(a [i][j].type), " ");
                        	}
			}
                        else if (a[i][j].col == RED)//printing red
                        {
                                printf("\033[1;31m%c\033[0m%s", static_cast<char>(a [i][j].type), " ");
                        }
                        else//printing other
                        {
                                cout << static_cast<char>(a[i][j].type) << " ";
                        }
                }
                cout << "|" << endl;
        }
        cout << "  +-----------+" << endl;
}

bool updateBoard(piece **a, char row, int column, char rowN, int columnN)
/*
============================================================================
Function : updateBoard
Parameters : array of pieces, the row and column of the piece, and
row and column of new location
Return : bool representing whether game is over or not
Description : This function updates the stratego board from the struct
with corresponding pieces and colors, and positions.
============================================================================
*/
{
	row -= 65;
	column -= 1;
	rowN -= 65;
	columnN -=1;
	
	if(a[rowN][columnN].type == FLAG)//if flag attacked
	{
		cout << "RED " << static_cast<char>(a[row][column].type) << " at " << static_cast<char>(row+65) << column + 1 << " capture BLUE " << static_cast<char>(a[rowN][columnN].type) << " at " << static_cast<char>(rowN+65) << columnN+1 << ". Congratulation! " << endl;
		return true;
	}
	else if(a[rowN][columnN].type == NOTHING)//regular movement
	{
		cout << "RED " << static_cast<char>(a[row][column].type) << " move from " << static_cast<char>(row+65) << column+1 << " to " << static_cast<char>(rowN+65) << columnN+1 << endl;
		a[rowN][columnN] = a[row][column];
		a[row][column].type = NOTHING;
		a[row][column].col = NONE;
		a[row][column].moveable = false;
		return false;
	}
	else if(a[rowN][columnN].type == BOMB && a[row][column].type != MINER)//non-miner hit bomb
        {
                cout << "RED " << static_cast<char>(a[row][column].type) << " at " << static_cast<char>(row+65) << column+1 << " blown up by BLUE " << static_cast<char>(a[rowN][columnN].type) << " at " << static_cast<char>(rowN+65) << columnN+1 << endl;
        	a[row][column].type = NOTHING;
		a[row][column].col = NONE;
                a[row][column].moveable = false;
		return false;
	}
	else if(a[rowN][columnN].type == BOMB && a[row][column].type == MINER)//miner hit bomb
        {
                cout << "RED " << static_cast<char>(a[row][column].type) << " at " << static_cast<char>(row+65) << column+1 << " defuse BLUE " << static_cast<char>(a[rowN][columnN].type) << " at " << static_cast<char>(rowN+65) << columnN+1 << endl;
		a[rowN][columnN] = a[row][column];
                a[row][column].type = NOTHING;
		a[row][column].col = NONE;
                a[row][column].moveable = false;
        	return false;
	}
	else if(a[row][column].type == SPY && (a[rowN][columnN].type == MARSHAL || a[rowN][columnN].type == GENERAL))
	{
		cout << "RED " << static_cast<char>(a[row][column].type) << " at " << static_cast<char>(row+65) << column+1 << " capture BLUE " << static_cast<char>(a[rowN][columnN].type) << " at " << static_cast<char>(rowN+65) << columnN+1 << endl;
		a[rowN][columnN] = a[row][column];
                a[row][column].type = NOTHING;
                a[row][column].col = NONE;
                a[row][column].moveable = false;
                return false;
	}
	else if(a[rowN][columnN].type < a[row][column].type && a[rowN][columnN].type != NOTHING )//blue capture red
        {
                cout << "RED " << static_cast<char>(a[row][column].type) << " at " << static_cast<char>(row+65) << column+1 << " captured by BLUE " << static_cast<char>(a[rowN][columnN].type) << " at " << static_cast<char>(rowN+65) << columnN+1 << endl;
                a[row][column].type = NOTHING;
                a[row][column].col = NONE;
                a[row][column].moveable = false;
                return false;
        }
        else if(a[rowN][columnN].type > a[row][column].type && a[rowN][columnN].type != NOTHING)//red capture blue
        {
                cout << "RED " << static_cast<char>(a[row][column].type) << " at " << static_cast<char>(row+65) << column+1 << " capture BLUE " << static_cast<char>(a[rowN][columnN].type) << " at " << static_cast<char>(rowN+65) << columnN+1 << endl;
                a[rowN][columnN] = a[row][column];
                a[row][column].type = NOTHING;
                a[row][column].col = NONE;
                a[row][column].moveable = false;
                return false;
        }
	else if(a[rowN][columnN].type == a[row][column].type)
	{
		cout << "RED " << static_cast<char>(a[row][column].type) << " at " << static_cast<char>(row+65) << column+1 << " and BLUE " << static_cast<char>(a[rowN][columnN].type) << " at " << static_cast<char>(rowN+65) << columnN+1 << " capture each other " << endl;
		a[row][column].type = NOTHING;
                a[row][column].col = NONE;
                a[row][column].moveable = false;
		a[rowN][columnN] = a[row][column];
		return false;
	}
	else
        {
                return false;
        }
}
