//Gameplay Stack
//Name - Sebastian Hadley
//Student - Number c3349742
//Course - SENG1120
//This file is used to build the functions the game runs on 
#include "GameplayStack.h"
//------Constructor and Destructor------//

//Default Constructor
GameplayStack::GameplayStack()
{
	Stack board[7];
	winner = "empty";
}
//Destructor
GameplayStack::~GameplayStack()
{
}

//------Board Mutators------//

//Loops to clear the Stacks in each position of the board.
void GameplayStack::initializeBoard() 
{
	for(int i = 0; i < 7; i++) 
		{
		while (board[i].is_empty() == 0)
		{
			board[i].remove();
		}
	}
}
//Handles the placement of pieces and implements the checking functions.
void GameplayStack::play(value_type pc, int loc) 
{
	int position = loc - 1;
	board[position].push(pc);
	drawCheck();
	winCheck(position);
	return;
}
//Outputs the board to visualize the game.
string GameplayStack::displayBoard()
{
	cout << winner << " Wins" << endl;
	winner = "empty";
	for (int i = 0; i < 7; i++)
	{
		string space = " ";
		while (board[i].size() < 7)
		{
			board[i].push(space);
		}
		
	}
	for (int i = 0; i < 7; i++) {
		cout << "#";
		for (int j = 0; j < 7; j++)
		{
			{
				cout << " " << board[j].pop() << " ";
			}
		}
		cout << "#";
		cout << endl;
	}
	cout << "#######################" << endl;
	cout << "  1  2  3  4  5  6  7" << endl;
	return "";
}

//------Game Checks------//
//Checks for vertical wins.
void GameplayStack::vertCheck(int i){
	string tempstring = board[i].peek();;
	if (board[i].size() > 3) {
		string temp1 = board[i].pop();
		string temp2 = board[i].pop();
		string temp3 = board[i].pop();
		string temp4 = board[i].peek();
	
		if (temp1 == temp2 && temp3 == temp4 && temp4 == temp1)
		{
			winner = tempstring;
			board[i].push(tempstring);
			board[i].push(tempstring);
			board[i].push(tempstring);
			return;
		}
		else
		board[i].push(temp3);
		board[i].push(temp2);
		board[i].push(temp1);

		return;
	}
	
}
//Checks for horizontal wins.

void GameplayStack::horizCheck(int i)
{
	string temp1, temp2;
	Stack tempsave[7];
	Stack tempboard[7];
	//Creates two temporary board that reverse the main board.
	for (int x = 0; x < 7; x++)
	{
		while (board[x].is_empty() == 0)
		{
			string tempstring = board[x].pop();
			tempboard[x].push(tempstring);
			tempsave[x].push(tempstring);
		}
	}
	//Uses a temporary board to check the win conditions
	for (int x = 0; x < 4; x++)
	{
		if (tempboard[x].is_empty() == 0 && tempboard[x + 1].is_empty() == 0 && tempboard[x + 2].is_empty() == 0 && tempboard[x + 3].is_empty() == 0)
		{
			string tempwinner = tempboard[3].peek();
			tempboard[x].peek() = temp1;
			tempboard[x + 3].peek() = temp2;
			if (tempboard[x].pop() == tempboard[x + 1].pop() && tempboard[x + 2].pop() == tempboard[x + 3].pop() && temp1 == temp2)
			{
				string winstring = tempwinner;
				winner = winstring;
			}
		}
	}
		//Returns board to its previous state
	for (int x = 0; x < 7; x++)
	{
		while(tempsave[x].is_empty() == 0)
		{
			string tempstring = tempsave[x].pop();
			board[x].push(tempstring);
		}
	}
	return;
}
	

//Combines the two checkers to check the board as a whole.
void GameplayStack::winCheck(int i) 
{			

		vertCheck(i);
		horizCheck(i);
		return;
}
		

//Checks for draws.
void GameplayStack::drawCheck() 
{
	int j = 0;
	for (int i = 0; i < 7; i++)
	{
		if (board[i].size() == 6)
		{
			j = j + 1;
		}
	}
	if (j == 6) {
		if (winner == "empty")
		{
			winner = "draw";
			return;
		}
	}
	j = 0;
	return;
}
		
