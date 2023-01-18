#ifndef _Carte_HPP_
#define _Carte_HPP_

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

using namespace std;

class Carte {
  protected:
    float surfaceTotale ;
    vector<Parcelle*> parcelles ;

  public:
    Carte (string pathFichier);

    float getSurfaceTotale() const;
    vector<Parcelle*> getParcelles() const;
  
  private :
    vector<string> split (string s, string delimiter);
  
};

std::ostream& operator<<(std::ostream &o, Carte const &p);
#endif