#ifndef _ZA_HPP_
#define _ZA_HPP_

#include <iostream>
#include "Parcelle.hpp"


using namespace std;

class Za: public virtual Parcelle {

  private:
    string typeCulture;
    float surfaceBatAgri;

  public:
   /* Constructeur */
    Za(int num, string prop, Polygone<int> forme, string typeCulture, float surfaceBatAgri, int pConstructible);

   /* Méthodes de la classe */
    string getTypeCulture() const;
    float getSurfaceBatAgri() const;

   /* Surcharge de méthode de la classe mère ou librairie standard */
    void setType(string type);
    void doprint(std::ostream& os, print inFile) const override;
    friend std::ostream& operator<< (std::ostream &flux, Za  const& za);
};
#endif