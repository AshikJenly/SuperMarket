#include<iostream>
#include<fstream>
#include<string>
#include "design.cpp"
using namespace std;

class Admin{
    private:
        string name;
        string password;
        static inline Admin *admin;
        string fileName;
        void getAdmin();
        void ReadAdmin();
        Admin(){
            fileName="adminInfo.txt";   
            this->ReadAdmin();
            
        }
    public:
        bool isAdmin();
        static inline Admin createAdmin(){
                if(admin==NULL)
                        admin =new Admin();
                return *admin;
        }
        
        
};
void Admin::getAdmin(){
            string s1,s2;
            cout<<"\n\t\t<<<<<<    ----------------    >>>>>>";
            cout<<"\n\t\t A D M I N     I N F O R M A T I O N ";
            cout<<"\n\tName : ";getline(cin,name);
                 pass:{
                    
                    cout<<"\n\tNew  Password : ";getline(cin,s1);
                    cout<<"\n\tConfirm Password : ";getline(cin,s2);
                     }
            if(!s1.compare(s2))
                    this->password=s1;
            else{
                     cout<<"\n\t<<<   Mismatched     >>>\n";
                     goto pass;
                 }
            //Write User info in the file 
            ofstream outfile;
            outfile.open(fileName);
            outfile<<name<<endl;
            outfile<<password;
            
        }
void Admin::ReadAdmin(){
        string name;
        string password;
        ifstream infile;
        try{
            infile.open(fileName);
            if(!infile)
                 throw 1;    
            infile>>name;infile>>password;
            infile.close();

        }
        catch(int e){
                cout<<"\n\n\t\t```````   Creating new Admin  ``````\n\a\a"<<endl;
                this->getAdmin();
                return;
        }
        catch(...){
              cout<<"Error in adminInfo.cpp"<<endl;
              this->getAdmin();
              return;
        }
        this->name=name;
        this->password=password;

}
bool Admin::isAdmin(){
        string temp;
        cout<<"\n\t\t<<<<<<    ----------------    >>>>>>";
        cout<<"\n\t\t A D M I N    I N F O R M A T I O N \n";
        cout<<"\tADMIN : "<<name<<endl;
        cin.ignore();
        cout<<"\tEnter password : ";getline(cin,temp);
        Design::superMarket();
        if(temp.compare(password)){
                cout<<"\n<<<<    ACCESS DENIED    >>>>\n";
                 return false;
                }
        return true;
}