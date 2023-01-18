#ifndef _PARCELLE_HPP_
#define _PARCELLE_HPP_

#include "string.h"
#include <iostream>
#include "Polygone.hpp"

class Parcelle {
  private :
    std::string type;
    int numero;
    std::string proprietaire;
    float surface;
    Polygone<int> forme;

  public :

    
    Parcelle(int num, std::string prop, Polygone<int> forme_poly) 
                  : numero(num), proprietaire(prop), forme(forme_poly) {}
    Parcelle(Parcelle &parc);
    int getNumero() const;
    std::string getProprietaire() const;
    float getSurface() const;
    Polygone<int> getForme() const;  
    std::string getType() const;
    void setNumero(int n);
    void setproprietaire(std::string prop);
    void setForme(Polygone<int> forme);
    virtual void setType(std::string type)=0;
    friend std::ostream& operator<<(std::ostream& flux,Parcelle const& p);
};

#endif