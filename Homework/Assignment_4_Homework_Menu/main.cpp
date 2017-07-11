/* 
  File:   main.cpp
  Author: Ryan Johnson
  Created on July 10, 2017, 10:32 PM
  Purpose:  Homework Menu for Assignment 4
 */

//System Libraries
#include <iostream>//Input Output Library
#include <cstdlib> //Random number generator seed
#include <ctime>   //Time Library
#include <iomanip> //Format Library
#include<cmath>    //Math Library
using namespace std;

//User Libraries

//Global Constants
const float GRAVITY=6.643e-8;//Universal Gravitational Constant (cm^3)/(g*sec^2)
const float CNVLTGAL=0.264179; //Conversion factor of 0.264179 Gallons/Liter
const int CNVPERC=100;

//Function Prototypes

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Declare Variables
    char choice;
    
    //Loop on the menu
    do{
    
        //Input values
        cout<<"Choose from the list"<<endl;
        cout<<"Type 1 for Savitch Practice Program #7"<<endl;
        cout<<"Type 2 for Savitch Practice Program #1"<<endl;
        cout<<"Type 3 for Savitch Practice Program #2"<<endl;
        cout<<"Type 4 for Savitch Practice Program #4"<<endl;
        cout<<"Type 5 for Savitch Practice Program #5"<<endl;
        cout<<"Type 6 for Savitch Problem #2"<<endl;
        cout<<"Type 7 for Savitch Problem #3"<<endl;
        cout<<"Type 8 for Savitch Problem #6"<<endl;
        cout<<"Type 9 for Savitch Practice Program #5"<<endl;
        cout<<"Type any other character to exit"<<endl;
        cin>>choice;

        //Switch to determine the Problem
        switch(choice){
            case '1':{
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
                cout<<"***********************************************"<<endl;
                break;
            }
            case '2':{
                //Declare variables
                float mpg;
                float miles,ltrs,gal;
                char again;

                //Initialize variables
                mpg=0;
                again=0;

                //Input data
                do{        
                    cout<<"How many miles did you drive?"<<endl;
                    cin>>miles;
                    cout<<"How many liters did your car consume?"<<endl;
                    cin>>ltrs;

                //Map inputs to outputs or process the data
                    gal=ltrs*CNVLTGAL;
                    mpg=miles/gal;

                //Output the transformed data
                    cout<<fixed<<setprecision(2);
                    cout<<"Your car's fuel efficiency is "<<mpg<<" Miles/Gal"<<endl;
                    cout<<"***********************************************"<<endl;
                    cout<<"Would you like to run the program again? (Y/N)";
                    cin>>again;        
                }while ((again=='Y')||(again=='y'));
                cout<<"***********************************************"<<endl;
                break;
            }
            case '3':{
                //Declare variables
                float miles1,ltrs1,gal1,miles2,ltrs2,gal2,mpg1,mpg2;
                char again;

                //Initialize variables
                mpg1=0,mpg2=0;
                again=0;

                //Input data
                do{        
                    cout<<"How far did Car 1 travel in miles?"<<endl;
                    cin>>miles1;
                    cout<<"How many liters did Car 1 consume?"<<endl;
                    cin>>ltrs1;
                    cout<<"How far did Car 2 travel in miles?"<<endl;
                    cin>>miles2;
                    cout<<"How many liters did Car 2 consume?"<<endl;
                    cin>>ltrs2;

                //Map inputs to outputs or process the data
                    gal1=ltrs1*CNVLTGAL;
                    mpg1=miles1/gal1;
                    gal2=ltrs2*CNVLTGAL;
                    mpg2=miles2/gal2;

                //Output the transformed data
                    cout<<fixed<<setprecision(2);
                    cout<<"Fuel efficiency of Car 1 is "<<mpg1<<" Miles/Gal"<<endl;
                    cout<<"Fuel efficiency of Car 2 is "<<mpg2<<" Miles/Gal"<<endl;
                    if (mpg1>mpg2){cout<<"Car 1 is more efficient."<<endl;}        
                    else if (mpg1==mpg2){cout<<"The cars are equally efficient."<<endl;}       
                    else {cout<<"Car 2 is more efficient."<<endl;}
                    cout<<"***********************************************"<<endl;
                    cout<<"Would you like to run the program again? (Y/N)";
                    cin>>again;        
                }while ((again=='Y')||(again=='y'));
                cout<<"***********************************************"<<endl;                
                break;
            }
            case '4':{
                //Declare variables
                float pVal,yAgoVal,infltnR;

                //Initialize variables
                infltnR=0;

                //Input data
                cout<<"This program will estimate inflation based on the change in value"
                        " of an item"<<endl;
                cout<<"Input the present value of an item $";
                cin>>pVal;
                cout<<"Input the value of the same item a year ago $";
                cin>>yAgoVal;

                //Map inputs to outputs or process the data
                infltnR=(pVal-yAgoVal)/yAgoVal*CNVPERC;

                //Output the transformed data
                cout<<fixed<<setprecision(2);
                cout<<"Estimated inflation rate is: "<<infltnR<<"%";
                cout<<"***********************************************"<<endl;
                break;
            }
            case '5':{
                //Declare variables
                float prstVal,prevVal,infltnR,nxtVal,nxtVal2;

                //Initialize variables
                infltnR=0;

                //Input data
                cout<<"This program will estimate inflation based on the change in value"
                        " of an item"<<endl;
                cout<<"Input the present value of an item: $";
                cin>>prstVal;
                cout<<"Input the value of the same item a year ago: $";
                cin>>prevVal;

                //Map inputs to outputs or process the data
                infltnR=(prstVal-prevVal)/prevVal;
                nxtVal=prstVal*(1+infltnR);
                nxtVal2=nxtVal*(1+infltnR);

                //Output the transformed data
                cout<<fixed<<setprecision(2);
                cout<<"Estimated inflation rate is: "<<infltnR*CNVPERC<<"%"<<endl;
                cout<<"Based on this estimate, a year from now the item will cost $"<<nxtVal;
                cout<<endl;
                cout<<"Two years from now it will cost $"<<nxtVal2<<endl;
                cout<<"***********************************************"<<endl;
                break;
            }
            case '6':{
                //Declare variables
                float hat,chest,waist,height,weight,age;
                char again=0;
                //Initialize variables
                hat,chest,waist=0;

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

                    //Output the transformed data
                    cout<<fixed<<setprecision(2)<<showpoint;
                    cout<<"Your approximate Sizes are:"<<endl;
                    cout<<"Hat Size is    "<<hat<<endl;
                    cout<<"Jacket Size is "<<chest<<"in."<<endl;
                    cout<<"Waist Size is  "<<waist<<"in"<<endl;
                    cout<<endl;
                    cout<<"If you would like to run the program again press 1 and "
                            "ENTER"<<endl;
                    cout<<"If not, press any other key and ENTER"<<endl;
                    cin>>again;
                }while (again=='1');
                cout<<"***********************************************"<<endl;
                break;
            }
            case '7':{
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
                cout<<"***********************************************"<<endl;
                break;
            }
            case '8':{
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
                cout<<"***********************************************"<<endl;
                break;
            }
            default:
                cout<<"You are exiting the program"<<endl;
        }
    }while(choice>='1'&&choice<='8');
    
    //Exit stage right!
    return 0;
}