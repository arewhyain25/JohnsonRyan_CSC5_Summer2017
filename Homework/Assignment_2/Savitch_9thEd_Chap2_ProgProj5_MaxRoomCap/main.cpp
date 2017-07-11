/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on June 29, 2017, 3:19 PM
 * Purpose:  Decide if a meeting is in violation of fire regulations.
 */

//System Libraries
#include <iostream>  //Input - Output Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    int attnds,rmCap;//Number of attendants and Allowable Room Capacity
        
    //Input data
    cout<<"This program will decide if a meeting is in violation"<<endl;
    cout<<"of fire regulations for the room it is being held in."<<endl;
    cout<<"Input the number of people attending the meeting: ";
    cin>>attnds;
    cout<<"Input the established maximum occupants of the room.";
    cin>>rmCap;
    
    //Map inputs to outputs or process the data
    if (attnds<=rmCap) {
        cout<<"This meeting is not in violation of fire regulations"
                " and may go ahead as planned.";
    }
    else {
        cout<<"This meeting is in violation of fire safety!"<<endl;
        cout<<attnds-rmCap<<" people must leave in order for this meeting"<<endl;
        cout<<"to take place in this room.";
    }
      
    //Output the transformed data
       
    //Exit stage right!
    return 0;
}

