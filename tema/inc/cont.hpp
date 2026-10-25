#ifndef CONT_HPP
#define CONT_HPP

///Cont cu tranzactii, id, sold, iar nrtranzactii este folosit drept numarator, iar nr este valoarea amxiam
class Cont{
private: double* tranzactii_;
 const  int id_;
  double sold_;
  int nr_;
  int nrtranzactii_;

public :
  Cont(int id, double sold, int nr);  //constructor
  ~Cont();  //destructor
  Cont(const Cont& first); ///copy constructor:deep constructor
  Cont(Cont&& other) noexcept; //move constructor
  int id() const;
  int dimensiune() const;
  double get(int i);
  double sold();
  void set( double valoare, int i);
  bool isEmpty();
  double * adresa() const;
  void afiseaza();
  bool tranzactia(double suma) ;
};


///demonstratie Copy Constructor, daca nu il avem se va pointa catre acelasi double, vom avea Shallow Copy, adica copie implicta copiaza pointerul
class ContShallow{
private: double* tranzactii_;
  const int id_;
  double sold_;
  int nrtranzactii_;
  int nr_;
public:
  ContShallow(int nr, int id, double sold);
  ~ContShallow();
  //fara Copy constructor
  double get(int i) const;
  double sold();
  double* adresa() const;
   bool tranzactia(double suma) ;
  void afiseaza();
};

#endif
