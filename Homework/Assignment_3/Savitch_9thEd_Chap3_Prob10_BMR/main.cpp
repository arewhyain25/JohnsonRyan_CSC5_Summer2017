/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on July 5, 2017, 6:48 PM
 * Purpose:  Candy Bar calculator with a question regarding activity level
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <cstdlib> //Library with Random Number Generator
#include <fstream> //Out Stream Library

using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    char sex, nBars;
    unsigned short wt,age,ht,bmr;
    unsigned int cndyCal=230;//230 calories for a chocolate candy bar
    ofstream out;
    char activity;
    
    //Open the output file stream
    out.open("randOut.dat");
    
    //Setting the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Randomly Generate Data
    //wt=rand()%221+80;//[80,300]
    //age=rand()%55+18;//[18,72]
    //ht=rand()%25+56;//[56,80]
    //sex=rand()%2*7+70;//70 = char F, 77=char M
    
    //Input data
    cout<<"Calculate how many candy bars you can eat each day."<<endl;
    cout<<"Input your weight(lbs), height(in, and age(yrs) "<<endl;
    cin>>wt>>ht>>age;
    cout<<"Input your sex M/F"<<endl;
    cin>>sex;
    cout<<"Which of the following best describes your activity?"<<endl;
    cout<<"a) Sedentary"<<endl;
    cout<<"b) Somewhat Active"<<endl;
    cout<<"c) Active (exercise 3-4 days a week)"<<endl;
    cout<<"d) Highly Active (exercise every day)"<<endl;
    cout<<"Enter a, b, c, or d."<<endl;
    cin>>activity;
    
    //Map inputs to outputs or process the data
    bmr=(sex=='F')?
        655+4.3*wt+4.7*ht-4.7*age:
         66+6.3*wt+12.9*ht-6.8*age;
    nBars=bmr/cndyCal;
    switch (activity){
        case 'a':bmr*=1.2f;break;
        case 'b':bmr*=1.3f;break;
        case 'c':bmr*=1.4f;break;
        case 'd':bmr*=1.5f;break;
        
    }
    //Output the transformed data
    cout<<"Given sex="<<sex<<", wt="<<wt<<" (lbs), ht="<<ht<<"(in), age="
        <<age<<"(yrs),"<<" and activity level."
            " BMR= "<<bmr<<"(cal)."<<endl;
    cout<<"Your chocolate candy bar consumption per day = "
            <<static_cast<int>(nBars)<<endl;
    out<<"Given sex="<<sex<<", wt="<<wt<<" (lbs), ht="<<ht<<"(in), age="
        <<age<<"(yrs),"<<" BMR= "<<bmr<<"(cal)."<<endl;
    out<<"Your chocolate candy bar consumption per day = "
            <<static_cast<int>(nBars)<<endl;
    
    //Exit stage right!
    return 0;
}

