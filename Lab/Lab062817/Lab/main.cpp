/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on June 14, 2017, 12:30 PM
 * Purpose:  Truth Table
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
    bool x,y;
    
    //Display the Truth Table Heading
    cout<<"X Y !X !Y X&&Y X||Y X^Y X^Y^Y X^Y^X !(X&&Y) !X||!Y";
    cout<<" !(X||Y) !X&&!Y"<<endl;
    
    //First Row of Table
    x=true;
    y=true;
    cout<<(x?'T':'F')<<" ";
    cout<<(y?'T':'F')<<" ";
    cout<<(!x?'T':'F')<<"  ";
    cout<<(!y?'T':'F')<<"  ";
    cout<<(x&&y?'T':'F')<<"    ";
    cout<<(x||y?'T':'F')<<"    ";
    cout<<(x^y?'T':'F')<<"   ";
    cout<<(x^y^y?'T':'F')<<"     ";
    cout<<(x^y^x?'T':'F')<<"     ";
    cout<<(!(x&&y)?'T':'F')<<"       "; 
    cout<<(!x||!y?'T':'F')<<"      ";
    cout<<(!(x||y)?'T':'F')<<"       ";
    cout<<(!x&&!y?'T':'F')<<"  ";
    cout<<endl;
    
    //Second Row of Table
    x=true;
    y=false;
    cout<<(x?'T':'F')<<" ";
    cout<<(y?'T':'F')<<" ";
    cout<<(!x?'T':'F')<<"  ";
    cout<<(!y?'T':'F')<<"  ";
    cout<<(x&&y?'T':'F')<<"    ";
    cout<<(x||y?'T':'F')<<"    ";
    cout<<(x^y?'T':'F')<<"   ";
    cout<<(x^y^y?'T':'F')<<"     ";
    cout<<(x^y^x?'T':'F')<<"     ";
    cout<<(!(x&&y)?'T':'F')<<"       "; 
    cout<<(!x||!y?'T':'F')<<"      ";
    cout<<(!(x||y)?'T':'F')<<"       ";
    cout<<(!x&&!y?'T':'F')<<"  ";
    cout<<endl;
        
    //Third Row of Table
    x=false;
    y=true;
    cout<<(x?'T':'F')<<" ";
    cout<<(y?'T':'F')<<" ";
    cout<<(!x?'T':'F')<<"  ";
    cout<<(!y?'T':'F')<<"  ";
    cout<<(x&&y?'T':'F')<<"    ";
    cout<<(x||y?'T':'F')<<"    ";
    cout<<(x^y?'T':'F')<<"   ";
    cout<<(x^y^y?'T':'F')<<"     ";
    cout<<(x^y^x?'T':'F')<<"     ";
    cout<<(!(x&&y)?'T':'F')<<"       "; 
    cout<<(!x||!y?'T':'F')<<"      ";
    cout<<(!(x||y)?'T':'F')<<"       ";
    cout<<(!x&&!y?'T':'F')<<"  ";
    cout<<endl;
    
    //Fourth Row of Table
    x=false;
    y=false;
    cout<<(x?'T':'F')<<" ";
    cout<<(y?'T':'F')<<" ";
    cout<<(!x?'T':'F')<<"  ";
    cout<<(!y?'T':'F')<<"  ";
    cout<<(x&&y?'T':'F')<<"    ";
    cout<<(x||y?'T':'F')<<"    ";
    cout<<(x^y?'T':'F')<<"   ";
    cout<<(x^y^y?'T':'F')<<"     ";
    cout<<(x^y^x?'T':'F')<<"     ";
    cout<<(!(x&&y)?'T':'F')<<"       "; 
    cout<<(!x||!y?'T':'F')<<"      ";
    cout<<(!(x||y)?'T':'F')<<"       ";
    cout<<(!x&&!y?'T':'F')<<"  ";
    cout<<endl;
    
    //Input data
    
    //Map inputs to outputs or process the data
    
    //Output the transformed data
    
    //Exit stage right!
    return 0;
}

