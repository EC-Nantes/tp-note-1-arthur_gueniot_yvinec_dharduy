#include "Parcelle.hpp"

//surcharge opérateur de la parcelle 
// std::ostream &operator<<(std::ostream &flux, Parcelle const &p) {
//   flux << "Parcelle n° "<<p.numero<<std::endl
//     << "\tType : " << p.getType()  <<std::endl
//     << "\t" << p.getForme() << std::endl 
//     << "\tProprietaire : " << p.getProprietaire() << std::endl 
//     << "\tSurface : " << p.getSurface()<<std::endl;
//   return flux;
// }
// std::ostream &operator<<(std::ostream &flux, Parcelle const &p) {
//   p.afficher();
//   return flux;
// }
Parcelle::Parcelle(int num, std::string prop, Polygone<int> forme_poly)
    : numero(num), proprietaire(prop), forme(forme_poly) {
    this->calculSurface();
      this->pConstructible = 0;//évite de redéfinir chaque constructibilité dans chaque classe filles (les ZA, ZAU, ZAN, ZN)
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
  for (int i = 0; i < points.size() - 1; i++) {
    surface += (points[i].getX() * points[i + 1].getY()) -
               (points[i + 1].getX() * points[i].getY());
  }
  this->surface = surface / 2;
}


