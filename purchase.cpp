#include<iostream>
#include "collection.cpp"
using namespace std;

void purchaseItem(Collections &collection,UserCart &user){
         
        int id;char ch;Thing *temp_thing;

        do{
                system("cls");
                Design::superMarket();
                collection.displayAll_Items(0);
                cout<<"\n\t\t------- PURCHASE PRODUCT --------\n\n";
                cout<<"\n\t\tEnter Product ID  : ";
                 cin>>id;
                 if(!cin){
                        cout<<"\nInvalid Input";
                        cin.clear();
                        id=0;

                 }
                temp_thing=collection.buyThing(id,user);
                if(temp_thing==NULL)
                        cout<<"\n\t\t````````  INVALID PRODUCT    `````````\n";
                else if(temp_thing->getCount()==0)
                        {cout<<"\n\t\t````````` PRODUCT UNAVAILABLE `````````\n";
                        temp_thing->printThing();
                        }
                else
                {
                        cout<<"\n\t\t <<<< ---- SUCCESSFULLY PURCHASED ----  >>>>\n";
                        cout<<"\n\t----- PRODUCT DETAILS  -----\n";
                        cout<<temp_thing->printThing()<<endl;
                        cout<<"\t\t TOTAL PRICE => $"<<user.getTotalCartPrice()<<"-/-"<<endl;
                        
                  }
                cout<<"\n\n\tBUY AGAIN ?  y/n  : ";
                try{cin>>ch;}catch(...){ch='n';}


          }while(ch!='n');

      
     }