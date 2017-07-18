/* 
 * File:   main.cpp
 * Author: Ryan Johnson
 * Created on July 12, 2017, 6:16 PM
 * Purpose: Compare Internet Packages to find the best match
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <iomanip>   //Format Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    float charge;//Monthly Bill
    float pkg1;//Cost with 5 hour package
    float pkg2;//Cost with 15 hour package
    float pkg3;//Cost with Unlimited Access
    int hrs;//Hours of Access this month
    int sub;//Current Subscription
    string scrip,nscrip;//Name of Subscription, New Subscription
    //Initialize variables
    pkg3=29.95;
    pkg2,pkg1=0;
    scrip=1;
            
    //Input data
    cout<<"This Program will calculate your ISP bill."<<endl;
    cout<<"First, which subscription package do you have?"<<endl;
    do{
        cout<<"Enter 1 if you have the Silver Package which is";
        cout<<" up to 5 hours of access for $16.75."<<endl;
        cout<<"Enter 2 if you have the Gold Package which is";
        cout<<" up to 15 hours of access for $23.75."<<endl;
        cout<<"Enter 3 if you have the Platinum Package which is unlimited ";
        cout<<"access for only $29.95 per month."<<endl;
        cin>>sub;
    }while (sub<1||sub>3);
    switch (sub){
        case 1: scrip="Silver";break;
        case 2: scrip="Gold";break;
        case 3: scrip="Platinum";break;
    }
    cout<<"You indicated you have a "<<scrip<<" Package Subscription"<<endl;
    cout<<"How many hours did you use this month? ";
    cin>>hrs;    
    //Map inputs to outputs or process the data
    switch (sub){
        case 1:{
            if (hrs<=5) {charge=16.75;}
            else if (hrs>5&&hrs<=20) {charge=16.75+.75*(hrs-5);}
            else {charge=16.75+.75*15+(hrs-20);}
            break;           
        }       
        case 2:{
            if (hrs<=15) charge=23.75;
            else if (hrs>15&&hrs<=25) charge=23.75+.55*(hrs-15);
            else charge=23.75+.55*10+(hrs-25)*.7;break;            
        }        
        default:charge=29.95;break;        
    }
    
    //Output the transformed data
    cout<<"Your monthly bill will be $";
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<charge<<endl;
    
    //Comparison
        //Package 1
        if (hrs<=5) pkg1=16.75;
        else if (hrs>5&&hrs<=20) pkg1=16.75+.75*(hrs-5);
        else pkg1=16.75+.75*15+(hrs-20);
        //Package 2
        if (hrs<=15) pkg2=23.75;
        else if (hrs>15&&hrs<=25) pkg2=23.75+.55*(hrs-15);
        else pkg2=23.75+.55*10+(hrs-25)*.7;    
        //Package 3
        pkg3=29.95;
    //Recommendation
        if ((pkg1<pkg2&&pkg1<pkg3)&&!(sub==1)){
            cout<<"Based on your usage your optimal package is "
                    "the Silver Package."<<endl; 
            nscrip="Silver";
            cout<<"Your savings by switching from ";
            cout<<scrip<<" to "<<nscrip<<" this month would be $";
            if (sub==2) {cout<<pkg2-pkg1<<endl;
            }else cout<<pkg3-pkg1<<endl;
        }
        
        else if ((pkg2<pkg1&&pkg2<pkg3)&&!(sub==2)){
            cout<<"Based on your usage your optimal package is "
                    "the Gold Package."<<endl;
            nscrip="Gold";
            cout<<"Your savings by switching from ";
            cout<<scrip<<" to "<<nscrip<<" this month would be $";
            if (sub==1) {cout<<pkg1-pkg2<<endl;
            }else cout<<pkg3-pkg2<<endl;
            
        }
        else if ((pkg3<pkg2&&pkg3<pkg1)&&!(sub==3)){
            cout<<"Based on your usage your optimal package is "
                    "the Platinum Package."<<endl;
            nscrip="Platinum";
            cout<<"Your savings by switching from ";
            cout<<scrip<<" to "<<nscrip<<" this month would be $";
            if (sub==1) {cout<<pkg1-pkg3<<endl;
            }else cout<<pkg2-pkg3<<endl;
        }        
        else cout<<"Your current package is your best option."<<endl;
              
    //Exit stage right!
    return 0;
}

