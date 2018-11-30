/*
 * Event.h
 * 
 * Class Description: Models the events-driven simulation of a bank. 
 * Class Invariant: Each event has a type Arrival(A) or Departure(D).
 *                  Each event has a time(Arrival time).
 *                  Each event has a length(Transaction time). 
 *
 * Last modified on: June, 29, 2017
 * Author: Jeff Wang 301309384 & Chao Chun Lai 301218471
 */

#pragma once
using namespace std;

class Event{
    private:
        char type;
        int times;
        int length;
    
    public:
        // Default Constructor
	    // Description: Create an event with type = 'A'.
	    // Postcondition: All data members set to 0, except type set to 'A'. 
        Event();

        // Parameterized Constructor
	    // Description: Create an event with the given type, given time and given length.
        Event(char aType, int aTime, int aLength);

        // Getters and setters
	    // Description: Returns event's type.
        char getType() const;

        // Description: Returns event's time.
        int getTime() const;

        // Description: Returns event's length.
        int getLength() const;

        // Description: Sets the event's type.
        void setType(const char aType);

        // Description: Sets the event's time.
        void setTime(const int aTime);

        // Description: Sets the event's length.
        void setLength(const int aLength);

        // Description: Greater than operator. Compares "this" Event object with "rhs" Event object.
	    //              Returns true if the time of "this" Event object is > the time of "rhs" Event object.
        //              If the time of "this" Event == the time of "rhs" Event. Return true, if the type of "this" Event > the type of "rhs" Event.
        bool operator > (const Event & rhs);

        //Description: Prints the content of "this" Event.
        friend ostream & operator<<(ostream & os, const Event & rhs);
};
// end of Event.h