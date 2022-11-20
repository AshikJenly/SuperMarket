#include<iostream>
#include<list>
#include<iomanip>
#include "things.cpp"
using namespace std;

class UserCart{
    private:
          long int total;
          list<Thing> cartList;
          list<Thing>::iterator itr;
    
           UserCart();
          static inline UserCart* user;
          

    public:
          static inline UserCart createUser();
          void addItem(Thing);
          void printCart();
          void resetUser();
          long int getTotalCartPrice(){return total;}
          ~UserCart(){cout<<"\nUser Cart Terminated";}
    
};
UserCart::UserCart(){
    user=nullptr;
    total=0;
    }
void UserCart::addItem(Thing t1){
   
    total +=t1.getPrice();
    cartList.push_back(t1);

}
UserCart UserCart::createUser(){
    if(user==nullptr)
        user =new UserCart();
    return *user;

}
void UserCart::printCart(){
  cout<<endl;
  cout<<"\t-----------   C A R T    ------------\n";
  for(itr=cartList.begin();itr!=cartList.end();itr++){
               
              cout<<"\n\t  "<<(*itr).getName()<<" [ ID : "<<(*itr).getId()<<" ]  [ $"<<(*itr).getPrice()<<" ] "<<endl;

  }
  cout<<"\t_ _ _ _ _  _ _ _ _ _ _ _ _ _ _ _ _ _ \n";
  cout<<"\t                 TOTAL AMOUNT :  $"<<total<<" \n";
  cout<<"\t-----------------------------------\n\n";

  

}
void UserCart::resetUser(){
    total=0;
    cartList.clear();
}

