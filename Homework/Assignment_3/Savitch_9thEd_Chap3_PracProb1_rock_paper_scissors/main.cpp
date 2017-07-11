/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on July 4, 2017, 2:19 PM
 * Purpose:  Make a 2-player rock-paper-scissors game
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
    char p1,p2;//Player 1 and 2 entries
    char again;//Response to rematch prompt
    
    //Initialize variables
    
    //Input data
    cout<<"Let's play rock paper scissors"<<endl;
    do{
        cout<<"Player 1 enter your throw: (r,p,s) "<<endl;
        cin>>p1;
                    
    //Player 1 throws Rock    
        if (p1=='r'||p1=='R'){
            cout<<"Player 2 enter your throw: (r,p,s) "<<endl;
            cin>>p2;
            switch (p2){
                case ('r'):cout<<"We have a tie!";break;
                case ('R'):cout<<"We have a tie!";break;
                case ('p'):cout<<"Paper covers rock! Player 2 wins!";break;
                case ('P'):cout<<"Paper covers rock! Player 2 wins!";break;
                case ('s'):cout<<"Rock breaks scissor! Player 1 wins!";break;
                case ('S'):cout<<"Rock breaks scissor! Player 1 wins!";break;
                default:cout<<"Invalid selection, Player 1 Wins by"
                        " default!";break;                        
            }
                
        }
    
    //Player 1 throws Scissors
        else if (p1=='s'||p1=='S'){
            cout<<"Player 2 enter your throw: (r,p,s) "<<endl;
            cin>>p2;
            switch (p2){
                case ('s'):cout<<"We have a tie!";break;
                case ('S'):cout<<"We have a tie!";break;
                case ('p'):cout<<"Scissor cuts paper! Player 1 wins!";break;
                case ('P'):cout<<"Scissor cuts paper! Player 1 wins!";break;
                case ('r'):cout<<"Rock breaks scissor! Player 2 wins!";break;
                case ('R'):cout<<"Rock breaks scissor! Player 2 wins!";break;
                default:cout<<"Invalid selection, Player 1 Wins by"
                        " default!";break;
            }
                
        }
    //Player 1 throws Paper
        else if (p1=='p'||p1=='P'){
            cout<<"Player 2 enter your throw: (r,p,s) "<<endl;
            cin>>p2;
             switch (p2){
               case ('p'):cout<<"We have a tie!";break;
               case ('P'):cout<<"We have a tie!";break;
               case ('s'):cout<<"Scissor cuts paper! Player 2 wins!";break;
               case ('S'):cout<<"Scissor cuts paper! Player 2 wins!";break;
               case ('r'):cout<<"Paper covers rock! Player 1 wins!";break;
               case ('R'):cout<<"Paper covers rock! Player 1 wins!";break;
               default:cout<<"Invalid selection, Player 1 Wins by"
                        " default!";break;
            }
        }
        else cout<<"Invalid selection, Player 1 forfeits"<<endl;
    
    //Propose rematch
    cout<<endl;
    cout<<"Would you like to play again?"<<endl;
    cout<<"Press Y to play again."<<endl;
    cout<<"Press any other key to end match."<<endl;
    cin>>again;
    }while (again=='Y'||again=='y');
    cout<<"Thanks for playing";
       
    //Exit stage right!
    return 0;
}

