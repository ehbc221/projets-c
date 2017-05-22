#include "stdio.h"
int main(int argc, char const *argv[])
{
	float x=8.8, y=3.5, z=-5.2, valeur;
	printf("Exercice 2 :\n");
	// x + y + z
	printf("\n(a)\n");
	valeur = x + y + z;
	printf("x + y + z = %f\n", valeur);
	// 2 * y + 3 * ( x - z )
	printf("\n(b)\n");
	valeur = 2 * y + 3 * ( x - z );
	printf("2 * y + 3 * ( x - z ) = %f\n", valeur);
	// x / y
	printf("\n(c)\n");
	valeur = x / y;
	printf("x / y = %f\n", valeur);
	// x % y
	printf("\n(d)\n");
	valeur = (int) x % (int) y;
	printf("x %% y = %f\n", valeur);
	// x / (y + z)
	printf("\n(e)\n");
	valeur = x / (y + z);
	printf("x / (y + z) = %f\n", valeur);
	// (x /y) + z
	printf("\n(f)\n");
	valeur = (x /y) + z;
	printf("(x /y) + z = %f\n", valeur);
	// 2 * x / 3 * y
	printf("\n(g)\n");
	valeur = 2 * x / 3 * y;
	printf("2 * x / 3 * y = %f\n", valeur);
	// 2 * x / (3 * y)
	printf("\n(h)\n");
	valeur = 2 * x / (3 * y);
	printf("2 * x / (3 * y) = %f\n", valeur);
	return 0;
}
