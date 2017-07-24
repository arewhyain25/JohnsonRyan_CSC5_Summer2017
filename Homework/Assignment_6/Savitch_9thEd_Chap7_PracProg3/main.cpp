/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on July 24, 2017, 1:32 AM
 * Purpose:  Swap first and last
 */

//System Libraries
#include <iostream>  //Input - Output Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes
int swapper(int&,int&);

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
    cout<<"The first entry was "<<array[0]<<endl;
    cout<<"The last entry was "<<array[n-1]<<endl;
    
    swapper (array[0],array[n-1]);
    
    cout<<"The first entry is now "<<array[0]<<endl;
    cout<<"The last entry is now "<<array[n-1]<<endl;
    
    //Map inputs to outputs or process the data
    
    //Output the transformed data
    
    //Exit stage right!
    return 0;
}

int swapper (int &a,int &b){
    
    int temp=a;
    a=b;
    b=temp;
    return (a,b);
}
