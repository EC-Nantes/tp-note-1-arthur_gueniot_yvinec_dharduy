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
  
    /* Méthodes de la classe */
    vector<Point2D<T>> getSommets() const;
    void setSommets(vector<Point2D<T>> listeSommets);
    void addPoint(Point2D<T> point);
    void translater(T x, T y);
  
     /* Surcharge de méthode de la classe mère ou librairie standard */
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
/** 
 * Retourner une liste de point de tous les sommets du polygone
 */
template <typename T> vector<Point2D<T>> Polygone<T>::getSommets( ) const{
  return this->sommets;
}

/** 
 * Remplacer tous les points de la forme
 */
template <typename T> void Polygone<T>::setSommets(vector<Point2D<T>> listeSommets){
  this->sommets = listeSommets;
}

/** 
 * Ajouter un nouveau point pour modifier la forme
 */
template <typename T> void Polygone<T>::addPoint(Point2D<T> point){
  this->sommets.push_back (point);
}

/** 
 * Permet de faire translater les coordonnées de la forme, tous les points sont déplacés en x et y
 */
template <typename T> void Polygone<T>::translater(T x, T y){
  for( auto it = this->sommets.begin(); it != this->sommets.end(); it++ ) {
    it->translater(x, y);
  }
}

/*********************************************************************
 * Surcharge d'opérateur
*********************************************************************/
/** 
 * Surcharge de l'opérateur d'affichage << de la librairie standard avec une mise en forme spécifique :
 * [X0,Y0] [X1,Y1] .. [Xn-1,Yn-1] [Xn,Yn]
 */
template <typename T>
std::ostream &operator<<(std::ostream &s, Polygone<T> const &p) {
  // s << "Polygone : "; 
  for( auto& it : p.getSommets())  {
    s << it <<" ";
  }  
  return s;
}


#endif /* _POLYGONE_HPP_ */