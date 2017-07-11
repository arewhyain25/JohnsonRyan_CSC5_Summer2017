/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on July 10, 2017, 12:54 PM
 * Purpose:  Convert Liters To Gallons
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <iomanip>   //Format Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants
const float CNVLTGAL=0.264179; //Conversion factor of 0.264179 Gallons/Liter

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    float mpg;
    float miles,ltrs,gal;
    char again;
    
    //Initialize variables
    mpg=0;
    again=0;
            
    //Input data
    do{        
        cout<<"How many miles did you drive?"<<endl;
        cin>>miles;
        cout<<"How many liters did your car consume?"<<endl;
        cin>>ltrs;
    
    //Map inputs to outputs or process the data
        gal=ltrs*CNVLTGAL;
        mpg=miles/gal;

    //Output the transformed data
        cout<<fixed<<setprecision(2);
        cout<<"Your car's fuel efficiency is "<<mpg<<" Miles/Gal"<<endl;
        cout<<"Would you like to run the program again? (Y/N)";
        cin>>again;        
    }while ((again=='Y')||(again=='y'));
        
    //Exit stage right!
    return 0;
}

