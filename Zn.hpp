#ifndef _Zn_HPP_
#define _Zn_HPP_

#include "Parcelle.hpp"

class Zn : public virtual Parcelle{

  public :
   /* Constructeur */
    Zn(int num, string prop, Polygone<int> forme);
  
   /* Surcharge de méthode de la classe mère ou librairie standard */
    void setType(string type);
    void doprint(std::ostream& os, print inFile) const override;
};
#endif /*_ZN_HPP_*/