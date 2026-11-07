#include "books.hpp"
  ///aici are loc initializarea, in format de lista de initializare
BooksGOOD:: BooksGOOD(string& name, string &id): nrpages_(0), price_(0.0), name_(name), id_(id) {}

BooksBAD::BooksBAD ( string &name, string & id)
    {
      name_=name;
      id_=id;  ///nrpages si price nu sunt initializate, iar aici au loc 2 actiuni
    }

RaftBAD::  RaftBAD( int ocupat_): ocupat(ocupat_), locuri(ocupat+7) {}  ///ordinea este gresita

RaftGOOD::  RaftGOOD(int ocupat_): ocupat(ocupat_), locuri(ocupat +7){}
