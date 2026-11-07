#ifndef BOOKS_HPP
#define BOOKS_HPP
#include<string>
class BooksGOOD{
private:
  int nrpages_;
  std::string name_, id_;
  double price_;

public:
  BooksGOOD(const std::string& name_, const std::string& id_);
  BooksGOOD(const BooksGOOD* alta);
  
  int getNRPages() const {return nrpages_;}
  double getPrice() const {return price_;}
 };

  class BooksBAD{
private:
  int nrpages_;
  std::string name_, id_;
  double price_;
  public:
    BooksBAD(const std::string& name_, const std::string& id_);
     //compilatorul genereaza copiere, copiaza doar adresa
      int getNRPages()const {return nrpages_;};
  double getPrice() const {return price_;}; 

  };


//aici nu folosim regula celor 3, compilatorul genereaza singur copierea si copiaza doar adresa
class RaftBAD
{
private:
  int locuri;//locuri disponibile
  int ocupat;///locuri ocupate
   std::string *titluri;
public:
  RaftBAD(int n);
  const std::string* getTitlurile() const {return titluri;}
  std::string getTitlu(int i) {return titluri[i];}
  void setTitlurile(int i, const std::string& titlu) {titluri[i]=titlu;}
  int getLocuri()const {return locuri;}
  int getOcupat() const {return ocupat;}
};

class RaftGOOD
{
private:
  int ocupat;
  int locuri;
   std::string* titluri;
public:
  RaftGOOD(int n);
  RaftGOOD(const RaftGOOD & alta); ///constructor de copiere
  RaftGOOD & operator=(const RaftGOOD& alta); ///operator de atribuire
  ~RaftGOOD();
const std::string* getTitlurile() const {return titluri;}
std::string getTitlu(int i) const{return titluri[i];}
 void setTitlurile(int i, const std::string& titlu) {titluri[i]=titlu;}
  int getLocuri() const{return locuri;}
  int getOcupat() const {return ocupat;}
};

///operator+ sters: referinta+const
class Imprumut{
public:
  RaftBAD& raft;
  const int zile;
  int getZile() const {return zile;}
  Imprumut(RaftBAD& r, int z);
};

#endif
