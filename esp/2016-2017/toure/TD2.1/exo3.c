/*
*   DIC 1 && Licence GL Langage C
*   TD & TP N° 2 1 2
*   Exercice 3
*/
#include<stdio.h>
void saisie_tableau(int n, int *tab);
void affichage_tableau(int n, int *tab);
int tableaux_identiques(int n1, int n2, int *tab1, int *tab2);
int tableaux_equivalents(int n1, int n2, int *tab1, int *tab2);
int main() {
    int n=0, taille_test=3, tab_test[3] = {1, 2, 3}, identiques, equivalents;
	while(n <= 0) {
        printf("Donner la taille du tableau : ");
        scanf("%d", &n);
    }
    int tab[n];
    printf("Saisissez les elements du tableau : \n");
    saisie_tableau(n, tab);
    printf("Voici les elements de votre tableau : \n");
    affichage_tableau(n, tab);
    printf("\n");
    identiques = tableaux_identiques(n, taille_test, tab, tab_test);
    if (identiques == 1) {
        printf("Les deux tableaux sont identiques.\n");
    }
    else {
        printf("Les deux tableaux ne sont pas identiques.\n");
    }
    equivalents = tableaux_equivalents(n, taille_test, tab, tab_test);
    if (equivalents == 1) {
        printf("Les deux tableaux sont equivalents.\n");
    }
    else {
        printf("Les deux tableaux ne sont pas equivalents.\n");
    }
	return 1;
}
// Ecrire une fonction qui permet de saisir un tableau d'entiers de taille N donné par l'utilisateur.
void saisie_tableau(int n, int *tab) {
	int i;
	for(i=0; i < n; i++) {
		printf("Element numero %d: ", i+1);
		scanf("%d", &tab[i]);
	}
}
// Ecrire une fonction qui permet d'afficher un tableau telle que les éléments soient séparés par une tabulation.
void affichage_tableau(int n, int *tab) {
	int i;
	for (i=0; i < n; i++){
		printf("%d\t", tab[i]);
	}
}
// Ecrire une fonction testant si deux tableaux sont identiques.
int tableaux_identiques(int n1, int n2, int *tab1, int *tab2) {
	int i, taille;
	if (n1 != n2) {
		return 0;
	}
	taille = n1;
	for (i=0; i < taille; i++) {
		if (tab1[i] != tab2[i]) {
			return 0;
		}
	}
	return 1;
}
// Ecrire une fonction qui teste si deux tableaux sont équivalents ; c'est-à-
// dire si les deux tableaux contiennent les mêmes éléments ; il n’est pas obligatoire que les deux tableaux aient la même taille.
int tableaux_equivalents(int n1, int n2, int *tab1, int *tab2) {
	int i, j, tampon, taille;
	if (n1 > n2) {
		taille = n2;
	}
	else{
		taille = n1;
	}
	for (i=0; i < taille; i++) {
		tampon = 0;
		for (j=0; j < taille; j++) {
			if (tab1[i] == tab2[j]) {
				tampon = 1;
				break;
			}
		}
		if (tampon == 0) {
			return 0;
		}
	}
	return 1;
}
