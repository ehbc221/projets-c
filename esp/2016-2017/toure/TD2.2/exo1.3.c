#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char const *argv[])
{
    char texte[100], espace=' ', caractere=' ';
    int i=0, j=0, taille_texte=0, tautologie=1;
        printf("Saisissez un texte pour savoir si c'est une tautologie ou non : ");
        gets(texte);
        taille_texte = strlen(texte);
        for (i=0; i<taille_texte; i++) {
            if (texte[i] != espace) {
                caractere = texte[i];
                break;
            }
        }
        for (i=0; i<taille_texte; i++) {
            j=i+1;
            if (texte[i] == espace && texte[j] != caractere && texte[j] != (caractere+32)) {
                tautologie = 0;
                break;
            }
        }
        if (tautologie == 1) {
            printf("Ce texte est une tautologie.");
        }
        else {
            printf("Ce texte n'est pas une tautologie.");
        }
	return 0;
}
