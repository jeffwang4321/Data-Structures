/*
 * Event.cpp
 * 
 * Class Description: Models the events-driven simulation of a bank. 
 * Class Invariant: Each event has a type Arrival(A) or Departure(D).
 *                  Each event has a time(Arrival time).
 *                  Each event has a length(Transaction time). 
 *
 * Last modified on: June, 29, 2017
 * Author: Jeff Wang 301309384 & Chao Chun Lai 301218471
 */
#include <iostream>
#include "Event.h"
using namespace std;

// Default Constructor
// Description: Create an event with type = 'A'.
// Postcondition: All data members set to 0, except type set to 'A'.
Event::Event():type('A'), times(0), length(0){
}

// Parameterized Constructor
// Description: Create an event with the given type, given time and given length.
Event::Event(char aType, int aTime, int aLength){
    type = aType;
    times = aTime;
    length = aLength;
}

// Getters and setters
// Description: Returns event's type.
char Event::getType() const{
    return type;
}

// Description: Returns event's time.
int Event::getTime() const{
    return times;
}

// Description: Returns event's length.
int Event::getLength() const{
    return length;
}

// Description: Sets the event's type.
void Event::setType(const char aType){
    type = aType;
}

// Description: Sets the event's time.
void Event::setTime(const int aTime){
    times = aTime;
}

// Description: Sets the event's length.
void Event::setLength(const int aLength){
    length = aLength;
}

// Description: Greater than operator. Compares "this" Event object with "rhs" Event object.
//              Returns true if the time of "this" Event object is > the time of "rhs" Event object.
//              If the time of "this" Event == the time of "rhs" Event. Return true, if the type of "this" Event > the type of "rhs" Event.
bool Event::operator > (const Event & rhs){
    //Compare both Event objects
    if(this->times > rhs.getTime()){
        return true;
    }
    //Compare both Event objects
    else if(this->times == rhs.getTime()){
         return this->type > rhs.getType();
    }
    else{
        return false;
    }
} //end of operator >

// Description: Prints the content of "this" patient.
ostream & operator<<(ostream & os, const Event & rhs){
    
    os << "Type: " <<rhs.getType() << " Time: " << rhs.getTime() << " Length: " << rhs.getLength() << endl;
    return os;
} //end of operator <<

//end of Event.cpp