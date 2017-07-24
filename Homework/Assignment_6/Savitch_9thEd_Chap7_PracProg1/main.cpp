/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on July 24, 2017, 12:31 AM
 * Purpose:  Template to be utilized in creating
 *           solutions to problems in our CSC/CIS 5 
 *           class.
 */

//System Libraries
#include <iostream>  //Input - Output Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes
bool true2(int [],int);

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    int SIZE=1000;
    int array[SIZE];
    int n=0;
    
    //Input data
    cout<<"How many entries would you like to use? No more than 1000."<<endl;
    cin>>n;
    while(n>=1000){
        cout<<"No more than 1000."<<endl;
        cin>>n;
    }    
    cout<<"Enter "<<n<<" different integers : "<<endl;
    for(int i=0;i<n;i++){
        cout<<"Number "<<i+1<<" : ";
        cin>>array[i];
    }
    
    if (true2(array,n)==true){
        cout<<"The array begins or ends with 2"<<endl;
    }else{
        cout<<"The array does not begin or end with 2"<<endl;
    }
    
    //Map inputs to outputs or process the data
    
    //Output the transformed data
    
    //Exit stage right!
    return 0;
}

bool true2(int array [],int n){
    if (array[0]==2||array[n]==2){
        return true;
    }else{
        return false;
    }          
        
    }
