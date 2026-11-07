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

  Imprumut(RaftBAD& r, int z);
};

class RaftBAD
{
  int locuri;//locuri disponibile
  int ocupat;///locuri ocupate
public:
  RaftBAD(int n);
  
 
};

class RaftGOOD
{
  int ocupat;
  int locuri;
 
};
