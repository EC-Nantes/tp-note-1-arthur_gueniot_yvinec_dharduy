#ifndef _POLYGONE_HPP_
#define _POLYGONE_HPP_

#include <vector>
#include "Point2D.hpp"

// Pour pouvoir déclarer la surcharge de l'affichage juste en dessous
template <typename T> class Polygone;

// Prototype de l'affichage
template <typename T> std::ostream &operator<< (std::ostream &s, Polygone<T> const &p);

/**
Création de la classe Polygone
*/
template <typename T> class Polygone {
protected:
  vector<Point2D<T>> sommets;

public:
  /* Constructeurs */
  Polygone( );
  Polygone(vector<Point2D<T>> listeSommets);
  Polygone(Polygone<T> const &poly);
  /* Méthode de la classe */
  vector<Point2D<T>> getSommets( ) const;
  void setSommets(vector<Point2D<T>> listeSommets);
  void addPoint(Point2D<T> point);
  void translater(T x, T y);
  friend std::ostream &operator<< <T>(std::ostream &s, Polygone<T> const &p);
};

/*********************************************************************
 * Constructeurs
*********************************************************************/
/** 
 * Constructeur par défaut
 */
template <typename T> Polygone<T>::Polygone() {
  /* A DEFINIR ce que l'on met dedans */
}

/** 
 * Constructeur
 */
template <typename T> Polygone<T>::Polygone(vector<Point2D<T>> listeSommets) {
  this->sommets = listeSommets;
}

/** 
 * Constructeur par recopie
 */
template <typename T> Polygone<T>::Polygone(Polygone<T> const &poly) {
  this->sommets = poly.sommets;
}
/*********************************************************************
 * Méthodes de classe
*********************************************************************/
template <typename T> vector<Point2D<T>> Polygone<T>::getSommets( ) const{
  return this->sommets;
}

template <typename T> void Polygone<T>::setSommets(vector<Point2D<T>> listeSommets){
  this->sommets = listeSommets;
}

template <typename T> void Polygone<T>::addPoint(Point2D<T> point){
  this->sommets.push_back (point);
}

template <typename T> void Polygone<T>::translater(T x, T y){
  for( auto it = this->sommets.begin(); it != this->sommets.end(); it++ ) {
    it->translater(x, y);
  }
}

/*********************************************************************
 * Surcharge d'opérateur
*********************************************************************/
template <typename T>
std::ostream &operator<<(std::ostream &s, Polygone<T> const &p) {
  s << "Polygone : "; 
  for( auto& it : p.getSommets())  {
    s << it <<" ";
  }  
  return s;
}


#endif /* _POLYGONE_HPP_ */