#include <stdio.h>
#include<stdlib.h>
#include<string.h>
char convertir_alphabet_majuscule (char caractere, char *alphabet_majuscule, char *alphabet_minuscule);
char crypter_caractere (char caractere, char *alphabet_majuscule, char *cle);
int verifier_alphabet (char *cle, char *alphabet_majuscule);
int main(int argc, char const *argv[])
{
	char alphabet_majuscule[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", alphabet_minuscule[] = "abcdefghijklmnopqrstuvwxyz", cle[27], texte_clair [100], texte_crypte [100];
	int i=0, taille_texte=0, validation=0;
	printf("Donnez votre texte clair : ");
	gets(texte_clair);
    taille_texte = strlen(texte_clair);
	for (i=0; i<taille_texte; i++) {
        texte_clair[i] = convertir_alphabet_majuscule(texte_clair[i], alphabet_majuscule, alphabet_minuscule);
	}
	while (validation == 0) {
        printf("Donnez la cle : ");
        gets(cle);
        for (i=0; i<26; i++) {
            cle[i] = convertir_alphabet_majuscule(cle[i], alphabet_majuscule, alphabet_minuscule);
        }
        validation = verifier_alphabet(cle, alphabet_majuscule);
        if (validation == 0) {
            printf("Cette cle n'est pas valide. Elle doit contenir tous les caracteres de l'alphabet (26 caracteres).\n");
        }
    }
	printf("\nVoici votre texte : %s\n", texte_clair);
	printf("Voici la cle : %s\n", cle);
	strcpy(texte_crypte, texte_clair);
	for (i=0; i<taille_texte; i++) {
        texte_crypte[i] = crypter_caractere(texte_crypte[i], alphabet_majuscule, cle);
	}
	printf("Le texte crypte donne : %s\n", texte_crypte);
	return 0;
}
char convertir_alphabet_majuscule (char caractere, char *alphabet_majuscule, char *alphabet_minuscule) {
    int i=0;
    for (i=0; i<26; i++) {
        if (caractere == alphabet_minuscule[i]) {
            caractere = alphabet_majuscule[i];
        }
    }
    return caractere;
}
char crypter_caractere(char caractere, char *alphabet_majuscule, char *cle) {
    int position=0, i=0;
    char caractere_crypte;
    for (i=0; i<26; i++) {
        if (caractere == alphabet_majuscule[i]) {
            position = i;
            caractere_crypte = cle[position];
            return caractere_crypte;
        }
    }
    return caractere;
}
int verifier_alphabet (char *cle, char *alphabet_majuscule) {
    int i=0, j=0, taille=0, verification=0;
    taille = strlen(cle);
    if (taille != 26) {
        return verification;
    }
    else {
        for (i=0; i<taille; i++) {
            verification = 0;
            for (j=0; j<taille; j++) {
                if (alphabet_majuscule[i] == cle[j]) {
                    verification = 1;
                    break;
                }
            }
            if (verification == 0) {
                return verification;
            }
        }
        return verification;
    }
}
