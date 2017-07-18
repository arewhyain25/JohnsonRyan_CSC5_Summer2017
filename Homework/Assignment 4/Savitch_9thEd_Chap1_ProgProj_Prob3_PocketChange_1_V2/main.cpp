/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on June 20, 2017, 12:44 PM
 * Purpose:  Calculate sum of change in ones pocket
 */

//System Libraries
#include <iostream>  //Input - Output Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    
    //Declare and initialize variables
    char nQts, nDms, nNks; //Number of Quarters, Number of Dimes, Number of Nickels
    short pcktChg;//Number of cents in ones pocket
    char vQts=25, vDms=10, vNks=5;//Value of a quarter, nickel or dime        
       
    //Input data
    cout<<"This program calculates your pocket change"<<endl;
    cout<<"Input the number of Quarters, Dimes and Nickels"<<endl;
    cout<<"Inputs are limited to 9 coins a piece"<<endl;
    cin>>nQts>>nDms>>nNks;
    
    //Map inputs to outputs or process the data
    pcktChg=(nQts-48)*vQts+(nDms-48)*vDms+(nNks-48)*vNks;
    
    //Output the transformed data
    cout<<nQts<<" Quarters +";
    cout<<nDms<<" Dimes +";
    cout<<nNks<<" Nickels =";
    cout<<pcktChg<<" Cents"<<endl;
    //Exit stage right!
    return 0;
}

