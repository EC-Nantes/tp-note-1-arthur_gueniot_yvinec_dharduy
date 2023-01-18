#ifndef _ZN_HPP_
#define _ZN_HPP_

#include "Parcelle.hpp"

class Zn : public virtual Parcelle{

public :
  Zn(int num, string prop, Polygone<int> forme);

  void setType(string type);
 // friend std::ostream& operator<< (std::ostream &flux, Zn  const&p);
      void afficher()const;
      std::ostream& doprint(std::ostream& os) const{
      return os << "One";
    };
};


#endif /*_ZN_HPP_*/