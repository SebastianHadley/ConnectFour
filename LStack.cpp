//Lstack
//Name - Sebastian Hadley
//Student - Number c3349742
//Course - SENG1120
//This file is used to define the Stacks used in the game
#include "LStack.h"

//------Constructors/Destructor------//
//Default Constructor
Stack::Stack()
{

}
//Destructor
Stack::~Stack()
{

}

//------Mutator Methods------//

//Stores at top of the stack.
void Stack::push(value_type& obj)
{
	data.addToHead(obj);
}
//Removes the data from the top of the stack and returns it.
Stack::value_type Stack::pop()
{
	return data.removeHead();
}
//Removes the data from the head without returning it.
void Stack::remove()
{
	data.removeHead();
}

//------Accessor Methods------//

//Checks if the Stack is empty and returns a bool.
bool Stack::is_empty() const
{
	if (data.getLength() > 0)
	{
		return false;
	}
	else
		return true;
}
//Returns the data from the top of the stack.
string Stack::peek()
{

	return data.getHead();
}
//Returns the length of the Stack.
int Stack::size() const
{
	return data.getLength();
}

int Stack::size2() const
{
	return used;
}
