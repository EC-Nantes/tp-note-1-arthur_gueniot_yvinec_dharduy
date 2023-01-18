#include "Zu.hpp"

Zu::Zu(int num, string prop, Polygone<int> forme, int pConstructible,
       float surfaceConstruite) : Parcelle(num, prop, forme) {
  this->pConstructible = pConstructible;
  this->surfaceConstruite = surfaceConstruite;
  this->setType("ZU");
}

float Zu::surfaceConstructible() const {
  return (((pConstructible / 100) * surface) -
          surfaceConstruite); // return surface constructible;
}

void Zu::setType(std::string type) { 
  this->type = type; }

// std::ostream &operator<<(std::ostream &flux, Zu const &zu) {
//   flux << "Parcelle n° "<<zu.numero<<std::endl
//     << "\tType : " << zu.getType()  <<std::endl
//     << "\t" << zu.getForme() << std::endl 
//     << "\tProprietaire : " << zu.getProprietaire() << std::endl 
//     << "\tSurface : " << zu.getSurface()<<std::endl << "\t% construvctible : "<< zu.pConstructible <<" %" << std::endl <<
//   "\tsurface construite : "<< zu.surfaceConstruite << std::endl << "\tsurface a construire  : " << zu.surfaceConstructible()<<std::endl;
//   return flux;
// }

void Zu::afficher() const { std::cout << "Affichage Zu"; }