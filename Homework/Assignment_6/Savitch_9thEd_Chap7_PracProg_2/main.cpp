/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on July 24, 2017, 1:14 AM
 * Purpose:  Find all the 2s in the array
 */

//System Libraries
#include <iostream>  //Input - Output Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes
void count2(int [],int);

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
    
    count2(array,n);
    
    //Map inputs to outputs or process the data
    
    //Output the transformed data
    
    //Exit stage right!
    return 0;
}

void count2(int array [],int n){
    int count=0;
    for(int i=0;i<n;i++){
        if (array[i]==2){
            count++;
            cout<<i<<" "<<array[i]<<endl;
        }        
    }             
    cout<<"there are "<<count<<" 2's";    
}
