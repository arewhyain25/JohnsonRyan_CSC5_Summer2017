/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on July 24, 2017, 7:30 PM
 * Purpose:  tic-tac-toe
 */

//System Libraries
#include <iostream>  //Input - Output Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes
void prntBrd(char[],int,int);
char xTurn(char[],int,int);
char oTurn(char[],int,int);

//Execution begins here
int main(int argc, char** argv) {
    //Declare and Initialize Variables
    int SIZE=9;
    char array[SIZE]={'1','2','3','4','5','6','7','8','9'};
    bool winner;
    
    //Display board
    prntBrd(array,SIZE,3);
    
    
    //Play
    do{
       xTurn(array,SIZE,3);
       if((array[0]=='X'&& array[1]=='X'&&array[2]=='X')||
                (array[3]=='X'&& array[4]=='X'&& array[5]=='X')||
                (array[6]=='X'&& array[7]=='X'&& array[8]=='X')||
                (array[0]=='X'&& array[3]=='X'&& array[6]=='X')||
                (array[1]=='X'&& array[4]=='X'&& array[7]=='X')||
                (array[2]=='X'&& array[5]=='X'&& array[8]=='X')||
                (array[0]=='X'&& array[4]=='X'&& array[8]=='X')||
                (array[2]=='X'&& array[4]=='X'&& array[6]=='X')){
            winner=true;
            cout<<"'X' WINS!"<<endl;
       }else{
        oTurn(array,SIZE,3); 
       }
        if((array[0]=='O'&& array[1]=='O'&&array[2]=='O')||
                (array[3]=='O'&& array[4]=='O'&& array[5]=='O')||
                (array[6]=='O'&& array[7]=='O'&& array[8]=='O')||
                (array[0]=='O'&& array[3]=='O'&& array[6]=='O')||
                (array[1]=='O'&& array[4]=='O'&& array[7]=='O')||
                (array[2]=='O'&& array[5]=='O'&& array[8]=='O')||
                (array[0]=='O'&& array[4]=='O'&& array[8]=='O')||
                (array[2]=='O'&& array[4]=='O'&& array[6]=='O')){
            winner=true;
            cout<<"'O' WINS!"<<endl;
        }
    }while(winner==false);
    
    
    //Exit stage right!
    return 0;
}

void prntBrd(char a[],int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

char xTurn(char a[],int n,int perLine){
    cout<<"X's turn, pick a space to place an 'X'"<<endl;
    int move=0;
    cin>>move;
    while (a[move-1]=='X'||a[move-1]=='0'){
        cout<<"Choose a different space."<<endl;
        cin>>move;
    }
    a[move-1]='X';
    prntBrd(a,n,perLine);
}
char oTurn(char a[],int n,int perLine){
    cout<<"O's turn, pick a space to place an 'O'"<<endl;
    int move=0;
    cin>>move;
    while (a[move-1]=='X'||a[move-1]=='0'){
        cout<<"Choose a different space."<<endl;
        cin>>move;
    }
    a[move-1]='O';
    prntBrd(a,n,perLine);    
}