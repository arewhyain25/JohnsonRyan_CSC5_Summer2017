/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on July 5, 2017, 5:28 PM
 * Purpose:  Solve the Riddler's riddle!
 */

//System Libraries
#include <iostream>  //Input - Output Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    
    //Declare and initialize variables
    char d1000,d100,d10,d1=0;
    short address=1000,test;
    bool con=true;
    
    //Test
    do{ con=true;
    address++;
    //Isolate the digits
    test=address;
        d1000=test/1000;
        test-=(1000*d1000);
        d100=test/100;
        test-=(100*d100);
        d10=test/10;
        test-=(10*d10);
        d1=test;
    //Test condition:Odd    
        if (address%2==0){
            con=false;
        }
    //1000s digit is 3 times 10s digit
        else if (d1000!=(3*d10)){
            con=false;
        }
    //Sum of digits is 27
        else if ((d1000+d100+d10+d1)!=27){
            con=false;
        }
    //Each digit is unique
        else if (d1000==d100||d1000==d10||d1000==d1
                ||d100==d10||d100==d1||d10==d1){
            con=false;
        }
        
    }while (con==false);
       
    //Map inputs to outputs or process the data
 
    
    //Output the transformed data
    cout<<"The Riddler's next caper is going to be at "<<address
            <<" Pennnsylvania Avenue."<<endl;
    
        
    //Exit stage right!
    return 0;
}

