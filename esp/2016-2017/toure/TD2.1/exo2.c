/*
*   DIC 1 && Licence GL Langage C
*   TD & TP N° 2 1 2
*   Exercice 2
*/
#include<stdio.h>
int main() {
    // Ecrire un programme dans lequel vous déclarez et initialisez un tableau d'entiers avec ces nombres {0, 5, 3, 1, 2, 8, 1, 7}
	int tab[8] = {0,5,3,1,2,8,1,7};
	int i, j, tampon;
	printf("Voici le tableau initial :\n");
	for (i = 0; i < 8; i++) {
		printf("%d\t", tab[i]);
	}
	// Vous devez trier le tableau par ordre croissant puis par ordre décroissant.
	printf("\nVoici le tableau trie par ordre croissant :\n");
	for (i = 0; i < 8; i++) {
		for (j = i; j < 8; j++) {
			if (tab[i] > tab[j]) {
				tampon = tab[i];
				tab[i] = tab[j];
				tab[j] = tampon;
			}
		}
		printf("%d\t", tab[i]);
	}
	printf("\nVoici le tableau trie par ordre decroissant :\n");
	for (i = 0; i < 8; i++) {
		for (j = i; j < 8; j++) {
			if (tab[i] < tab[j]) {
				tampon = tab[i];
				tab[i] = tab[j];
				tab[j] = tampon;
			}
		}
		printf("%d\t", tab[i]);
	}
	return 1;
}
