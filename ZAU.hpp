#ifndef _ZAU_HPP_
#define _ZAU_HPP_

#include "Parcelle.hpp"

class Zau : public virtual Parcelle{

public :
  Zau(int num, string prop, Polygone<int> forme, int pConstructible);
  void setType(std::string type);
  float surfaceConstructible()const; // surface constructible totale pour une ZAU
  // friend std::ostream& operator<< (std::ostream &s, Zau  const &z);
      void afficher()const;
      std::ostream& doprint(std::ostream& os) const{
      return os << "One";
    };
};


#endif /* _ZAU_HPP_ */