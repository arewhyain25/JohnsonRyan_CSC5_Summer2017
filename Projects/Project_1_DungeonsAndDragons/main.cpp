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
#include <iomanip>   //Format Library
#include <cmath>     //Math Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes
int d4(int);//Roll 4-sided die x times
int d6(int);//Roll 6-sided die x times
int d8(int);//Roll 8-sided die x times
int d10(int);//Roll 10-sided die x times
int d12(int);//Roll 12-sided die x times
int d20(int);//Roll 20-sided die x times
bool check(int,int,int);//Set check difficulty,add bonuses, test for success
int abltmod(int);//determine modifier from ability scores
int dmg(int,int,int);//Roll + Ability Modifier + Bonus
int rapier();
int dagger();
int shrtbow();
int fists();
int combat(int,int,int,int,int,int,int,int,int);
int hlthpot(int,int,int);
bool guesNum(int,int,int,int);//Guess the number

//Execution begins here
int main(int argc, char** argv) {
    //Setting the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare and Initialize variables
    char action=0;
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
        int profbns=3;//Proficiency Bonus
        int     athltcs=profbns*1,  //Athletics
                acrbtcs=profbns*1,  //Acrobatics
                sltohnd=profbns*2, //Sleight of Hand (double proficiency)
                stlth=profbns*1,    //Stealth
                arcana=profbns*0,   //Arcana
                history=profbns*0,  //History
                invstgt=profbns*0,  //Investigate
                nature=profbns*0,   //Nature
                relgion=profbns*0,  //Religion
                anmlhnd=profbns*0,  //Animal Handling
                insight=profbns*0,  //Insight
                medicn=profbns*0,   //Medicine
                prcptn=profbns*1,   //Perception
                survl=profbns*0,    //Survival
                decptn=profbns*2,   //Deception (double proficiency)
                intmdtn=profbns*0,  //Intimidation
                prfmnc=profbns*0,   //Performance
                persn=profbns*2,    //Persuasion (double proficiency)
                fweapon=profbns*1,   //Finesse Weapon
                rweapon=profbns*1,   //Ranged Weapon
                mweapon=profbns*1,   //Marshal Weapon
                gweapon=profbns*0;   //Great/2-hand Weapon


        //Character Features
        int maxhlth=30;//Character's Health
        int health=maxhlth;//Character's current health
        float money=200;//The most important thing to a thief, Character's Gold
        int silver=0;//100 Silver = 1 Gold
        int gold=money;//Whole value is gold, decimal value is silver
        int armor=18;//Character's Armor Class
        string name;//Character's name
        string helper;//Name of contracted help

        //Environmental Features
        bool helped=false;
        int beers=0;//Beers drank
        int potions;//Health potions in inventory
        float house;//Available gold in the Inn
        int ring=1;//Limits the occurrence of the ring theft
    //Combat Test    ******************************                 ******************************          
   // health=combat(health,dexmod,maxhlth,potions,armor,fweapon,20,0,12);
                        //Player's health,max health, number of potions,
                        //Players Combat Modifier, Player's Armor Class;
                        //Mob's health,mob's combat modifier,mobs Armor Class;
    
    /*if(check(15,dexmod,fweapon)==true){
        
    }else 
    */
    
    //Input data
    //****************File for Arrival**************
    cout<<setw(100)<<"What name will you be going by this evening?"<<endl;
    cin>>name;
    cout<<setw(100)<<"Okay '"+name+"' and what is the name of your friend here?"<<endl;
    cin>>helper;
    cout<<setw(100)<<"Great well then Masters "+name+" and "+helper+" I will set your "
            "things in your room upstairs."<<endl;
    cout<<setw(100)<<"Please make yourselves at home in our humble common room"<<endl;    
    //Begin Play
            //**************File for common room****************
            do{
               cout<<setw(100)<<"What would you like to do?"<<endl; 
               cout<<setw(100)<<"Look for a game for gambling, though what"
                       " you do could hardly be called gambling. - PRESS 1"<<endl;
               cout<<setw(100)<<"Listen to the room of rowdy commoners "
                       "for any useful rumors. - PRESS 2"<<endl;
               cout<<setw(100)<<"Step up to the bar and buy a drink. - Press 3";
                       cout<<endl;
               cin>>action;
               switch(action){
                   case '1':{//Gambling
                       //file describing gambling "guess the number"
                       cout<<"You step up to the table of gamblers."<<endl;
                       int temp=gold;
                       if (house<=0){
                           cout<<setw(100)<<"The table is tapped out, haven't you done"
                                   " enough?"<<endl;
                       }
                       gold=guesNum(gold,house,chamod,decptn);
                       if (gold<0){
                            health=combat(health,dexmod,maxhlth,potions,armor,fweapon,20,1,14);
                            //Player's health,max health, number of potions,
                            //Players Combat Modifier, Player's Armor Class;
                            //Mob's health,mob's combat modifier,mobs Armor Class;
                            gold*=(-1);
                            house=temp-gold;
                            cout<<"You have "<<gold<<"gold"<<endl;
                       }
                       break;
                   }
                   case '2':{//Listen for Rumors
                       if(ring>=1){
                           
                       }
                       
                   }
                   case '3':{//Buy a drink
                       ////file for conversation with guy at the bar.
                       beers=0;
                       do{
                           if (ring<1){
                               cout<<"There is nothing of interest at the bar."<<endl;
                           }else{
                          switch (beers){
                                case 0:{
                                    cout<<setw(100)<<"The young man seems very anxious perhaps a "
                                            "nice cold ale will help calm his nerves."<<endl;break;
                                }
                                case 1:{
                                    cout<<setw(100)<<"The young man seems calm and more "
                                            "at ease."<<endl;break;
                                }
                                case 2:{
                                    cout<<setw(100)<<"Now he's getting tipsy but just "
                                            "a little goofy."<<endl;break;
                                }
                                case 3:{
                                    cout<<setw(100)<<"Okay, he's drunk now and starting"
                                            "to attract attention."<<endl;break;
                                }
                                case 4:{
                                    cout<<setw(100)<<"Oh that did it! He passed out"
                                            " as he falls to the ground you pick him up"
                                            " and set him back on the bar."<<endl;
                                    cout<<"Of course you also nicked the ring "
                                            "in the process, hopefully its worth the gold "
                                            "in beer you spent."<<endl;break;
                                }
                              default:
                                  cout<<"He's still passed out."<<endl;
                            }

                           cout<<setw(100)<<"Would you like to buy him a drink?"
                                   " - PRESS 1"<<endl;
                           cout<<setw(100)<<"Do you want to relieve him of his"
                                   " burden? - PRESS 2"<<endl;
                           cout<<setw(100)<<"Or do you want to just walk away?"
                                   " - PRESS 3"<<endl;
                           cin>>action;
                           switch (action){
                               case '1':{
                                   if (beers==4){
                                       cout<<"The bartender looks at you scornfully and "
                                               "declines to pour your friend nother drink."
                                               <<endl;
                                       beers++;
                                   }else{
                                       beers++;
                                   }
                               }break;
                               case '2':{
                                   if(check(15-beers,dexmod,sltohnd)==true){
                                       //cout//file for successful pickpocket
                                         ring--;
                                         int worth=(rand()%5+1)*50;
                                         cout<<"The ring was worth "<<worth<<" gold."<<endl;
                                         gold+=worth;
                                   }else{//Combat!!
                                       health=combat(health,dexmod,maxhlth,potions,armor,fweapon,14,0,10);
                                    //Player's health,max health, number of potions,
                                    //Players Combat Modifier, Player's Armor Class;
                                    //Mob's health,mob's combat modifier,mobs Armor Class;
                                   }
                               }break;
                               case '3':{
                                   if (beers==4){
                                       cout<<"The smart thing to do no is remove "
                                               "yourself from the situation and avoid "
                                               "notice."<<endl;
                                       ring--;
                                       int worth=(rand()%5+1)*50;
                                         cout<<"The ring was worth "<<worth<<" gold."<<endl;
                                         gold+=worth;
                                   }else{
                                   cout<<"You decide not to waste your time on the kid "
                                           "and walk away, leaving him with his questionably"
                                           " valued engagement ring."<<endl;
                                   cout<<"Moments later the lucky lady arrives at the inn"
                                           " and he promptly begins his proposal unable"
                                           " to wait a second longer."<<endl;
                                   cout<<"The woman sweetly laughs and accepts the proposal."
                                           <<endl;
                                   ring--;
                                   }
                               }break;
                           }
                           }
                       }while (ring>=1); 
                       
                   }
                   default:{
                       
                   }
               }
            cout<<"You have "<<health<<" hit points, "<<gold<<" gold and "
                    <<silver<<" silver."<<endl;
            }while(health>0);
       
    //Output the transformed data
       
    //Exit stage right!
    return 0;
}
   
