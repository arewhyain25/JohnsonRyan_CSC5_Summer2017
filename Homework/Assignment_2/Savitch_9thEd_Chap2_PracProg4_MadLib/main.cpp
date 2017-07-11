/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on June 28, 2017, 12:58 PM
 * Purpose: Mad Lib
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
    const int SIZE=20;
    char inst[SIZE],you[SIZE],food[SIZE],adj[SIZE],color[SIZE],animal[SIZE];   
    char num[SIZE];
    //Initialize variables
    
    //Input data
    cout<<"Let's do a Mad Lib!"<<endl;
    cout<<"What is your instructor's name? ";
    cin.getline(inst,SIZE);
    cout<<"What is your first name? ";
    cin.getline(you,SIZE);
    cout<<"Name a food: ";
    cin.getline(food,SIZE);
    cout<<"Pick a number between 100 and 120 :";
    cin.getline(num,SIZE);
    cout<<"Pick an adjective, really get crazy with this one: ";
    cin.getline(adj,SIZE);
    cout<<"What's your favorite color? ";
    cin.getline(color,SIZE);
    cout<<"Pick an animal :";
    cin.getline(animal,SIZE);
    cout<<endl;
    
    //Map inputs to outputs or process the data
    
    //Output the transformed data
    cout<<"Dear Instructor "<<inst<<","<<endl;
    cout<<endl;
    cout<<"I am sorry that I am unable to turn in my homework at this time. ";
    cout<<"First,"<<endl;
    cout<<"I ate a rotten "<<food<<" which made me turn "<<color;
    cout<<" and extremely ill. I"<<endl;
    cout<<"came down with a fever of "<<num<<". Next, my "<<adj<<" pet ";
    cout<<animal<<endl;
    cout<<"must have smelled the remains of the "<<food<<" on my";
    cout<<" homework,"<<endl;
    cout<<"because he ate it.I am currently rewriting my homework and hope";
    cout<<" you"<<endl;
    cout<<"will accept it late."<<endl;
    cout<<endl;
    cout<<"Sincerely,"<<endl;
    cout<<you;   
    
    //Exit stage right!
    return 0;
}

