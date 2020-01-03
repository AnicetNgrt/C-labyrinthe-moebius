/**
 * @file vecteur3D.h
 * Projet DesprésGr109NougaretGr109
 * @author Antoine Després, Anicet Nougaret
 * @version 1 06/01/20
 * @brief Composant vecteur 3D
 * Structures de données et algorithmes
 */

#include <iostream>
#include <cassert>

struct Vec3 {
	int x;
	int y;
	int z;
};

Vec3 tuple(int x, int y, int z);
Vec3 from_list(const int crd[3]);
Vec3 inv_y(const Vec3& v, const int max_y);
void afficher(const Vec3& v);
bool egal(const Vec3& v1, const Vec3& v2);