/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on June 27, 2017, 12:13 PM
 * Purpose:  Monthly Payment Calculator
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <cmath> //Math Library
#include <iomanip> 
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    float rate,loan,mnPmnt,totPmnt,totInt;
    int months;
    
    //Convert variables    
    
    //Input data
    cout<<"This program will calculate the monthly payment for a loan."<<endl;
    cout<<"What is the initial loan amount? $";
    cin>>loan;
    cout<<"What is the length of the term (months)?";
    cin>>months;    
    cout<<"What is the annual interest rate being applied"
            " to the loan (%)?";
    cin>>rate;
    
    
    //Map inputs to outputs or process the data
    float irPerM=rate/1200; //convert annual percentage to monthly percentage
    float temp=pow((1+irPerM),months);//(1+r)^n
    mnPmnt=loan*(irPerM*temp)/(temp-1);//[r*(1+r)^n]/[((1+r)^n)-1]*L
    mnPmnt=static_cast<int>(mnPmnt*100)/100.0f;//COnvert to pennies and back
    totPmnt=mnPmnt*months;//Monthly Payment* Length of Term
    totInt=totPmnt-loan;//Total Payment - Loan Amount            
    
    //Output the transformed data
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<endl;
    cout<<"Loan Amount = "<<loan<<endl;
    cout<<"Annual Interest Rate = "<<rate<<endl;
    cout<<"Monthly Interest Rate = "<<irPerM<<"%/month"<<endl;
    cout<<"Number of Compounding Periods = "<<months<<"Months"<<endl;
    cout<<"Monthly Payment $"<<mnPmnt<<"."<<endl;
    cout<<"Total Amount Paid = $"<<totPmnt<<endl;
    cout<<"Total Interest Paid = $"<<totInt<<endl;

    //Exit stage right!
    return 0;
}

