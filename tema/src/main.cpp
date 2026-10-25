#include<iostream>
#include "cont.hpp"
#include<utility>

int main()
{
  std::cout <<"1. Constructor si destructor"<<std::endl;
  {
    Cont cont(1, 2346.7, 8);
    cont.tranzactia(500.0);//retragere
    cont.tranzactia(-200.0);//depunere
    cont.afiseaza();
    
  }

  std::cout<<"2. Copy constructor, cu tabloul propriu"<<std::endl;
  {
    Cont cont(2,3000.9,5);
    cont.tranzactia(45.7);
    Cont cont2=cont;
    std::cout<<"adresa cont1: "<<cont.adresa()<<std::endl;
    std::cout<<"adresa cont2: "<<cont2.adresa()<<std::endl;
    cont2.tranzactia(888.8);
    cont.afiseaza();
    cont2.afiseaza();
   
  }
  std::cout<<"3. Move constructor"<<std::endl;
    {
      Cont cont(3,23456.9,3);
      cont.tranzactia(34.9);
      double *adre=cont.adresa();
      std::cout<<"Adresa de inceput "<<adre<<std::endl;
      Cont cont2=std::move(cont);
      std::cout<<"Adresa cont2 dupa move "<<cont2.adresa()<< " in comparatie cu adresa precedenta "<<adre<<std::endl;
      std::cout<<"cont= "<<cont2.sold()<<std::endl;
      std::cout<<"Contul este gol? "<<(cont.isEmpty()? "da":"nu")<<std::endl;
    }

  return 0;
}
