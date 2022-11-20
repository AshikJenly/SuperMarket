#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;
// int lastId;
class Thing{
    private:
        string name;
        int count;
        int price;
        int id;
        inline static int lastId;
        string fileName;
        // ifstream infile;
        // ofstream outfile;
    public:
        Thing();
        void buyThing();
        string printThing();
        void getThing();
        string getName(){return name;}
        int getCount(){return count;}
        int getPrice(){return price;}
        int getId(){return id;}
        void updateThing(string name,int count,int price,int id);
};
void Thing::buyThing(){
    if(count>0)
        count--;
    else    
        count=0;
}
Thing::Thing(){
        fileName="lastIdFile.txt";
         ifstream infile;
        infile.open(fileName);
        infile>>lastId;
        infile.close();

        }
string Thing::printThing(){
            string s1;
            s1="\tName : ";s1.append(name);
            s1.append("\n\tPrice : ");s1.append(to_string(price));
            s1.append("\n\tAvailable : ");s1.append(to_string(count));
            s1.append("\n\tProduct Id : ");s1.append(to_string(id));
            return s1;
        }
void Thing::getThing(){
            string name;

           int count,price;
            cout<<"\nEnter Item Details"<<endl;
            cout<<"\nName : ";getline(cin,name);
            cout<<"\nPrice : ";try{cin>>price;}catch(...){price=1000;}
            cout<<"\nInitial count : ";cin>>count;
            id=++lastId;
             ofstream outfile;
            outfile.open(fileName,ios::trunc);
            outfile<<lastId;
            this->updateThing(name,count,price,id);
}

void Thing::updateThing(string name,int count,int price,int id){
            this->name=name;
            this->count=count;
            this->price=price;
            this->id=id;
}


