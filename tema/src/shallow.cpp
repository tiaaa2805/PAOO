#include "cont.hpp"
#include<iostream>

int main()
{
    std::cout<<" Demonstratie Copy constructor folosind ShallowConstructor"<<std::endl;
    {
      ContShallow a(30.9);
      ContShallow b=a;

      std::cout<<"a="<<a.adresa()<<std::endl;
      std::cout<<"b= "<<b.adresa()<<std::endl;

      b.set(88.3);
      std::cout<<"b este egal cu 88.3, iar a "<<a.get()<<std::endl;
      std::cout<<"In acest caz, avem aceeasi adresa"<<std::endl;
    }
  return 0;
}
