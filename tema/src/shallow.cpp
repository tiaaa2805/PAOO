#include "cont.hpp"
#include<iostream>

int main()
{
    std::cout<<" Demonstratie Copy constructor folosind ShallowConstructor"<<std::endl;
    {
      ContShallow a(9,1, 9930.9);
      ContShallow b=a;

      std::cout<<"a= "<<a.adresa()<<std::endl;
      std::cout<<"b= "<<b.adresa()<<std::endl;
      a.tranzactia(88.9);
      b.tranzactia(488.3);
      std::cout<<"b= "<<b.sold()<<" iar a= "<<a.sold()<<std::endl;
      std::cout<<"Tranzactia lui b (488.3) a suprascris-o pe a lui a (88.9), tabloul este comun"<<std::endl;
      std::cout<<"In acest caz, avem aceeasi adresa"<<std::endl;
      a.afiseaza();
      b.afiseaza();
      std::cout<<"\nLa final se face double delete fiindca vorbim despre aceeasi adresa"<<std::endl;
    }
  return 0;
}
