#ifndef _carte_HPP_
#define _carte_HPP_

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include "Parcelle.hpp"
#include "Polygone.hpp"
#include "Point2D.hpp"

#include "Za.hpp"
#include "Zu.hpp"
#include "ZAU.hpp"
#include "Zn.hpp"

class Carte {
  private:
    float surfaceTotale ;
    vector<Parcelle*> parcelles ;
  public:
   /* Constructeurs */
    Carte (string pathFichier);
   /* Accesseur */
    float getSurfaceTotale() const;
    vector<Parcelle*> getParcelles() const;
   /* Méthode de la classe */
    Parcelle* search_and_translate(int num);
    void saveCarteDansFichier(string file);
  private :
    vector<string> split (string s, string delimiter);//pour délimiter le texte charger des fichiers
   /* Surcharge de méthode de la classe mère ou librairie standard */
    friend std::ostream& operator<<(std::ostream &o, Carte const &p);
};

int crossProduct(Point2D<int> A, Point2D<int> B, Point2D<int> C);
void isTrigonometric(vector<Point2D<int>> points) ;


#endif