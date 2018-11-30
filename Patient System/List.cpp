/*
 * List.cpp
 * 
 * Class Description: A value-oriented List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - It is sorted by ascending sort order of its elements.
 *                   - Its data structure is expandable: when full, it expands to accommodate 
 *                     new insertion. This is done unbeknown to the client code.
 *
 * Last modified on: June, 07, 2017
 * Author: Jeff Wang 301309384 & Chao Chun Lai 301218471
 */

#include<iostream>
#include"List.h"
#include<string>
#include<cassert>

using namespace std;

    //Constructor
    List::List(): elementCount(0), maxElements(DEFAULT_CAPACITY){
    }

    //Destructor
    List::~List(){
        delete[] elements;
    }

    // *** Start of Public Interface ***    
    // Note: Public Interface must not be modified.

	// Description: Returns the total element count currently stored in List.
	int List::getElementCount() const{
        return elementCount;
    }

	// Description: Insert an element.
    //              When "this" List is full, its data structure is expanded to accommodate 
    //              a new element. This is done unbeknown to the client code.
	//              If the insertion is successful, true is returned otherwise, false is returned.
	// Precondition: newElement must not already be in data collection.  
	// Postcondition: newElement inserted and the appropriate elementCount has been incremented.	
	bool List::insert(const Patient& newElement){
         bool done = false;
         int where = elementCount;

         //search for repeated element, execute if not.
         if(search(newElement) == NULL){
            //Expand array size if elementCount hits maxElements
            if(elementCount == maxElements-1){
                maxElements = maxElements * 2;
                Patient* newArray = new Patient[maxElements];
                for(int i=0; i < elementCount; i++){
                    newArray[i] = elements[i];
                }
                delete [] elements;
                elements = newArray;
            }
            //Inseting elements and shifting remaining elements one index to the right
            for(int index = 0; index < elementCount && !done; index++){
                if(elements[index] > newElement){
                    for(int shift = elementCount; shift > index; shift--){
                        elements[shift] = elements[shift-1];
                    }
                    where = index;
                    done = true;
                }
            }
            //Set new element and increment elementCount
            elements[where] = newElement;
            elementCount++;
            done = true;
         }
         return done;
    }

	// Description: Remove an element. 
	//              If the removal is successful, true is returned otherwise, false is returned.
	// Postcondition: toBeRemoved is removed, the appropriate elementCount has been decremented.	
	bool List::remove( const Patient& toBeRemoved ){
        bool check = false;
        //search for element toBeRemoved, execute if found.
        if(search(toBeRemoved) != NULL){
            for(int i=0; i < elementCount; i++){
                if(elements[i] == toBeRemoved){
                    check = true;
                }
                //Shifting elements one index to the left.
                if(check == true){
                    elements[i] = elements[i+1];
                }
            }
            elementCount--;
        }
        return check;
    }
	
	
    // Description: Remove all elements.
    void List::removeAll(){
        elementCount = 0;
    }
   

	// Description: Search for target element and returns a pointer to it if found,
	//              otherwise, returns NULL.
	Patient* List::search(const Patient& target){ 
        for(int i=0; i < elementCount; i++){
            if(elements[i] == target){
                return &elements[i];
            }
        }
        return NULL;
    }
   
	// Description: Prints all n elements stored in List in sort order and does so in O(n).
    void List::printList(){
        for(int i = 0; i < elementCount; i++){
            elements[i].printPatient();
        }
    }
	
// *** End of Public Interface ***