int d4(int nDice){ 
    int total=0;
    for(int i=1;i<=nDice;i++){
        int die=rand()%4+1;//[1,4]
        //cout<<die<<endl;
        total+=die;
    }
    return total;
}
int d6(int nDice){ 
    int total=0;
    for(int i=1;i<=nDice;i++){
        int die=rand()%6+1;//[1,6]
        //cout<<die<<endl;
        total+=die;
    }
    return total;
}
int d8(int nDice){ 
    int total=0;
    for(int i=1;i<=nDice;i++){
        int die=rand()%8+1;//[1,8]
        //cout<<die<<endl;
        total+=die;
    }
    return total;
}
int d10(int nDice){ 
    int total=0;
    for(int i=1;i<=nDice;i++){
        int die=rand()%10+1;//[1,10]
        //cout<<die<<endl;
        total+=die;
    }
    return total;
}
int d12(int nDice){ 
    int total=0;
    for(int i=1;i<=nDice;i++){
        int die=rand()%12+1;//[1,12]
        //cout<<die<<endl;
        total+=die;
    }
    return total;
}
int d20(int nDice){ 
    int total=0;
    for(int i=1;i<=nDice;i++){
        int die=rand()%20+1;//[1,20]
        if (die==20){cout<<"CRITICAL ROLL!"<<endl;}
        total+=die;
        //cout<<total;
    }
    return total;
}
bool check(int diff,int abltmod,int prof){
    bool check;
    int roll=0;
    roll=d20(1)+abltmod+prof;
    cout<<endl;
    if (roll==20){check=true;
    }
    else {(roll>=diff)?check=true:check=false;}
    return check;
}
int abltmod(int ablty){
    int mod=(ablty-10)/2;
    return mod;
}
int dmg(int roll,int mod,int bonus){
    int dmg=roll+mod+bonus;    
    return dmg;
}
int rapier(){
   return d8(1);
}
int dagger(){
    return d4(1);
}
int shrtbow(){
    return d6(1);
}
int fists(){
    return d4(1);
}
int hlthpot(int health){
    health+=d4(4);
    return health;
}
//Gambling Games
bool guesNum(int gold,int table,int chamod,int decptn){//Character's Gold, Possible gold at the table
    char stay=1;
    int beer=0;
    int wager=0;
    int wins=0,losses=0;
    char num;
    char action='0';
    do{
        cout<<"Table : "<<table<<" Beers : "<<beer<<" Wins : "<<wins<<" Losses : "<<losses<<endl;
        cout<<setw(100)<<"Would you like to buy a round for the table for be 5 gold?"<<endl;
        cout<<setw(100)<<"Yes - PRESS 1"<<endl;
        cout<<setw(100)<<"No - PRESS 2"<<endl;
        cin>>action;
        if (action=='1'){
            cout<<"You buy a round of ale for the table."<<endl;
            cout<<setw(100)<<"The table of risk takers thank you kindly and"
                    " urge you on to the next game."<<endl;
            beer++;
        }else{
            cout<<"You politely decline the suggestion and things continue as"
                    " they were."<<endl;
        }
        cout<<setw(100)<<"Make a wager"<<endl;
        cout<<"Wager : ";
        cin>>wager;
        while(wager>table){
            cout<<setw(100)<<"There isn't that much gold left on the table. "
                    "Try wagering less."<<endl;
            cin>>wager;
        }
        cout<<setw(100)<<"Okay pal, now pick a number 1-3 and lets see if we can guess it"<<endl;
        cout<<"Your number : ";
        cin>>num;
        while(num>'3'||num<'1'){
            cout<<setw(100)<<"Come on, pick a number between 1 and 3, this isn't the "
                    "part you get to cheat on."<<endl;
            cout<<"Your number : ";
            cin>>num;
        }
        int guess=rand()%3+1;
        cout<<setw(98)<<"Is your number "<<static_cast<char>(guess+48)<<"?"<<endl;
        if(!(num==static_cast<char>(guess+48))){
            gold+=wager;
            table-=wager;
            wins++;
            cout<<"No."<<endl;
            cout<<"You won honestly...neat! Now you have "<<gold;
            cout<<" gold."<<endl;
        }else{
            cout<<setw(100)<<"Do you want to tell the truth or lie?"<<endl;
            cout<<setw(100)<<"Check Difficulty is : "<<((10-beer+wins-losses)*(1+wager/table))<<endl;
            cout<<setw(100)<<"Lie - PRESS 1"<<endl;
            cout<<setw(100)<<"Lie - PRESS 2"<<endl;
            cout<<setw(100)<<"Lie - PRESS 3"<<endl;
            cout<<setw(100)<<"Lie - PRESS 4"<<endl;
            cout<<setw(100)<<"Tell Truth - PRESS 5"<<endl;
            cin>>action;
            if (action=='5'){
                cout<<"You admit the truth and share with them that they"
                        " guessed correctly, your pockets are lighter"<<endl;
                cout<<"but so is you hearth for all that will get you."<<endl;
                gold-=wager;
                table+=wager;
                losses--;
                cout<<"Now you have "<<gold<<" gold."<<endl;
            }else{                     
                cout<<"You decided to lie, of course you did. Simple games require"
                        "simple lies, you respond with a simple 'No'"<<endl;
                /*Difficulty of deception check rises when a larger percentage
                 * of the table's money is at stake and when you have won several
                 * times. Losing occasionally lowers their suspicion, but so does
                 * beer.
                 */       
                if (check((10+wins*2-beer-losses/2)*(1+wager/table),chamod,decptn)==true){ 
                    cout<<"The gamblers are disappointed but they believe you."<<endl;
                    gold+=wager;
                    table-=wager;
                    wins++;
                    cout<<"Now you have "<<gold<<" gold."<<endl;
                }else{ //Combat!!!
                    bool combat=true;
                    gold-=wager;
                    gold*=(-1);
                }
                    
            }

        }
        if (gold>0){
        cout<<setw(100)<<"Do you want to stay at the table?"<<endl;
        cout<<setw(100)<<"Stay - PRESS 1"<<endl;
        cout<<setw(100)<<"Leave - PRESS 2"<<endl;
        cin>>stay;
        }
    }while (stay=='1'||combat==false);
    return gold;           
}
    
