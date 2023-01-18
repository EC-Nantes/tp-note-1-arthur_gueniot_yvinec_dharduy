#ifndef _ZU_HPP_
#define _ZU_HPP_


#include "Parcelle.hpp"
#include "Constructible.hpp"

class Zu : public virtual Parcelle, public virtual Constructible{
  private : 
    float surfaceConstruite;
  
  public :
    Zu(int num, string prop, Polygone<int> forme,int  pConstructible, float surfaceConstruite);
    float surfaceConstructible() const ;
    void setType(std::string type);
    // friend std::ostream& operator<< (std::ostream &flux, Zu const &zu);
      void afficher()const;
};


#endif /*_ZU_HPP_*/