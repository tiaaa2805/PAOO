#include<iostream>
#include "cont.hpp"

///Constructor, initializam toti membrii, tranzactiile se aloca pe heap
Cont:: Cont(int id, double sold, int nr):
  tranzactii_(new double[nr]()), id_(id), sold_(sold), nr_(nr), nrtranzactii_(0)
{
  std::cout<<"Contul are id: "<<id_<< " soldul este "<<sold_<<std::endl;
}
//Destructorul este : eliberarea tabloului de pe heap, folosim tot []
Cont::~Cont()
{
  std::cout<<"Stergem acum contul cu id ul " << id_<<" cu "<<nr_<<" tranzactii, la adresa "<<tranzactii_<<std::endl;
  delete[] tranzactii_;
  
}


///Copy constructor - Deep constructor , se copiaza element cu element
Cont::Cont(const Cont& first) : tranzactii_(new double[first.nr_]), id_(first.id_), sold_(first.sold_), nr_(first.nr_), nrtranzactii_(first.nrtranzactii_)
{
  for(int i=0;i<nr_; i++)
    tranzactii_[i]=first.tranzactii_[i];
  std::cout<<"Al doilea cont a fost creat, cu id ul "<<id_<<" toate la adresa "<<tranzactii_ <<std::endl;
  
}

//Move constructor preia pointerul si dimensiunea, fara alocare noua. Sursa ramane goala, ca destructorul ei sa nu stearga tabloul
Cont::Cont(Cont&& first) noexcept : tranzactii_(first.tranzactii_), id_(first.id_), sold_(first.sold_), nr_(first.nr_), nrtranzactii_(first.nrtranzactii_)
{
  first.tranzactii_=nullptr;
  first.sold_=0;
  first.nr_=0;
  first.nrtranzactii_=0;
  std::cout<<"Move constructor: id: "<<id_<<" de la adresa "<<tranzactii_<<std::endl;
}

///Trecerea tranzactiei in istoric si actualizare sold

bool Cont:: tranzactia(double suma)
{
  if(tranzactii_==nullptr || nrtranzactii_==nr_)
    {
      std::cout<<"Cont indisponibil"<<std::endl;
      return false;
    }
  if(sold_-suma<0){
    std::cout<<"Fonduri insuficiente"<<std::endl;
    return false;
  }
  tranzactii_[nrtranzactii_]=suma;
  nrtranzactii_++;
  sold_-=suma;
  return true;
}
int Cont:: id()const {return id_;}
int Cont:: dimensiune()const {return nr_;}
double Cont::get(int i) {return tranzactii_[i];}
void Cont::set(double income, int i){tranzactii_[i]=income;}
bool Cont:: isEmpty() {return tranzactii_==nullptr;};
double* Cont:: adresa()const {return tranzactii_;}
double Cont:: sold() {return sold_;}
void Cont:: afiseaza()
{
  std::cout<< "Cont: "<<id_<<" soldul: "<<sold_<< " Tranzactii la adresa "<<tranzactii_<< " cu un nr de "<< nrtranzactii_<<" de tranzactii"<<std::endl;
  for(int i=0; i<nrtranzactii_; i++)
    std::cout<< tranzactii_[i]<<" "<<std::endl;
}

/// Varianta Shallow 
ContShallow:: ContShallow(int nr, int id, double sold) : tranzactii_(new double[nr]()), id_(id), sold_(sold), nrtranzactii_(0), nr_(nr){
  
  std::cout<<" Constructor not-good la adresa "<<tranzactii_<<std::endl;
}

ContShallow:: ~ContShallow(){
  std::cout<<"Delete la adresa "<< tranzactii_<<std::endl;
  delete[] tranzactii_;
}

bool ContShallow::tranzactia(double suma)
{
  if(tranzactii_==nullptr || nrtranzactii_==nr_ || sold_-suma<0)
    {
      return false;
    }
  tranzactii_[nrtranzactii_]=suma;
  nrtranzactii_++;
  sold_-=suma;
  return true;
}
double* ContShallow::adresa() const {
  return tranzactii_;
}

double ContShallow:: get(int i) const {
  return tranzactii_[i];
}
 void ContShallow:: afiseaza()
{
  std::cout<< "Cont: "<<id_<<" soldul: "<<sold_<< " Tranzactii la adresa "<<tranzactii_<< " cu un nr de "<< nrtranzactii_<<" de tranzactii"<<std::endl;
  for(int i=0; i<nrtranzactii_; i++)
    std::cout<< tranzactii_[i]<<" "<<std::endl;
}

double ContShallow:: sold()
{
  return sold_;
}
