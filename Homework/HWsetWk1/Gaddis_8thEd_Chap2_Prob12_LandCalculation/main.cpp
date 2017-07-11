/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on June 21, 2017, 1:26 PM
 * Purpose:  Land Calculation
 */

//System Libraries
#include <iostream>  //Input - Output Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants
const float CNVFTA=43560.0f;//43560 ft/acre
const float CNVFTM=5280.0f;//5280 ft/mile

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    float inSqFt,inAcres;//inputs Square Feet and Acres
    float nAcres,nSqMls;//outputs Acres and Square Miles
    //Initialize variables
    
    //Input data
    cout<<"Input square footage and acres to convert"<<endl;
    cin>>inSqFt>>inAcres;
            
    //Map inputs to outputs or process the data
    nAcres=inSqFt/CNVFTA;
    nSqMls=inAcres*CNVFTA/CNVFTM/CNVFTM;
    
    //Output the transformed data
    cout<<inSqFt<<" feet = "<<nAcres<<" Acres"<<endl;
    cout<<inAcres<<" Acres = "<<nSqMls<<" Square Miles"<<endl;
    
    //Exit stage right!
    return 0;
}

