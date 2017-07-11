/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on July 4, 2017, 3:08 PM
 * Purpose:  Find at what temperature Celsius=Fahrenheit.
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <iomanip> //Formating Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    int c,f,diff;
    
    //Initialize variables
    c=100;
        
    //Process the data
    cout<<"   F      C    Dif"<<endl;
    do{
    f=(9.0f*c--/5.0f)+32;
    diff=f-c;
    cout<<setw(6)<<f<<setw(6)<<c<<setw(6)<<diff<<endl;              
    }while (diff>0);        
    //Output the transformed data
       
    //Exit stage right!
    return 0;
}

