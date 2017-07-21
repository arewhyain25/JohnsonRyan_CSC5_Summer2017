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
int combat(int&,int&,int,int&,int,int,int,int,int,int,bool&);
int hlthpot(int&,int&,int&);
bool guesNum(int&,float&,int,int,int&);//Guess the number


//Execution begins here
int main(int argc, char** argv) {
    //Setting the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare and Initialize variables
    char action=0;
        //Character Ability Scores
        int str=10,//Strength
            dex=16,//Dexterity
            con=10,//Constitution
            intl=14,//Intellect
            wis=13,//Wisdom
            cha=14;//Charisma

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
        int gold=50;//Starting gold
        int armor=16;//Character's Armor Class
        string name;//Character's name
        string helper;//Name of contracted help

        //Environmental Features
        bool helped=false;
        int beers=0;//Beers drank
        int potions=3;//Health potions in inventory
        float table=2000;//Available gold in the Inn
        int ring=1;//Limits the occurrence of the ring theft
        bool victory=true;//Condition set by combat resolution
        int wager=0;
        bool fight=false;//Prevents player from returning to the gambling table 
                         //After fighting.
    
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
                       cout<<"Your choice of ACTION : ";
               cin>>action;
               switch(action){
                   case '1':{//Gambling
                        //file describing gambling "guess the number"
                       if(fight==true){
                           cout<<"There is no one gambling, the fight made "
                                   "everyone move on to new things for the evening."
                                   <<endl;
                           table=0;
                       }                       
                       if (table<=0){//Prevent's taking money from house that isn't there
                            cout<<setw(100)<<"There is no money at the table, haven't you done"
                                    " enough?"<<endl;
                        }
                       cout<<"You step up to the table of gamblers."<<endl;
                       guesNum(gold,table,chamod,decptn,wager);
                       if (gold<0){//You are fighting the gambler (Health=20,mod=1,AC=14)
                           gold=abs(gold);
                            combat(gold,health,maxhlth,potions,dexmod,armor,fweapon,20,1,14,victory);
                            //Player's Gold, Current Health, Max Health, # of Potions,
                            //Combat Modifier, and Armor Class;
                            //Mob's Health, Combat Modifier, and Armor Class;
                            if (victory==false&&health>0){
                                cout<<"Running from a fight is not necessarily a bad decision but it"
                                        "will end your night at least you kept"<<endl;
                                cout<<"the gold on your person. You cannot go back into the in "
                                        "for the shame would be too much."<<endl;
                                cout<<"You eventually put together a workable disguise and return to"
                                        " the room you rented."<<endl;                                
                            }
                            else if (health<=0&&victory==false){
                                cout<<"You lost the fight and were thrown out of the inn"<<endl;
                                cout<<"You lost half of your money in the exchange."<<endl;
                                gold/=2;                                
                            }else {
                                cout<<"You defeated the suspicious gamblers. Collect what gold you can find on the ground"
                                        " and go about your business."<<endl;
                                cout<<"Fights over gambling are common and while everyone is a bit wary of you,"
                                        " no one is giving you trouble."<<endl;
                                int find=(wager*2-wager/d20(1));//Randomize gold recovered just the a DM would
                                gold+=find;
                                cout<<"You find "<<find<<" gold and now have "<<gold<<" total."<<endl;
                            }
                            if (helped==true){
                                gold-=10;
                                cout<<"You pay "+helper+" 10g."<<endl;
                            }
                            fight=true;
                            helped=false;    
                       }break;
                   }
                   case '2':{//Listen for Rumors
                       action=0;
                       cout<<"In the least suspicious way possible you blend into "
                               "your surroundings and listen to the crowd."<<endl;
                       //file for what you hear
                       cout<<setw(100)<<"What do you want to do?"<<endl;
                       cout<<"Pursue this lead - PRESS 1"<<endl;
                       cout<<"Ignore the drunk fool - PRESS 2"<<endl;
                       cout<<"Your ACTION";
                       cin>>action;
                       turn++;
                       switch (action){
                           case 1:{
                               //file for going up stairs to door
                            while(check(15,dexmod,sltohnd)==false){//Sleight of hand and Thieves 
                                turn++;                            //tools have same proficiency bonus 
                            } 
                            
                           }
                       }
                       
                       int turns=0;                       
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
                                    cout<<setw(100)<<"The young man seems very anxious, perhaps a "
                                            "nice cold ale will help calm his nerves."<<endl;break;
                                }
                                case 1:{
                                    cout<<"You buy a round for the two of you."<<endl;
                                    gold-=5;
                                    cout<<setw(100)<<"He seems to calm down and "
                                            "be more at ease."<<endl;break;
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

                           cout<<setw(100)<<"Would you like to buy a round of drinks for 5g?"
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
                                   if(check(20-beers*2,dexmod,sltohnd)==true){
                                       //cout//file for successful pickpocket
                                         ring--;
                                         int worth=(rand()%20+1)*5;
                                         cout<<"The ring was worth "<<worth<<" gold."<<endl;
                                         gold+=worth;
                                   }else{//Combat!!!You're fighting Lover-Boy (health=14,mod=0,ac=12)
                                       combat(gold,health,maxhlth,potions,dexmod,armor,fweapon,14,0,12,victory);
                                            //Player's Gold, Current Health, Max Health, # of Potions,
                                            //Combat Modifier, and Armor Class;
                                            //Mob's Health, Combat Modifier, and Armor Class;
                                       if (victory==false&&health>0){
                                            cout<<"Running from a fight is not necessarily a bad decision but it"
                                                    "will end your night at least you kept"<<endl;
                                            cout<<"the gold on your person. You cannot go back into the in "
                                                    "for the shame would be too much."<<endl;
                                            cout<<"You eventually put together a workable disguise and return to"
                                                    " the room you rented."<<endl;                                
                                        }
                                        else if (health<=0&&victory==false){
                                            cout<<"You lost the fight and were thrown out of the inn"<<endl;
                                            cout<<"You lost half of your money in the exchange."<<endl;
                                            gold/=2;                                
                                        }
                                        else {
                                            cout<<"You beat the kid up for catching you in the act "
                                                    "this is not what we would call a high moment for you."<<endl;;
                                            ring--;
                                            int worth=(rand()%20+1)*5;
                                            cout<<"The ring was worth "<<worth<<" gold."<<endl;
                                            gold+=worth;
                                            gold+=(rand()%20+1)*3;//Randomize gold recovered just the a DM would
                                            cout<<"What just occurred is not exactly a mystery to the patrons "
                                                    "and you are 'asked' to leave."<<endl;
                                            victory=false;
                                        }
                                        if (helped==true){
                                            gold-=10;
                                            cout<<"You pay "+helper+" 10g."<<endl;
                                        }     
                                        helped=false;
                                   }
                               }break;
                               case '3':{
                                   if (beers==4){
                                       cout<<"The smart thing to do now is remove "
                                               "yourself from the situation and avoid "
                                               "notice."<<endl;
                                       ring--;
                                       int worth=(rand()%20+1)*5;
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
            cout<<"You have "<<health<<" hit points, "<<gold<<" gold."<<endl;
            }while(health>0&&victory==true);
cout<<"You have "<<gold<<"gold and your night in the inn is over."<<endl;
cout<<endl;
cout<<setw(50)<<"GAME OVER"<<endl;
       
   //Exit stage right!
    return 0;
} 
//Scenarios:

//Gambling Games
bool guesNum(int& gold,float& table,int chamod,int decptn,int& wager){//Character's Gold, Possible gold at the table
    char stay=1;
    int beer=0;
    float wager=0;//Must be a float for Lie detector Difficulty to adjust properly
    int wins=0,losses=0;
    char num;
    char action='0';
    if(table<=0){
        cout<<setw(100)<<"..."<<endl;
    }else if (gold<=0){
        cout<<setw(100)<<"You can't gamble if you don't have anything to "
                "wager, move along."<<endl;
    }else{
        do{
            cout<<"|Table : "<<table<<" |Beers : "<<beer<<" |Wins : "<<wins<<" |Losses : "
                    <<losses<<"|"<<endl;
            cout<<setw(100)<<"Would you like to buy a round for the table for  5g?"<<endl;
            cout<<setw(100)<<"Yes - PRESS 1"<<endl;
            cout<<setw(100)<<"No - PRESS 2"<<endl;
            cin>>action;
            if (action=='1'){
                cout<<"You buy a round of ale for the table."<<endl;
                cout<<setw(100)<<"The table of risk takers thank you kindly and"
                        " urge you on to the next game."<<endl;
                beer++;
                gold-=5;
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
                cout<<"Wager : ";
                cin>>wager;
            }
            while(wager>gold){
                cout<<setw(100)<<"Try as you may, you can't bet money you don't have."
                        "Try wagering less."<<endl;
                cout<<"Wager : ";
                cin>>wager;
            }
            while(wager<=0){
                cout<<setw(100)<<"That's not a real wager. "
                        "Try wagering less."<<endl;
                cout<<"Wager : ";
                cin>>wager;
            }
            gold-=wager;//Player Ante
            table-=wager;//Table Ante
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
                gold+=wager*2;
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
                    table+=wager*2;
                    losses++;
                    cout<<"Now you have "<<gold<<" gold."<<endl;
                }else{                     
                    cout<<"You decided to lie, of course you did. Simple games require"
                            " simple lies, you respond with a simple 'No'"<<endl;
                    /*Difficulty of deception check rises when a larger percentage
                     * of the table's money is at stake and when you have won several
                     * times. Losing occasionally lowers their suspicion, but so does
                     * beer.
                     */       
                    if (check((10+wins*2-beer-losses/2)*(1+wager/table),chamod,decptn)==true){ 
                        cout<<"The gamblers are disappointed but they believe you."<<endl;
                        gold+=wager*2;
                        wins++;
                        cout<<"Now you have "<<gold<<" gold."<<endl;
                    }else{ //Combat!!!
                        cout<<setw(100)<<"As convincing as you typically are they don't "
                            "buy it. The biggest of the bunch"<<endl;
                        cout<<setw(100)<<"flips the table over and attacks you."<<endl;
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
        }while (stay=='1'&&gold>0&&table>0);
    }
    return gold,table,wager;           
}
//If Combat is necessary    
int combat(int& gold,int& health,int maxhlth,int& potions,int abltmod,int plyrAC,int weapon,
        int mobhlth,int cbtmod,int mobAC,bool& victory){
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
                                    d4(1);//Helper's Damage
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
                        if(potions>=1){
                            cout<<"You drink a health potion to regain some strength";
                            cout<<endl;
                            hlthpot(health,maxhlth,potions);
                            cout<<"Your health is now "<<health<<endl;
                        }else{
                            cout<<"You have no more potions."<<endl;
                        }break;
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
                            int damage=dmg(total,cbtmod,d8(1)+3);
                            cout<<"You are hit and receive "<<damage<<" damage."<<endl;
                            health-=damage;
                        }else cout<<"Your enemy missed"<<endl;
                }else{
                    cout<<"Your enemy attempts to punch you...";
                    if(check(plyrAC,cbtmod,0)==true){
                            int total=0;
                            int damage=dmg(total,cbtmod,rapier());
                            cout<<"you are hit and receive "<<damage<<" damage."<<endl;
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
                            int damage=dmg(total,cbtmod,d8(1)+3);
                            cout<<"You are hit and receive "<<damage<<" damage."<<endl;
                            health-=damage;
                        }else cout<<"Your enemy missed"<<endl;
                }else{
                    cout<<"Your enemy attempts to punch you...";
                    if(check(plyrAC,cbtmod,0)==true){
                            int total=0;
                            int damage=dmg(total,cbtmod,rapier());
                            cout<<"you are hit and receive "<<damage<<" damage."<<endl;
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
                                    d4(1);//Helper's Damage
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
                        }break;
                    }
                    case '5':{//Use Health Potion
                        if(potions>=1){
                            cout<<"You drink a health potion to regain some strength";
                            cout<<endl;
                            hlthpot(health,maxhlth,potions);
                            cout<<"Your health is now "<<health<<endl;
                        }else{
                            cout<<"You have no more potions."<<endl;
                        }break;
                    }
                    default: cout<<"You failed to make a real decision."<<endl;
                }
            }//End Player's move
            cout<<"Your health : "<<health<<"   Enemy's health : "<<mobhlth<<endl;
            if (health<=0)victory=false;
        }while (health>0&&mobhlth>0);
    }    
    abs(gold);
    return gold,health,potions,victory;
}
//Mechanics and Rules
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
int hlthpot(int& health,int& maxhlth,int& potions){
    health+=d4(4);
    if (health>=maxhlth)health=maxhlth;
    potions--;
    cout<<"You have "<<potions<<" left!"<<endl;
    return health;
}