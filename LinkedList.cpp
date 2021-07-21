//LinkedList 
//Name - Sebastian Hadley
//Student - Number c3349742
//Course - SENG1120
//This file is used to define the data structure the trains are stored in.
#include "LinkedList.h"

//------Constructors------//

//Default
LinkedList::LinkedList()
{
    head = NULL;
    tail = NULL;
    current = NULL;
    listLength = 0;

}

//Specific
LinkedList::LinkedList(value_type& item)
{
    head = new Node(item);
    tail = head;
    current = head;
    listLength = 1;
}



//------Destructor------//

LinkedList::~LinkedList()
{
    while (head != NULL)
        removeHead();
    tail = NULL;
    delete head;
    delete tail;
    delete current;
 
}



//------Adding Nodes------//

//Adding At Head
void LinkedList::addToHead(const value_type& item)
{
    //For an empty list
    if(listLength == 0)
    {
        head = new Node(item);
        tail = head;
        current = tail;
        listLength = 1;
        return;
    }

    else
    {
        //1. New Node on heap.
        Node* inserthead = new Node(item);

        //2. set the heads previous ptr to the new head and set the next nodes 
        //next pointer to the node at the current head
        head->setPrev(inserthead);
        inserthead->setNext(head);

        //3. set the head to new node
        head = inserthead;

        //4.increment the list
        listLength++;
        
        //5.Unassign the new node
        inserthead = NULL;
        return;
    }
}

//Adding At Tail
void LinkedList::addToTail(const value_type& item)
{
    //For an empty list
    if (listLength == 0)
    {
        head = new Node(item);
        tail = head;
        current = tail;
        listLength = 1;
        return;
    }

    else
    {
        //1.New Node on the heap.
        Node* inserttail = new Node(item);

        //2. set the tails next ptr to the new tail and set the new nodes "prev 
        //ptr to the node at the current tail
        tail->setNext(inserttail);
        inserttail->setPrev(tail);

        //3. set the tail to new node
        tail = inserttail;

        //4.Unassign node
        inserttail = NULL;
        //5 increase list length
        listLength++;
        return;
    }
}

//Adding At Current
void LinkedList::addToCurrent(const value_type& item)
{
    if (listLength == 0)
    {
        head = new Node(item);
        tail = head;
        current = tail;
        listLength = 1;
        return;
    }
    return;
}



//------Removing Nodes------//

//Remove Head
LinkedList::value_type LinkedList::removeHead()
{
    //if list is empty do nothing
    if (listLength == 0)
    {
        return "";
    }

    //remove final node if only 1 node in list
    else if (listLength == 1)
    {
       value_type temp = head->getData();
        delete head;
        head = NULL;
        tail = NULL;
        current = NULL;
        listLength--;
        return temp;
    }
    
    else
    {
        //1.make a temporary head and set it as current
        value_type temp = head->getData();
        Node* temphead = head;
        
        //2. rearrange head for the list
        head = temphead->getNext();

        //3. Delete temporary head to prevent memory leak
       
        delete temphead;

        //4. set list length
        listLength--;

        //5.set NULL ptr
        temphead = NULL;
        return temp;
     // 
    }
    return "";
}

//Remove Tail
void LinkedList::removeTail()
{
    if (listLength == 0)
    {
        return;
    }

    //remove final node if only 1 node in list
    else if (listLength == 1)
    {
        delete head;
        head = NULL;
        tail = NULL;
        current = NULL;
        listLength--;
        return;
    }

    else
    {
        //1.make a temporary tail and set it as current
        Node* temptail = tail;

        //2. rearrange head for the list
        tail = temptail->getPrev();
        tail->setNext(NULL);
        //3. Delete temporary tail to prevent memory leak
        delete temptail;

        //4. set list length
        listLength--;

        //5.set NULL ptr
        temptail = NULL;
        
        return;
    }
    return;
}

//Remove Current
void LinkedList::removeCurrent()
{
    //If list is empty.
    if (listLength == 0)
    {
        return;
    }
    //If the list has only one node.
    else if (listLength == 1)
    {
        delete head;
        head = NULL;
        tail = NULL;
        current = NULL;
        listLength--;
        return;
    }
    //If the current node is the head node.
    else if (current == head)
    {
        removeHead();
        start();
        return;
    }
    //If the current node is the tail node.
    else if (current == tail)
    {
        removeTail();
        start();
        return;
    }
    //if the current node is anywhere between the tail and head.
    else
    {
        //set a temorary node and set it as current
        Node* tempcurrent = current;
        //rellocate current node to change the next and prev of current
        forward();
        current->setPrev(tempcurrent->getPrev());
        back();
        current->setNext(tempcurrent->getNext());
        start();
        //prevent memory leak.
        delete tempcurrent;
        //correct the length of list
        listLength--;
        //set NULL ptr
        tempcurrent = NULL;
        return;
      
    }
    return;
}

//------Accessor Methods------//

//Length of List
int LinkedList::getLength() const
{
    return listLength;
}

//Current Nodes Data
LinkedList::value_type LinkedList::getCurrent() const
{
    return current->getData();
}
LinkedList::value_type LinkedList::getHead() const
{
    return head->getData();

}



//------Movements for Current------///


//Moves current towards the tail.
void LinkedList::forward()
{
    current = current->getNext();
}
//Moves current towards the head.
void LinkedList::back()
{
    current = current->getPrev();
}
//Moves current to the head of the list.
void LinkedList::start()
{
    current = head;
}
//Moves current to the tail of then lsit.
void LinkedList::end()
{
    current = tail;
}



//------Calculations------//

//Swaps nodes index and current.




//------Overloading------//

//Used to define how the += operator works for Linked Lists.
void LinkedList::operator += (LinkedList& reflist) {
    //loops for the length of the list to add nodes to the tail.
    for (int i = 0; i < reflist.getLength(); i++)
    {
        addToTail(reflist.getCurrent());
        reflist.forward();
    }
    reflist.start();
    return;
}
//Allows direct output of a Linked List.
std::ostream& operator << (std::ostream& out,LinkedList& p)
{ 
    //loops for the length of the list to output each individual node.
    for (int i = 0; i < p.getLength(); i++)
    {
        out << p.getCurrent();
        p.forward();
    }
    p.start();
    return out;
    
}

