/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on June 14, 2017, 11:32 AM
 * Purpose:  Display CS! using characters followed by "Computer Science is Cool Stuff"
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
    char c;
    char s;
        
    //Initialize variables
    
    //Input data
    cout<<"What character do you want to use for the big C?";
    cin>>c;
    cout<<"What character would you like to use for the big S?";
    cin>>s;
            
    //Output the transformed data
        //the problem in the book requires a border of "*" but i am having trouble with using that character...why?
    cout<<"***********************************************"<<endl;
    cout<<endl;
    cout<<"          "<<c<<" "<<c<<" "<<c<<"             "<<s<<" "<<s<<" "<<s<<" "<<s<<"      !!  "<<endl;
    cout<<"        "<<c<<"       "<<c<<"         "<<s<<"         "<<s<<"    !!     "<<endl;
    cout<<"       "<<c<<"                 "<<s<<"               !!    "<<endl;
    cout<<"      "<<c<<"                   "<<s<<"              !!"<<endl;
    cout<<"      "<<c<<"                    "<<s<<" "<<s<<" "<<s<<" "<<s<<"       !!"<<endl;
    cout<<"      "<<c<<"                             "<<s<<"    !!"<<endl;
    cout<<"       "<<c<<"                             "<<s<<"   !!"<<endl;
    cout<<"        "<<c<<"       "<<c<<"         "<<s<<"         "<<s<<endl;
    cout<<"          "<<c<<" "<<c<<" "<<c<<"             "<<s<<" "<<s<<" "<<s<<" "<<s<<"      00  "<<endl;
    cout<<endl;
    cout<<"    Computer Science is Cool Stuff!!!"<<endl;
    cout<<"***********************************************"<<endl;
    
    //Exit stage right!
    return 0;
}

