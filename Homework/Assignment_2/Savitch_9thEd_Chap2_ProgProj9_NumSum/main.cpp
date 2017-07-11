/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on June 28, 2017, 10:38 PM
 * Purpose:  Enter 10 numbers, total of all positive numbers,
 * total of all negative numbers, total of all numbers.
 */

//System Libraries
#include <iostream>  //Input - Output Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Declare and Initialize variables
    int n1,n2,n3,n4,n5,n6,n7,n8,n9,n10;//Inputted numbers 1-10
    int nTot,nNeg,nPos = 0;//Raw Total, Total of negative numbers and
                       //Total of Positive Numbers
    
    //Input data
    cout<<"This program will add up all of the positive numbers provided,"<<endl;
    cout<<"all of the negative numbers, and total of all 10 numbers."<<endl;
    cout<<"Input 10 integers, positive and/or negative."<<endl;
    cin>>n1>>n2>>n3>>n4>>n5>>n6>>n7>>n8>>n9>>n10;
    
    //Map inputs to outputs or process the data
    (n1>=0)? nPos += n1 : nNeg += n1;
    (n2>=0)? nPos += n2 : nNeg += n2;
    (n3>=0)? nPos += n3 : nNeg += n3;
    (n4>=0)? nPos += n4 : nNeg += n4;
    (n5>=0)? nPos += n5 : nNeg += n5;
    (n6>=0)? nPos += n6 : nNeg += n6;
    (n7>=0)? nPos += n7 : nNeg += n7;
    (n8>=0)? nPos += n8 : nNeg += n8;
    (n9>=0)? nPos += n9 : nNeg += n9;
    (n10>=0)? nPos += n10 : nNeg += n10;
    nTot=nPos+nNeg;
            
    //Output the transformed data
    cout<<"The sum of all of the positive integers entered is: ";
    cout<<nPos<<endl;
    cout<<"The sum of all of the negative integers entered is: ";
    cout<<nNeg<<endl;
    cout<<"The sum of all of all of the integers entered is: ";
    cout<<nTot<<endl;
    //Exit stage right!
    return 0;
}

