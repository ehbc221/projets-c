/*
*   DIC 1 && Licence GL Langage C
*   TD & TP N° 2 1 2
*   Exercice 4
*/
#include<stdio.h>
void afficher_matrice(int m, int n, int **matrice);
void somme_matrice(int m1, int n1, int *matrice1, int m2, int n2, int *matrice2, int *matrice_resultat);
int main() {
    // Ecrire un programme dans lequel vous déclarez une matrice d’entiers de 3 lignes et 3 colonnes.
	int matrice[3][3] = {{0,0,0}, {1,1,1}, {2,2,2}};
	afficher_matrice(3, 3, matrice);
	return 1;
}
// Ecrire une fonction permettant d'afficher la matrice sous la forme habituelle des matrices.
void afficher_matrice(int m, int n, int **matrice) {
	int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
            printf("%d %d OK", m, n);
			printf("%d\t", matrice[i][j]);
		}
		printf("\n");
	}
}
//Ecrire une fonction permettant de faire la somme de deux matrices puis affiche la matrice résultante
void somme_matrice(int m1, int n1, int *matrice1, int m2, int n2, int *matrice2, int *matrice_resultat) {
	int i, j, lignes, colonnes;
    if (m1 >= m2) {
        lignes = m1;
    }
    else {
        lignes = m2;
    }
    if (n1 >= n2) {
        colonnes = n1;
    }
    else {
        colonnes = n2;
    }
    for (i=0; i < lignes; i++) {
        for (j=0; j < colonnes; j++) {
            if (m1 >= lignes && n1 >= colonnes) {
                matrice_resultat[i][j] += matrice1[i][j];
            }
            if (m2 >= lignes && n2 >= colonnes) {
                matrice_resultat[i][j] += matrice2[i][j];
            }
        }
    }
    for (i=0; i < lignes; i++) {
        for (j=0; j < colonnes; j++) {
                printf("%d\t", matrice_resultat[i][j]);
            }
        printf("\n");
        }
    }
}
