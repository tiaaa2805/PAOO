#include "books.hpp"
#include <iostream>


int main()
{
  std::cout<<"-----------Item 4----------"<<std::endl;
  std::cout<<"Varianta gresita item 4\n"<<std::endl;
  BooksBAD bB("Ion", "7fvbsj8752");
  std::cout<<" numar pagini "<<bB.getNRPages()<<" pret sau este "<<bB.getPrice()<<std::endl;

  std::cout<<"Varianta Buna item 4\n"<< std::endl;
  BooksGOOD bG("Mara", "jfurrrjen87");
  std::cout<<" numarul de pagini este "<< bG.getNRPages()<< " pretul este "<< bG.getPrice()<<std::endl;


  std::cout<<" Ordinea pe rafturi item4"<<std::endl;
  RaftBAD rB(5);//aici locuri o sa aiba o valoare aleatoare
  RaftGOOD rG(5);
  std::cout<<" Raftul rau: "<< rB.getLocuri()<<std::endl;
  std::cout<<" Raftul bun: "<<rG.getLocuri()<<std::endl;


  std::cout<<"---------------Item 5------------"<<std::endl;
  std::cout<<" Incercam functiile generate de compilator "<<std::endl;
  RaftBAD a(8);
  a.setTitlurile(0,"Ion");
  RaftBAD b=a; //copierea facuta de compilator
  std::cout<<" A.titluri ="<<a.getTitlurile()<<std::endl;
  std::cout<<" B.titluri="<<b.getTitlurile()<<std::endl;
  //aici vom avea aceeasi adresa
  b.setTitlurile(0,"Enigma Otiliei");
  std::cout<<" S-au modificat ambele, prin urmare a.titlurile "<<a.getTitlu(0)<<std::endl;

  std::cout<<"Acum varianta buna "<<std::endl;
  RaftGOOD c(2);
  c.setTitlurile(0,"Ion");
  RaftGOOD d=c;///se apeleaza constructorul nostru de copiere
    std::cout<<" C.titluri ="<<c.getTitlurile()<<std::endl;
  std::cout<<" D.titluri="<<d.getTitlurile()<<std::endl;
  d.setTitlurile(0, "Enigma Otiliei ");
  std::cout<< "Am schimbat d, deci c[0] are tot cartea Ion"<<c.getTitlu(0)<<std::endl;

  
  RaftGOOD e(2);
  e=c;
  //folosim functia noastra de atribuire
  std::cout<<" e[0] a preluat de la c "<<e.getTitlu(0)<<" iar adresa este "<< e.getTitlurile()<< std::endl;
  std::cout<<"----------------------Item6---------------"<<std::endl;
  std::cout<<"Varianta gresita "<<std::endl;
  //acolada ca sa vedem cand se apeleaza destructorii
  {
    ManuscrisBAD m1("Luceafarul - original ");
    ManuscrisBAD m2(m1); //shallow copy
    ManuscrisBAD m3("Alt manuscris");
    m3=m1;// operator= generat de compilator
    std::cout<<"m2="<<m2.getTitlu()<<" al doilea original"<<std::endl;
    std::cout<<"m3="<<m2.getTitlu()<<" al treilea original"<<std::endl;
    std::cout<<"In acest caz, manuscrisul este distrus de 3 ori"<<std::endl;
    
  }

  std::cout<<"Varianta corecta "<<std::endl;
  ManuscrisGOOD m1("Moara cu noroc");
  std::cout<<"m1="<<m1.getTitlu()<<std::endl;
  //ManuscrisGOOD m2(m1);  // Eroare fiindca folosim deleted function
  //m1=m1 // again.folosim deleted function


  int cartiBAD=bibliotecaGlobala.getNrCarti();  ///poate rula inainte de constructor ->0

  int cartiGOOD=biblioteca().getNrCarti();
  ///mereu 100

  std::cout<<" Obiecte globale din fisiere diferite "<<std::endl;
  std::cout<< " Gresit: cartiBad ="<<cartiBAD<<" nu este 100"<<std::endl;
  std::cout<< "Corect: cartiGOOD ="<< cartiGOOD<< std::endl;
  return 0;
}
