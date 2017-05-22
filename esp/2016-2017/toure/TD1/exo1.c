#include "stdio.h"
int main(int argc, char const *argv[])
{
	int x=0, y=0, somme, produit;
	printf("Donner le premier nombre: \n");
	scanf('%d', &x);
	printf("Donner le second nombre: \n");
	scanf('%d', &y);
	somme = x + y;
	produit = x * y;
	printf("La somme de ces deux nombres donne: %d\n", somme);
	printf("Le produit de ces deux nombres donne: %d\n", produit);
	return 0;
}