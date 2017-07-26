/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on July 25, 2017, 12:16 PM
 * Purpose:  Project 2: The Devilish Rogue w/ Arrays
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <ctime>     //Time
#include <cstdlib>   //Random Function
#include <fstream>   //File I/O
#include <iomanip>   //Format Library
#include <cmath>     //Math Library
#include <sstream>   //Stream Library
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
int fists();
int combat(int&,int&,int,int&,int,int,int,int,int,int,bool&,bool&);
int hlthpot(int&,int&,int&);
bool guesNum(int&,float&,int,int,int&);//Guess the number
void scorSrt(int[],string[],int);//Sorting High Scores


//Execution begins here
int main(int argc, char** argv) {
    //Setting the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare and Initialize variables
    char action=0;
        //Character Ability Scores
        const int str=10,//Strength
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
        int maxhlth=20;//Character's Health
        int health=maxhlth;//Character's current health
        int gold=50;//Starting gold
        int armor=16;//Character's Armor Class
        string name;//Character's name
        string helper;//Name of contracted help

        //Environmental Features
        bool helped=false;
        int beers=0;//Beers drank
        int potions=3;//Health potions in inventory
        float table=500;//Available gold in the Inn
        int ring=1;//Limits the occurrence of the ring theft
        bool victory=true;//Condition set by combat resolution
        int wager=0;
        bool fight=false;//Prevents player from returning to the gambling table 
                         //After fighting.
        //I/O Files
        string instrng="";
    cout<<"/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*"
                        "*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/"
                        "*/*/*/*/*/"<<endl;
    cout<<endl;    
    //Intro
    ifstream intro;  
    intro.open("intro.txt");    
    while(!intro.eof())
        {
        getline(intro, instrng);
        cout<<instrng<<endl;
        }
        intro.close();   
        cout<<endl;
    cout<<"/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*"
            "*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/"
            "*/*/*/*/*/"<<endl;
    cout<<endl;
    cout<<setw(100)<<"What name will you be going by this evening?"<<endl;
    getline(cin,name);
    cout<<setw(100)<<"Okay '"+name+"' and what is the name of your friend here?"<<endl;
    getline(cin,helper);
    cout<<setw(100)<<"Great well then Masters "+name+" and "+helper+" I will"<<endl;
    cout<<setw(100)<<"set your things in your room upstairs."<<endl;
    cout<<setw(100)<<"Please make yourselves at home in our humble common room"<<endl; 
    cout<<endl;
    cout<<"/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*"
                        "*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/"
                        "*/*/*/*/*/"<<endl;
    cout<<endl;
    //Begin Play
            ifstream cmnroom;  
            cmnroom.open("cmnroom.txt");
            while(!cmnroom.eof())
                {
                getline(cmnroom,instrng);
                cout <<instrng<<endl;
                }
                cmnroom.close(); 
                cout<<endl;
                cout<<"/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*"
                        "*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/"
                        "*/*/*/*/*/"<<endl;
    cout<<endl;
    
            do{
               cout<<"|Health : "<<health<<"|Gold : "<<gold;
               cout<<"|Potions : "<<potions<<endl;
               cout<<setw(100)<<"What would you like to do?"<<endl; 
               cout<<setw(100)<<"Look for a game for gambling, though what"
                       " you do could hardly be called gambling. - PRESS 1"<<endl;
               cout<<setw(100)<<"Step up to the bar and buy a drink. - Press 2";
                       cout<<endl;
               cout<<setw(100)<<"Call it a night. - Press 3";
                       cout<<endl;
                       cout<<"Your choice of ACTION : ";
               cin>>action;
               while(action>'3'||action<'1'){
                   cout<<"Try again."<<endl;
                   cout<<"Your choice of ACTION : ";
                   cin>>action;                   
               }
               cout<<"/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*"
                        "*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/"
                        "*/*/*/*/*/"<<endl;
               cout<<endl;
               switch(action){
                   case '1':{//Gambling                         
                       if(fight==true){
                           cout<<"There is no one gambling, the fight made "
                                   "everyone move on to new things for the evening."
                                   <<endl;
                           table=0;
                       }                       
                       if (table<=0&&fight==false){//Prevents taking money from house that isn't there
                            cout<<setw(100)<<"There is no money at the table, "
                                    "haven't you done"
                                    " enough?"<<endl;
                       }
                       guesNum(gold,table,chamod,decptn,wager);
                       if (gold<0){//You are fighting the gambler (Health=20,mod=1,AC=14)
                           gold=abs(gold);//Return gold to positive if negative
                           gold--;//resets gold to true value.
                            combat(gold,health,maxhlth,potions,dexmod,armor,
                                    fweapon,20,1,14,victory,helped);
                            //Player's Gold, Current Health, Max Health, # of Potions,
                            //Combat Modifier, and Armor Class;
                            //Mob's Health, Combat Modifier, and Armor Class;
                            if (victory==false&&health>0){
                                cout<<"Running from a fight is not necessarily a bad decision but it"
                                        " will end your night at least you "<<endl;
                                cout<<"kept the gold on your person. You cannot go back into the in "
                                        "for the shame would be too much."<<endl;
                                cout<<"You eventually put together a workable disguise and return to"
                                        " the room you rented."<<endl;                               
                            }
                            else if (health<=0&&victory==false){
                                cout<<"You lost the fight and were thrown out "
                                        "of the inn"<<endl;
                                cout<<"You lost half of your money in the "
                                        "exchange."<<endl;
                                gold/=2;                                
                            }else {
                                cout<<"You defeated the suspicious gamblers. "
                                        "Collect what gold you can find on the"
                                        " ground and go about your business."<<endl;
                                cout<<"Fights over gambling are common and "
                                        "while everyone is a bit wary of you,"
                                        " no one is giving you trouble."<<endl;
                                int find=(wager*2-wager/d20(1));//Randomize gold recovered just the a DM would
                                gold+=find;
                                cout<<"You find "<<find<<" gold and now have "
                                        <<gold<<" total."<<endl;
                            }
                            if (helped==true){
                                gold-=10;
                                cout<<"You pay "+helper+" 10g."<<endl;
                            }
                            fight=true;
                            helped=false;    
                       }break;
                   }
                   case '2':{//Buy a drink                       
                       beers=0;
                       
                           if (ring<1){
                               cout<<"There is nothing of interest at the bar."<<endl;
                           }else{
                               cout<<"/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*"
                                        "*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/"
                                        "*/*/*/*/*/"<<endl;
                               cout<<endl;
                               ifstream loverboy;  
                               loverboy.open("loverboy.txt");
                               while(!loverboy.eof())
                                   {
                                   getline(loverboy,instrng);
                                   cout <<instrng<<endl;
                                   }
                                   loverboy.close();
                                   cout<<"/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*"
                                            "*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/"
                                            "*/*/*/*/*/"<<endl;
                                   cout<<endl;
                            do{
                                switch (beers){
                                    case 0:{
                                        cout<<setw(100)<<"Perhaps a nice cold ale"
                                                " will help calm his nerves."<<endl;break;
                                    }
                                    case 1:{
                                        cout<<"You buy a round for the two of you."<<endl;
                                        gold-=5;
                                        cout<<setw(100)<<"He seems to calm down and "
                                                "be more at ease."<<endl;break;
                                    }
                                    case 2:{
                                        cout<<"You buy another round."<<endl;
                                        gold-=5;
                                        cout<<setw(100)<<"Now he's getting tipsy but just "
                                                "a little goofy."<<endl;break;
                                    }
                                    case 3:{
                                        cout<<"How about another! "<<endl;
                                        cout<<setw(100)<<"'A tust' he shouts!"
                                                "'Tu th must butufl wemn IN th werld!'"<<endl;
                                        gold-=5;
                                        cout<<setw(100)<<"Okay, he's drunk now and starting"
                                                " to attract attention."<<endl;break;
                                    }
                                    case 4:{
                                        cout<<"One more couldn't hurt..."<<endl;
                                        gold-=5;
                                        cout<<setw(100)<<"Oh that did it! He passed out."
                                                " As he falls"<<endl;
                                        cout<<setw(100)<<"to the ground you pick him up and set him "
                                                "back on the bar."<<endl;
                                        cout<<setw(100)<<"Of course you also nicked the ring "
                                                "in the process, hopefully"<<endl;
                                        cout<<setw(100)<<"its worth the gold in beer you spent."<<endl;
                                        break;
                                    }
                                  default:
                                      cout<<"He's still passed out."<<endl;
                                }
                                cout<<"|Health : "<<health<<"|Gold : "<<gold;
                                cout<<"|Potions : "<<potions<<endl;
                               cout<<setw(100)<<"Would you like to buy a round of drinks for 5g?"
                                       " - PRESS 1"<<endl;
                               cout<<setw(100)<<"Attempt to swipe the ring? - PRESS 2"<<endl;
                               cout<<setw(100)<<"Or do you want to just walk away?"
                                       " - PRESS 3"<<endl;
                               cin>>action;
                               switch (action){
                                   case '1':{
                                       if (beers==4){
                                           cout<<setw(100)<<"The bartender looks at you scornfully and "
                                                   "declines to pour your friend another drink."
                                                   <<endl;
                                           beers++;
                                       }else{
                                           beers++;
                                       }
                                   }break;
                                   case '2':{
                                       if(ring<=0){
                                           cout<<"You already grabbed it, don't linger"<<endl; 
                                      }
                                       if(check(20-beers*2,dexmod,sltohnd)==true){
                                             ring--;
                                             int worth=(rand()%20+1)*5;
                                             cout<<"The ring was worth "<<worth<<" gold."<<endl;
                                             gold+=worth;
                                       }else{//Combat!!!You're fighting Lover-Boy (health=14,mod=0,ac=12)
                                           combat(gold,health,maxhlth,potions,dexmod,
                                                   armor,fweapon,14,0,12,victory,helped);
                                                //Player's Gold, Current Health, Max Health, # of Potions,
                                                //Combat Modifier, and Armor Class;
                                                //Mob's Health, Combat Modifier, and Armor Class;
                                           if (victory==false&&health>0){
                                                cout<<"Running from a fight is not necessarily a bad decision but it"
                                                        " will end your night at least you "<<endl;
                                                cout<<"kept the gold on your person. You cannot go back into the in "
                                                        "for the shame would be too much."<<endl;
                                                cout<<"You eventually put together a workable disguise and return to"
                                                        " the room you rented."<<endl; 
                                                ring--;
                                            }
                                            else if (health<=0&&victory==false){
                                                cout<<"You lost the fight and were thrown out of the inn"<<endl;
                                                cout<<"You lost half of your money in the exchange."<<endl;
                                                gold/=2; 
                                                ring--;
                                            }
                                            else {
                                                cout<<"You beat the kid up for catching you in the act "
                                                        "this is not what we would call a high moment for you."<<endl;;
                                                ring--;
                                                int worth=(rand()%20+1)*5;
                                                cout<<"The ring was worth "<<worth<<" gold."<<endl;
                                                gold+=worth;
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
                                       if (beers>=4){
                                           cout<<setw(100)<<"The smart thing to do now is remove "
                                                   "yourself from the situation"<<endl;
                                           cout<<setw(100)<<"and avoid further notice."<<endl;
                                           ring--;
                                           int worth=(rand()%20+1)*5;
                                             cout<<"The ring was worth "<<worth<<" gold."<<endl;
                                             gold+=worth;
                                       }else{
                                           cout<<"/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*"
                                                    "*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/"
                                                    "*/*/*/*/*/"<<endl;
                                           cout<<endl;
                                       ifstream proposal;  
                                        proposal.open("loverboy.txt");
                                        while(!proposal.eof())
                                            {
                                            getline(proposal,instrng);
                                            cout <<instrng<<endl;
                                            }
                                            proposal.close();
                                            cout<<"/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*"
                                                    "*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/"
                                                    "*/*/*/*/*/"<<endl;
                                            cout<<endl;
                                       ring--;
                                       }
                                   }break;
                               }
                           }while (ring>=1);
                       } 
                       
                   }break;
                   default:{                       
                       cout<<"After a long night you decide you've had you fill of the"
                               " inn."<<endl;
                       cout<<"You gather your things and head up stairs to"
                               " your room."<<endl;
                       victory=false;//Ends Game        
                   }
               }            
            }while(health>0&&victory==true);
cout<<"You have "<<gold<<" gold and your night in the inn is over."<<endl;
cout<<endl;
cout<<"/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*"
        "*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/"
        "*/*/*/*/*/"<<endl;
cout<<endl;
cout<<setw(50)<<"GAME OVER"<<endl;
ofstream scorBrd;
  scorBrd.open ("ScorBrd.txt",std::ios::app);
  scorBrd <<setw(20)<<name<<setw(20)<<gold<<endl;
  scorBrd.close();
  cout<<endl;
  
  //Sort and display leader board
  cout<<setw(51)<<"High Scores"<<endl;
  cout<<setw(33)<<"Name"<<setw(30)<<"Gold Total"<<endl;
ifstream showBrd; 
int SIZE=10;
string names[SIZE]={};
int scores[SIZE]={};
showBrd.open("ScorBrd.txt");

    
    for (int i=0;i<SIZE;i++){
        showBrd>>names[i];
        showBrd>>scores[i];
    }
    

    showBrd.close(); 
    //Sort and Display Leader Board
    scorSrt(scores,names,SIZE);
    for(int i=0;i<10;i++){
    cout<<setw(35)<<names[i];
    cout<<setw(25)<<scores[i]<<endl;
    }
    
    
       
   //Exit stage right!
    return 0;
} 

//Sorting High scores
void scorSrt(int a[],string b[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]<a[j]){
                int temp1=0;
                string temp2="";
                temp1=a[i];
                a[i]=a[j];
                a[j]=temp1;
                temp2=b[i];
                b[i]=b[j];
                b[j]=temp2;
                
            }
        }
    }
}
//Scenarios:

