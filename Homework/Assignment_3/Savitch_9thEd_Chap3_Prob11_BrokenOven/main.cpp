/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on July 5, 2017, 2:10 PM
 * Purpose:  The oven keypad is broken
 *          Output the next best temperature
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
    char n100,n10,n1,h100,h10,h1,l100,l10,l1;
    int tempIn,tempOut;
        
    //Input data
    cout<<"The 1, 4,and 7 keys are broken on my oven."<<endl;
    cout<<"Input your desired temperature (0-100) and we'll get"
            " as close as we can."<<endl;
    cin>>tempIn;
    
    //Isolate the Digits
    n100=tempIn/100;
    tempIn-=100*n100;
    n10=tempIn/10;
    tempIn-=10*n10;
    n1=tempIn;
    //Test Isolation
    cout<<"The desired temperature is "<<100*n100+10*n10+n1<<endl;
    
    //Alter input
    switch (n100){
        case 1:h100=2,l100=0;break;
        case 4:h100=5,l100=3;break;
        case 7:h100=8,l100=6;break;
        default:h100=n100,l100=n100;break;
    }
    switch (n10){
        case 1:h10=2,l10=0;break;
        case 4:h10=5,l10=3;break;
        case 7:h10=8,l10=6;break;
        default:h10=n10,l10=n10;break;        
    }
    switch (n1){
        case 1:h1=2,l1=0;break;
        case 4:h1=5,l1=3;break;
        case 7:h1=8,l1=6;break;
        default:h1=n1,l1=n1;break;
    }
    if (h100>n100){
        h10=0,h1=0,l10=9,l1=9;
    }
    if (h10>n10){
        h1=0,l1=9;
    }
    
    //Output the transformed data
    cout<<"The closest usable temperature above your desired temperature is:"<<endl;
    cout<<100*h100+10*h10+h1<<" F"<<endl;
    cout<<"The closest usable temperature below your desired temperature is:"<<endl;
    cout<<100*l100+10*l10+l1<<" F"<<endl;
    
    //Exit stage right!
    return 0;
}

