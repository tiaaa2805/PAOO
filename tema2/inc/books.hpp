#ifndef BOOKS_HPP
#define BOOKS_HPP

class BooksGOOD{
private:
  int nrpages_;
  std::string name_, id_;
  double price_;

public:
  BooksGOOD(nrpages_, price_);
  BooksGOOD(const BooksGOOD* alta);
  RaftGOOD& operator=(RaftGOOD &alta);
  ~RaftGOOD();
  int getNRPages();
  double getPages();
 };

  class BooksBAD{
private:
  int nrpages_;
    std::string name_, id_;
  double price_;
  public:
    BooksBAD(int nrpages, double price)
     //compilatorul genereaza copiere, copiaza doar adresa
      int getNRPages()const {return nrpages_;};
  double getPages() const {return price_;}; 

  };
///operator+ sters: referinta+const
class Imprumut{
public:
  RaftBAD& raft;
  const int zile;
  const int getZile() const {return zile;}
  Imprumut(RaftBAD& r, int z);
};


//aici nu folosim regula celor 3, compilatorul genereaza singur copierea si copiaza doar adresa
class RaftBAD
{
 
  int locuri;//locuri disponibile
  int ocupat;///locuri ocupate
   std::string *titlurile;
public:
  RaftBAD(int n);
  const std::string* getTitlurile() const {return titlurile;}
  std::string getTitlu(int i) {return titlurile[i];}
  void setTitlurile(int i, std::string& titlu) {titlurile[i]=titlu;}
};

class RaftGOOD
{
 
  int ocupat;
  int locuri;
   std::string* titluri;
  RaftGOOD(int n);
  RaftGOOD(const RaftGOOD & alta); ///constructor de copiere
  RaftGOOD & operator=(const RaftGOOD& alta);) ///operator de atribuire
  ~RaftGOOD();

const std::string* getTitlurile() const {return titlurile;}
std::string getTitlu(int i) const{return titlurile[i];}
 void setTitlurile(int i, std::string& titlu) {titlurile[i]=titlu;}
};

