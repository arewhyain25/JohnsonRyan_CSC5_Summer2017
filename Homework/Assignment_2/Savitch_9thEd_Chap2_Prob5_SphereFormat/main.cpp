/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on June 29, 2017, 7:25 PM
 * Purpose:  Compute the Volume of a Sphere
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <cmath>     //Math Library
#include <iomanip>   //Formatting Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants
const float PI = 3.141592;

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    float radius,volume;//radius of sphere, volume of the sphere
    
    //Input data
    cout<<"This program will compute the volume of a sphere"
            " for a given radius."<<endl;
    cout<<"Input Radius (in): ";
    cin>>radius;
    
    //Map inputs to outputs or process the data
    volume=4.0f/3.0f*PI*pow(radius,3);
    
    //Output the transformed data
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"The volume of a sphere with a radius of "<<radius<<" (in)"<<endl;
    cout<<"is "<<volume<<" in^3";
    
    //Exit stage right!
    return 0;
}

