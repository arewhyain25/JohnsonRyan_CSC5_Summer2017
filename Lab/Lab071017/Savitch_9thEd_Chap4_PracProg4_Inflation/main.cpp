/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on July 10, 2017, 1:30 PM
 * Purpose:  Estimate Inflation Rate
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <iomanip>   //Format Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants
const int CNVPERC=100;

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    float pVal,yAgoVal,infltnR;

    //Initialize variables
    infltnR=0;

    //Input data
    cout<<"This program will estimate inflation based on the change in value"
            " of an item"<<endl;
    cout<<"Input the present value of an item $";
    cin>>pVal;
    cout<<"Input the value of the same item a year ago $";
    cin>>yAgoVal;
    
    //Map inputs to outputs or process the data
    infltnR=(pVal-yAgoVal)/yAgoVal*CNVPERC;

    //Output the transformed data
    cout<<fixed<<setprecision(2);
    cout<<"Estimated inflation rate is: "<<infltnR<<"%";
    //Exit stage right!
    return 0;
}

