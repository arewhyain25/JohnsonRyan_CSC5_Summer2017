/* 
  File:   main.cpp
  Author: Ryan Johnson
  Created on July 17, 2017, 5:40 PM
  Purpose:  Assignment 5 Homework Menu
 */

//System Libraries
#include <iostream>//Input Output Library
#include <iomanip> //Format Library
#include <cmath>   //Math Library
#include <string.h>
using namespace std;

//User Libraries

//Global Constants
const float CVMtFT=0.3048;//Convert 0.3048 meters to 1 foot
const float CVCMtM=100;//Convert 100 centimeters to 1 meter
const float CVINtFT=12;//Convert 12 inches to 1 foot
const float CVLBTKG=2.2046;//Convert 2.2046 lbs to/from 1 kg.
const float CVOZTLB=16;//Convert 16 ounces to/from 1 lb.
const float CVGTKG=1000;//Convert 1000 grams to/from 1 kilogram

//Function Prototypes
        //ft-in to m-cm converter
float ft2m (float);//Convert feet to meters
float in2ft (float);//Convert inches to feet
float cmFromM (int,float);//Isolates the centimeters from the total in meters

        //m-cm to ft-in converter
float m2ft (float);//convert meters to feet
float cm2m (float);//convert centimeters to meters
float ft2in (float);//convert decimal of feet to inches
float getinch (float);//separate decimal in feet to allow for conversion to inch

        //lbs-oz to kg-g converter
float totlbs (int,float);//convert input pounds and ounces to just ounces
float lb2kg (float);
float dispKgs (float);

        //kg-g to lbs-oz converter
float totKgs (int,float);//convert input kilograms and grams to just kilograms
float kg2lb (float);
float dispLbs (float);
        //Military Time to Standard Time
void gettime (int,int);
int time12 (int);
int display (int,int);
char ampm (int);

        //Day of the Week
