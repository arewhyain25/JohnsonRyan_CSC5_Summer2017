/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on July 11, 2017, 3:26 PM
 * Purpose:  Input a number
 *           Output an X made up of integers counting down
 *           from the number entered.
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <iomanip>   //Format Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    int input, //High number (starting value)
        low,  //Low number (starts at 1 and moves up)
        space,//Spaces between numbers
        spaceL;//Space before first number is printed 
    //Initialize Variables
    low=1;
    input=0;
        
    //Input data
    cout<<"This program will print an 'X' made out of integers."<<endl;
    cout<<"Input a positive non-zero integer to determine the size"
          " of the 'X' :"<<endl;
    cout<<"Input : ";
    cin>>input;
    cout<<endl;
    
    while (input<=0) {
        cout<<input<<" is an invalid entry, please try again. ";
        cin>>input;
    }  
    
    //ODD***************************************************
    if (input%2==1){
        //Declare Variables
        int j=0;//Space Counter
        int i;//Loop representative for Variable : input
                        
         //Top Half of X*************************************
        for (space=input-2,i=input,low=1,spaceL=0;i>=low;i--,low++,spaceL++,space-=2){
            //Left Space loop
            for(j=0;j<spaceL;j++){
                cout<<" ";
            }
            cout<<i;
            for(j=0;j<space;j++){
                cout<<" ";
            }
            if (low<i){cout<<low<<endl;}
        
        } 
        cout<<endl;
        //Bottom Half of X*************************************
        for (space=1,i=((input+3)/2),low=(((input+1)/2)-1),spaceL=low-1;
                i<=input;
                i++,low--,spaceL--,space+=2){
            //Left Space loop
            for(j=0;j<spaceL;j++){
                cout<<" ";
            }
            cout<<i;
            for(j=0;j<space;j++){
                cout<<" ";
            }
            cout<<low<<endl;
        
        }        
    }
    //EVEN**************************************************
    else{
        //Declare Variables
        int j=0;//Counters
        int i,l;//Counters for input and low
        //space=input-2;
                
         //Top Half of X*************************************
        for (space=input-2,i=input,low=1,spaceL=0;i>=low;i--,low++,spaceL++,space-=2){
            //Left Space loop
            for(j=0;j<spaceL;j++){
                cout<<" ";
            }
            cout<<low;
            for(j=0;j<space;j++){
                cout<<" ";
            }
            cout<<i<<endl;
        
        } 
        //Bottom Half of X*************************************
        for (space=0,i=((input/2)+1),low=(input/2),spaceL=low-1;
                i<=input;
                i++,low--,spaceL--,space+=2){
            //Left Space loop
            for(j=0;j<spaceL;j++){
                cout<<" ";
            }
            cout<<low;
            for(j=0;j<space;j++){
                cout<<" ";
            }
            cout<<i<<endl;
        
        }        
    }        
        
    //Map inputs to outputs or process the data
    space=input-2;
    
    //Output the transformed data
       
    //Exit stage right!
    return 0;
}

