/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on July 10, 2017, 12:54 PM
 * Purpose:  Convert Liters To Gallons and calculate mgp of two vehicles
 *          compares the fuel efficiency of the vehicles and declares
 *          the better one.
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
    float miles1,ltrs1,gal1,miles2,ltrs2,gal2,mpg1,mpg2;
    char again;
    
    //Initialize variables
    mpg1=0,mpg2=0;
    again=0;
            
    //Input data
    do{        
        cout<<"How far did Car 1 travel in miles?"<<endl;
        cin>>miles1;
        cout<<"How many liters did Car 1 consume?"<<endl;
        cin>>ltrs1;
        cout<<"How far did Car 2 travel in miles?"<<endl;
        cin>>miles2;
        cout<<"How many liters did Car 2 consume?"<<endl;
        cin>>ltrs2;
    
    //Map inputs to outputs or process the data
        gal1=ltrs1*CNVLTGAL;
        mpg1=miles1/gal1;
        gal2=ltrs2*CNVLTGAL;
        mpg2=miles2/gal2;

    //Output the transformed data
        cout<<fixed<<setprecision(2);
        cout<<"Fuel efficiency of Car 1 is "<<mpg1<<" Miles/Gal"<<endl;
        cout<<"Fuel efficiency of Car 2 is "<<mpg2<<" Miles/Gal"<<endl;
        if (mpg1>mpg2){cout<<"Car 1 is more efficient."<<endl;}        
        else if (mpg1==mpg2){cout<<"The cars are equally efficient."<<endl;}       
        else {cout<<"Car 2 is more efficient."<<endl;}
        cout<<"Would you like to run the program again? (Y/N)";
        cin>>again;        
    }while ((again=='Y')||(again=='y'));
        
    //Exit stage right!
    return 0;
}

