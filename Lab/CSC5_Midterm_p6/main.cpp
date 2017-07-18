/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on July 12, 2017, 4:10 PM
 * Purpose:  Sum a Sequence containing exponents and factorial functions.
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <cmath>     //Math Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    float n,x,i,j;//Input Number of Terms,x=Starting Value,i & j=counters
    float fact;//Factorial for bottom term
    double sum;//Result
    
    //Initialize Variables
    fact=1;
    sum=0;
    
    //Input data
    cout<<"This program will estimate sin(x)."<<endl;
    cout<<"Input Values for x and n : "<<endl;
    cout<<"x = ";
    cin>>x;
    cout<<"n = ";
    cin>>n;
    
    //Map inputs to outputs or process the data
    for (float term=0,i=1;i<=n;i++){
        float k=(2*i-1);//k increases to next odd number
        for (j=1,fact=1;j<=k;j++){
            fact*=(j);            //fact=1*2*3*4...
        }        
        term=((pow(x,k))/fact*pow(-1,i+1));//Add Terms as i->n
                   //pow(-1,i+1) alternates between positive and negative terms        
        sum+=term;
    }    
    //Output the transformed data
    cout<<"Program estimate of Sin of x = "<<sum<<endl;    
    cout<<"Exact Sin(x)                 = "<<sin(x);
    
    //Exit stage right!
    return 0;
}

