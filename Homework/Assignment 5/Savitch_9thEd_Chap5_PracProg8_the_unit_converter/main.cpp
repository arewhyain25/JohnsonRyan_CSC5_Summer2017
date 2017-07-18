/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on July 17, 2017, 7:15 PM
 * Purpose: Length/Weight Unit converter
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
const float CVMtFT=0.3048;//Convert 0.3048 meters to 1 foot
const float CVCMtM=100;//Convert 100 centimeters to 1 meter
const float CVINtFT=12;//Convert 12 inches to 1 foot

//Function Prototypes
float totKgs (int,float);//convert input kilograms and grams to just kilograms
float kg2lb (float);
float dispKgs (float);
float totlbs (int,float);//convert input pounds and ounces to just ounces
float lb2kg (float);
float dispLbs (float);
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
    char option;//for menu navigation
    char type;//Declare type of conversion (weight, length)
    
    //Prompt for desired type for measurement
    cout<<"What type of measurement do you want to convert?"<<endl;
    cout<<"PRESS 1 for weight"<<endl;
    cout<<"PRESS 2 for length"<<endl;
    cout<<"Measrument type : ";
    cin>>type;
    
    
    if (type=='1'){//Weight Conversion
        //Prompt option for conversion to be used
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
    }else if (type=='2'){//Length Conversion
        //Declare Variables
        char option;//for menu navigation

        //Prompt option for conversion to be used
        do{
        cout<<"What would you like to convert?"<<endl;
        cout<<"feet and inches to meters and centimeters? PRESS 1"<<endl;
        cout<<"meters and centimeters to feet and inches? PRESS 2"<<endl;        
        cout<<endl;
        cout<<"To leave the program PRESS any other key."<<endl;
        cin>>option;
        switch (option){
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
        int meter,intfeet;//feet as integer to separate the decimals to obtain inches
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
        meter=meterin;//gets rid of decimal on desplay which is represented
                      //by centimeters

        inchout=feetout-intfeet;

        inchout=ft2in(inchout);

        //Output the transformed data
        cout<<meter<<" meters and "<<cmin<<" centimeters = "<<intfeet;
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
        }while(option>='1'&&option<='2');
    }else {
        cout<<"Leaving Program"<<endl;
    }
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