/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on July 4, 2017, 5:42 PM
 * Purpose:  Approximate Pi
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <cmath>     //Math Library
#include <iomanip>   //Format Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants
const float pi = 3.14159265358979323846;//Pi

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    float aprxPi,term;
    int counter;
    int n;//User input for number of loops
    
    //Initialize variables
    aprxPi=0;
    counter=0;
    term=1;
    
    //Input number of loops
    cout<<"This program will approximate pi using a looping equation."<<endl;
    cout<<"How many times do you want the program to run?"<<endl;
    cin>>n;
    
    //Output the terms in the table
    cout<<" pi = "<<pi<<" out to 5 decimal places."<<endl;
         
    //Calculate the terms in the series
    do{
        counter+=1;
        term+=pow(-1,counter)/(2*counter+1);
        aprxPi=4*term;

        //Output the next term
        
    }while(counter<n);

    cout<<fixed<<setprecision(0);
        cout<<"Counter = "<<static_cast<int>(counter)<<endl;
        cout<<fixed<<setprecision(5)<<showpoint;
        cout<<"Calculated value of pi = "<<aprxPi<<endl;
        cout<<"Difference between pi and our calculation = "
                <<pi-aprxPi<<endl;
    //Exit stage right!
    return 0;
}