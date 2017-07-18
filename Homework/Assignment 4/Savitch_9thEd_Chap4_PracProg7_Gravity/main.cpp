/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on July 10, 2017, 4:10 PM
 * Purpose:  Calculate Gravity between two masses
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <cmath>     //Math Library
#include <iomanip>   //Format Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants
const float GRAVITY=6.643e-8;//Universal Gravitational Constant (cm^3)/(g*sec^2)

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    float mass1,mass2,dist;//Mass of each object and the distance between them
    float gForce;//Gravitational force between the two
    char again;   
    //Initialize variables
    gForce=0;
    
    //Input data
    cout<<"Let's do science!"<<endl;
    cout<<"We can calculate the gravitational force between"<<endl;
    cout<<"two objects with a simple equation."<<endl;
    cout<<"All we need is to know their masses and the distance between them";
    cout<<endl;
    do{
        cout<<"Mass of the first object in grams: ";
        cin>>mass1;
        cout<<"Mass of the second object in grams: ";
        cin>>mass2;
        cout<<"Distance between the two objects in cm: ";
        cin>>dist;   

        //Map inputs to outputs or process the data
        gForce=((mass1*mass2)*GRAVITY)/pow(dist,2);

        //Output the transformed data
        cout<<"The Gravitational force between two objects that are "<<dist<<"cm";
        cout<<endl;
        cout<<"apart with masses of "<<mass1<<"g and "<<mass2<<"g is : "<<gForce;
        cout<<" (g*cm)/sec^2"<<endl;
        cout<<"This unit is also known as a dyne"<<endl;
        cout<<"If you would like to run the program again press 1"<<endl;
        cout<<"otherwise press any other key ";
        cin>>again;
    }while (again=='1');
    //Exit stage right!
    return 0;
}

