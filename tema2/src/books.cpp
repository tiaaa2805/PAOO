#include "books.hpp"
  ///aici are loc initializarea, in format de lista de initializare
BooksGOOD:: BooksGOOD(string& name, string &id): nrpages_(0), price_(0.0), name_(name), id_(id) {}

BooksBAD::BooksBAD ( string &name, string & id)
    {
      name_=name;
      id_=id;  ///nrpages si price nu sunt initializate, iar aici au loc 2 actiuni
    }

RaftBAD::  RaftBAD( int ocupat_): ocupat(ocupat_), locuri(ocupat+7), titluri(new std::string[locuri]) {}  ///ordinea este gresita
//nu facem nici copiere si nici destructor, le face compilatorul
RaftGOOD::  RaftGOOD(int ocupat_): ocupat(ocupat_), locuri(ocupat +7) titluri(new std::string[ocupat_]){}


RaftGOOD:: RaftGOOD(const RaftGOOD & alt) : ocupat(alt.ocupat), locuri(alt.locuri), titluri(new std::string[alta.locuri])
{
  for(int i=0; i<alt.ocupat; i++)
    titluri[i]=alta.titluri[i];
}


//Atribuirea, formarea unui noi raft de carti
RaftGOOD& RaftGOOD::operator=(const RaftGOOD & alt)
{
  if(this != &alt)/// sa nu vori=bim despre aceeasi adresa
    {
      delete[] titluri; //curatam memoria veche alocata, daca nu am face asta si am aloca peste, am avea scuregri de memorie
      ocupat_=alt.ocupat_;
      locuri_=alt.locuri_;
      titlurile=new std::string[locuri_];
      for(int i=0; i<ocupat_; i++)
	titluri[i]=alt.titluri[i];
    }
  return *this;
}


RaftGOOD:: ~RaftGOOD(){
  delete[] titluri;
}

Imprumut:: Imprumut(RaftBAD &r, int z): raft(r), zile(z){}
