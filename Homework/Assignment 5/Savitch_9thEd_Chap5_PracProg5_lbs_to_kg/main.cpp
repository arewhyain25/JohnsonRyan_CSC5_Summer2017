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
const float CVLBTKG=2.2046;//Convert 2.2046 lbs to/from 1 kg.
const float CVOZTLB=16;//Convert 16 ounces to/from 1 lb.
const float CVGTKG=1000;//Convert 1000 grams to/from 1 kilogram

//Function Prototypes
float totlbs (int,float);//convert input pounds and ounces to just ounces
float lb2kg (float);
float display (float);
//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    int pounds;//Decimals represented by smaller units
    float ounces;//Output meters and centimeters
    char again=0;//Allows for repeat
    
    //Initialize variables
    pounds=ounces=0;    
    
    //Input data
    cout<<"This program will convert a weight in pounds and ounces to"<<endl;
    cout<<"kilograms and grams.";
    do{
    cout<<" Input data in the following format:"<<endl;
    cout<<"(pounds ounces)"<<endl;
    cin>>pounds>>ounces;
    
    //Output the transformed data
    display (lb2kg (totlbs (pounds, ounces)));
    cout<<endl;
    cout<<"If you would like to run this program again PRESS 1"<<endl;
    cin>>again;
    }while (again=='1');
    //Exit stage right!
    return 0;
    
}

float totlbs (int pounds,float ounces){
    float tlbs=pounds+ounces/CVOZTLB;
    return tlbs;
}

float lb2kg (float tlbs){
    float tkgs=tlbs/CVLBTKG;
    return tkgs;
}

float display (float tkgs){
    int kgrams=tkgs;
    float grams=(tkgs-kgrams)*CVGTKG;
    cout<<kgrams<<" kg and "<<grams<<" g."<<endl;
}