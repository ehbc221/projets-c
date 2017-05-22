#include "stdio.h"
int main(int argc, char const *argv[])
{
	char c1='E', c2='?', c3=' ', valeur;
	printf("Exercice 3 :\n");
	// c1
	printf("\n(a)\n");
	valeur = c1;
	printf("c1 = %c\n", valeur);
	// c1 - c2 + c3
	printf("\n(b)\n");
	valeur = c1 - c2 + c3;
	printf("c1 - c2 + c3 = %c\n", valeur);
	// c2 - 2
	printf("\n(c)\n");
	valeur = c2 - 2;
	printf("c2 - 2 = %c\n", valeur);
	// c2 - ' 2 '
	printf("\n(d)\n");
	valeur = c2 - ' 2 ';
	printf("c2 - ' 2 ' = %c\n", valeur);
	// c3 + '#'
	printf("\n(e)\n");
	valeur = c3 + '#';
	printf("c3 + '#' = %c\n", valeur);
	// c1 % c3
	printf("\n(f)\n");
	valeur = c1 % c3;
	printf("c1 %% c3 = %c\n", valeur);
	// ' 2 ' + ' 2 '
	printf("\n(g)\n");
	valeur = ' 2 ' + ' 2 ';
	printf("' 2 ' + ' 2 ' = %c\n", valeur);
	// ( c1 / c2) * c3
	printf("\n(h)\n");
	valeur = ( c1 / c2) * c3;
	printf("( c l / c2) * c3 = %c\n", valeur);
	// 3 * c2
	printf("\n(i)\n");
	valeur = 3 * c2;
	printf("3 * c2 = %c\n", valeur);
	// ' 3 ' * c2
	printf("\n(j)\n");
	valeur = ' 3 ' * c2;
	printf("' 3 ' * c2 = %c\n", valeur);
	return 0;
}
