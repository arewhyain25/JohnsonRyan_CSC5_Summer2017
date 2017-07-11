/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on June 22, 2017, 5:20 PM
 * Purpose:  Add and Multiply 2 integers
 */

//System Libraries
#include <iostream>  //Input - Output Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    int a,b,prod,sum;
    
    //Initialize variables
    
    //Input data
    cout<<"This program will provide the sum and product of"<<endl;
    cout<<"any two integers between -46340 and 46340."<<endl;
    cout<<endl;
    cout<<"Input two integers between -46340 and 46340: "<<endl;
    cout<<endl;
    cin>>a;
    cin>>b;
    cout<<endl;
    
    //Map inputs to outputs or process the data
    sum=a+b;
    prod=a*b;
    
    //Output the transformed data
    cout<<a<<" x "<<b<<" = "<<prod<<endl;
    cout<<endl;
    cout<<a<<" + "<<b<<" = "<<sum;
    cout<<endl;
    
    //Exit stage right!
    return 0;
}