//Gambling Games
bool guesNum(int& gold,float& table,int chamod,int decptn,int& wager){
                //Character's Gold, Possible gold at the table
    char stay=1;
    int beer=0;
    int wins=0,losses=0;
    char num;
    char action='0';
    if(table<=0){
        cout<<setw(100)<<"..."<<endl;
    }else if (gold<=0){
        cout<<setw(100)<<"You can't gamble if you don't have anything to "
                "wager, move along."<<endl;
    }else{
        cout<<"/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*"
                        "*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/"
                        "*/*/*/*/*/"<<endl;
        cout<<endl;
        string instrng="";
        ifstream gambling;  
        gambling.open("gambling.txt");
        while(!gambling.eof())
            {
            getline(gambling,instrng);
            cout <<instrng<<endl;
            }
            gambling.close();
            cout<<endl;
        cout<<"/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*"
                    "*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/"
                    "*/*/*/*/*/"<<endl;
        cout<<endl;
        do{
            cout<<"|Table : "<<table<<"|Gold : "<<gold<<"|Beers : "<<beer<<" |Wins : "<<wins<<" |Losses : "
                    <<losses<<"|"<<endl;
            cout<<setw(100)<<"Would you like to buy a round for the table for  5g?"<<endl;
            cout<<setw(100)<<"Yes - PRESS 1"<<endl;
            cout<<setw(100)<<"No - PRESS 2"<<endl;
            cout<<"Buy Round? ";
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
            while(!(wager<=table)||!(wager<=gold)||!(wager>0)||(cin.fail())){
                cin.clear();//clears error thrown by cin.fail
                cin.ignore();//allows acceptance of next entry
                wager=0;
                cout<<setw(100)<<"That's not a real wager. "
                        "Try a different wager."<<endl;
                cout<<"Wager : ";
                cin>>wager;
            }
            /*while(wager>gold){
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
            }*/
            gold-=wager;//Player Ante
            table-=wager;//Table Ante
            cout<<setw(100)<<"Okay pal, now pick a number between 1-3 and lets"
                    " see if we can guess it"<<endl;
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
                float dfclty=((10-beer+wins-losses)*(1+wager/(table+1)));
                cout<<setw(98)<<"Check Difficulty is : "<<fixed;
                cout<<setprecision(0)<<dfclty<<endl;
                cout<<setw(100)<<"Lie - PRESS 1"<<endl;
                cout<<setw(100)<<"Tell Truth - PRESS 2"<<endl;
                cin>>action;
                if (action=='2'){
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
                    if (check(dfclty,chamod,decptn)==true){ 
                        cout<<"The gamblers are disappointed but they believe you."<<endl;
                        gold+=wager*2;
                        wins++;
                        cout<<"Now you have "<<gold<<" gold."<<endl;
                    }else{ //Combat!!!
                        cout<<setw(100)<<"As convincing as you typically are they don't "
                            "buy it. The biggest of the bunch"<<endl;
                        cout<<setw(100)<<"flips the table over and attacks you."<<endl;
                        gold++;//Prevents gold from being '0' which would 
                               //avoid combat
                        gold*=(-1);//Makes gold value negative so that combat
                                   //triggers.
                    }

                }

            }
            if (table<=0){
                cout<<setw(100)<<"'Well that's it for us!'"<<endl;
                cout<<setw(100)<<"There is no more gold to be won here,"
                        "time to move on."<<endl;
            }            
            if (gold>0&&table>0){
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
        int mobhlth,int cbtmod,int mobAC,bool& victory,bool& helped){
    //roll initiative
    
    char move='0';
    int pInitv=d20(1)+abltmod;//player initiative plus dexterity
    int mInitv=d20(1);//mob initiative (no dex bonus because inn mobs are unspecial
    if (pInitv>mInitv){//Player goes first
        do{
            //Player Move
            if(health>0){
                cout<<"COMBAT";
                cout<<"|Health : "<<health<<"|Gold : "<<gold;
                cout<<"|Potions : "<<potions<<"|Enemy's health : ";
                cout<<mobhlth<<endl;
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
                        victory=false;
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
                cout<<"|Health : "<<health<<"|Gold : "<<gold;
                cout<<"|Potions : "<<potions<<"|Enemy's health : ";
                cout<<mobhlth<<endl;
                cout<<setw(94)<<"Make a decision."<<endl;
                cout<<setw(100)<<"Attack with my sword - PRESS 1"<<endl;
                cout<<setw(100)<<"Attack with my dagger - PRESS 2"<<endl;
                cout<<setw(100)<<"Run away! - PRESS 3"<<endl;
                cout<<setw(100)<<"Signal to your helper for assistance - PRESS 4"<<endl;
                cout<<setw(100)<<"Use a health Potion - PRESS 5"<<endl;
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
                        victory=false;
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
            if (health<=0)victory=false;
        }while (health>0&&mobhlth>0&&victory==true);
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