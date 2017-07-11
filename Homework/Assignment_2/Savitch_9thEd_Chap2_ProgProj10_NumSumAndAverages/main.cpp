/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on June 28, 2017, 10:52 PM
 * Purpose:  Enter 10 numbers, total of all positive numbers,
 * total of all negative numbers, total of all numbers and
 * find the averages of positive, negative and all integers.
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <iomanip> //Formating Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Declare and Initialize variables
    int n1,n2,n3,n4,n5,n6,n7,n8,n9,n10;//Inputted numbers 1-10
    float nTot,nNeg,nPos = 0;//Raw Total, Total of negative numbers and
                           //Total of Positive Numbers
    float totAvg,negAvg,posAvg;//Total Average, Average of Negatives
                             //Average of Positives
    float pos,neg;//number of positive numbers, number of negative numbers
    
    //Initialize Variables
    pos=0;
    neg=0;
            
    //Input data
    cout<<"This program will add up all of the positive numbers provided,"<<endl;
    cout<<"all of the negative numbers, and total of all 10 numbers."<<endl;
    cout<<"Input 10 integers, positive and/or negative."<<endl;
    cin>>n1>>n2>>n3>>n4>>n5>>n6>>n7>>n8>>n9>>n10;
    
    //Total-up positive and negative integers entered
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
    
    //Count negative and positive integers entered
    (n1>=0)? pos+=1 : neg+=1;
    (n2>=0)? pos+=1 : neg+=1;
    (n3>=0)? pos+=1 : neg+=1;
    (n4>=0)? pos+=1 : neg+=1;
    (n5>=0)? pos+=1 : neg+=1;
    (n6>=0)? pos+=1 : neg+=1;
    (n7>=0)? pos+=1 : neg+=1;
    (n8>=0)? pos+=1 : neg+=1;
    (n9>=0)? pos+=1 : neg+=1;
    (n10>=0)? pos+=1 : neg+=1;
    
    //Calculate Averages
    totAvg=nTot/10;//Average of all integers = Total of integers/10
    posAvg=nPos/pos;//Avg of Pos integers = sum of pos integers/#pos integers
    negAvg=nNeg/neg;//avg of negative integers= sum of negative integers/#negative integers
    
    //Output the transformed data
    cout<<"The sum of all of the positive integers entered is: ";
    cout<<nPos<<endl;
    cout<<"The sum of all of the negative integers entered is: ";
    cout<<nNeg<<endl;
    cout<<"The sum of all of all of the integers entered is: ";
    cout<<nTot<<endl;
    cout<<"Number of positive integers entered = "<<pos<<endl;
    cout<<"Number of negative integers entered = "<<neg<<endl;
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"The average of all entered integers is: "<<totAvg<<endl;
    cout<<"The average of all positive integers entered is: "<<posAvg<<endl;
    cout<<"The average of all negative integers entered is: "<<negAvg<<endl;
    //Exit stage right!
    return 0;
}

