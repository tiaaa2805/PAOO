#include<iostream>
#include "cont.hpp"
#include<utility>

int main()
{
  std::cout <<" 1. Constructor si destructor"<<std::endl;
  {
    Cont cont(2346.7);
  }

  std::cout<<"2.Copy constructor"<<std::endl;
  {
    Cont cont(3000.9);
    Cont cont2=cont;
    std::cout<<"adresa cont1: "<<cont.adresa()<<std::endl;
    std::cout<<"adresa cont2 "<<cont2.adresa()<<std::endl;
    cont2.set(98.0);
    std::cout<<"Cont ="<<cont.get()<<" cu adresa "<< cont.adresa()<<" al doilea cont" <<cont2.get()<<" cu adresa "<<cont2.adresa()<<std::endl;
  }
  std::cout<<"3.Move constructor"<<std::endl;
    {
      Cont cont(23456.9);
      double *adre=cont.adresa();
      std::cout<<"Adresa de inceput "<<adre<<std::endl;
      Cont cont2=std::move(cont);
      std::cout<<"Adresa cont2 dupa move "<<cont2.adresa()<< " in comparatie cu adresa precedenta "<<adre<<std::endl;
      std::cout<<"cont= "<<cont2.get()<<std::endl;
      std::cout<<"Contul este gol?"<<(cont.isEmpty()? "da":"nu")<<std::endl;
    }

  return 0;
}
