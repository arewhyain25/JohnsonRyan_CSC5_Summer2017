/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * * Created on June 19, 2017, 12:21 PM
 * Purpose: Sum of Two Numbers
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;  //Libraries using namespace standard

//User Libraries

//GLobal Constants -> Physics/Math/Conversions

//Function Prototypes

//Execution Begins Hear!
int main(int argc, char** argv) {
    //Declare Variables
    short num1,num2; //1Byte data type range [0,255]
    short sum; //1 Byte data type range [0,255]
    
    //Initialize variables   
    num1=50;
    num2=100;

    //Map inputs to outputs or process the data
    sum=num1+num2;
    
    //Output the results
    cout<<num1<<"+"<<num2<<"="<<sum<<endl;
    cout<<static_cast<int>(num1)<<"+"
        <<static_cast<int>(num2)<<"="
        <<static_cast<int>(sum)<<endl;
   
    //Exit the stage right   
    return 0;
}

