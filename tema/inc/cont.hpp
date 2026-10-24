#ifndef CONT_HPP
#define CONT_HPP

class Cont{
private: double* income_;

public :
  Cont(double income);
  ~Cont();
  Cont(const Cont& first);
  Cont(Cont&& other) noexcept;
  double get();
  void set(double income);
};

#endif
