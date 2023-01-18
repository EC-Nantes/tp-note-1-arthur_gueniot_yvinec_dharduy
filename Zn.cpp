#include "Zn.hpp"

Zn::Zn(int num, string prop, Polygone<int> forme)
      : Parcelle(num, prop, forme) {
  this->setType("ZN");
}

void Zn::setType(string type) { 
  this->type = type; 
}

// std::ostream& operator<<(std::ostream &flux, Zn const &p)
// {
//   flux << "Parcelle n° "<<p.numero<<std::endl
//     << "\tType : " << p.getType()  <<std::endl
//     << "\t" << p.getForme() << std::endl 
//     << "\tProprietaire : " << p.getProprietaire() << std::endl 
//     << "\tSurface : " << p.getSurface()<<std::endl;
//   return flux;
// }

void Zn::afficher() const{ std::cout << "Affichage Zn"; }