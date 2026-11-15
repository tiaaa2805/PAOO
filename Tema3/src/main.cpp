#include "produse.hpp"
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

// Item 13: o functie care poate arunca exceptie in mijlocul lucrului
void vanzare(Produs& p, int cantitate) {
    if (cantitate > p.getStoc())
        throw std::runtime_error(std::string("Stoc insuficient pentru ") + p.getNume());
    p -= cantitate;
}

int main() {
    std::cout << "Item 10" << std::endl;
    {
    Produs produs1("Produs1", 10.5, 100);
    Produs produs2("Produs2", 15.0, 50);
    Produs produs3("Produs3", 20.0, 10);

    std::cout << "Produs 1: " << produs1.getNume() << ", Pret: " << produs1.getPret() << ", Stoc: " << produs1.getStoc() << std::endl;

    produs1 += produs2; // Adaugam stocul produsului 2 la produsul 1;
    std::cout << "Produs 1 dupa adaugare: " << produs1.getNume() << ", Pret: " << produs1.getPret() << ", Stoc: " << produs1.getStoc() << std::endl;
    (produs1 += 8) += 10; // operator+= inlantuit: stocul creste cu 18
    std::cout << "Produs 1 dupa adaugare: " << produs1.getNume() << ", Pret: " << produs1.getPret() << ", Stoc: " << produs1.getStoc() << std::endl;

    produs3 = produs2 = produs1; // atribuire inlantuita
    std::cout << "Dupa produs3 = produs2 = produs1:" << std::endl;
    produs2.afiseaza();
    produs3.afiseaza();

/*
ProdusVoid x, y, z;
x = y;        // merge
x = y = z;    // EROARE de compilare: y = z nu returnează nimic de atribuit lui x
*/
    }

    
    std::cout << "Item 11: autoatribuirea " << std::endl;
    {
    Produs p("Cafea", 25.0, 50);

    std::cout << "Inainte: ";  p.afiseaza();

    Produs& alias = p;      // alt nume pentru același obiect
    p = alias;              // autoatribuire

    std::cout << "Dupa:    ";  p.afiseaza();   // trebuie să fie identic
    }

    
    std::cout << "Item 12: copiem toate partile obiectului" << std::endl;
    {
    ProdusPerisabil iaurt("Iaurt", 4.5, 40, 14);
    iaurt.adaugaLot(5);
    iaurt.adaugaLot(9);

    ProdusPerisabil copie(iaurt);          // constructor de copiere
    ProdusPerisabil alt;
    alt = iaurt;                           // operator=

    iaurt.adaugaLot(20);                   // modificam originalul dupa copiere

    std::cout << "Original: "; iaurt.afiseaza();
    std::cout << "Copie:    "; copie.afiseaza();   // nu are lotul 20: loturile au fost copiate in adancime
    std::cout << "Alt:      "; alt.afiseaza();

/* ProdusFaraBaza orig("Sampon", 20.0, 5, 99);
ProdusFaraBaza copie(orig);
// copie are extra_ = 99, dar numele este "fara nume" (valoarea implicită), nu "Sampon"
*/
    }

    std::cout << " Item 13: obiecte care gestioneaza resursele (RAII)" << std::endl;
    try {
        std::unique_ptr<Produs> lapte = std::make_unique<Produs>("Lapte", 7.5f, 10);

        vanzare(*lapte, 3);                  // merge
        std::cout << "Dupa vanzare: "; lapte->afiseaza();

        vanzare(*lapte, 100);                // arunca exceptie
        std::cout << "Linia asta nu se mai executa" << std::endl;
    }
    catch (const std::exception& e) {
        // "[Sters: Lapte]" apare INAINTE de mesajul de eroare:
        // unique_ptr a sters produsul automat, desi a aparut o exceptie
        std::cout << "Eroare: " << e.what() << std::endl;
    }

/*  Varianta GRESITA, fara RAII:
    Produs* lapte = new Produs("Lapte", 7.5f, 10);
    vanzare(*lapte, 100);   // arunca exceptie...
    delete lapte;           // ...deci linia asta nu se executa: memory leak
*/

    // unique_ptr si pentru produse de tipuri diferite (destructorul virtual din Produs)
    {
        std::vector<std::unique_ptr<Produs>> raft;
        raft.push_back(std::make_unique<Produs>("Paine", 3.0f, 20));
        raft.push_back(std::make_unique<ProdusPerisabil>("Smantana", 6.0f, 15, 10));
        for (const auto& p : raft) p->afiseaza();
        std::cout << "Raftul iese din scope:" << std::endl;
    }   // fara niciun delete: unique_ptr sterge fiecare produs

    // ===================================================================
    std::cout << "\n===== Item 14: politici de copiere pentru resurse =====" << std::endl;

    std::cout << "-- a) + d) unique_ptr: copiere interzisa, mutare permisa --" << std::endl;
    {
        std::unique_ptr<Produs> p1 = std::make_unique<Produs>("Ulei", 9.0f, 5);
        // std::unique_ptr<Produs> p2 = p1;          // a) EROARE de compilare: copierea e interzisa
        std::unique_ptr<Produs> p3 = std::move(p1);  // d) transfer de proprietate
        std::cout << "p1 dupa mutare: " << (p1 ? "are produs" : "gol") << std::endl;
        std::cout << "p3: "; p3->afiseaza();
    }

    std::cout << "-- b) shared_ptr: furnizor comun, numarare de referinte --" << std::endl;
    {
        auto furnizor = std::make_shared<std::string>("Lactate SRL");
        std::cout << "Folosiri furnizor la inceput: " << furnizor.use_count() << std::endl;   // 1

        Produs lapte("Lapte", 7.5f, 10, furnizor);
        ProdusPerisabil branza("Branza", 30.0f, 8, 21, furnizor);
        Produs copie(lapte);                           // copia imparte acelasi furnizor

        std::cout << "Folosiri furnizor: " << furnizor.use_count() << std::endl;              // 4
        copie.afiseaza();
    }

    std::cout << "-- c) deep copy: fiecare produs are numele lui --" << std::endl;
    {
        Produs original("Zahar", 4.0f, 30);
        Produs copie(original);
        std::cout << "Adresa nume original: " << static_cast<const void*>(original.getNume()) << std::endl;
        std::cout << "Adresa nume copie:    " << static_cast<const void*>(copie.getNume()) << std::endl;
    }

    std::cout << " Sfarsit" << std::endl;
    return 0;
}
