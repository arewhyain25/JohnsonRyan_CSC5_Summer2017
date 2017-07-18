/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on July 10, 2017, 9:10 PM
 * Purpose:  Print lyrics to Ninety-Nine Bottles of Beer
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
    const int SIZE=20;
    int n100s,n10s,n1s,n;
    char prnt10[SIZE],prnt1[SIZE];
    
    
    //Initialize variables
    n10s,n1s=0;  
    
    //Map inputs to outputs or process the data
    
    //Output the transformed data
    for (n=99;n<=0;n--){
        switch (n10s){
            cin>>n;
            n10s=n/10;
            n-=10*n10s;
            n1s=n;
            case 9:(prnt10[SIZE])='Ninety-';
            case 8:(prnt10[SIZE])='Eighty-';
            case 7:(prnt10[SIZE])='Seventy-';
            case 6:(prnt10[SIZE])='Sixty-';
            case 5:(prnt10[SIZE])='Fifty-';
            case 4:(prnt10[SIZE])='Fourty-';
            case 3:(prnt10[SIZE])='Thirty-';
            case 2:(prnt10[SIZE])='Twenty-';
            default:"";break;
        }
        switch (n1s){
            cin>>n;
            n10s=n/10;
            n-=10*n10s;
            n1s=n;
            case 9:(prnt1[SIZE])='Nine';
            case 8:(prnt1[SIZE])='Eight';
            case 7:(prnt1[SIZE])='Seven';
            case 6:(prnt1[SIZE])='Six';
            case 5:(prnt1[SIZE])='Five';
            case 4:(prnt1[SIZE])='Four';
            case 3:(prnt1[SIZE])='Three';
            case 2:(prnt1[SIZE])='Two';
            case 1:(prnt1[SIZE])='One';
            default:"";break;
        }
        cout<<prnt10<<prnt1<<" bottles of beer on the wall"<<endl;
        cout<<prnt10<<prnt1<<" bottles of beer"<<endl;
        cout<<"Take one down, pass it around,"<<endl;
        cout<<prnt10<<prnt1<<" bottles of beer on the wall"<<endl;
    }      
         
    
    //Exit stage right!
    return 0;
}

