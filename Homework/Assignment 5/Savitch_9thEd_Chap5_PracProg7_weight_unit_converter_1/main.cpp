/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on July 16, 2017, 6:27 PM
 * Purpose: Weight Unit converter
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
float dispKgs (float);
float totlbs (int,float);//convert input pounds and ounces to just ounces
float lb2kg (float);
float dispLbs (float);

//Execution begins here
int main(int argc, char** argv) {
    //Declare Variables
    char option;//for menu navigation
    
    //Prompt choice for conversion to be used
    do{
    cout<<"What would you like to convert?"<<endl;
    cout<<"Kilograms and grams to pounds and ounces? PRESS 1"<<endl;
    cout<<"Pounds and ounces to kilograms and grams? PRESS 2"<<endl;
    cout<<"To leave the program PRESS any other key."<<endl;
    cin>>option;
        switch (option){
            case '1':{
                //Declare variables
                float kgrams;//Input
                float grams;//Input
                char again=0;//Allows for repeat

                //Initialize variables
                kgrams=grams=0;  

                //Input data
                do{
                    cout<<" Input data in the following format:"<<endl;
                    cout<<"(kilograms grams)"<<endl;
                    cin>>kgrams>>grams;

                    //Output the transformed data
                    dispLbs (kg2lb (totKgs (kgrams, grams)));
                    cout<<endl;
                    cout<<"If you would like to run this program again PRESS 1"<<endl;
                    cin>>again;
                }while (again=='1');break;
            }

            case '2':{
                //Declare variables
                int pounds;//Decimals represented by smaller units
                float ounces;//Output meters and centimeters
                char again=0;//Allows for repeat

                //Initialize variables
                pounds=ounces=0;    

                //Input data
                do{
                    cout<<" Input data in the following format:"<<endl;
                    cout<<"(pounds ounces)"<<endl;
                    cin>>pounds>>ounces;

                    //Output the transformed data
                    dispKgs (lb2kg (totlbs (pounds, ounces)));
                    cout<<endl;
                    cout<<"If you would like to run this program again PRESS 1"<<endl;
                    cin>>again;
                }while (again=='1');
            }

            default:{
                cout<<"Leaving Program"<<endl;break;
            }

        }
    }while(option>='1'&&option<='2');
    
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

float dispLbs (float tlbs){
    int lbs=tlbs;
    float ounces=(tlbs-lbs)*CVOZTLB;
    cout<<lbs<<" lbs and "<<ounces<<" oz."<<endl;
}

float totlbs (int pounds,float ounces){
    float tlbs=pounds+ounces/CVOZTLB;
    return tlbs;
}

float lb2kg (float tlbs){
    float tkgs=tlbs/CVLBTKG;
    return tkgs;
}

float dispKgs (float tkgs){
    int kgrams=tkgs;
    float grams=(tkgs-kgrams)*CVGTKG;
    cout<<kgrams<<" kg and "<<grams<<" g."<<endl;
}