/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on July 12, 2017, 10:28 AM
 * Purpose:  Input a date
 *           Output day of the week
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <string.h>
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes
bool isLpYr(int);
char getCent(int);
char getYear(int);
char getMnth(string,int);
char getDay(string);

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    string sMonth;//Month as a string
    string sDay;  //Day as a string
    short  nYear; //Year
    
    //Input data
    cout<<"This program takes in a date and returns the day of the week."<<endl;
    cout<<"Input date in the following format (July 4, 2008)"<<endl;
    cin>>sMonth>>sDay>>nYear;
    cout<<static_cast<int>(getDay(sDay))<<endl;
    
    //Map inputs to outputs or process the data
    char day=(getDay (sDay))+getMnth(sMonth,nYear)+getYear(nYear)+getCent(nYear);
    day%=7;
    string msg;
    switch (day){
        case 0:msg="Sunday";break;
        case 1:msg="Monday";break;
        case 2:msg="Tuesday";break;
        case 3:msg="Wednesday";break;
        case 4:msg="Thursday";break;
        case 5:msg="Friday";break;
        default:msg="Saturday";
    }
    cout<<"Day of the week: "<<msg<<endl;
    //Output the transformed data
       
    //Exit stage right!
    return 0;    
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
    }else 
        return 0;       
}
char getDay(string sDay){
    char len=strlen(sDay.c_str());
    if(len==2)return sDay[0]-48;
    return (sDay[0]-48)*10+(sDay[1]-48);
}
char getYear(int year){
    year%=100;
    return year+year/4;
}

char getCent(int year){
    char cent=year/100;
    char remndr=cent%4;
    return (3-remndr)*2;
}

bool isLpYr(int year){
    return ((year%400==0)||((year%4==0)&&!(year%100==0)));
}