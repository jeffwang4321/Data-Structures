/* 
 * Queue.h - Header of the Queue.class
 *
 * Description: Link-based implementation of data collection PriorityQueue ADT.
 *              Its underlying data structure is a doubly-headed singly-linked list (DHSL).
 * 
 * Class invariants: FIFO or LILO
 * 
 * Last modified on: June, 29, 2017
 * Author: Jeff Wang 301309384 & Chao Chun Lai 301218471
 */
#pragma once
#include "Node.h"
#include "EmptyDataCollectionException.h"
template <class ElementType>
class Queue {

private:

// We must complete this section.
    int elementCount;           // Number of elements currently in the Queue.
    Node<ElementType>* head;    //Pointer to the first Node in Queue.
    Node<ElementType>* tail;    //Pointer to the last Node in Queue.

public:
// Let's put our constructor(s) and destructor (if any) ***here***.
    //Description: Default Constructore
    Queue();

    //Description: Copy Constructore to copy an existing Queue.
    Queue(const Queue& Q);

    //Description: Destructor.
    ~Queue();
/******* Public Interface - START - *******/
        
   // Description: Returns the number of elements in the Queue.
   // (This method eases testing.)
   // Time Efficiency: O(1)
   int getElementCount() const;

   // Description: Returns "true" is this Queue is empty, otherwise "false".
   // Time Efficiency: O(1)
   bool isEmpty() const;
   
   // Description: Adds newElement to the "back" of this Queue 
   //              (not necessarily the "back" of its data structure) and 
   //              returns "true" if successful, otherwise "false".
   // Time Efficiency: O(1)
   bool enqueue(const ElementType& newElement);
   
   // Description: Removes the element at the "front" of this Queue 
   //              (not necessarily the "front" of its data structure) and  
   //              returns "true" if successful, otherwise "false".
   // Precondition: This Queue is not empty.
   // Time Efficiency: O(1)
   bool dequeue();
   
   // Description: Returns (a copy of) the element located at the "front" of this Queue.
   // Precondition: This Queue is not empty.
   // Postcondition: This Queue is unchanged.
   // Exceptions: Throws EmptyDataCollectionException if this Queue is empty.
   // Time Efficiency: O(1)
   ElementType peek() const throw(EmptyDataCollectionException);  
 
/******* Public Interface - END - *******/
    // Let's feel free to add other private helper methods to our Queue class.
    //Description: Print the cotents of the Queue from head to tail.
    void printQueue();
}; // end Queue



/////////////////////////////////////Queue.cpp//////////////////////////////////
#include <iostream>
#include "Queue.h"
using namespace std;

//Description: Default Constructore
template <class ElementType> 
Queue<ElementType>::Queue(){
	elementCount = 0;
	head = NULL;
    tail = NULL;
}

//Description: Copy Constructore to copy an existing Queue.
template <class ElementType> 
Queue<ElementType>::Queue(const Queue& Q){
	elementCount = Q.elementCount;
	head = NULL;
	Node<ElementType>* p = Q.head;
	// Traverse the first list
	while (p != NULL){
		enqueue(p -> data); // add data
		p = p -> next; // Go to next Node
	}
}

//Description: Destructor.
template <class ElementType>
Queue<ElementType>::~Queue(){
    while (head != NULL){
        Node<ElementType>* temp = head->next;
        delete head;
   		head = temp;
	}
}

// Description: Returns the number of elements in the Queue.
// (This method eases testing.)
// Time Efficiency: O(1)
template <class ElementType> 
int Queue<ElementType>::getElementCount() const {
	return elementCount;
}

// Description: Returns "true" is this Queue is empty, otherwise "false".
// Time Efficiency: O(1)
template <class ElementType> 
bool Queue<ElementType>::isEmpty() const{
    return elementCount == 0;
}

// Description: Adds newElement to the "back" of this Queue 
//              (not necessarily the "back" of its data structure) and 
//              returns "true" if successful, otherwise "false".
// Time Efficiency: O(1)
template <class ElementType> 
bool Queue<ElementType>::enqueue(const ElementType& newElement){
	Node<ElementType> *p = new Node<ElementType>; //temporary node
	bool result = false;
	
	if ( p != NULL ) {
        //If head is empty insert first item at head.
        if(head == NULL){
		    p->data = newElement;
		    head = p;
        }
        //Else insert new item at tail.
        else{
            p->data = newElement;
            tail->next = p;
        }
        //Increment elementCount and set new tail.
		elementCount++;
        tail = p;
        p->next = NULL;
		result = true;
	}
	return result;
}

// Description: Removes the element at the "front" of this Queue 
//              (not necessarily the "front" of its data structure) and  
//              returns "true" if successful, otherwise "false".
// Precondition: This Queue is not empty.
// Time Efficiency: O(1)
template <class ElementType> 
bool Queue<ElementType>::dequeue() {
	bool result = false;
	
	//Dequeue the first item if list is not empty.
    if (head != NULL) {
            Node<ElementType> *p = head;
			head = head->next;
            p->next = NULL;
			delete p; //currently assigned head
            p = NULL;
			elementCount--;
			result = true;
	    }
	return result;
}

// Description: Returns (a copy of) the element located at the "front" of this Queue.
// Precondition: This Queue is not empty.
// Postcondition: This Queue is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Queue is empty.
// Time Efficiency: O(1)
template <class ElementType>
ElementType Queue<ElementType>::peek() const throw(EmptyDataCollectionException){
    if(isEmpty())
        throw EmptyDataCollectionException("peek() called with empty queue.");

    return head->data;
}

//Description: Print the cotents of the Queue from head to tail.
template <class ElementType> 
void Queue<ElementType>::printQueue(){
	Node<ElementType> *p = head;
	// Traverse the list
	while (p != NULL){
		cout << p -> data; // Print data
		p = p -> next; // Go to next Node
	}
}
