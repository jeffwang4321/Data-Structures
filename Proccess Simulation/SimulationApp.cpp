/*
 * SimulationApp.cpp
 *
 * Class Description: Models a event-driven  simulation of a bank..
 *
 *
 *
 * Created on: June, 29, 2017
 * Author: Jeff Wang 301309384 & Chao Chun Lai 301218471
 */
#include <iostream>
#include <sstream>
#include <iomanip>
#include "Event.h"
#include "Queue.h"
#include "PriorityQueue.h"
#include "EmptyDataCollectionException.h"
using namespace std;

//Description: Process an arrival event.
//Precondition: arrivalEvent is not an empty event.
//Postcondition: Return whether or not teller is free.
bool processArrival(Event arrivalEvent, PriorityQueue<Event>& pQueue, Queue<Event>& Queue, int curTime, bool tellerIsFree){
    int departTime;
    Event newDepartEvent;
    
    //Print arrival time.
    cout << "Processing an arrival event at time: " << setw(4) <<right << arrivalEvent.getTime() << endl;

    //Remove this event from PriorityQueue
    pQueue.dequeue();

    //Calculate new departure time and enqueue to PriorityQueue.
    if(Queue.isEmpty() && tellerIsFree){
        departTime = curTime + arrivalEvent.getLength();
        newDepartEvent = Event('D', departTime, 0);
        pQueue.enqueue(newDepartEvent);
        tellerIsFree = false;
    }
    else{
        Queue.enqueue(arrivalEvent);
    }
    return tellerIsFree;
}

//Description: Process an departure event.
//Precondition: departureEvent is not an empty event.
//Postcondition: Return whether or not teller is free.
bool processDeparture(Event departureEvent, PriorityQueue<Event>& pQueue, Queue<Event>& Queue, int curTime, bool tellerIsFree){
    Event customer;
    Event newDepartEvent;
    int departTime;
    
    //Print depature time.
    cout << "Processing a departure event at time:" << setw(4) <<right << departureEvent.getTime() << endl;
    try{
        //Remove this event from PriorityQueue
        pQueue.dequeue();
        
        if(!Queue.isEmpty()){
            //Customer at front of line begins transaction.
            customer = Queue.peek();
            Queue.dequeue();
            departTime = curTime + customer.getLength();
            newDepartEvent = Event('D', departTime, 0);
            pQueue.enqueue(newDepartEvent);
        }
        else{
            tellerIsFree = true;
        }
    }
    catch ( EmptyDataCollectionException&anException ) {
        cout << "peeking() unsuccessful because " << anException.what() << endl;
    }
    return tellerIsFree;
}

//Description: Calculate the average waiting time.
//Precondition: PriorityQueue is not empty.
//Postcondition: Return the average wait time of customers.
float calcAvgWaitTime(PriorityQueue<Event> pQueue){
    Event waitEvent;
    float wait = 0;
    int departure = 0;
    int maxCustomer = pQueue.getElementCount();
    
    while(!pQueue.isEmpty()){
        try{
            waitEvent = pQueue.peek();
            //Calculate departure time.
            if(waitEvent.getTime() < departure){
                departure += waitEvent.getLength();
            }
            else{
                departure = waitEvent.getTime() + waitEvent.getLength();
            }
            
            //Remove this event form the PriorityQueue.
            pQueue.dequeue();
            
            if(!pQueue.isEmpty()){
                try{
                    waitEvent = pQueue.peek();
                    //Use departure time and arrival time to calculate wait time.
                    if(departure - waitEvent.getTime() > 0){
                        wait += departure - waitEvent.getTime();
                    }
                }
                catch( EmptyDataCollectionException&anException ) {
                    cout << "peeking() unsuccessful because " << anException.what() << endl;
                }
            }
        }
        catch( EmptyDataCollectionException&anException ) {
            cout << "peeking() unsuccessful because " << anException.what() << endl;
        }
    }
    return wait/maxCustomer;
}

int main(){
    string aLine = "";
    int length = 0;
    int times = 0;
    int currentTime = 0;
    int peopleCount = 0;
    float avgWaitTime = 0.0;
    bool lineIsEmpty = true;
    PriorityQueue<Event> EventPQ;
    Queue<Event> lineupQ;
    Event peekedEvent;
    Event newEvent;

    //Create and add arrival events to PriorityQueue.
    while(getline(cin >> ws, aLine)) {   // while (there is data)
      stringstream ss(aLine);
      ss >> times >> length;      
      newEvent = Event('A', times, length);
      if (!EventPQ.enqueue(newEvent))  return 1;
    }
    //Retrieve total number of people processed.
    peopleCount = EventPQ.getElementCount();

    cout << "Simulation Begins" << endl;
    
    //Call calcAvgWaitTime and calculate event wait time.
    avgWaitTime = calcAvgWaitTime(EventPQ);

    //Event loop.
    while(!EventPQ.isEmpty()){
      try {
        peekedEvent = EventPQ.peek();
        
        //Get current time.
        currentTime = peekedEvent.getTime();
        
        //If new element is an arrival event.
        if(peekedEvent.getType() == 'A'){
          //Call processArrival.
          lineIsEmpty = processArrival(peekedEvent, EventPQ, lineupQ, currentTime, lineIsEmpty);
        } 
        else{
          //Call processDeparture.
          lineIsEmpty = processDeparture(peekedEvent, EventPQ, lineupQ, currentTime, lineIsEmpty);
        }
      }
      catch ( EmptyDataCollectionException&anException ) {
        cout << "peeking() unsuccessful because " << anException.what() << endl;
      }
    }

    //Print out number of people and average wait time.
    cout << "Simulation Ends" << endl;
    cout << endl << "Final Statistics: " << endl;
    cout << "\tTotal number of people processed:  " << peopleCount << endl;
    cout << "\tAverage amount of time spent waiting: " << avgWaitTime << endl;

    return 0;
}
//End of SimulationApp.cpp.
