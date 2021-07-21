//Lstack
//Name - Sebastian Hadley
//Student - Number c3349742
//Course - SENG1120
//This file is used to define the Stacks used in the game
#ifndef LSTACK
#define LSTACK
#include "LinkedList.h"
#include <iostream>
#include <string>
class Stack
{
public:
	//------TypeDef Declarations------//
	typedef string value_type;
	//------Constructor and destructor------//
	//Default Constructor
	Stack();
	//Destructor
	~Stack();
	//------Mutator Methods------//

	//Insert Object at Top.
	void push(value_type& obj);
	//Remove and Return Object from top of Stack.
	value_type pop();
	//Removes object from top of stack.
	void remove();

	//------Accessor Methods------//

	//Return a reference to the object at the top of the stack, NULL if the stack is empty.
	value_type peek();
	//Return Number of Objects in Stack.
	int size() const;
	int size2() const;
	//Return Bool Indicating if Stack is Empty.
	bool is_empty() const;


private:
	LinkedList data;
	int used;


};
#endif
