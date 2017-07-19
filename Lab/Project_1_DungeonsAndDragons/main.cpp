/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on July 17, 2017, 3:34 PM
 * Purpose:  Project 1: The Devilish Rogue
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <ctime>     //Time
#include <cstdlib>   //Random Function
#include <fstream>   //File I/O
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes
int d4(int);
int d6(int);
int d8(int);
int d10(int);
int d12(int);
int d20(int);
bool check(int,int,int);//Set check difficulty,add bonuses
int abltmod(int);
int dmg(int,int);

//Execution begins here
int main(int argc, char** argv) {
    //Setting the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare and Initialize variables
    
    //Character Ability Scores
    int str=10,//Strength
        dex=18,//Dexterity
        con=10,//Constitution
        intl=14,//Intellect
        wis=13,//Wisdom
        cha=16;//Charisma
    
    //Ability Modifiers
    int strmod=abltmod(str);
    int dexmod=abltmod(dex);
    int conmod=abltmod(con);
    int intmod=abltmod(intl);
    int wismod=abltmod(wis);
    int chamod=abltmod(cha);
                
    //Character Proficiencies
    int     athltcs=3,  //Athletics
            acrbtcs=7,  //Acrobatics
            sltohnd=10, //Sleight of Hand
            stlth=7,    //Stealth
            arcana=0,   //Arcana
            history=0,  //History
            invstgt=0,  //Investigate
            nature=0,   //Nature
            relgion=0,  //Religion
            anmlhnd=0,  //Animal Handling
            insight=0,  //Insight
            medicn=0,   //Medicine
            prcptn=3,   //Perception
            survl=0,    //Survival
            decptn=3,   //Deception
            intmdtn=0,  //Intimidation
            prfmnc=0,   //Performance
            persn=3,    //Persuasion
            fweapon=3,   //Finesse Weapon
            rweapon=3,   //Ranged Weapon
            mweapon=3,   //Marshal Weapon
            gweapon=0;   //Great/2-hand Weapon
    
    //Initialize variables
    cout<<d4(4);
    
    
    //Input data
       
    //Map inputs to outputs or process the data
       
    //Output the transformed data
       
    //Exit stage right!
    return 0;
}

int d4(int nDice){ 
    int dmg;
    for(int i=1;i<=nDice;i++){
        int die=rand()%4+1;//[1,4]
        cout<<die<<endl;
        dmg+=die;
    }
    return dmg;
}
int d6(){
    int die=rand()%6+1;//[1,6]
    return die;
}
int d8(){
    int die=rand()%8+1;//[1,8]
    return die;
}
int d10(){
    int die=rand()%10+1;//[1,10]
    return die;
}
int d12(){
    int die=rand()%12+1;//[1,12]
    return die;
}
int d20(){
    int die=rand()%20+1;//[1,20]
    return die;
}
bool check(int diff,int abltmod,int prof){
    bool check;
    int roll=d20()+abltmod+prof;
    (roll>=diff)?check=true:check=false;
    return check;
}
int abltmod(int ablty){
    int mod=(ablty-10)/2;
    return mod;
}
int dmg(int die,int nDice){
    int dmg=0;
    for(int i=1;i<=nDice;i++){
        cout<<die<<endl;
        dmg+=die;
    }
    cout<<dmg;
        return dmg;
}
    
    
