#ifndef CONT_HPP
#define CONT_HPP

class Cont{
private: double* income_;

public :
  Cont(double income);
  ~Cont();
  Cont(const Cont& income);
  Cont(Cont&& other) noexcept;
  double get();
  void set(double income);
  bool isEmpty();
  double * adresa() const;
};


///demonstratie Copy Constructor, daca nu il avem se va pointa catre acelasi double, vom avea Shallow Copy.
class ContShallow{
private: double* income_;
public:
  ContShallow(double income);
  ~ContShallow();
  //fara Copy constructor
  double get() const;
  double* adresa() const;
  void set(double income);
 
};

#endif
