/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on June 27, 2017, 1:24 PM
 * Purpose:  Temperature Converter
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <iomanip>
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants


//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    float fahr,cels,fahr2;
    
    //Initialize variables
    
            
    //Input data
    cout<<"Input a temperature in degrees F :";
    cin>>fahr;
            
    //Map inputs to outputs or process the data
    cels=5.0f*(fahr-32)/9.0f;
    fahr2=(9.0f*(cels)/5.0f)+32;
    
    //Output the transformed data 
    cout<<fixed<<setprecision(12)<<showpoint;
    cout<<fahr<<"F = "<<cels<<"C."<<endl;
    cout<<"When we convert back to Celsius"<<endl;
    cout<<fahr2<<"F"<<endl;
    
    //Exit stage right!
    return 0;
}

