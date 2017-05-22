#include <stdio.h>
int main(int argc, char const *argv[])
{
	int a=8, b=3, c=-5, valeur;
	printf("Exercice 1 :\n");
	// a + b + c
	printf("\n(a)\n");
	valeur = a + b + c;
	printf("a + b + c = %d\n", valeur);
	// 2 * b + 3 * ( a - c )
	printf("\n(b)\n");
	valeur = 2 * b + 3 * ( a - c );
	printf("2 * b + 3 * ( a - c ) = %d\n", valeur);
	// a / b
	printf("\n(c)\n");
	valeur = a / b;
	printf("a / b = %d\n", valeur);
	// a % b
	printf("\n(d)\n");
	valeur = a % b;
	printf("a %% b = %d\n", valeur);
	// a / c
	printf("\n(e)\n");
	valeur = a / c;
	printf("a / c = %d\n", valeur);
	// a % c
	printf("\n(f)\n");
	valeur = a % c;
	printf("a %% c = %d\n", valeur);
	// a * b / c
	printf("\n(g)\n");
	valeur = a * b / c;
	printf("a * b / c = %d\n", valeur);
	// a * (b / c)
	printf("\n(h)\n");
	valeur = a * (b / c);
	printf("a * (b / c) = %d\n", valeur);
	// (a * c) % b
	printf("\n(i)\n");
	valeur = (a * c) % b;
	printf("(a * c) %% b = %d\n", valeur);
	// a * (c % b)
	printf("\n(j)\n");
	valeur = a * (c % b);
	printf("a * (c %% b) = %d\n", valeur);
	return 0;
}
