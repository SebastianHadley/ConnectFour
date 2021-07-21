//Node
//Name - Sebastian Hadley
//Student - Number c3349742
//Course - SENG1120
//This file is used to store the trains as members of the linked list.
#ifndef NODE
#define NODE
#include <string>
#include <cstddef>
using namespace std;
class Node
{
public:
   //typedef statement
    typedef string value_type; 

   //Constructor
    Node();
    Node(const value_type& i = NULL,Node* n = NULL,Node* p = NULL);

    //Deconstructor
    ~Node();

    
    void setNext(Node* n);
    void setPrev(Node* p);
    void setData(const value_type& i);
    
    //Getters
    Node* getNext() const;
    Node* getPrev() const;
    value_type getData() const;

  private:
    Node* next; 
    Node* prev;
    value_type data;
};

#endif
