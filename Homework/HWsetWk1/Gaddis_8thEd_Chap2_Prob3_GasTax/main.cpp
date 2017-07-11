/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on June 20, 2017, 1:35 PM
 * Purpose:  Gas Tax
 */

//System Libraries
#include <iostream>  //Input - Output Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables and Initialize
    float ppGal=2.75f;//$2.75/gallon for Regular
    float taxGal=0.764f;//74.6 cents per gallon
    float nGal=15;//Number of Gallons for a fill-up
    float totAmt;//Total Amount tendered for purchase price in $'s
    float totTax;//Total tax paid on a fill-up
    float prcTax;//Percentage taxed on a purchase
              
    //Map inputs to outputs or process the data
    totAmt=nGal*ppGal;
    totTax=taxGal*nGal;
    prcTax=totTax/totAmt*100;
    
    //Output the transformed data
    cout<<"Number of gallons for a fill up = "<<nGal<<endl;
    cout<<"Price per gallon paid = $"<<ppGal<<endl;
    cout<<"Tax paid per gallon = $"<<taxGal<<endl;
    cout<<"Tax Composition = 18.4 cents Fed, 36 cents State,"<<endl;
    cout<<"and 8% sales Tax"<<endl;
    cout<<"Total Amount paid to fill-up = $"<<totAmt<<endl;
    cout<<"Total taxes paid to fill-up = $"<<totTax<<endl;
    cout<<"Percentage Tax paid = "<<prcTax<<"%"<<endl;
            
    //Exit stage right!
    return 0;
}

