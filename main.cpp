#include "Polygone.hpp"
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
  std::cout << poly1 << std::endl;

  /** Ajouter un nouveau point */
  Point2D<int> p1(9, 10);
  poly1.addPoint(p1);
  /** Afficher le polygone 1 après ajout du point 1 */
  std::cout << poly1 << std::endl;

  /** Modifier point 1 et vérifier que le polynome n'a pas bougé */
  p1.setX(15);
  std::cout << poly1 << std::endl;

  // Test de création d'un polygone vide
  Polygone<int> poly2;
  assert(poly2.getSommets().empty());

  // // Test d'ajout de sommet
  // poly2.addPoint(Point2D<int>(1, 2));
  // assert(poly2.getSommets().size() == 1);
  // assert(poly2.getSommets()[0].getX() == 1);
  // assert(poly2.getSommets()[0].getY() == 2);

  // // // Test de translation
  // poly2.translater(2, 3);
  // assert(poly2.getSommets()[0].getX() == 3);
  // assert(poly2.getSommets()[0].getY() == 5);

  // // Test de copie de polygone
  // Polygone<int> poly3(poly2);
  // // assert(poly3.getSommets() == poly2.getSommets());
}

int main() {
  std::cout << "Hello World!!!" << std::endl;
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

  return 0;
}
