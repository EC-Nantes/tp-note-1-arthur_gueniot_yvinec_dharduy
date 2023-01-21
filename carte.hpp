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
  protected:
    float surfaceTotale ;
    vector<Parcelle*> parcelles ;

  public:
    Carte (string pathFichier);

    float getSurfaceTotale() const;
    vector<Parcelle*> getParcelles() const;

    void search_and_translate(int num);
    void saveCarteDansFichier(string file);

  private :
    vector<string> split (string s, string delimiter);
    friend std::ostream& operator<<(std::ostream &o, Carte const &p);
};

int crossProduct(Point2D<int> A, Point2D<int> B, Point2D<int> C);
void isTrigonometric(vector<Point2D<int>> points) ;


#endif