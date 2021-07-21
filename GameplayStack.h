//Gameplay Stack
//Name - Sebastian Hadley
//Student - Number c3349742
//Course - SENG1120
//This file is used to build the functions the game runs on 
#ifndef GAMEPLAYSTACK
#define GAMEPLAYSTACK
#include "LStack.h"
#include <string> 
#include <iostream>
class GameplayStack
{
	public:
		typedef string value_type;
		//------Constructor and Destructor------//
		GameplayStack();
		~GameplayStack();
		//------Board Mutators------//
		void initializeBoard();
		void play(value_type pc, int loc);
		string displayBoard();
		//------Game Checks------//
		void winCheck(int position);
		void drawCheck();
		void horizCheck(int i);
		void vertCheck(int i);
	private:
		Stack board[7];
		value_type winner;
};



#endif