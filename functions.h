#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<ctime>
#include<cctype>
using namespace std;

const int BOARD_SIZE = 5; // the size of the stratego board

//enums
enum rank {FLAG = 'F', BOMB = 'B', MARSHAL = '1', GENERAL = '2', COLONEL = '3', MAJOR = '4', CAPTAIN = '5', LIEUTENTANT = '6', SERGEANT = '7', MINER = '8', SPY = 'S', NOTHING = ' '}; //type of piece
enum color {RED, BLUE, NONE}; //color of piece

//struct
struct piece{
	rank type;
	color col;
	bool moveable;
};

//functions
void header(); //header
void rules(); //rules
void initializeBoard(piece **a, int size); //intializes the board
void assignBoard(piece **a, int size); //assigns pieces to the board
void displayBoard(piece **a, int size, bool reveal); //displays the board
bool updateBoard(piece **a, char row, int column, char rowN, int columnN);//updates the game board with moves
