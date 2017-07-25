/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on July 24, 2017, 6:53 PM
 * Purpose:  phone book
 */

//System Libraries
#include <iostream>  //Input - Output Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes
string phnBk(string,string[],string[],int);

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    string names []={"Michael Myers", "Ash Williams", "Jack Torrance",
                     "Freddie Kruger"};
    string phnNums []={"333-8000", "333-2323", "333-6150", "339-7970"};
    string tgtName, tgtPhn;
    char c='y';
    
    do{
        cout<<"Enter a name to find the corresponding phone number."<<endl;
        getline(cin, tgtName);
        tgtPhn=phnBk(tgtName,names,phnNums,4);
        if (!(tgtPhn=="")){
            cout<<"The number is : "<<tgtPhn<<endl;
        }
        else{
            cout<<"Name not found. "<<endl;
        }
        cout<<"Look up another name? (y/n)"<<endl;
        cin>>c;
        cin.ignore();        
    }while(c=='y');  
    
    //Exit stage right!
    return 0;
}

string phnBk(string target,string names[],string numbers[],int n){
    string tgtNum="";
    for(int i=0;i<4;i++){
        if (target==names[i])
            tgtNum=numbers[i];        
    }
    return tgtNum;
}
