#include<iostream>

class NoDelete{
private :
  double *income_;
public:
  NoDelete(double value) : income_(new double(value))
  {
    std::cout<<"Contul fara delete later "<<*income_<<std::endl;
  }
  ~NoDelete(){
    std::cout<<"No delete"<<std::endl;
    
  }
};

int main()
{
  for(int i=0; i<3; i++)
    {
      NoDelete c(10*i);
    }
  std::cout<<"Sunt 3 double-uri alocate pe heap"<<std::endl;
  return 0;
}
