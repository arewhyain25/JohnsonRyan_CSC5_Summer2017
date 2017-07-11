/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on June 27, 2017, 10:48 AM
 * Purpose:  Candy Bar calculator
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <cstdlib> //Library with Random Number Generator
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
    
    //Setting the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Randomly Generate Data
    wt=rand()%221+80;//[80,300]
    age=rand()%55+18;//[18,72]
    ht=rand()%25+56;//[56,80]
    sex=rand()%2*7+70;//70 = char F, 77=char M
    
    //Input data
    //cout<<"Calculate how many candy bars you can eat each day."<<endl;
    //cout<<"Input your weight(lbs), height(in, and age(yrs) "<<endl;
    //cin>>wt>>ht>>age;
    //cout<<"Input your sex M/F"<<endl;
    //cin>>sex;
    
    //Map inputs to outputs or process the data
    bmr=(sex=='F')?
        655+4.3*wt+4.7*ht-4.7*age:
         66+6.3*wt+12.9*ht-6.8*age;
    nBars=bmr/cndyCal;
    
    //Output the transformed data
    cout<<"Given sex="<<sex<<", wt="<<wt<<" (lbs), ht="<<ht<<"(in), age="
        <<age<<"(yrs),"<<" BMR= "<<bmr<<"(cal)."<<endl;
    cout<<"Your chocolate candy bar consumption per day = "
            <<static_cast<int>(nBars)<<endl;
    
    //Exit stage right!
    return 0;
}

