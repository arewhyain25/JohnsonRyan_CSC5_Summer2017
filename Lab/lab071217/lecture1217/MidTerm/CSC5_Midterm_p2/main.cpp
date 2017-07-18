/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on July 11, 2017, 7:36 PM
 * Purpose:  Input a 4 character number
 *           Output in reverse '*' representing the digit
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
    char d4,d3,d2,d1;
    
    //Initialize variables
    
    
    //Input data
    cout<<"This Program will display *'s as representation of a 4-character"
            "number."<<endl;
    cout<<"Input a four character number : ";
    cin>>d4>>d3>>d2>>d1;
    cout<<endl;
    
    //Output the transformed data
    cout<<"Output with * representation is:"<<endl;
    
    //Digit Test
    //cout<<"  123456789"<<endl;
    
    //First Digit
    cout<<d1<<" ";
    switch (d1){        
        case '9':cout<<'*';
        case '8':cout<<'*';
        case '7':cout<<'*';
        case '6':cout<<'*';
        case '5':cout<<'*';
        case '4':cout<<'*';
        case '3':cout<<'*';
        case '2':cout<<'*';
        case '1':cout<<'*';
        case '0':cout<<' '<<endl;break;
        default: cout<<'?'<<endl;break;        
    }
    //Second Digit
    cout<<d2<<" ";
    switch (d2){
        case '9':cout<<'*';
        case '8':cout<<'*';
        case '7':cout<<'*';
        case '6':cout<<'*';
        case '5':cout<<'*';
        case '4':cout<<'*';
        case '3':cout<<'*';
        case '2':cout<<'*';
        case '1':cout<<'*';
        case '0':cout<<' '<<endl;break;
        default: cout<<'?'<<endl;break;
    }
    //Third Digit
    cout<<d3<<" ";
    switch (d3){
        case '9':cout<<'*';
        case '8':cout<<'*';
        case '7':cout<<'*';
        case '6':cout<<'*';
        case '5':cout<<'*';
        case '4':cout<<'*';
        case '3':cout<<'*';
        case '2':cout<<'*';
        case '1':cout<<'*';
        case '0':cout<<' '<<endl;break;
        default: cout<<'?'<<endl;break;
    }
    //Fourth Digit
    cout<<d4<<" ";
    switch (d4){
        case '9':cout<<'*';
        case '8':cout<<'*';
        case '7':cout<<'*';
        case '6':cout<<'*';
        case '5':cout<<'*';
        case '4':cout<<'*';
        case '3':cout<<'*';
        case '2':cout<<'*';
        case '1':cout<<'*';
        case '0':cout<<' '<<endl;break;
        default: cout<<'?'<<endl;break;
    }
    //Digit Test
    //cout<<"  123456789"<<endl;
    //Exit stage right!
    return 0;
}

