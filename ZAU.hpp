#ifndef _ZAU_HPP_
#define _ZAU_HPP_

#include "Parcelle.hpp"

class Zau : public virtual Parcelle{

  public :
   /* Constructeur */
    Zau(int num, string prop, Polygone<int> forme, int pConstructible);

   /* Méthodes de la classe */
    float surfaceConstructible()const; // surface constructible totale pour une ZAU

   /* Surcharge de méthode de la classe mère ou librairie standard */
    void setType(std::string type);
    void doprint(std::ostream& os, print inFile) const override;
    friend std::ostream& operator<< (std::ostream &s, Zau  const &zau);
};


#endif /* _ZAU_HPP_ */