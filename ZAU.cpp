#include "ZAU.hpp"

Zau::Zau(int num, string prop, Polygone<int> forme, int pConstructible) : Parcelle(num, prop, forme) {
  this->setType("ZAU");
  this->pConstructible = pConstructible;
}

void Zau::setType(string type) { 
  this->type = type; 
}

float Zau::surfaceConstructible() const{
  return this->pConstructible;
}

void Zau::doprint(std::ostream& os, print inFile) const{
  switch (inFile) {
    case CONSOLE:
      Parcelle::doprint(os, inFile);
      os << "\t% constructible : " << this->surfaceConstructible() << " %" << std::endl;
      break;
    case FICHIER:
      // 1ère ligne e ZAU : typeParcelle numéro propriétaire pConstructible
      os << this->getType() <<" "<< this->getNumero() <<" "<< this->getProprietaire() <<" "<< this->pConstructible << std::endl;
      // 2ème ligne : affichage des sommets du polygone commune à toute les parcelles
      Parcelle::doprint(os, inFile) ;
    break;
  }
}

std::ostream& operator<< (std::ostream &flux, Zau  const& zau){
  zau.doprint(flux, CONSOLE);
  return flux;
}