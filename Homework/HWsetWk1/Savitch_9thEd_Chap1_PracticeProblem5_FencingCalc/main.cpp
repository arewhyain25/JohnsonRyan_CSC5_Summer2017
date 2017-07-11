/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on June 20, 2017, 8:13 PM
 * Purpose:  Friendly fence calculator for a rectangular yard
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
    int width, depth, totL; //width and depth of area, total length of fence
    
    //Initialize variables
    
    //Input data
    cout<<"Hello!"<<endl;
    cout<<"Press return after entering a number."<<endl;
    cout<<"Enter the width (in feet) of the area to be fenced: "<<endl;
    cin>>width;
    
    cout<<"Enter the depth (in feet)of the area to be fenced: "<<endl;
    cin>>depth; 
    
    //Map inputs to outputs or process the data
    totL=width*2+depth*2;
    
    //Output the transformed data
    cout<<"For a yard that is ";
    cout<<width;
    cout<<" ft wide, "<<endl;
    cout<<"and ";
    cout<<depth;
    cout<<" feet deep, "<<endl;
    cout<<"you will need ";
    cout<<totL;
    cout<<" feet of fencing to enclose the yard."<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Good-bye"<<endl;
    
    
    //Exit stage right!
    return 0;
}

