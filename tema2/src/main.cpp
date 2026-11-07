#include "books.hpp"
#include <iostream>


int main()
{
  std::cout<<"Varianta gresita item 4\n"<<std::endl;
  BooksBAD bB("Ion", "7fvbsj8752");
  std::cout<<" numar pagini "<<bB.nrpages<<" pret sau este "<<bB.price<<std::endl;

  std::cout<<"Varianta Buna item 4\n"<< std::endl;
  BooksGOOD bG("Mara", "jfurrrjen87");
  std::cout<<" nuumarul de pagini este "<<< bG.nrpagess<< " pretul este "<< bG.price<<std::endl;


  std::cout<<" Ordinea oe rafturi item4"<<std::endl;
  RaftBAD rB(5);
  RaftGOOD rG(5);
  std::cout<<" Raftul rau: "<< rB.total<<std::endl;
  std::cout<<" Raftul bun: "<<rG.total<<std::endl;
  return 0;
}
