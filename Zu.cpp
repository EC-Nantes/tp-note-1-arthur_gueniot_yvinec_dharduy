#include "Zu.hpp"

Zu::Zu(int num, string prop, Polygone<int> forme, int pConstructible,
       float surfaceConstruite) : Parcelle(num, prop, forme) {
  this->pConstructible = pConstructible;
  this->surfaceConstruite = surfaceConstruite;
  this->setType("ZU");
}

float Zu::surfaceConstructible() const {
  float calcul = (((pConstructible / 100.0) * surface) - surfaceConstruite); // return surface constructible;
  return calcul;
}

void Zu::setType(std::string type) { 
  this->type = type; }

void Zu::doprint(std::ostream& os, print inFile) const{
  switch (inFile) {
    case CONSOLE:
      Parcelle::doprint(os, inFile);
      os << "\t% constructible : " << this->pConstructible <<" %\n" 
            << "\tsurface construite : "<< this->surfaceConstruite << std::endl 
            << "\tsurface a construire  : " << this->surfaceConstructible() << std::endl;
      break;
    case FICHIER:
      // 1ère ligne de ZU : typeParcelle numéro propriétaire pConstructible surfaceConstruite
      os << this->getType() <<" "<< this->getNumero() <<" "<< this->getProprietaire() <<" "<< this->pConstructible <<" "<< this->surfaceConstruite << std::endl;
      // 2ème ligne : affichage des sommets du polygone commune à toute les parcelles
      Parcelle::doprint(os, inFile) ;
    break;
  }
}

std::ostream &operator<< (std::ostream &flux, Zu  const& zu){
  zu.doprint(flux, CONSOLE);
  return flux;
}