/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on July 29, 2017, 10:10 PM
 * Purpose:  Change the input time from 24 hour format to 12 hours format
 */

//System Libraries
#include <iostream>  //Input - Output Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes
void gettime (int,int);
int time12 (int);
int display (int,int);
char ampm (int);

//Execution begins here
int main(int argc, char** argv) {
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
    //Exit stage right!
    return 0;
    
}

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