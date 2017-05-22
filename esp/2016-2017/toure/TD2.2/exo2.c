#include <stdio.h>
#include<stdlib.h>
#include<string.h>
char crypter_caractere (int cle, char caractere, char *alphabet_majuscule, char *alphabet_minuscule);
char decrypter_code (int cle, char caractere, char *alphabet_majuscule, char *alphabet_minuscule);
int main(int argc, char const *argv[])
{
	char alphabet_majuscule[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", alphabet_minuscule[] = "abcdefghijklmnopqrstuvwxyz", texte_clair [100], texte_crypte [100], texte_decrypte [100];
	int cle=3, i=0, taille_texte=0;
	printf("Donnez votre texte clair : ");
	gets(texte_clair);
	taille_texte = strlen(texte_clair);
	strcpy(texte_crypte, texte_clair);
	for (i=0; i<taille_texte; i++) {
        texte_crypte[i] = crypter_caractere(cle, texte_crypte[i], alphabet_majuscule, alphabet_minuscule);
	}
	printf("Le texte crypte donne : %s\n", texte_crypte);
	strcpy(texte_decrypte, texte_crypte);
	for (i=0; i<taille_texte; i++) {
        texte_decrypte[i] = decrypter_code(cle, texte_decrypte[i], alphabet_majuscule, alphabet_minuscule);
	}
	printf("Le texte decrypte donne : %s\n", texte_decrypte);
	return 0;
}
char crypter_caractere(int cle, char caractere, char *alphabet_majuscule, char *alphabet_minuscule) {
    int position=0, i=0;
    char caractere_crypte;
    for (i=0; i<26; i++) {
        if (caractere == alphabet_majuscule[i] || caractere == alphabet_minuscule[i]) {
            position = i+cle;
            position = position%26;
            if (caractere == alphabet_majuscule[i]) {
                caractere_crypte = alphabet_majuscule[position];
            }
            else {
                caractere_crypte = alphabet_minuscule[position];
            }
            return caractere_crypte;
        }
    }
    return caractere;
}
char decrypter_code(int cle, char caractere_crypte, char *alphabet_majuscule, char *alphabet_minuscule) {
    int position=0, i=0, j=0;
    char caractere;
    for (i=0; i<26; i++) {
        if (caractere_crypte == alphabet_majuscule[i] || caractere_crypte == alphabet_minuscule[i]) {
            position = i-cle;
            position = position % 26;
            if (caractere_crypte == alphabet_majuscule[i]) {
                caractere = alphabet_majuscule[position];
            }
            else {
                caractere = alphabet_minuscule[position];
            }
            return caractere;
        }
    }
    return caractere_crypte;
}
