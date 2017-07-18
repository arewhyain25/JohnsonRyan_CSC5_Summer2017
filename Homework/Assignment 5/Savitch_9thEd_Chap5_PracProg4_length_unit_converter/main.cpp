/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on July 16, 2017, 6:27 PM
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
float ft2m (float);//convert feet to meters
float cmFromM (int,float);//extrapolates centimeters from the decimal of meters
float m2ft (float);//convert meters to feet
float in2ft (float);//convert inches to feet
float cm2m (float);//convert centimeters to meters
float ft2in (float);//convert decimal of feet to inches
float getinch (float);//separate decimal in feet to allow for conversion to inch

//Execution begins here
int main(int argc, char** argv) {
    //Declare Variables
    char choice;//for menu navigation
    
    //Prompt choice for conversion to be used
    do{
    cout<<"What would you like to convert?"<<endl;
    cout<<"meters and centimeters to feet and inches? PRESS 1"<<endl;
    cout<<"feet and inches to meters and centimeters? PRESS 2"<<endl;
    cout<<endl;
    cout<<"To leave the program PRESS any other key."<<endl;
    cin>>choice;
    switch (choice){
        case '1':{
    //Declare variables for conversion of standard to metric
    float feet,inch,ftplus;//input feet and inches
    float meter,cmeter;//Output meters and centimeters
    int mOnly;
    char again=0;
    
    //Initialize variables
    feet=cmeter=inch=meter=0;    
    
    //Input data
    do{
    cout<<" Input data in the following format:"<<endl;
    cout<<"(feet inches)"<<endl;
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
    }while (again=='1');break;
    }
    
        case '2':{
        //Declare variables
    float cmin,meterin;//input centimeters and meters
    float inchout,feetout;//Output inches and feet
    int intfeet;//feet as integer to separate the decimals to obtain inches
    char again;//Allow for repeat
    
    //Initialize variables
    inchout=feetout=cmin=meterin=0;    
    
    //Input data
    do{
    cout<<"Input data in the following format:"<<endl;
    cout<<"(meters centimeters)"<<endl;
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
    }while (again=='1');break;
    }
    
        default:{
        cout<<"Leaving Program"<<endl;break;
    }
    
    }
    }while(choice>='1'&&choice<='2');
    
    //Exit stage right!
    return 0;
    
}

float ft2m (float feet){
     float meter=feet*CVMtFT;
    return meter;
}

float cmFromM (int mOnly,float meter){
    float cmeter=meter-mOnly;
    cmeter*=CVCMtM;
    return cmeter;
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