/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on June 20, 2017, 9:39 PM
 * Purpose:  Coin Calculator
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
    short pennies, nickels, dimes, qrts, totChng;
        
    //Initialize variables
    
    //Input data
    cout<<"This program will count your change for you."<<endl;
    cout<<"Please input the number of each coins you have."<<endl;
    cout<<"How many pennies to you have? ";
    cin>>pennies;
    cout<<"How many nickels do you have? ";
    cin>>nickels;
    cout<<"How man dimes do you have? ";
    cin>>dimes;
    cout<<"How many quarters to you have? ";
    cin>>qrts;            
    
    //Map inputs to outputs or process the data
    totChng=pennies+nickels*5+dimes*10+qrts*25;
    
    //Output the transformed data
    cout<<endl;
    cout<<"Based on the information you have given me"<<endl;
    cout<<"regarding the coins you have, I have determined you have"<<endl;
    cout<<"a total of ";
    cout<<totChng;
    cout<<" cents or ";
    cout<<totChng/100.0f<<(totChng%100==0?".00":(totChng%10==0?"0":" "))<<" Dollars"<<endl;
    cout<<"CONGRATULATIONS!";
    
    //Exit stage right!
    return 0;
}

