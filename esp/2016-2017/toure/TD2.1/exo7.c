/*
*   DIC 1 && Licence GL Langage C
*   TD & TP N° 2 1 2
*   Exercice 7
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main() {
    char formule[100], *suite_formule=NULL, operandes[11], *expressions[50], operandes_trouvees[50];
    int i, j, taille, resultat=0, tampon=1, nombre_operandes_trouvees=0;
    operandes[0] = '+';
    operandes[1] = '-';
    operandes[2] = '*';
    operandes[3] = '/';
    operandes[4] = '(';
    operandes[5] = ')';
    operandes[6] = 'e';
    operandes[7] = 'r';
    operandes[8] = 'c';
    operandes[9] = 's';
    operandes[10] = 't';
    printf("%c", operandes[10]);
    printf("Tapez votre formule : ");
    scanf("%s", formule);
    taille = strlen(formule);
    while (tampon == 1) {
        for (i=4; i<5; i++) {
            suite_formule = strchr(formule, operandes[i]);
            if (suite_formule != NULL) {
                for (j=5; j<6; j++) {
                    suite_formule = strchr(formule, operandes[i]);
                    if (suite_formule != NULL) {

                    }
                }
                nombre_operandes_trouvees++;
                operandes_trouvees[nombre_operandes_trouvees] = suite_formule[0];
            }
        }
    }
    printf("%d Le resultat de %s est : %d", taille, formule, resultat);
    return 1;
}
