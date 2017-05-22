/*
*   DIC 1 && Licence GL Langage C
*   TD & TP N° 2 1 2
*   Exercice 6
*/
#include<stdio.h>
void affichage_sequences_tableau(int n, int *tab);
int main() {
    int n=10, tab_test[10] = {2, 3, 1, 4, 5, 3, 2, 1, 6, 7};
    affichage_sequences_tableau(n, tab_test);
    return 1;
}
// Ecrivez une fonction qui, à partir d'un tableau T de N entiers, affiche toutes les séquences strictement croissantes, de ce tableau, ainsi que le nombre de séquences.
void affichage_sequences_tableau(int n, int *tab) {
    int i, precedent=tab[0], tampon=0, sequence=0;
    if (n <= 1 ) {
        printf("Il n'y a pas de sequences strictement croissantes.");
    }
    else {
        printf("Voici les sequences strictement croissantes :");
        for (i=1; i<n; i++) {
            if (tab[i] > precedent) {
                if (tampon == 0) {
                    sequence += 1;
                    printf("\nSequence N %d : %d - %d", sequence, precedent, tab[i]);
                    tampon = 1;
                }
                else {
                    printf(" - %d", tab[i]);
                }
            }
            else {
                tampon = 0;

            }
            precedent = tab[i];
        }
    }
}