int combat(int health,int maxhlth,int potions,int abltmod,int plyrAC,int weapon,
        int mobhlth,int cbtmod,int mobAC){
    //roll initiative
    
    char move='0';
    bool helped=false;
    int pInitv=d20(1)+abltmod;//player initiative plus dexterity
    int mInitv=d20(1);//mob initiative (no dex bonus because inn mobs are unspecial
    if (pInitv>mInitv){//Player goes first
        do{
            //Player Move
            if(health>0){
                cout<<"COMBAT";
                cout<<setw(94)<<"Make a decision."<<endl;
                cout<<setw(100)<<"Attack with my sword - PRESS 1"<<endl;
                cout<<setw(100)<<"Attack with my dagger - PRESS 2"<<endl;
                cout<<setw(100)<<"Run away! - PRESS 3"<<endl;
                cout<<setw(100)<<"Signal to your helper for assistance - PRESS 4"<<endl;
                cout<<setw(100)<<"Use a health potion - PRESS 5"<<endl;
                cin>>move;
                switch (move){
                    case '1':{//Sword Attack
                        if(check(mobAC,abltmod,weapon)==true){
                            int total=0;
                            if (helped==true){
                                    total=d6(3)+//Sneak Attack
                                    d4(1)+2;//Helper's Damage
                            }
                            int damage=dmg(total,abltmod,rapier());
                            cout<<"You hit dealing "<<damage<<" damage."<<endl;
                            mobhlth-=damage;
                        }else cout<<"You missed"<<endl;
                        break;
                    }
                    case '2':{//Dagger Attack
                        if(check(mobAC,abltmod,weapon)==true){
                            int total=0;
                            if (helped==true){
                                    total=d6(3)+//Sneak Attack
                                    d4(1)+2;//Helper's Damage
                            }
                            int damage=dmg(total,abltmod,rapier());
                            cout<<"You hit dealing "<<damage<<" damage."<<endl;
                            mobhlth-=damage;
                        }else cout<<"You missed"<<endl;
                        break;
                    }
                    case '3':{//Run away little girl, run away
                        cout<<"You run out of the inn and everybody laughs at you";
                        cout<<endl;
                        health=0;
                        mobhlth=0;
                        break;
                    }
                    case '4':{//Call for help
                        cout<<"You execute the agreed upon signal to call "
                                "for assistance"<<endl;
                        if(helped==true){cout<<"but your helper is already "
                                "involved, quit wasting time!"<<endl;
                        }else {cout<<"and your helper joins the fight."<<endl;
                        helped=true;
                        break;
                        }
                    }
                    case '5':{//Use Health Potion
                        cout<<"You drink a health potion to regain some strength";
                        cout<<endl;
                        health=fmin(hlthpot(health),maxhlth);
                        cout<<"Your health is now "<<health<<endl;
                        potions--;
                        break;
                    }               
                    default: cout<<"You failed to make a real decision."<<endl;
                }
            }//End Player's move
            //Enemy's Move
            if(mobhlth>0){
                if(rand()%10==0){
                    cout<<"Your enemy picks up a chair and attempts to hit you with it"<<endl;
                    if(check(plyrAC,cbtmod,0)==true){
                            int total=0;
                            int damage=dmg(total,cbtmod,rapier());
                            cout<<"You are hit and recieve "<<damage<<" damage."<<endl;
                            health-=damage;
                        }else cout<<"Your enemy missed"<<endl;
                }else{
                    cout<<"Your enemy attempts to punch you...";
                    if(check(plyrAC,cbtmod,0)==true){
                            int total=0;
                            int damage=dmg(total,cbtmod,rapier());
                            cout<<"you are hit and recieve "<<damage<<" damage."<<endl;
                            health-=damage;
                        }else cout<<"but misses."<<endl;
                }
            } 
            cout<<"Your health : "<<health<<"   Enemy's health : "<<mobhlth<<endl;
        }while (health>0&&mobhlth>0);       
    }else{
        do{       
        //Enemy's Move
            if(mobhlth>0){
                if(rand()%10==0){
                    cout<<"Your enemy picks up a chair and attempts to hit you with it"<<endl;
                    if(check(plyrAC,cbtmod,0)==true){
                            int total=0;
                            int damage=dmg(total,cbtmod,rapier());
                            cout<<"You are hit and recieve "<<damage<<" damage."<<endl;
                            health-=damage;
                        }else cout<<"Your enemy missed"<<endl;
                }else{
                    cout<<"Your enemy attempts to punch you...";
                    if(check(plyrAC,cbtmod,0)==true){
                            int total=0;
                            int damage=dmg(total,cbtmod,rapier());
                            cout<<"you are hit and recieve "<<damage<<" damage."<<endl;
                            health-=damage;
                        }else cout<<"but misses."<<endl;
                }
            }
            //Player Move
            if(health>0){
                cout<<"COMBAT";
                cout<<setw(94)<<"Make a decision."<<endl;
                cout<<setw(100)<<"Attack with my sword - PRESS 1"<<endl;
                cout<<setw(100)<<"Attack with my dagger - PRESS 2"<<endl;
                cout<<setw(100)<<"Run away! - PRESS 3"<<endl;
                cout<<setw(100)<<"Signal to your helper for assistance - PRESS 4"<<endl;
                cout<<setw(100)<<"Create a distraction - PRESS 5"<<endl;
                cin>>move;
                switch (move){
                    case '1':{//Sword Attack
                        if(check(mobAC,abltmod,weapon)==true){
                            int total=0;
                            if (helped==true){
                                    total=d6(3)+//Sneak Attack
                                    d4(1)+2;//Helper's Damage
                            }
                            int damage=dmg(total,abltmod,rapier());
                            cout<<"You hit dealing "<<damage<<" damage."<<endl;
                            mobhlth-=damage;
                        }else cout<<"You missed"<<endl;
                        break;
                    }
                    case '2':{//Dagger Attack
                        if(check(mobAC,abltmod,weapon)==true){
                            int total=0;
                            if (helped==true){
                                    total=d6(3)+//Sneak Attack
                                    d4(1)+2;//Helper's Damage
                            }
                            int damage=dmg(total,abltmod,rapier());
                            cout<<"You hit dealing "<<damage<<" damage."<<endl;
                            mobhlth-=damage;
                        }else cout<<"You missed"<<endl;
                        break;
                    }
                    case '3':{//Run away little girl, run away
                        cout<<"You run out of the inn and everybody laughs at you";
                        cout<<endl;
                        health=0;
                        mobhlth=0;
                        break;
                    }
                    case '4':{//Call for help
                        cout<<"You execute the agreed upon signal to call "
                                "for assistance"<<endl;
                        if(helped==true){cout<<"but your helper is already "
                                "involved, quit wasting time!"<<endl;
                        }else {cout<<"and your helper joins the fight."<<endl;
                        helped=true;
                        break;
                        }
                    }
                    case '5':{//Use Health Potion
                        cout<<"You drink a health potion to regain some strength";
                        cout<<endl;
                        health=fmin(hlthpot(health),maxhlth);
                        cout<<"Your health is now "<<health<<endl;
                        potions--;
                        break;
                    }
                    default: cout<<"You failed to make a real decision."<<endl;
                }
            }//End Player's move
            cout<<"Your health : "<<health<<"   Enemy's health : "<<mobhlth<<endl;
        }while (health>0&&mobhlth>0);
    }
    if (health==0&&mobhlth==0){
        cout<<"Running from a fight is not necessarily a bad decision but it"
                "will end your night."<<endl;
        cout<<"You cannot go back into the in for the shame would be too much."
                " You eventually put together a workable disguise and return to"
                " the room you rented."<<endl;
    }
    else if (health<=0){
        cout<<"You lost the fight and were thrown out of the inn"<<endl;
    }
    else if (mobhlth<=0){
        cout<<"You defeated your enemy. Collect your gold and"
                " go about your business."<<endl;
    }
    return health;
}