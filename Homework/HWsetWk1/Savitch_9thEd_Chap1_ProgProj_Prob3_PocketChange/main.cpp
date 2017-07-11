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
    short nQts, nDms, nNks, nPns; //Number of Quarters, Number of Dimes, Number of Nickels
    short pcktChg;//Number of cents in ones pocket
    short vQts=25, vDms=10, vNks=5;//Value of a quarter, nickel or dime        
       
    //Input data
    cout<<"This program calculates your pocket change"<<endl;
    cout<<"Input the number of Quarters, Dimes, Nickels and Pennies"<<endl;
    cout<<"Inputs are limited to 32767 coins a piece"<<endl;
    cin>>nQts>>nDms>>nNks>>nPns;
    
    //Map inputs to outputs or process the data
        pcktChg=nQts*vQts+nDms*vDms+nNks*vNks+nPns;
    
    //Output the transformed data
    cout<<nQts<<" Quarters +";
    cout<<nDms<<" Dimes +";
    cout<<nNks<<" Nickels +";
    cout<<nPns<<" Pennies = ";
    cout<<pcktChg<<" Cents or ";
    cout<<pcktChg/100.0f<<(pcktChg%10==0?'0':' ')<<" Dollars"<<endl;
    //PROBLEM!!!If total is divisible by 100 amount in dollars gets multiplied by 10
    
    //Exit stage right!
    return 0;
}

