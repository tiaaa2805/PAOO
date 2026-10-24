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
    cont2.set(98.0);
    std::cout<<"Cont ="<<cont.get()<<" al doilea cont" <<cont2.get()<<std::endl;
  }
  std::cout<<"3.Move constructor"<<std::endl;
    {
      Cont cont(23456.9);
      Cont cont2=std::move(cont);
      std::cout<<"cont= "<<cont2.get()<<std::endl;
      std::cout<<"Contul este gol?"<<(cont.isEmpty()? "da":"nu")<<std::endl;
    }
  return 0;
}
