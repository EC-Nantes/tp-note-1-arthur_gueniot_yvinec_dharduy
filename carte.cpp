#include "carte.hpp"

Carte::Carte(string pathFichier) {
  
  // Ouverture du fichier
  ifstream fichier{pathFichier};

  string infoParcelle{""};
  string pointsParcelle{""};

  while ((getline(fichier >> std::ws, infoParcelle)) &&
         (getline(fichier >> std::ws, pointsParcelle))) {

    vector<string> infoSplit = this->split(infoParcelle, " ");
    vector<string> pointsSplit = this->split(pointsParcelle, " ");

    Polygone<int> poly = Polygone<int>();
    
    for (auto i : pointsSplit) {
      if (i.size() > 1) {
        string chaine = i.substr(1, i.size() - 2);
        vector<string> pointSeparer = this->split(chaine, ";");

        int x = stoi(pointSeparer[0]);
        int y = stoi(pointSeparer[1]);

        Point2D<int> a = Point2D<int>(x, y);
        poly.addPoint(a);
      }
    }
    string type = infoSplit[0];

    if (type == "ZA") {
      Za *parcelleAjouter =
          new Za(stoi(infoSplit[1]), infoSplit[2], poly, infoSplit[3], 0, 0);
      this->parcelles.push_back(parcelleAjouter);
    }

    else if (type == "ZN") {
      Zn *parcelleAjouter = new Zn(stoi(infoSplit[1]), infoSplit[2], poly);
      this->parcelles.push_back(parcelleAjouter);
    }

    else if (type == "ZAU") {
      Zau *parcelleAjouter =
          new Zau(stoi(infoSplit[1]), infoSplit[2], poly, stoi(infoSplit[3]));
      this->parcelles.push_back(parcelleAjouter);
    }

     else if (type == "ZU") {
      Zu *parcelleAjouter =
          new Zu(stoi(infoSplit[1]), infoSplit[2], poly, stoi(infoSplit[3]), stof(infoSplit[4]));
      this->parcelles.push_back(parcelleAjouter);
       }
    else {
      cout << type << endl;
    }
  }

  // Calcul taille surface
  float max;
  for (auto const uneParcelle : this->parcelles) {
    max += uneParcelle->getSurface();
  }
  this->surfaceTotale = max;
}

// for string delimiter
vector<string> Carte::split(string s, string delimiter) {
  size_t pos_start = 0, pos_end, delim_len = delimiter.length();
  string token;
  vector<string> res;

  while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
    token = s.substr(pos_start, pos_end - pos_start);
    pos_start = pos_end + delim_len;
    res.push_back(token);
  }

  res.push_back(s.substr(pos_start));
  return res;
}

float Carte::getSurfaceTotale() const { return this->surfaceTotale; }

vector<Parcelle *> Carte::getParcelles() const { return this->parcelles; }

std::ostream &operator<<(std::ostream &o, Carte const &p) {
  vector<Parcelle *> lesParcelles = p.getParcelles();

  if (lesParcelles.size() == 0) {
    o << "Aucune parcelle !" << endl;
  }
   else {
    o << "La carte est de taille " << p.getSurfaceTotale() << endl;

    for (auto  uneParcelle : lesParcelles) {
       // if(uneParcelle->getType()=="ZU") {
       //   uneParcelle->surfaceConstructible();
       // } else {
       //    cout << "c is not an instance of the class Parent" << endl;
       // }
      uneParcelle->afficher();
    }
  }
  return o;
}