bool isLpYr(int);//Test Leap Year
char getCent(int);//Isolates Century
char getYear(int);//Isolates 2-digit year
char getMnth(string,int);//Finds Month
char getDay(string);//Finds day of week
void getDate(string &,string &,short &);//Input Date
string result(char);//Output day of the week

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Declare Variables
    char choice;
    //Loop on the menu
    do{    
        //Input values
        cout<<"Choose from the list"<<endl;
        cout<<"Type 1 for Savitch Practice Program 2: feet-inch to "
                "meter-centimeter"<<endl;
        cout<<"Type 2 for Savitch Practice Program 3: meter-centimeter to "
                "feet-inch"<<endl;
        cout<<"Type 3 for Savitch Practice Program 4: Length "
                "Unit Converter"<<endl;
        cout<<"Type 4 for Savitch Practice Program 5: pounds-ounces to "
                "kilograms-grams"<<endl;
        cout<<"Type 5 for Savitch Practice Program 6: kilograms-grams to "
                "pounds-ounces"<<endl;
        cout<<"Type 6 for Savitch Practice Program 7: Weight Unit "
                "Converter"<<endl;
        cout<<"Type 7 for Savitch Practice Program 8: Combined Unit Converter";
        cout<<endl;
        cout<<"Type 8 for Savitch Program Project 1: Military time to"
                " standard-time"<<endl;
        cout<<"Type 9 for Savitch Program Project 7: Day of the Week"<<endl;
        cout<<"Type any other character to exit"<<endl;
        cin>>choice;

        //Switch to determine the Problem
        switch(choice){
            case '1':{//ft/in to m/cm converter
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
                break;
                }
            case '2':{//m-cm to foot-inch converter
                //Declare variables
                float cmin,meterin;//input centimeters and meters
                float inchout,feetout;//Output inches and feet
                int intfeet;//feet as integer to separate the decimals to obtain inches
                char again;//Allow for repeat

                //Initialize variables
                inchout=feetout=cmin=meterin=0;    

                //Input data
                cout<<"This program will convert a length in meters and centimeters to"<<endl;
                cout<<"feet and inches."<<endl;                
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
                break;
            }
            case '3':{//Length Unit Converter
                char option;
                do{
                    cout<<"What would you like to convert?"<<endl;
                    cout<<"meters and centimeters to feet and inches? PRESS 1"<<endl;
                    cout<<"feet and inches to meters and centimeters? PRESS 2"<<endl;
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
                }while(option>='1'&&option<='2');
                break;
            }
            case '4':{//kg-g to lbs-oz converter
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
                dispKgs (lb2kg (totlbs (pounds, ounces)));
                cout<<endl;
                cout<<"If you would like to run this program again PRESS 1"<<endl;
                cin>>again;
                }while (again=='1');
                break;
            }
            case '5':{//lbs-oz to kg-g converter
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
                dispLbs (kg2lb (totKgs (kgrams, grams)));
                cout<<endl;
                cout<<"If you would like to run this program again PRESS 1"<<endl;
                cin>>again;
                }while (again=='1');
                break;
            }
            case '6':{//weight unit converter
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
            break;
            }  
            case '7':{//Combined Unit Converter
                //Declare Variables
                char option;//for menu navigation
                char type;//Declare type of conversion (weight, length)

                //Prompt for desired type for measurement
                cout<<"What type of measurement do you want to convert?"<<endl;
                cout<<"PRESS 1 for weight"<<endl;
                cout<<"PRESS 2 for length"<<endl;
                cout<<"Measurement type : ";
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
                break;
            }
            case '8':{//Military Time to Standard Time
                //Declare and Initialize variables
                int hour,minute=0;
                char again='1';//For repeat
                do{
                    //Input data
                    cout<<"What time is it in 24-hour format?"<<endl;
                    cout<<"Hour :";
                    cin>>hour;
                    cout<<"Minute :";
                    cin>>minute;           

                    //Output the transformed data
                    cout<<"12 hour time format time is : "<<time12(hour)<<":"<<minute<<" ";
                    cout<<ampm(hour)<<endl;  
                    cout<<"To run this program again PRESS 1";
                    cin>>again;
                }while (again=='1');
            break;
            }
            case '9':{//Day of the Week
                char again=0;
                do{
                    //Declare variables
                    string sMonth;//Month as a string
                    string sDay;  //Day as a string
                    short  nYear; //Year as an integer

                    //Input data
                    getDate(sMonth,sDay,nYear);

                    //Map inputs to outputs or process the data
                    char day=(getDay(sDay) + 
                              getMnth(sMonth,nYear) + 
                              getYear(nYear) + 
                              getCent(nYear))%7;

                    //Output the results, i.e. which day of the week
                    cout<<endl<<"Day of the week = "<<result(day)<<endl;
                                    cout<<endl;                    
                }while (again=='1');
            break;
            }
            default:
                cout<<"You are exiting the program"<<endl;
        }
    }while(choice>='1'&&choice<='8');
    
    //Exit stage right!
    return 0;
}
//CASE 1:ft-in to m-cm converter
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
//CASE 2:m-cm to ft-in converter
float m2ft (float meter){
     float feet=meter/CVMtFT;
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
//CASE 4:lbs-oz to kg-g converter
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
//CASE 5: kg-g to lbs-oz converter
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

//Military Time to Standard Time
void gettime (int hour,int minute){
    cout<<"The time is "<<hour<<":"<<minute<<endl;    
}
int time12 (int hour){
    if (hour>12) {
        hour-=12;
    }else if (hour==0){
        hour=12;
    }
    return hour;
}
char ampm (int hour){    
    char ampm='A';
    if (hour>=12) {
        ampm='P';
    }
    return ampm;
}

//Problem 9 - Day of the Week
string result(char day){
    string msg;
    switch(day){
        case 0:msg ="Sunday";break;
        case 1:msg ="Monday";break;
        case 2:msg ="Tuesday";break;
        case 3:msg ="Wednesday";break;
        case 4:msg ="Thursday";break;
        case 5:msg ="Friday";break;
        default:msg="Saturday";
    }
    return msg;
}
void getDate(string &sMonth,string &sDay,short &nYear){
    cout<<"This program takes in a date and returns ";
    cout<<"the day of the week"<<endl;
    cout<<"Input date in the following format July 4, 2008"<<endl;
    cin>>sMonth>>sDay>>nYear;
}

char getDay(string sDay){
    char len=0;
    while(sDay[++len]==',');
    if(len==2)return (sDay[0]-48);
    return (sDay[0]-48)*10+(sDay[1]-48);
}

char getMnth(string month,int year){
    if(month=="January"){
        if(isLpYr(year))return 6;
        return 0;
    }else if(month=="February"){
        if(isLpYr(year))return 2;
        return 3;
    }else if(month=="March"||month=="November"){
        return 3;
    }else if(month=="April"||month=="July"){
        return 6;
    }else if(month=="May"){
        return 1;
    }else if(month=="June"){
        return 4;
    }else if(month=="August"){
        return 2;
    }else if(month=="September"||month=="December"){
        return 5;
    }else return 0;
}

char getYear(int year){
    year%=100;
    return year+year/4;
}

char getCent(int year){
    char cent=year/100;
    char remndr=cent%4;
    return 2*(3-remndr);
}

bool isLpYr(int year){
    return ((year%400==0)||((year%4==0)&&!(year%100==0)));
}