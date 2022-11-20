#include<iostream>
#include "purchase.cpp"
using namespace std;
int Main_option();

int main(){
   
    Collections collection=Collections::createCollection();
    UserCart user_cart=UserCart::createUser();
    bool cont=true;
    while(cont){
        switch (Main_option())
        {

            case 0://EXIT
                    cont=false;
                    cout<<"\nexit";break;

            case 111:// MANAGE 
                    {       
                            int option=Design::manageArt();
                            switch(option){
                                        case 1:
                                                int x;
                                                cout<<"\n\tADD PRODUCT [ 1  ]\n\tEDIT PRODUCT[ 2 ]\n\n\t   YOUR OPTION : ";
                                                try{cin>>x;}catch(...){x=1;}
                                                switch (x)
                                                {
                                                case 1:
                                                        collection.AddThings();
                                                        break;
                                                case 2:
                                                        //EDIT PRODUCT
                                                       collection.EditProduct();
                                                        cin.ignore();
                                                        break;
                                                
                                                default:
                                                        cout<<"\n\t----- invalid input -------\n";
                                                        break;
                                                }
                                                
                                                break;
                                        case 2:
                                                collection.displayAll_Items(1);
                                                break;
                                        default:
                                            break;
                                        
                                        }
                            break;
                    }
                    
            default://PURCHASE
                            int option=Design::purchaseProduct();
                            switch(option){
                                        case 1://BUY PRODUCT
                                                
                                               
                                                //purchase item at "purchase.cpp"
                                                purchaseItem(collection,user_cart);
                                                    
                                                break;
                                        case 2:
                                                //DISPLAY CART
                                                 user_cart.printCart();
                                                 cin.ignore();
                                                break;
                                        case 3:
                                                //Making payment
                                                cout<<"\n\t       -------    Successfully purchased     ------\n";
                                                user_cart.resetUser();
                                                cin.ignore();
                                        default:
                                            break;
                                        
                                        }
                            break;
                break;
    
        }
    }


    
} 
int Main_option(){
    cin.clear();
    cout<<"=> Enter ........";
    cin.ignore();
    Design::superMarket();
    int option;
    cout<<"\n\n"<<setw(75)<<"PURCHASE [ 1 ] "<<"\t\tEXIT [ 0 ]\t\t"<<"MANAGE [ 111 ]"<<endl;
    cout<<"\n"<<setw(100)<<" YOUR OPTION : ";try{cin>>option;}catch(...){option=0;}
    return option;
}