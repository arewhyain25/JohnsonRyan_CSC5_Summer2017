/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on June 29, 2017, 4:10 PM
 * Purpose:  Calculate the volume in gallons of a well
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <cmath>     //Math Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants
const float CNVCFTG=7.48;//Gallons of water in 1 cubic foot
const float INTF=12;//inches in 1 foot  
const float PI = 3.141592;//pi
//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    float radius,depth;//Radius of the well opening, depth of the well
    float vCft,vGal;//Volume in cuft and gallons
    
    //Input data
    cout<<"This program will calculate the volume in gallons of a well"<<endl;
    cout<<"Please provide the radius and depth of the well casing."<<endl;
    cout<<"Radius (in): ";
    cin>>radius;
    cout<<"Depth (ft): ";
    cin>>depth;
    
    //Map inputs to outputs or process the data
    radius/=12;
    vCft=PI*pow(radius,2)*depth;
    vGal=vCft*CNVCFTG;
    
    //Output the transformed data
    cout<<"Your well can hold "<<vGal<<" gallons."<<endl;
        
    //Exit stage right!
    return 0;
}

