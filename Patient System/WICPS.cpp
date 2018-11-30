/*
 * WICPS.cpp
 *
 * Class Description: Models a walk-in clinic patient.
 *
 *
 *
 * Created on: June, 07, 2017
 * Author: Jeff Wang 301309384 & Chao Chun Lai 301218471
 */

#include <iostream>
#include <string>
#include <stdlib.h>  
#include <cctype>
#include "Patient.h"
#include "List.h"

using namespace std;


// Description: Inserts one new Carecard number into the system
// Precondition: theMembers must not already be in data collection.
// Postcondition: theMembers inserted and elementCount has been incremented.
void enter(List * theMembers, string toInsert) { 

   // Entering a new patient
   Patient pInsert = Patient(toInsert);

   if(pInsert.getCareCard() == "error"){
     cout << "Invalid Carecard number please input 10 digits." << endl;
     return;
   }

   // Add new member profile to the list, checks if full
   if(theMembers->search(pInsert) == NULL){
      //Set patient's information
      cout << "Please, enter the name: ";
      getline(cin >> ws, toInsert);
      pInsert.setName(toInsert);

      cout << "Please, enter the address: ";
      getline(cin >> ws, toInsert);
      pInsert.setAddress(toInsert);

      cout << "Please, enter the phone number: ";
      getline(cin >> ws, toInsert);
      pInsert.setPhone(toInsert);

      cout << "Please, enter the email: ";
      getline(cin >> ws, toInsert);
      pInsert.setEmail(toInsert);

      theMembers->insert(pInsert);
      // Report to user
      cout << "Carecard Number: " << pInsert.getCareCard() << " has successfully joined." << endl;

    }else{
      //Capacity is full
      cout << pInsert.getCareCard() << " was unable to join, due to repeat." << endl;
    }
    return;
}


// Description: Removes one Carecard number from the system
// Precondition: theMembers must be in data collection.
// Postcondition: theMembers removed and elementCount has been decreased.
void remov(List * theMembers, string toRemove) {
  
  //Checks if the System is empty
  if(theMembers->getElementCount() != 0){

    Patient pRemove = Patient(toRemove);
    
    //execute if patient found
     if(theMembers->remove(pRemove)){
       // Report to user
        cout << "Carecard Number: " << toRemove << " has successfully been removed." << endl;
     }else{
        //Carecard number does not match
        cout << "Carecard Number: " << toRemove << " does not exist." << endl;
     }

 }else{
   //System is empty
   cout << "There are no patients in the system to remove or Carecard Number: " << toRemove << " does not exist." << endl;
 }
 return;
}


// Description: Removes all patients from the system
// Precondition: System must contian at least one patient
// Postcondition: All patients removed and elementCount set to 0.
void aremov(List* sect[]) {
  bool check = false;

  //Checks if the System is empty
  for(int i = 0; i < 10; i++){
    if(sect[i] -> getElementCount() != 0){
      sect[i] -> removeAll();
      check = true;
    }
  }
  
  if(check == true){
    // Report to user
    cout << "All patients have successfully been removed." << endl;
  }else{
    //System is empty
    cout << "There are no patients in the system to remove." << endl;
  }
  return;
}


// Description: Modifies one patient in the system
// Precondition: System must contian at least one patient
// Postcondition: The patient is modified.
void modify(List * theMembers, string toModify) {
  
  //Checks if the System is empty
  if(theMembers->getElementCount() != 0){

    //execute if patient found
    if(theMembers -> search(toModify) != NULL){

      Patient pModify = Patient(toModify);
      theMembers -> remove(pModify);

      cout << "Please, modify the name: ";
      getline(cin >> ws, toModify);
      pModify.setName(toModify);

      cout << "Please, modify the address: ";
      getline(cin >> ws, toModify);
      pModify.setAddress(toModify);

      cout << "Please, modify the phone number: ";
      getline(cin >> ws, toModify);
      pModify.setPhone(toModify);

      cout << "Please, modify the email: ";
      getline(cin >> ws, toModify);
      pModify.setEmail(toModify);

      theMembers -> insert(pModify);

      //Report to user
      cout << "Carecard Number: " << pModify.getCareCard() << " has successfully been modified." << endl;

    }else{
      //Carecard number does not match
      cout << "Carecard Number: " << toModify << " does not exist." << endl;
    }

  }else{
    //System is empty or does not match
    cout << "There are no patients in the system to modify or Carecard Number: " << toModify << " does not exist." << endl;
  }
  return;
}


