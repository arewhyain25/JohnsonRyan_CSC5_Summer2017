/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on July 10, 2017, 9:40 PM
 * Purpose:  Determine Clothing Size
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
    //Declare variables
    float hat,chest,waist,height,weight,age,chest10,waist10;
    char again=0;
    //Initialize variables
    hat,chest,waist,chest10,waist10=0;
            
    //Input data
    do {
        cout<<"Input height (in): ";
        cin>>height;
        cout<<"Input weight (lbs): ";
        cin>>weight;
        cout<<"Input age: ";
        cin>>age;

        //Map inputs to outputs or process the data
        hat=(weight/height)*2.9f;
        chest=(height*weight/288)+((1.0f/8.0f)*((age-30)/10));
        waist=(weight/5.7f)+((age-28)/2)/10.0f;
        chest10=(height*weight/288)+((1.0f/8.0f)*((age-20)/10));
        waist10=(weight/5.7f)+((age-18)/2)/10.0f;

        //Output the transformed data
        cout<<fixed<<setprecision(2)<<showpoint;
        cout<<"Your approximate Sizes are:"<<endl;
        cout<<"Hat Size is    "<<hat<<endl;
        cout<<"Jacket Size is "<<chest<<"in."<<endl;
        cout<<"Waist Size is  "<<waist<<"in"<<endl;
        cout<<endl;
        cout<<"When you are "<<static_cast<int>(age+10)<<" your sizes "
                "will change as follows:"<<endl;
        cout<<"Jacket Size will be "<<chest10<<"in."<<endl;
        cout<<"Waist Size will be  "<<waist10<<"in"<<endl;
        cout<<"If you would like to run the program again press 1 and "
                "ENTER"<<endl;
        cout<<"If not, press any other key and ENTER"<<endl;
        cin>>again;
    }while (again=='1');
    
    //Exit stage right!
    return 0;
}

