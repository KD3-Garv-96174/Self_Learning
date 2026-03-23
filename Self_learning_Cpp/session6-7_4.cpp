#include<iostream>
using namespace std;

class Laptop{
   private:
   int brandId;
   double price;

   public:
   Laptop(){
    this->brandId = 1;
    this->price = 50000;
    cout<<"Laptop Constructor Called"<<endl;
   }
   ~Laptop(){
    cout<<"Laptop destructor Called"<<endl;
   }
   void displayLaptopDeatils(){
     cout<<"laptop detail : \nbrandId : "<<this->brandId<<"\nprice : "<<this->price<<endl;
   }
};
int main(){
    Laptop l;
    l.displayLaptopDeatils();

}