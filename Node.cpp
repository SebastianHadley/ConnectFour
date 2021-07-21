//Node
//Name - Sebastian Hadley
//Student - Number c3349742
//Course - SENG1120
//This file is used to store the trains as members of the linked list.
#include "Node.h"

using namespace std;

//------Constructors------//
//Default
Node::Node()
{

}

//Specific
Node::Node(const value_type& i, Node* n, Node* p)
 {
  data = i;
  next = n;
  prev = p;
 }



//-------Destructor------//

Node::~Node()
{
	next = NULL;
	prev = NULL;
}


//-------Accessor Methods------//

  Node::value_type Node::getData() const
 {
  return data;
 }
  
 Node* Node::getNext() const
 {
	return next;
 }
 
 Node* Node::getPrev() const
 {
	return prev;
 }



  //------Mutator Methods------//

void Node::setData(const value_type& i)
{
  data = i;
}

void Node::setNext(Node* n)
{
  next = n;
}
void Node::setPrev(Node* p)
{
	prev = p;
}
