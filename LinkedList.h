//LinkedList 
//Name - Sebastian Hadley
//Student - Number c3349742
//Course - SENG1120
//This file is used to define the data structure the trains are stored in.
#ifndef LINKEDLIST
#define LINKEDLIST
#include "Node.h"
#include <cstdlib>
class LinkedList {
public:
    //TYPEDEF
    typedef string value_type;
    //Constructor
    LinkedList();
    LinkedList(value_type& item);

    //Destructor
    ~LinkedList();

    //------Accessor Methods------//
    int getLength() const;
    value_type getCurrent() const;
    value_type getHead() const;
    //------Adding Nodes------//
    void addToHead(const value_type& item);
    void addToCurrent(const value_type& item);//
    void addToTail(const value_type& item);

    //------Removing Nodes------//
    value_type removeHead();
    void removeTail();
    void removeCurrent();

    //------Movements for Current------//
    void start();
    void end();
    void forward();
    void back();

    //------Calculations------//
    void operator += (LinkedList& reflist);
    void swap();
private:
    Node* head;
    Node* tail;
    Node* current;
    int listLength;
};


std::ostream& operator << (std::ostream& out, LinkedList& p);
#endif
