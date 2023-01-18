#include "Za.hpp"

using namespace std;

Za::Za(int num, string prop, Polygone<int> forme, string typeCulture,
       float surfaceBatAgri, int pConstructible)
    : Parcelle(num, prop, forme) {
  this->setType("ZA");
  this->typeCulture = typeCulture;

  // La construction est possible si la surface requise est inférieure à 10% de
  // la surface du terrain et aussi < à 200m2
  if ((surfaceBatAgri < this->surface * 0.1) && (surfaceBatAgri < 200)) {
    this->surfaceBatAgri = surfaceBatAgri;
  } else {
    this->surfaceBatAgri = 0;
  }
}

void Za::setType(std::string type) { this->type = type; }

string Za::getTypeCulture() const { return this->typeCulture; }

float Za::surfaceConstructiblegetSurfaceBatAgri() const {
  return this->surfaceBatAgri;
}

// surcharge opérateur
// std::ostream &operator<<(std::ostream &flux, Za const &za) {
//   flux << "Parcelle n° " << za.numero << std::endl
//        << "\tType : " << za.getType() << std::endl
//        << "\t" << za.getForme() << std::endl
//        << "\tProprietaire : " << za.getProprietaire() << std::endl
//        << "\tSurface : " << za.getSurface() << std::endl
//        << "\tSurface Batiment Agricole : " << za.getSurfaceBatAgri() << " \n"
//        << "\tType culture : " << za.getTypeCulture() << " \n"
//        << endl;
//   return flux;
// }

void Za::afficher() const{ std::cout << "Affichage Za"; }