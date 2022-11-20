#include<iomanip>
#include<iostream>
#define S(x) cout<<setw(x)
using namespace std;
class Design{
      public:
          static void superMarket(){
              system("cls");
              cout<<endl;
              S(130)<<"  ____  _   _ ____  _____ ____     __  __    _    ____  _  _______ _____ "<<endl;
              S(130)<<" / ___|| | | |  _ \\| ____|  _ \\   |  \\/  |  / \\  |  _ \\| |/ / ____|_   _|"<<endl;
              S(130)<<" \\___ \\| | | | |_) |  _| | |_) |  | |\\/| | / _ \\ | |_) | ' /|  _|   | |  "<<endl;
              S(130)<<"  ___) | |_| |  __/| |___|  _ <   | |  | |/ ___ \\|  _ <| . \\| |___  | |  "<<endl;
              S(130)<<" |____/ \\___/|_|   |_____|_| \\_\\  |_|  |_/_/   \\_\\_| \\_\\_|\\_\\_____| |_|  "<<endl;
          };
          static int manageArt(){
             cout<<"\n";
             S(50)<<"                          __   _ "<<endl;
             S(50)<<"   |\\/|   /\\   |\\ |   /\\   /__  |_ "<<endl;
             S(49)<<"  |  |  /--\\  | \\|  /--\\  \\_|  |_"<<endl;

             cout<<"\n\n";
             S(35)<<"______________________________ \n";
             S(35)<<"|                              |\n";
             S(35)<<"|   MANAGE  PRODUCT  -  [ 1 ]  |\n";
             S(35)<<"|  DISPLAY ALL PRODUCT -[ 2 ]  |\n";
             S(35)<<"______________________________ \n";

           try{ int x;
            S(30)<<"\n\nYOUR OPTION :  ";cin>>x;
            if(x==1||x==2)
                return x;
            else throw 1;
           }
           catch(...){
            return 2;
           }
          }
          static int purchaseProduct(){
            cout<<"\n";
            cout<<"  ___ _   _ ___  ___ _  _   _   ___ ___ \n";
            cout<<" | _ \\ | | | _ \\/ __| || | /_\\ / __| __|\n";
            cout<<" |  _/ |_| |   / (__| __ |/ _ \\__ \\ _| \n";
            cout<<" |_|  \\___/|_|_\\___|_||_/_/ \\_\\___/___|\n";
            cout<<"\n\n";
             S(35)<<"______________________________ \n";
             S(35)<<"|                              |\n";
             S(35)<<"|    BUY    PRODUCT  -  [ 1 ]  |\n";
             S(35)<<"|    DISPLAY  CART   -  [ 2 ]  |\n";
             S(35)<<" |    MAKE   PAYMENT  -  [ 3 ]  |\n";
             S(35)<<"______________________________ \n";
           
            try
            { 
                int x;
                S(30)<<"\n\nYOUR OPTION :  ";cin>>x;
                if(x>=1 && x<=3)
                    return x;
                else throw 1;
            }
           catch(...){
            return 0;
           }
          }
};
                                        