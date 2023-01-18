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
      Za(int num, string prop, Polygone<int> forme, string typeCulture, float surfaceBatAgri, int pConstructible);
      string getTypeCulture() const;
      void setType(string type);
      float getSurfaceBatAgri() const;
      float surfaceConstructiblegetSurfaceBatAgri() const;
      // friend std::ostream& operator<< (std::ostream &flux, Za  const& za);
      void afficher()const;
      std::ostream& doprint(std::ostream& os) const;
};
#endif