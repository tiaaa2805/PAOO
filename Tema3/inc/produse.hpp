#ifndef PRODUSE_HPP
#define PRODUSE_HPP
#include <string>
#include <iostream>
#include <memory>

class Produs
{
    private:
        char* nume;                              // resursa gestionata manual: deep copy (itemii 10-12, 14c)
        float pret;
        int stoc;
        std::shared_ptr<std::string> furnizor;   // resursa partajata intre produse (item 14b)

        static char* copiazaSir(const char* sursa);
    public:
    Produs(const char* nume_ = "fara nume", float pret_ = 0, int stoc_ = 0,
           std::shared_ptr<std::string> furnizor_ = nullptr);
    virtual ~Produs();                           // item 13: virtual, ca unique_ptr<Produs> sa stearga corect si un ProdusPerisabil
    Produs(const Produs& other);
    Produs& operator=(const Produs& other);
    Produs& operator+=(const Produs& other);
    Produs& operator+=(int cantitate);
    Produs& operator-=(int cantitate);
    const char* getNume() const { return nume; }
    float getPret() const { return pret; }
    int getStoc() const { return stoc; }
    std::shared_ptr<std::string> getFurnizor() const { return furnizor; }
    virtual void afiseaza() const;
};

class ProdusVoid {
public:
    void operator=(const ProdusVoid& rhs) { /* copiază, dar nu returnează nimic */ }
};

class ProdusPerisabil : public Produs
{
    private:
        int termenValabilitate;
        int * loturi;
        int numarLoturi;
    public:
    ProdusPerisabil(const char* nume_ = "fara nume", float pret_ = 0, int stoc_ = 0,
                    int termenValabilitate_ = 0, std::shared_ptr<std::string> furnizor_ = nullptr);
    ~ProdusPerisabil() override;
    ProdusPerisabil(const ProdusPerisabil& other);
    ProdusPerisabil& operator=(const ProdusPerisabil& other);

    int getTermenValabilitate() const { return termenValabilitate; }

    static int * copiereLoturi(const int * loturi, int numarLoturi);
    void adaugaLot(int lot);
    void afiseaza() const override;
};

/*
class ProdusFaraBaza : public Produs {
    int extra_;
public:
    ProdusFaraBaza(const char* n, double p, int s, int extra)
        : Produs(n, p, s), extra_(extra) {}

    // GRESIT: lipsește Produs(rhs)
    ProdusFaraBaza(const ProdusFaraBaza& rhs) : extra_(rhs.extra_) {}

    // GRESIT: lipsește Produs::operator=(rhs)
    ProdusFaraBaza& operator=(const ProdusFaraBaza& rhs) {
        extra_ = rhs.extra_;
        return *this;
    }
};
*/
#endif
