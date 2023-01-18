#include "Polygone.hpp"
#include "carte.hpp"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void testPolygone() {
  // Test de création d'un polygone avec des sommets spécifiques
  std::vector<Point2D<int>> sommets = {Point2D<int>(1, 2), Point2D<int>(3, 4),
                                       Point2D<int>(5, 6)};
  /** Création d'un polygone à partir de Sommets */
  Polygone<int> poly1(sommets);

  /** Afficher le polygone 1 */
  std::cout << "Affichage polygone 1" << std::endl;
  std::cout << poly1 << std::endl;

  /** Ajouter un nouveau point */
  Point2D<int> p1(9, 10);
  poly1.addPoint(p1);
  std::cout << "Afficher le polygone 1 après ajout du point 1" << std::endl;
  std::cout << poly1 << std::endl;

  /** Modifier point 1 et vérifier que le polynome n'a pas bougé */
  p1.setX(15);
  std::cout << "Après modification du point, le point du polydone doit être identique à avant" << std::endl;
  std::cout << poly1 << std::endl;

  /** Test de translation */
  poly1.translater(1, 2);
  std::cout << "Polygone 1 translaté" << std::endl;
  std::cout << poly1 << std::endl;
  
  /** Test de création d'un polygone vide */
  Polygone<int> poly2;
  assert(poly2.getSommets().empty());

  /** Test d'ajout de sommet */
  poly2.addPoint(Point2D<int>(1, 2));
  assert(poly2.getSommets().size() == 1);
  assert(poly2.getSommets()[0].getX() == 1);
  assert(poly2.getSommets()[0].getY() == 2);

  /** Test de translation,  */
  poly2.translater(2, 3);
  assert(poly2.getSommets()[0].getX() == 3);
  assert(poly2.getSommets()[0].getY() == 5);

  /** Test de copie de polygone, Le polygone doit afficher l'identique de la copie*/
  Polygone<int> poly3(poly1);
  std::cout << "Affichage du polygone 3 créé par recopiede polygone 1" << std::endl;
  std::cout << poly3 << std::endl;
}

int main(void){

  // Test création point
  // Point2D<int> point1(2, 3);
  // assert(point1.getX() == 2);
  // assert(point1.getY() == 3);

  // // Test création point avec coordonées par défaut
  // Point2D<int> point2;
  // assert(point2.getX() == 0);
  // assert(point2.getY() == 0);

  // // Test copie de point
  // Point2D<int> point3(1, 2);
  // Point2D<int> point4(point3);
  // assert(point4.getX() == 1);
  // assert(point4.getY() == 2);

  // // Test de translation
  // Point2D<int> point6(1, 2);
  // point6.translater(2, 3);
  // assert(point6.getX() == 3);
  // assert(point6.getY() == 5);

  // // Test surcharge opérateur
  // Point2D<int> point7(1, 2);
  // cout << point7 << endl;
  // affiche [1;2];

  testPolygone();

  //Test carte!
  Carte carte = Carte("./Parcelles.txt");
  cout << carte << endl;

  
  // std::vector<Point2D<int>> sommets = {Point2D<int>(1, 2), Point2D<int>(3, 4),
  //                                      Point2D<int>(5, 6)};
  // /** Création d'un polygone à partir de Sommets */
  // Polygone<int> poly1(sommets);
  // Za test_za(10, "toto", poly1, "terre", 100.0, 1);
  // std::cout << test_za<< std::endl;
  return 0;
}
