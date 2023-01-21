#include "Za.hpp"

using namespace std;

Za::Za(int num, string prop, Polygone<int> forme, string typeCulture,
       float surfaceBatAgri, int pConstructible)
    : Parcelle(num, prop, forme) {
  this->setType("ZA");
  this->typeCulture = typeCulture;

  // La construction est possible si la surface requise est inférieure à 10% de
  // la surface du terrain est aussi < à 200m2
  if ( (surfaceBatAgri < this->surface * 0.1) && (surfaceBatAgri < 200) ) {
    this->surfaceBatAgri = surfaceBatAgri;
  } else {
    this->surfaceBatAgri = 0;
  }
}

void Za::setType(std::string type) { this->type = type; }

string Za::getTypeCulture() const { return this->typeCulture; }

float Za::getSurfaceBatAgri() const {
  return this->surfaceBatAgri;
}

void Za::doprint(std::ostream& os, print inFile) const{
  switch (inFile) {
    case CONSOLE:
      Parcelle::doprint(os, inFile);
      os << "\tSurface Batiment Agricole : " << this->getSurfaceBatAgri() << std::endl
            << "\tType culture : " << this->getTypeCulture() << std::endl
            <<  std::endl;
      break;
    case FICHIER:
      // 1ère ligne ZA : typeParcelle numéro propriétaire typeCulture
      os << this->getType() <<" "<< this->getNumero() <<" "<< this->getProprietaire() <<" "<< this->getTypeCulture() << std::endl;
      // 2ème ligne : affichage des sommets du polygone commune à toute les parcelles
      Parcelle::doprint(os, inFile) ;
    break;
  }
}

std::ostream& operator<< (std::ostream &flux, Za  const& za){
  za.doprint(flux, CONSOLE);
  return flux;
}