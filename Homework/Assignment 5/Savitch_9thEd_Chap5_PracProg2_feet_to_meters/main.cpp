/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on July 16, 2017, 5:53 PM
 * Purpose:  Unit converter
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <iomanip>   //Format Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants
const float CVMtFT=0.3048;//Convert 0.3048 meters to 1 foot
const float CVCMtM=100;//Convert 100 centimeters to 1 meter
const float CVINtFT=12;//Convert 12 inches to 1 foot

//Function Prototypes
float ft2m (float);
float in2ft (float);
float cmFromM (int,float);
//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    float feet,inch,ftplus;//input feet and inches
    float meter,cmeter;//Output meters and centimeters
    int mOnly;
    char again=0;
    
    //Initialize variables
    feet=cmeter=inch=meter=0;    
    
    //Input data
    cout<<"This program will convert a length in feet and inches to"<<endl;
    cout<<"meters and centimeters.";
    do{
    cout<<" Input data in the following format:"<<endl;
    cout<<"(feet, inches)"<<endl;
    cin>>feet>>inch;
    
    //Map inputs to outputs or process the data
    ftplus=feet+in2ft(inch);
    meter=ft2m(ftplus);
    mOnly=meter;
    cmeter=cmFromM(mOnly,meter);
        
    //Output the transformed data
    cout<<feet<<" feet and "<<inch<<" inches = "<<mOnly;
    cout<<" meters and "<<fixed<<setprecision(2)<<cmeter<<" centimeters."<<endl;
    cout<<endl;
    cout<<"If you would like to run this program again PRESS 1"<<endl;
    cin>>again;
    }while (again=='1');
    //Exit stage right!
    return 0;
    
}

float ft2m (float feet){
     float meter=feet*CVMtFT;
    return meter;
}
float in2ft (float inch){
    float feet=inch/CVINtFT;
    return feet;
}
float cmFromM (int mOnly,float meter){
    float cmeter=meter-mOnly;
    cmeter*=CVCMtM;
    return cmeter;
}

