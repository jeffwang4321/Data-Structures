/* 
 * PriorityQueue.h - Header of the PriorityQueue.class
 *
 * Description: Array-based implementation of data collection PriorityQueue ADT.
 * 
 * Class invariants: FIFO or LILO.
 *                   The elements stored in PriorityQueue are always sorted.
 * 
 * Last modified on: June, 29, 2017
 * Author: Jeff Wang 301309384 & Chao Chun Lai 301218471
 */
#pragma once
#include "EmptyDataCollectionException.h"

template <class ElementType>
class PriorityQueue {

private:

// We must complete this section.
static const int CAPACITY = 100;
ElementType arr[CAPACITY]; // Array of PriorityQueue items
int front;  // Index to front of PriorityQueue
int back;   // Index to back of PriorityQueue
int elementCount;   // Number of elements currently in the PriorityQueue
 
public:

// Let's put our constructor(s) and destructor (if any) ***here***.
   //Description: Default Constructor
   PriorityQueue();
   
   //Description: Copy Constructore to copy an existing PriorityQueue.
   PriorityQueue(const PriorityQueue& PQ);
   
   //Description: Destructor
   ~PriorityQueue();

/******* Public Interface - START - *******/
        
   // Description: Returns the number of elements in the Priority Queue.
   // (This method eases testing.)
   // Time Efficiency: O(1)
   int getElementCount() const;   
   
   // Description: Returns "true" is this Priority Queue is empty, otherwise "false".
   // Time Efficiency: O(1)
   bool isEmpty() const;
    
   // Description: Inserts newElement in sort order.
   //              It returns "true" if successful, otherwise "false".
   // Precondition: This Priority Queue is sorted.   
   // Postcondition: Once newElement is inserted, this Priority Queue remains sorted.    
   // Time Efficiency: O(n)        
   bool enqueue(const ElementType& newElement);
      
   // Description: Removes the element with the "highest" priority.
   //              It returns "true" if successful, otherwise "false".
   // Precondition: This Priority Queue is not empty.
   // Time Efficiency: O(1) 
   bool dequeue();
    
   // Description: Returns (a copy of) the element with the "highest" priority.
   // Precondition: This Priority Queue is not empty.
   // Postcondition: This Priority Queue is unchanged.
   // Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
   // Time Efficiency: O(1) 
   ElementType peek() const throw(EmptyDataCollectionException);
   
/******* Public Interface - END - *******/
    // Let's feel free to add other private helper methods to our Priority Queue class.
    //Description: Print the cotents of the PriorityQueue from the first to the last element.
    void printPriorityQueue();

}; // end PriorityQueue


//////////////////////////////////////PriorityQueue.cpp/////////////////////////////////////
#include <iostream>
#include "PriorityQueue.h"

//Default Constructor
template <class ElementType>
PriorityQueue<ElementType>::PriorityQueue():front(0), back(CAPACITY-1), elementCount(0){
}

//Description: Copy constructor to copy an existing PriorityQueue class
template <class ElementType> 
PriorityQueue<ElementType>::PriorityQueue(const PriorityQueue& PQ){
    //Copy data members of existing PriorityQueue to new PriorityQueue.
    elementCount = PQ.elementCount;
    front = PQ.front;
    back  = PQ.back;
    for( int index = 0; index < elementCount; index ++){
       arr[index] = PQ.arr[index];
    }
}

//Destructor
template <class ElementType>
PriorityQueue<ElementType>::~PriorityQueue(){
}

// Description: Returns the number of elements in the Priority Queue.
// (This method eases testing.)
// Time Efficiency: O(1)
template <class ElementType>
int PriorityQueue<ElementType>::getElementCount() const{
    return elementCount;
}

// Description: Returns "true" is this Priority Queue is empty, otherwise "false".
// Time Efficiency: O(1)
template <class ElementType>
bool PriorityQueue<ElementType>::isEmpty() const{
    return elementCount == 0;
}

// Description: Inserts newElement in sort order.
//              It returns "true" if successful, otherwise "false".
// Precondition: This Priority Queue is sorted.   
// Postcondition: Once newElement is inserted, this Priority Queue remains sorted.    
// Time Efficiency: O(n)  
template <class ElementType>
bool PriorityQueue<ElementType>::enqueue(const ElementType& newElement){
    bool queuedOK = false;
    int where = elementCount;
    //Execute insert if elementCount < CAPACITY.
    if (elementCount < CAPACITY){
        //Set newElement at front if PriorityQueue is empty.
        if(elementCount == 0){
            arr[front] = newElement;
        }
        else{
            //Inserting the newElement and shifting remaining elements one index to the right.
            for(int index = 0; index < elementCount && !queuedOK; index++){
                if((arr[index] > newElement ) == 1){
                    for(int shift = elementCount; shift > index; shift--){
                        arr[shift] = arr[shift-1];
                    }
                    where = index;
                    queuedOK = true;
                }
            }
        }
        //Insert new element and increment elementCount.
        arr[where] = newElement;
        elementCount++;
        queuedOK = true;
    }
    
    return queuedOK;
}

// Description: Removes the element with the "highest" priority.
//              It returns "true" if successful, otherwise "false".
// Precondition: This Priority Queue is not empty.
// Time Efficiency: O(1) 
template <class ElementType>
bool PriorityQueue<ElementType>::dequeue(){
    bool dequeuedOk = false;
    //Dequeue front if PriorityQueue is empty.
    if(elementCount != 0){
        //Shifting elements one index to the left.
        for(int index = 1; index < elementCount; index++){
            arr[index-1] = arr[index];
        }
        dequeuedOk = true;
        elementCount--;
    }

    return dequeuedOk;
}

// Description: Returns (a copy of) the element with the "highest" priority.
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
// Time Efficiency: O(1) 
template <class ElementType>
ElementType PriorityQueue<ElementType>::peek() const throw(EmptyDataCollectionException){
    if(isEmpty())
        throw EmptyDataCollectionException("peek() called with empty queue.");

    return arr[front];
}

//Description: Print the cotents of the PriorityQueue from the first to the last element.
template <class ElementType> 
void PriorityQueue<ElementType>::printPriorityQueue(){
	// Traverse the list
	for(int i = 0; i < elementCount; i++){
        cout << arr[i];
	}
    cout << endl;
}
//end of PriorityQueue.h
