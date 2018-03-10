#include "hw6prgm.h"
using namespace std;

int main()
{
        //header display
        header();

        //rules display
        rules();

	piece** boardP;
        boardP = new piece* [BOARD_SIZE]; //dynamic array of rows of pieces that will be on board
	for(int i=0; i < BOARD_SIZE; i++)
	{
		boardP[i] = new piece[BOARD_SIZE]; //dynamic array of columns of pieces that will be on boar
	}

        initializeBoard(boardP, BOARD_SIZE); //intializing the board
        assignBoard(boardP, BOARD_SIZE); //assigning pieces to the board
	displayBoard(boardP, BOARD_SIZE, false); //displaying the board

	char row = 0;//row of piece
	char rowN;//new row of piece
	int column = 0;//column of piece
	int columnN;//new column of piece
	bool x = false;//continue game or not

	do
	{
	        cout << "RED MOVE: Enter current coordinates of piece (e.g., D2, or QQ to quit): ";
	        cin >> row >> column;

		if(row != 'Q' && column != 'Q')
		{
			while(row < 65 || row > 69)//if row incorrect
			{
				cout << "Error: Invalid row location " << static_cast<char>(row) << ". Try again..." << endl;
				cout << "RED MOVE: Enter current coordinates of piece (e.g., D2, or QQ to quit): ";
             			cin >> row >> column;
			}
			while(column < 0 || column > 5)//if column incorrect
			{
				cout << "Error: Invalid column location " << column << ". Try again..." << endl;
                		cout << "RED MOVE: Enter current coordinates of piece (e.g., D2, or QQ to quit): ";
                		cin >> row >> column;
			}
			while(boardP[row - 65][column - 1].moveable == false)//if piece not moveble
                	{
                        	cout << "Error: Invalid piece or not moveable at " << static_cast<char>(row) << column << ". Try again..." << endl;
                        	cout << "RED MOVE: Enter current coordinates of piece (e.g., D2, or QQ to quit): ";
                        	cin >> row >> column;
                	}

			cout << "RED MOVE: Enter new coordinates of piece at " << static_cast<char>(row) << column << ": ";
			cin >> rowN >> columnN;
                	while(rowN < 65 || rowN > 69)//row incorrect
                	{
                        	cout << "Error: Invalid row location " << static_cast<char>(rowN) << ". Try again..." << endl;
                        	cout << "RED MOVE: Enter new coordinates of piece at " << static_cast<char>(row) << column << ": ";
                        	cin >> rowN >> columnN;
                	}
                	while(columnN < 0 || columnN > 5)//column incorrect
                	{
                        	cout << "Error: Invalid column location " << columnN << ". Try again..." << endl;
                        	cout << "RED MOVE: Enter new coordinates of piece at " << static_cast<char>(row) << column << ": ";
                        	cin >> rowN >> columnN;
                	}
			while(boardP[rowN-65][columnN-1].col == RED) //move to own piece
			{
				cout << "Error:Piece in way at " << static_cast<char>(rowN) << columnN << ". Try again..." << endl;
				cout << "RED MOVE: Enter new coordinates of piece at " << static_cast<char>(row) << column << ": ";
                        	cin >> rowN >> columnN;
			}

			while(columnN > column + 1 || columnN < column - 1 || rowN > row + 1 || rowN < row - 1 || (rowN == row + 1 && columnN == column+1) || (rowN == row + 1 && columnN == column - 1) || (rowN == row - 1 && columnN == column - 1) || (rowN == row - 1 && columnN == column+1) || (rowN == row && columnN == column))//invalid move
			{
				cout << "Error: Invalid piece move " << static_cast<char>(row) << column << " to " << static_cast<char>(rowN) << columnN << ". Try again..." << endl;
				cout << "RED MOVE: Enter new coordinates of piece at " << static_cast<char>(row) << column << ": ";
                        	cin >> rowN >> columnN;
			}

			x = updateBoard(boardP, row, column, rowN, columnN); //updating the board
			if (x == true)
			{
				displayBoard(boardP, BOARD_SIZE, true); //displaying the board revealed
			}
			else
			{
				displayBoard(boardP, BOARD_SIZE, false);//displaying the board unrevealed
			}
		}
	}while((row != 'Q' && column != 'Q') && x == false);//if user inputs qq to stop or win
	
	if (x == false)
	{
		cout << "RED player forfeits game. Please play again soon!" << endl;
	}

	for (int i = 0; i <BOARD_SIZE; i++)
	{
		delete[]boardP[i];//deleting columns
	}
	delete [] boardP; //deleting rows

        return 0;
}
