#include "Parcelle.hpp"

Parcelle::Parcelle(int num, std::string prop, Polygone<int> forme_poly)
    : numero(num), proprietaire(prop), forme(forme_poly) {
  this->calculSurface();
  this->pConstructible = 0; //évite de redéfinir chaque constructibilité dans
                            // chaque classe filles (les ZA, ZAU, ZAN, ZN)
}

Parcelle::Parcelle(Parcelle &parc) {
  this->numero = parc.getNumero();
  this->proprietaire = parc.getProprietaire();
  this->type = parc.getType();
  this->surface = parc.getSurface();
  this->forme = parc.getForme();
}

int Parcelle::getNumero() const { return this->numero; }

std::string Parcelle::getProprietaire() const { return this->proprietaire; }

float Parcelle::getSurface() const { return this->surface; }

Polygone<int> Parcelle::getForme() const { return this->forme; }
std::string Parcelle::getType() const { return this->type; }
void Parcelle::setNumero(int n) { this->numero = n; }
void Parcelle::setproprietaire(std::string prop) { this->proprietaire = prop; };
void Parcelle::setForme(Polygone<int> forme) { this->forme = forme; }

void Parcelle::calculSurface() {
  vector<Point2D<int>> points = this->forme.getSommets();

  float surface = 0;
  for (int i = 0; i < points.size(); i++) {
    if ( (i+1) == points.size() ) {
      surface += (points[i].getX() * points[0].getY()) -
                 (points[0].getX() * points[i].getY());
    } else {
      surface += (points[i].getX() * points[i + 1].getY()) -
                 (points[i + 1].getX() * points[i].getY());
    }
  }
  this->surface = surface / 2;
}

void Parcelle::doprint(std::ostream& os, print inFile) const {
  switch (inFile) {
    case CONSOLE:
      os << "Parcelle n° " << this->numero << std::endl
         << "\tType : " << this->getType() << std::endl
         << "\tPolygone : " << this->getForme() << std::endl
         << "\tProprietaire : " << this->getProprietaire() << std::endl
         << "\tSurface : " << this->getSurface() << std::endl;
      break;
    case FICHIER:
      // 1ère ligne  du fichier géré par chaque type de parcelle
      // 2ème ligne
      os << this->getForme() << std::endl;
    break;
  }
}

std::ostream &operator<<(std::ostream &flux, Parcelle const &p) {
  p.doprint(flux, CONSOLE);
  return flux;
} 
