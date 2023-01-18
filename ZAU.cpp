#include "ZAU.hpp"

Zau::Zau(int num, string prop, Polygone<int> forme, int pConstructible) : Parcelle(num, prop, forme) {
  this->setType("ZN");
  this->pConstructible = pConstructible;
}

void Zau::setType(string type) { 
  this->type = type; 
}

float Zau::surfaceConstructible() const{
  return 0.2;
}
// std::ostream &operator<<(std::ostream &s, Zau const &z){
//   s <<  "Parcelle n° "<<z.numero<<std::endl
//     << "\tType : " << z.getType()  <<std::endl
//     << "\t" << z.getForme() << std::endl 
//     << "\tProprietaire : " << z.getProprietaire() << std::endl 
//     << "\tSurface : " << z.getSurface()<<std::endl << "\t% constructible : " << z.surfaceConstructible() << " %\n"
//      << endl;
//   return s;
// }

void Zau::afficher() const{ std::cout << "Affichage Zau"; }