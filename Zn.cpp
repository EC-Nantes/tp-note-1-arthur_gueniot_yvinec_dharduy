#include "Zn.hpp"

Zn::Zn(int num, string prop, Polygone<int> forme)
      : Parcelle(num, prop, forme) {
  this->setType("ZN");
}

void Zn::setType(string type) { 
  this->type = type; 
}

void Zn::doprint(std::ostream& os, print inFile) const{
  switch (inFile) {
    case CONSOLE:
      Parcelle::doprint(os, inFile);
      break;
    case FICHIER:
      // 1ère ligne de ZU : typeParcelle numéro propriétaire pConstructible surfaceConstruite
      os << this->getType() <<" "<< this->getNumero() <<" "<< this->getProprietaire() << std::endl;
      // 2ème ligne : affichage des sommets du polygone commune à toute les parcelles
      Parcelle::doprint(os, inFile) ;
    break;
  }
}

