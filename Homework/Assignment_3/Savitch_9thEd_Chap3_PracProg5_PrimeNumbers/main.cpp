/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on July 4, 2017, 5:10 PM
 * Purpose:  Find all prime numbers between 3 and 100
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
    int counter,mod,test;//counter[3,100], mod is test result, test is checking
                         //divisibility.
    
    
    //Find Prime Numbers
    for (counter=3; counter<=100;counter++){       
        for(test=2;test<=counter;test++){
            mod=counter%(test); 
            if (test==counter){cout<<counter<<endl;}
            else if (mod==0){break;}            
        
        }
    }   
    //Output the transformed data
    
    
    //Exit stage right!
    return 0;
}

