#include "labyrinthe.h"

int main() {
	Laby laby;
	char path[] = "inSmall.txt";

	initialiser(path, laby);
	afficher(laby);

	return 0;
}