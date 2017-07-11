/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on June 28, 2017, 12:48 PM
 * Purpose:  Cereal weight converter
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
    float crlOnz, crlMT;//Weight of a box of cereal in ounces
                        //Weight of a box of cereal in metric tons
    int bxPerT;//Boxes of cereal per metric ton
    //Initialize variables
    
    //Input data
    cout<<"Ever wonder how much your box of cereal weighs in metric tons?"<<endl;
    cout<<"Input the weight of that box in ounces. ";
    cin>>crlOnz;
    
    //Map inputs to outputs or process the data
    crlMT=crlOnz/35273.92;//Cereal in metric tons=Cereal in ounces/Conversion
    bxPerT=35273.92/crlOnz;//Boxes per metric ton=conversion/weight of box in ounces
            
    //Output the transformed data
    cout<<"Prepare to be underwhelmed."<<endl;
    cout<<"Your "<<crlOnz<<" ounce box of cereal weighs "
            <<crlMT<< " metric tons"<<endl;
    cout<<"There would be "<<bxPerT<<" boxes of cereal in a metric ton.";
    cout<<endl;
    cout<<"Aren't you glad you asked?";
    
    //Exit stage right!
    return 0;
}

