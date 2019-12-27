#include "vecteur3D.h"

Vec3 tuple(int x, int y, int z) {
	Vec3 v; v.x = x; v.y = y; v.z = z;
	return v;
}

Vec3 from_list(const int crd[3]) {
	Vec3 nouv;
	nouv.x = crd[0];
	nouv.y = crd[1];
	nouv.z = crd[2];
	return nouv;
}

void afficher(const Vec3& v) {
	std::cout << "(" << v.x << "," << v.y << "," << v.z+1 << ")";
}

bool egal(const Vec3& v1, const Vec3& v2) {
	bool x_egal = v1.x == v2.x;
	bool y_egal = v1.y == v2.y;
	bool z_egal = v1.z == v2.z;
	return x_egal && y_egal && z_egal;
}