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
    float prstVal,prevVal,infltnR,nxtVal,nxtVal2;

    //Initialize variables
    infltnR=0;

    //Input data
    cout<<"This program will estimate inflation based on the change in value"
            " of an item"<<endl;
    cout<<"Input the present value of an item: $";
    cin>>prstVal;
    cout<<"Input the value of the same item a year ago: $";
    cin>>prevVal;
    
    //Map inputs to outputs or process the data
    infltnR=(prstVal-prevVal)/prevVal;
    nxtVal=prstVal*(1+infltnR);
    nxtVal2=nxtVal*(1+infltnR);

    //Output the transformed data
    cout<<fixed<<setprecision(2);
    cout<<"Estimated inflation rate is: "<<infltnR*CNVPERC<<"%"<<endl;
    cout<<"Based on this estimate, a year from now the item will cost $"<<nxtVal;
    cout<<endl;
    cout<<"Two years from now it will cost $"<<nxtVal2<<endl;
    //Exit stage right!
    return 0;
}

