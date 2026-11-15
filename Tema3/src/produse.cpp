#include "produse.hpp"
#include <cstring>
#include <iostream>

// ===================== Produs =====================

char* Produs::copiazaSir(const char* sursa) {
    if (sursa == nullptr) sursa = "";
    char* copie = new char[std::strlen(sursa) + 1];
    std::strcpy(copie, sursa);
    return copie;
}

Produs::Produs(const char* nume_, float pret_, int stoc_, std::shared_ptr<std::string> furnizor_)
    : nume(copiazaSir(nume_)), pret(pret_), stoc(stoc_), furnizor(furnizor_) {
}

Produs::Produs(const Produs& other)
    : nume(copiazaSir(other.nume)),   // item 14c: deep copy (fiecare produs are numele lui)
      pret(other.pret),
      stoc(other.stoc),
      furnizor(other.furnizor) {      // item 12: membrul nou e copiat si aici
                                      // item 14b: copie superficiala, shared_ptr numara folosirile
}

Produs::~Produs() {
    std::cout << "  [Sters: " << nume << "]" << std::endl;   // item 13: vezi cand se elibereaza resursa
    delete[] nume;
}

Produs& Produs::operator+=(const Produs& other) {
    this->stoc += other.stoc;
    return *this;
}

Produs& Produs::operator+=(int cantitate) {
    this->stoc += cantitate;
    return *this;                                 // item 10
}

Produs& Produs::operator-=(int cantitate) {
    this->stoc -= cantitate;
    return *this;                                 // item 10
}

Produs& Produs::operator=(const Produs& other) {
    if (this != &other) {
        char* nou = copiazaSir(other.nume);       // item 11: intai facem copia...
        delete[] this->nume;                      // ...abia apoi stergem numele vechi
        this->nume = nou;
        this->pret = other.pret;
        this->stoc = other.stoc;
        this->furnizor = other.furnizor;          // item 12: copiem toti membrii
    }
    return *this;                                 // item 10
}

void Produs::afiseaza() const {
    std::cout << "Nume: " << nume << ", Pret: " << pret << ", Stoc: " << stoc;
    if (furnizor) std::cout << ", Furnizor: " << *furnizor;
    std::cout << std::endl;
}

// ===================== ProdusPerisabil =====================

ProdusPerisabil::ProdusPerisabil(const char* nume_, float pret_, int stoc_,
                                 int termenValabilitate_, std::shared_ptr<std::string> furnizor_)
    : Produs(nume_, pret_, stoc_, furnizor_),
      termenValabilitate(termenValabilitate_),
      loturi(nullptr),
      numarLoturi(0) {
}

int * ProdusPerisabil::copiereLoturi(const int * loturi, int numarLoturi) {
    if (loturi == nullptr || numarLoturi <= 0) return nullptr;
    int * copie = new int[numarLoturi];
    for (int i = 0; i < numarLoturi; ++i) {
        copie[i] = loturi[i];
    }
    return copie;
}

ProdusPerisabil::ProdusPerisabil(const ProdusPerisabil& other)
    : Produs(other),                                           // item 12: copiem partea de baza
      termenValabilitate(other.termenValabilitate),
      loturi(copiereLoturi(other.loturi, other.numarLoturi)),  // item 14c: deep copy
      numarLoturi(other.numarLoturi) {
}

ProdusPerisabil::~ProdusPerisabil() {
    delete[] loturi;
}

ProdusPerisabil& ProdusPerisabil::operator=(const ProdusPerisabil& other) {
    if (this != &other) {
        Produs::operator=(other);                                   // item 12: apelam operatorul clasei de baza
        int * noi = copiereLoturi(other.loturi, other.numarLoturi); // item 11: intai copiem loturile...
        delete[] loturi;                                            // ...abia apoi le stergem pe cele vechi
        loturi = noi;
        numarLoturi = other.numarLoturi;
        termenValabilitate = other.termenValabilitate;
    }
    return *this;                                                   // item 10
}

void ProdusPerisabil::adaugaLot(int lot) {
    int * loturiNoi = new int[numarLoturi + 1];
    for (int i = 0; i < numarLoturi; ++i) {
        loturiNoi[i] = loturi[i];
    }
    loturiNoi[numarLoturi] = lot;
    delete[] loturi;
    loturi = loturiNoi;
    numarLoturi++;
}

void ProdusPerisabil::afiseaza() const {
    Produs::afiseaza();
    std::cout << "    Termen: " << termenValabilitate << " zile, Loturi: [";
    for (int i = 0; i < numarLoturi; ++i) {
        std::cout << loturi[i] << (i + 1 < numarLoturi ? ", " : "");
    }
    std::cout << "]" << std::endl;
}
