#ifndef _Zn_HPP_
#define _Zn_HPP_

#include "Parcelle.hpp"

class Zn : public virtual Parcelle{

public :
  Zn(int num, string prop, Polygone<int> forme);

  void setType(string type);

  void doprint(std::ostream& os, print inFile) const override;
};
#endif /*_ZN_HPP_*/