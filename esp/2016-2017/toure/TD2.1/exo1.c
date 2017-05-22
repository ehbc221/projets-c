/*
*   DIC 1 && Licence GL Langage C
*   TD & TP N° 2 1 2
*   Exercice 1
*/
#include<stdio.h>
int main() {
    // Ecrire un programme dans lequel vous déclarez et initialisez un tableau d'entiers avec ces nombres {0, 5, 3, 0, 0, 2, 8, 1, 0, 7}.
	int tab[10] = {0, 5, 3, 0, 0, 2, 8, 1, 0, 7};
	int taille = 10;
	int i, j;
	printf("Tableau initial: \n");
	for (i = 0; i < taille; i++) {
		printf("%d\t", tab[i]);
	}
	//Vous parcourez le tableau puis vous affichez les indices des cases contenant 0.
	printf("\nIndices des cases contenant 0: \n");
	for (i = 0; i < taille; i++) {
		if (tab[i] == 0){
			printf("%d\t", i);
		}
	}
	//Ensuite vous tasserez le tableau et éliminerez toutes les cases contenant 0.
	printf("\nTableau tasse avec les 0 elimines: \n");
	for (i = 0; i < taille; i++) {
		j = 0;
		if (tab[i] != 0) {
			tab[j] = tab[i];
			printf("%d\t", tab[j]);
		}
	}
	return 1;
}
