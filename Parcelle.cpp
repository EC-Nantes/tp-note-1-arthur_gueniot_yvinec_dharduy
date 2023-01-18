#include "Parcelle.hpp"

std::ostream& operator<< (std::ostream &flux, Parcelle const &p )
{
  // flux << "Type : " << p.getType()  <<std::endl<< "Polygone : " << p.getForme() << std::endl << "Proprietaire : " << p.getProprietaire() << std::endl << " Surface : " << p.getSurface()<<std::endl;
  return flux;
}

Parcelle::Parcelle(Parcelle &parc) {
  this->numero = parc.getNumero();
  this->proprietaire = parc.getProprietaire();
  this->type = parc.getType();
  this->surface = parc.getSurface();
  this->forme = parc.getForme();
}

int Parcelle::getNumero() const {
  return this->numero;
}

std::string Parcelle::getProprietaire() const{
  return this->proprietaire;
}

float Parcelle::getSurface() const {
  return this->surface;
}

Polygone<int> Parcelle::getForme() const {
  return this->forme;
} 
std::string Parcelle::getType() const {
  return this->type;
}
void Parcelle::setNumero(int n){
  this->numero = n;
}
void Parcelle::setproprietaire(std::string prop){
  this->proprietaire = prop;
};
void Parcelle::setForme(Polygone<int> forme){
  this->forme = forme;
}
