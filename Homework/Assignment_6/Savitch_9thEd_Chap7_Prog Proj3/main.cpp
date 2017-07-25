/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on July 24, 2017, 7:30 PM
 * Purpose:  repeat deleter
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <ctime>     //Time for random nimber function
#include <cstdlib>   //Random Number Generator
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes
void prntAry(char[],int);
void dupRmvr(char[],char [],int);
void sortAry(char[],int);

//Execution begins here
int main(int argc, char** argv) {
    //Set the seed for the random number generator
    srand(static_cast<unsigned int>(time(0)));
    //Initialize Variables
    int SIZE=20;
    char array[SIZE]={'a','b','a','c','d','b','c','d','e','f','e',
                      'j','g','h','j'};
    char unqAry[SIZE]={};
    
    //Declare variables
   
    
    //Initialize variables
    
    //Output Data
    prntAry(array,SIZE);
    
    //Sort Data
    sortAry(array,SIZE);
    
     //Output Data
    prntAry(array,SIZE);
            
    //Delete Duplicates
    dupRmvr(array,unqAry,SIZE);
    
    //Output Data
    prntAry(unqAry,SIZE);
    
    //Exit stage right!
    return 0;
}
void sortAry(char a[],int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if (a[i]>a[j]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}
void prntAry(char a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i];
        if (i%5==4)cout<<endl;
    }
}
void dupRmvr(char a[],char b[],int n){
    int k=0;
    for (int i=0;i<n;i++){
        int j=i+1;
           if(!(a[i]==a[j])){
                b[k]=a[i];
                k++;                
                    
        }
    }
}
