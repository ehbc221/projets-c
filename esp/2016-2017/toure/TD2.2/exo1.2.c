#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char const *argv[])
{
    char texte[100], espace=' ';
    int i=0, j=0, taille_texte=0, superflus=1;
        printf("Saisissez un texte puis ses espaces superflus seront effaces :");
        gets(texte);
        taille_texte = strlen(texte);
        char tampon[taille_texte];
        for (i=0; i<taille_texte; i++) {
            if (texte[i] != espace || ((texte[i] == espace) && superflus == 0)) {
                superflus = 0;
                tampon[j] = texte[i];
                j++;
            }
        }
        tampon[j] = '\0';
        strcpy(texte, tampon);
        printf("Voici votre nouveau texte :%s\n", texte);
	return 0;
}
