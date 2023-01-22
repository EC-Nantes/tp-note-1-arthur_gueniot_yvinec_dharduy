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
    bool doIntersect(Point2D<T> p1, Point2D<T> q1, Point2D<T> p2, Point2D<T> q2);
    bool isSelfIntersecting();
  
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
  /* Rien a faire pour le moment */
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
      try{
       isTrigonometric(this->getSommets());
    } catch(std::string const& erreur){
      std::cerr<<erreur<<std::endl<<*this<<std::endl;
    }
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

// Fonction pour vérifier si deux segments de droite se croisent
template <typename T>
bool Polygone<T>::doIntersect(Point2D<T> p1, Point2D<T> q1, Point2D<T> p2, Point2D<T> q2) {
    // Calcul des coefficients des équations des droites formées par les segments
    double a1 = q1.getY() - p1.getY();
    double b1 = p1.getX() - q1.getX();
    double c1 = a1 * p1.getX() + b1 * p1.getY();

    double a2 = q2.getY() - p2.getY();
    double b2 = p2.getX() - q2.getX();
    double c2 = a2 * p2.getX() + b2 * p2.getY();

    double determinant = a1 * b2 - a2 * b1;

    if (determinant == 0) {
        // Les droites sont parallèles
        return false;
    } else {
        double x = (b2 * c1 - b1 * c2) / determinant;
        double y = (a1 * c2 - a2 * c1) / determinant;
        if (min(p1.getX(), q1.getX()) <= x && x <= max(p1.getX(), q1.getX()) && min(p1.getY(), q1.getY()) <= y && y <= max(p1.getY(), q1.getY()) &&
            min(p2.getX(), q2.getX()) <= x && x <= max(p2.getX(), q2.getX()) && min(p2.getY(), q2.getY()) <= y && y <= max(p2.getY(), q2.getY())) {
            return true;
        }
    }
    return false;
}

template <typename T>
bool Polygone<T>::isSelfIntersecting() {
    auto points = this->getSommets();
    int n = points.size();
    for (int i = 0; i < n; i++) {
        Point2D<T> p1 = points[i];
        Point2D<T> q1 = points[(i + 1) % n];
        for (int j = i + 2; j < n - 1; j++) {
            Point2D<T> p2 = points[j];
            Point2D<T> q2 = points[(j + 1) % n];
            if (doIntersect(p1, q1, p2, q2)) {
                return true;
            }
        }
    }
    return false;
}


#endif /* _POLYGONE_HPP_ */