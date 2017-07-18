/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on July 16, 2017, 5:53 PM
 * Purpose:  Kilogram to Pounds - Unit converter
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <iomanip>   //Format Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants
const float CVLBTKG=2.2046;//Convert 2.2046 lbs to/from 1 kg.
const float CVOZTLB=16;//Convert 16 ounces to/from 1 lb.
const float CVGTKG=1000;//Convert 1000 grams to/from 1 kilogram

//Function Prototypes
float totKgs (int,float);//convert input kilograms and grams to just kilograms
float kg2lb (float);
float display (float);
//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    float kgrams;//Input
    float grams;//Input
    char again=0;//Allows for repeat
    
    //Initialize variables
    kgrams=grams=0;    
    
    //Input data
    cout<<"This program will convert a weight in kilograms and grams to"<<endl;
    cout<<"pounds and ounces.";
    do{
    cout<<" Input data in the following format:"<<endl;
    cout<<"(kilograms grams)"<<endl;
    cin>>kgrams>>grams;
    
    //Output the transformed data
    display (kg2lb (totKgs (kgrams, grams)));
    cout<<endl;
    cout<<"If you would like to run this program again PRESS 1"<<endl;
    cin>>again;
    }while (again=='1');
    //Exit stage right!
    return 0;
    
}

float totKgs (int big,float small){
    float tkgs=big+small/CVGTKG;
    return tkgs;
}

float kg2lb (float tkgs){
    float tlbs=tkgs*CVLBTKG;
    return tlbs;
}

float display (float tlbs){
    int lbs=tlbs;
    float ounces=(tlbs-lbs)*CVOZTLB;
    cout<<lbs<<" lbs and "<<ounces<<" oz."<<endl;
}