// Description: Searches for one patient in the system
// Precondition: System must contian at least one patient
// Postcondition: The patient is found or unfound.
void search(List * theMembers, string toSearch) {
  
  //Checks if the System is empty
  if(theMembers->getElementCount() != 0){

    //execute if patient found
    if(theMembers->search(toSearch) != NULL){
        cout << "Carecard Number: " << toSearch << " has successfully been found." << endl;
    }else{
        //Carecard number does not match
        cout << "Carecard Number: " << toSearch << " does not exist." << endl;
    }

  }else{
      //System is empty or does not match
      cout << "There are no profiles in the system to search or careCard" << toSearch << "does not exist." << endl;
  }
  return;
}

// Description: Prints all patients by ascending Carecard numbers
// Precondition: System must contian at least one patient
// Postcondition: All patients are printed in ascending order
void print(List* sect[]){
  bool check = false; 

  //Print each list if list contains a least one element
  for(int i = 0; i < 10; i++){
    if(sect[i] -> getElementCount() != 0){
      check = true;
      sect[i] -> printList();
    }
  }

  //Report to the user
  if(check == true){
      cout << "All patients have successfully been printed." << endl;
  }else{
      //System is empty
      cout << "There are no profiles in the system to print." << endl;
  }
  return;
}

//Description: Return the index value when found.
//Postcodition: Return the first number of carecard.
int findSection(string careCardNum){
    //Check first digit of the carecard.
    for(int i = 0; i < 10; i++){
      //int buffer = careCardNum[0] - '0';
      if(careCardNum[0] - '0' == i){ //if(buffer == i){
        return i;
      }
    }
    // if(careCardNum[0] == '0'){ Before for loop x10
    //     return 0;
    // }
    return 0;
}


int main() {
  // Variables declaration
  List* members0 = new List();
  List* members1 = new List();
  List* members2 = new List();
  List* members3 = new List();
  List* members4 = new List();
  List* members5 = new List();
  List* members6 = new List();
  List* members7 = new List();
  List* members8 = new List();
  List* members9 = new List();
  List* sections[10] = {members0, members1, members2, members3, members4, members5, members6, members7, members8, members9};

  string toInsert = "";
  int index;
  bool done = false;
  char input = 0;

  // Keep doing what the user selects There are no patients in the system to modifyuntil the user exits
  while (not done) {
    // Print menu to user
    cout << "\n----Welcome to The Walk-in Clinic Patient System!\n" << endl;
    cout << "To enter a new patient into the system              enter: e" << endl;
    cout << "To remove one patient from the system               enter: r" << endl;
    cout << "To remove all patients from the system              enter: a" << endl;
    cout << "To search for a patient                             enter: s" << endl;
    cout << "To modify a patient's record                        enter: m" << endl;
    cout << "To print all patients by ascending Carecard order   enter: p" <<endl;
    cout << "To exit The Walk-in Clinic Patient System           enter: x\n" << endl;

    cout << "Your choice: ";
    cin >> input;
    input = tolower(input);
    switch(input) {
      case 'e': 
      cout << "Please, enter the Carecard Number to insert: ";
      getline(cin >> ws, toInsert);
      index = findSection(toInsert);
      enter(sections[index], toInsert); 
      break;
      
      case 'r':
      cout << "Please, enter the Carecard Number to remove: ";
      getline(cin >> ws, toInsert);
      index = findSection(toInsert);
      remov(sections[index], toInsert); 
      break;

      case 'a':
      aremov(sections);
      break;
      
      case 's': 
      cout << "Please, enter the Carecard Number to search: ";
      getline(cin >> ws, toInsert);
      index = findSection(toInsert);
      search(sections[index], toInsert);  
      break;
      
      case 'm':
      cout << "Please, enter the Carecard Number to modify: ";
      getline(cin >> ws, toInsert);
      index = findSection(toInsert);
      modify(sections[index], toInsert);  
      break;
      
      case 'p': 
      print(sections); 
      break;
      
      case 'x': cout << "\n----Bye!\n" << endl; done = true; break;
      default: cout << "Not sure what you mean! Please, try again!" << endl;

    }
  }
  return 0;
}//end of WICPS.cpp    