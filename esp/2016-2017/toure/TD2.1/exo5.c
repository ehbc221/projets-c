/*
*   DIC 1 && Licence GL Langage C
*   TD & TP N° 2 1 2
*   Exercice 5
*/
#include<stdio.h>
int main() {
    int m=0, n=0, i, j, q=0, r, tab_m[25], tab_n[25], taille_m=0, taille_n=0, pgcd=1;
    // Ecrire un programme qui calcule le PGCD de deux nombres saisis par l’utilisateur en se servant de la méthode apprise au « collège », c'est-à-dire décomposition en produits de facteurs premiers.
	while(m <= 0) {
        printf("Donner le 1er nombre : ");
        scanf("%d", &m);
    }
    tab_m[taille_m] = 1;
    i = 2;
    q = m;
    while ( q != 1 && i<=q) {
        r = q%i;
        if (r == 0) {
            q /= i;
            taille_m ++;
            tab_m[taille_m] = i;
        }
        else {
            i++;
        }
    }
	while(n <= 0) {
        printf("Donner le 2nd nombre : ");
        scanf("%d", &n);
    }
    tab_n[taille_n] = 1;
    i = 2;
    q = n;
    while ( q != 1 && i<=q) {
        r = q%i;
        if (r == 0) {
            q /= i;
            taille_n ++;
            tab_n[taille_n] = i;
        }
        else {
            i++;
        }
    }
    // Décomposer le premier nombre et afficher sous cette forme :
    printf("\nDecomposition du 1er nombre : \n\n");
    printf("Nombre 1 = %d\n", m);
    for (i=0; i<=taille_m; i++) {
        if (i == 0) {
            printf("Nombre 1 = %d", tab_m[i]);
        }
        else {
            printf(" * %d", tab_m[i]);
        }
    }
    // Décomposer le deuxième nombre et l’afficher sous cette forme :
    printf("\n\nDecomposition du 2nd nombre : \n\n");
    printf("Nombre 2 = %d\n", n);
    for (i=0; i<=taille_n; i++) {
        if (i == 0) {
            printf("Nombre 2 = %d", tab_n[i]);
        }
        else {
            printf(" * %d", tab_n[i]);
        }
    }
    // Afficher le résultat du PGCD sous cette forme :
    printf("\n\nResultat du PGCD : \n\n");
    printf("PGCD (%d, %d) = 1 ", m, n);
    if (taille_m < taille_n) {
        for (i=1; i<taille_m; i++) {
            for (j=i; j<taille_n; j++) {
                if (tab_m[i] == tab_n[j]) {
                    printf("* %d", tab_m[i]);
                    pgcd *= tab_m[i];
                }
            }
        }
    }
    else {
        for (i=1; i<taille_n; i++) {
            for (j=i; j<taille_m; j++) {
                if (tab_n[i] == tab_m[j]) {
                    printf("* %d", tab_n[i]);
                    pgcd *= tab_n[i];
                }
            }
        }
    }
    printf("\nPGCD (%d, %d) = %d", m, n, pgcd);
    return 1;
}
