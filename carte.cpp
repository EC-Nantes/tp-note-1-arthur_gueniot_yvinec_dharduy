#include "carte.hpp"

Carte::Carte(string pathFichier) {
  // Ouverture du fichier
  ifstream fichier{pathFichier};
  if(fichier)  // si l'ouverture a réussi
  {       
    std::cout<<"ouverture et chargement du fichier"<<std::endl;
  }
  else { // sinon
    throw("Impossible d'ouvrir le fichier ! Le nom n'éxiste pas");
  }

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
    //sens trigo verif
    try{
       isTrigonometric(poly.getSommets());
    } catch(std::string const& erreur){
      std::cerr<<erreur<<std::endl<<poly<<std::endl;
    }
    //polygone croisé ou pas
    if (poly.isSelfIntersecting()) {
        std::cout<<"Attention, Le polygone est croisé.\n";
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

  /** Calcul taille surface de la carte */
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
    throw ("Aucune parcelle, la carte est vide !");
  }
   else {
    o << "La carte est de taille " << p.getSurfaceTotale() << endl;

    for (auto  uneParcelle : lesParcelles) {
      std::cout << *uneParcelle << std::endl;
    }
  }
  return o;
}


Parcelle* Carte::search_and_translate(int num){
  int sommet, sommetX, sommetY;
  /** Recherche dans le vecteur parcelles celui qui a le numéro demandé par l'utilisateur */
  for(auto &it : this->parcelles){
    if(it->getNumero() == num){
      /** Demander à l'utilisateur la translation souhaitée en x et y */
      std::cout<<"Donne moi la valeur de X à translater du polygone : "<<std::endl;
      std::cin >> sommetX;
      std::cout<<"Donne moi la valeur de Y à translater du polygone : "<<std::endl;
      std::cin >> sommetY;
      it->getformePointeur()->translater(sommetX, sommetY);
      return it;
    }
  }
  throw ("Pas de parcelle avec le numéro " + std::to_string(num) +" !");
}


void Carte::saveCarteDansFichier(string file) {
  ofstream myfile (file);
  /** Vérifier l'ouverture du fichier */
  if (myfile.is_open())
  {
    std::cout<<"Ecriture des données dans le fichier '"<< file << "'" << std::endl;
    /** Enregistrer chaque parcelle dans le fichier au format FICHIER */
    for(auto &it : this->parcelles){
      it->doprint(myfile, FICHIER);
    }
    /** Fermer le fichier */
    myfile.close();
  } else { 
      /** signaler une anomalie dans l'ouverture du fichier */
      throw("Impossible d'ouvrir le fichier '" + file + "' !");
  }
}


int crossProduct(Point2D<int> A, Point2D<int> B, Point2D<int> C) {
    int x1 = B.getX() - A.getX();
    int y1 = B.getY() - A.getY();
    int x2 = C.getX() - A.getX();
    int y2 = C.getY() - A.getY();
    return x1*y2 - x2*y1;
}


void isTrigonometric(vector<Point2D<int>> points) {
  int total = 0;
  for (int i = 0; i < points.size(); i++) {
      Point2D<int> A = points[i];
      Point2D<int> B = points[(i+1) % points.size()];
      Point2D<int> C = points[(i+2) % points.size()];
      total += crossProduct(A, B, C);
    //std::cout<<"\t"<<total;
      if(total <= 0){ 
    throw std::string("Les points du polynome ci-dessous ne sont pas alignés dans le sens trigonométrique \n");
  }

  }
}
