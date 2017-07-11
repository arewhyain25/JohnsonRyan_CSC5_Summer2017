/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on June 22, 2017, 5:02 PM
 * Purpose:  Pea counter
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
    int nPods,peasPP,tPeas;//Number of Pea Pods, Number of Peas in a Pod, Total Peas   
    
    //Initialize variables
    
    //Input data
    cout<<"Press return after entering a number."<<endl;
    cout<<"Enter the number of pods: "<<endl;
    cin>>nPods;
    cout<<"Enter the number of peas in a pod: "<<endl;
    cin>>peasPP;
    
    
    //Map inputs to outputs or process the data
    tPeas=nPods*peasPP;//total peas = number of pods X peas in each pods
    //tPeas=nPods+peasPP;//Problem 4: Change the multiplication to addition
    //and observe that the logic is wrong
    //tPeas=nPods/peasPP;//Problem 3: Change the multiplication to division
    //and enter zero for peasPP, observe the runtime error due to division by 0
    //Output the transformed data
    cout<<"If you have ";
    cout<<nPods;
    cout<<" pea pods"<<endl;
    cout<<"and ";
    cout<<peasPP;
    cout<<" peas in each pod, then"<<endl;
    cout<<"you have ";
    cout<<tPeas;
    cout<<" peas in all the pods."<<endl;
    cout<<"Good-bye"<<endl;//Practice problem 2
    
    
    //Exit stage right!
    return 0;
}

