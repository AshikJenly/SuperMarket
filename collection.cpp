#include<iostream>
#include<fstream>
#include<vector>
#include "adminInfo.cpp"
#include "usercart.cpp"

#define SPACE cout<<"\t\t\t"
using namespace std;

class Collections{
    private:
         Thing thingTemp;
         vector<Thing>things;
         vector<Thing>::iterator itr;
         string fileName;
         static inline  Collections* collect;
         Admin admin=Admin::createAdmin();
         Collections(){
            fileName="ProductDetails.txt";
            this->ReadCollection();
        }
    public:
        static inline Collections createCollection();
        void ReadCollection();
        void EditProduct();
        void AddThings();
        void PrintThings();
        Thing * buyThing(int,UserCart&);
        void displayAll_Items(int);

        ~Collections();
};
Collections  Collections::createCollection(){
            if(!collect)
                    collect =new Collections();
            return *collect;    
}
Thing * Collections::buyThing(int id,UserCart &user_cart){
        for(itr=things.begin();itr!=things.end();itr++){
                    if((*itr).getId()==id){
                        if((*itr).getCount()!=0)
                            user_cart.addItem(*(itr.base()));
                            (*itr).buyThing();
                            return itr.base();

                    }
                    
            }
            return nullptr;
}
void Collections::AddThings(){
     
        if(admin.isAdmin()){  
                
                string option;
                add:{
                thingTemp.getThing();
                things.push_back(thingTemp);
                
                }
                cin.ignore();
                cout<<"\nAdd Product again ? y/n : ";getline(cin,option);
                
                if(option.compare("n"))
                goto add;    
       }
}
void Collections::ReadCollection(){
            
            ifstream infile(fileName);
            if(infile){
            string name;int price,count;int id;
            while(!infile.eof()){
                    infile>>name>>price>>count>>id;
                    thingTemp.updateThing(name,count,price,id);
                    //Append in Things
                    things.push_back(thingTemp);
                    
            }
            things.pop_back();
           infile.close();
            }
           
            system("del ProductDetails.txt");
}

Collections::~Collections(){
cout<<"\nCollection Terminated";
          ofstream outfile;
                    try
                    {
                        outfile.open(fileName,ios::app);
                        for(itr=things.begin();itr!=things.end();itr++)
                                {
                                    // cout<<"\n"<<(*itr).printThing()<<endl;
                                    //Appending things to File
                                    outfile<<(*itr).getName()<<endl;
                                    outfile<<(*itr).getPrice()<<endl;
                                    outfile<<(*itr).getCount()<<endl;
                                    outfile<<(*itr).getId()<<endl;
                                }
                        outfile.close();
                    }
                    catch(...){
                        cout<<"\nError in collection.cpp"<<endl;
                    }
}
void Collections::EditProduct(){
        system("cls");
        Thing *temp_thing=NULL;
        Design::superMarket();
        this->displayAll_Items(1);
        cout<<"\n\t<<<<--- EDIT PRODUCT ---->>>>\n";
        cout<<"\n   Enter product id : ";
        int x;
        try{
                cin>>x;
                if(!cin)
                    {cin.clear();throw 1;}
          }catch(...)
                    {x=0;}
        for(itr=things.begin();itr!=things.end();itr++){
                    if((*itr).getId()==x){
                            temp_thing=itr.base();
                    }            
            }
         if(temp_thing==NULL){
                cout<<"\n\t\t````````  INVALID PRODUCT    `````````\n";
         }
        else {
              cout<<"\n\t~ ~ ~ ~PRODUCT INFO ~ ~ ~ ~\n";
              cout<<"\n\tProduct Name : "<<temp_thing->getName();
              cout<<"\n\tOld Price    : "<<temp_thing->getPrice();
              cout<<"\n\tOld count    : "<<temp_thing->getCount();
              cout<<"\n\tEnter new Price : ";int p;try{cin>>p;}catch(...){p=0;}
              cout<<"\n\tEnter new Count : ";int c;try{cin>>c;}catch(...){c=0;}
              temp_thing->updateThing(temp_thing->getName(),c,p,temp_thing->getId());

        }

           
}

void Collections::displayAll_Items(int flag){
      cout<<endl;
     SPACE<<"\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
      SPACE<<"\t\t   <<<<<<<        <<<<        <<    P R O D U C T          L I S T    >>        >>>>          >>>>>>>  \n\n";
      int i=0;
      SPACE;
      for(itr=things.begin();itr!=things.end();itr++){

        if(!flag){  
             
             cout<<(*itr).getName()<<" [  ID : "<<(*itr).getId()<<" ]";SPACE;
             i++;
             if(i==4){
                cout<<"\n\n";
                SPACE;
                i=0;
                }
                }
        else{

               cout<<"\n\t\t\t\t\t\t"<<"[NAME  :  "<<(*itr).getName()<<"]  [ ID :  "<<(*itr).getId()<<"]  [ COUNT : "<<(*itr).getCount()<<"] [PRICE : "<<(*itr).getPrice()<<"]"<<endl;
                cout<<"\t\t\t\t\t\t   __________________________________________\n";
                }
      }
      
      cout<<endl;
      SPACE<<"\n\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
     cin.ignore();
}
