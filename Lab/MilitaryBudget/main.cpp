/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * * Created on June 19, 2017, 12:32 PM
 * Purpose: Calculate the Federal Military Budget
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;  //Libraries using namespace standard

//User Libraries

//GLobal Constants -> Physics/Math/Conversions

//Function Prototypes

//Execution Begins Hear!
int main(int argc, char** argv) {
    //Declare Variables
    float milBudg;//Military Budget
    float fedBudg;//Federal Budget
    float percMil;//Percentage Military Budget
    
    //Initialize variables
    milBudg=609.3e09f;//609.3 Billion Dollars - Google Internet Search
    fedBudg=3.8e12f;//3.8 Trillion Dollars - Google Internet Search
    
    //Map inputs to outputs or process the data
    percMil=milBudg/fedBudg*100;// Percentage result
    
    //Output the transformed data
    cout<<"The Military Budget = $"<<milBudg<<endl;
    cout<<"The Federal Budget = $"<<fedBudg<<endl;
    cout<<"The Military Percentage = "<<percMil<<"%"<<endl;
   
    //Exit the stage right   
    return 0;
}

