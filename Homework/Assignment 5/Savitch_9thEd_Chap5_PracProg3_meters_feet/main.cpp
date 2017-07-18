/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on July 16, 2017, 5:30 PM
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
float m2ft (float);//convert meters to feet
float in2ft (float);//convert inches to feet
float cm2m (float);//convert centimeters to meters
float ft2in (float);//convert decimal of feet to inches
float getinch (float);//separate decimal in feet to allow for conversion to inch

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    float cmin,meterin;//input centimeters and meters
    float inchout,feetout;//Output inches and feet
    int intfeet;//feet as integer to separate the decimals to obtain inches
    char again;//Allow for repeat
    
    //Initialize variables
    inchout=feetout=cmin=meterin=0;    
    
    //Input data
    cout<<"This program will convert a length in meters and centimeters to"<<endl;
    cout<<"feet and inches.";
    do{
    cout<<"Input data in the following format:"<<endl;
    cout<<"(meters, centimeters)"<<endl;
    cin>>meterin>>cmin;
    
    //Map inputs to outputs or process the data
    meterin+=cm2m(cmin);
    feetout=m2ft(meterin);
    intfeet=feetout;
    
    inchout=feetout-intfeet;
    
    inchout=ft2in(inchout);
    
    //Output the transformed data
    cout<<meterin<<" meters and "<<cmin<<" centimeters = "<<intfeet;
    cout<<" feet and "<<fixed<<setprecision(2)<<inchout<<" inches."<<endl;
    cout<<endl;
    cout<<"If you would like to run this program again PRESS 1"<<endl;
    cin>>again;
    }while (again=='1');
    
    //Exit stage right!
    return 0;
}

float m2ft (float meter){
     float feet=meter/CVMtFT;
    return feet;
}
float in2ft (float inch){
    float feet=inch/CVINtFT;
    return feet;
}
float cm2m (float cmeter){
    float meter=cmeter/CVCMtM;
    return meter;
}
float ft2in (float inOnly){
    float inch=inOnly*CVINtFT;
    return inch;
}
float getinch (float feetout){
    int ftOnly=feetout;
    float inOnly=feetout-ftOnly;
    return inOnly;
}
