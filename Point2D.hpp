#ifndef Point2D_HPP
#define Point2D_HPP
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Point2D;

template <typename T>
std::ostream& operator<< (std::ostream &, Point2D<T> const&);

template<typename T> 
class Point2D
{
  private:
    T x;
    T y;

  public:
   /* Constructeurs */
    Point2D();
    Point2D(T x,T y);
    Point2D(Point2D const &p);

   /* Accesseurs */
    T getX() const;
    T getY() const;

   /* Mutateurs */
    void setX(T x);
    void setY(T x);

   /* Méthodes de la classe */
    void translater(T xt, T yt);

   /* Surcharge de méthode de la classe mère ou librairie standard */
    friend std::ostream& operator<< <T>(std::ostream &, Point2D<T> const&);
};

/*********************************************************************
 * Constructeurs
*********************************************************************/
/** 
 * Constructeurs du point avec les coordonnées
 */
template<typename T> 
Point2D<T>::Point2D(T x,T y)
{
  this->x = x;
  this->y = y;
}

/** 
 * Constructeur par défaut, coordonnées à l'origine (0,0)
 */
template<typename T> 
Point2D<T>::Point2D()
{
  this->x = (T)0;
  this->y = (T)0;
}

/** 
 * Constructeur par recopie
 */
template<typename T>
Point2D<T>::Point2D(Point2D const &p)
{
  this->x = p.getX();
  this->y = p.getY();
}

/*********************************************************************
 * Accesseurs et Mutateurs
*********************************************************************/
/** 
 * Récupérer la valeur en X
 */
template<typename T> 
T Point2D<T>::getX() const
{
  return this->x;
}

/** 
 * Modifier la valeur du point en X
 */
template<typename T> 
void Point2D<T>::setX(T x)
{
  this->x = x;
}

/** 
 * Récupérer la valeur en Y
 */
template<typename T> 
T Point2D<T>::getY() const
{
  return this->y;
}

/** 
 * Modifier la valeur du point en Y
 */
template<typename T> 
void Point2D<T>::setY(T y)
{
  this->y = y;
}

/*********************************************************************
 * Les fonctions
 *********************************************************************/
/** 
 * Translater un point en X et Y
 */
template<typename T>
void Point2D<T>::translater(T xt, T yt)
{ 
  setX(getX() + xt);
  setY(getY() + yt);
}

/*********************************************************************
 * Surcharge d'opérateur
*********************************************************************/
/** 
 * Surcharge de l'opérateur d'affichage << de la librairie standard avec une mise en forme spécifique [X,Y]
 */
template<typename T>
std::ostream& operator<< (std::ostream &flux, Point2D<T> const &p )
{
  flux << "[" << p.getX()  << ";" << p.getY() << "]";
  return flux;
}

#endif
