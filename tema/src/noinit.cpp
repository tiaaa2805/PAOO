#include<iostream>

class NoInit{
private :
  double *tranzactii_;
  int nrtranzactii_;
public:
  NoInit() : tranzactii_(new double[5]())
  {
    //nrtranzactii_ nu este initializat, are o valoare oarecare
    std::cout<<"Constructor fara initializare, nrtranzactii = "<<nrtranzactii_<<std::endl;
  }
  ~NoInit(){
    std::cout<<"Delete la adresa "<<tranzactii_<<std::endl;
    delete[] tranzactii_;
  }
};

int main()
{
  for(int i=0; i<3; i++)
    {
      NoInit c;
    }
  std::cout<<"Valoarea lui nrtranzactii este intamplatoare (poate iesi si 0), folosita ca index ar scrie in afara tabloului (verificati cu valgrind)"<<std::endl;
  return 0;
}
