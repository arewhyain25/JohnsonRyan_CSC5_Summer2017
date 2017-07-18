/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on July 10, 2017, 10:11 PM
 * Purpose:  Total Change inserted to a vending machine.
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
    //Declare and Initialize variables
    float total,change=0;
    int coin=0;   
    //Map inputs to outputs or process the data
    cout<<"You need to insert $3.50 to get your deep-fried twinkie."<<endl;
    cout<<"Please being inserting coins."<<endl;
    cout<<"Press 1 to enter a dollar."<<endl;
    cout<<"Press 2 to enter a quarter."<<endl;
    cout<<"Press 3 to enter a dime."<<endl;
    cout<<"Press 4 to enter a nickel."<<endl;
    do {
        cout<<fixed<<setprecision(2)<<showpoint;
        cin>>coin;
        switch (coin) {
            case 1:total+=1;break;
            case 2:total+=.25;break;
            case 3:total+=.1;break;
            case 4:total+=.05;break;
        }
        cout<<"Total $"<<total<<endl;
    } while (total<3.50);
    //Output the transformed data
    cout<<"Enjoy your deep-fried twinkie!"<<endl;
    change=total-3.50;
    if (change>0){
        cout<<fixed<<setprecision(2)<<showpoint;
        cout<<"Your Change is $"<<change<<endl;
    }
    //Exit stage right!
    return 0;
}

