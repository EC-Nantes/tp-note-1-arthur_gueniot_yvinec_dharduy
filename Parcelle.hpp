#ifndef _PARCELLE_HPP_
#define _PARCELLE_HPP_

#include "string.h"
#include <iostream>
#include "Polygone.hpp"


enum print { CONSOLE, FICHIER };

class Parcelle {
  protected :
    std::string type;
    int numero;
    std::string proprietaire;
    float surface;
    Polygone<int> forme;
    int pConstructible;

  public :
   /* Constructeurs */
    Parcelle(int num, std::string prop, Polygone<int> forme_poly);
    Parcelle(Parcelle &parc);

   /* Accesseurs */
    int getNumero() const;
    std::string getProprietaire() const;
    float getSurface() const;
    Polygone<int> getForme() const;  
    std::string getType() const;
    Polygone<int>* getformePointeur(){return &(this->forme);}

   /* Mutateurs */
    void setNumero(int n);
    void setproprietaire(std::string prop);
    void setForme(Polygone<int> forme);
    virtual void setType(std::string type) =0; //virtuelle pure à redéfinir dans les classes filles (Zxx)

   /* Surcharge de méthode de la classe mère ou librairie standard */
    friend std::ostream& operator<<(std::ostream& flux,Parcelle const& p);
    virtual void doprint(std::ostream& os, print inFile) const;

   /* Méthode de la classe */
    void calculSurface();
};


#endif