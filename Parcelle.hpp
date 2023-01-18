#ifndef _PARCELLE_HPP_
#define _PARCELLE_HPP_

#include "string.h"
#include <iostream>
#include "Polygone.hpp"

class Parcelle {
  protected :
    std::string type;
    int numero;
    std::string proprietaire;
    float surface;
    Polygone<int> forme;
    int pConstructible;

  public :
    Parcelle(int num, std::string prop, Polygone<int> forme_poly);
    Parcelle(Parcelle &parc);
    int getNumero() const;
    std::string getProprietaire() const;
    float getSurface() const;
    Polygone<int> getForme() const;  
    std::string getType() const;
    void setNumero(int n);
    void setproprietaire(std::string prop);
    void setForme(Polygone<int> forme);
    virtual void setType(std::string type) =0; //virtuelle pure à redéfinir dans les classes filles (Zxx)
    friend std::ostream& operator<<(std::ostream& flux,Parcelle const& p);
    virtual void afficher() const =0;

private :
      void calculSurface();
};

#endif