#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char const *argv[])
{
	char caractere, texte[100], alphabet_majuscule[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", alphabet_minuscule[] = "abcdefghijklmnopqrstuvwxyz", chiffres[] = "0123456789", ponctuations[] = ".,;:?!()[]«»-", espace=' ', retour_ligne='\n';
	int fin=0, valide=0, taille_texte=0, i=0, j=0, nbr_espaces=0, nbr_alphabets=0, nbr_chiffres=0, nbr_ponctuations=0, nbr_retours_ligne=0;
	printf("Saisissez votre texte (taper FIN pour arreter la saisie) : \n");
	while (i < 100 && fin != 3) {
		caractere = getchar();
		texte[i] = caractere;
		taille_texte++;
		switch (caractere) {
			case 'F' :
				fin = 1;
				break;
			case 'I' :
				fin = (fin == 1) ? 2 : 0;
				break;
			case 'N' :
				fin = (fin == 2) ? 3 : 0;
				break;
			default :
				fin = 0;
				break;
		}
		i++;
	}
	for (i=0; i<taille_texte; i++) {
		// Nombre d'espaces
		if (texte[i] == espace) {
			nbr_espaces++;
			printf("Espace %c %c\n", texte[i], espace);
		}
		// Nombre de caracteres alphabetiques
		for (j=0; j<26; j++) {
			if (texte[i] == alphabet_majuscule[j] || texte[i] == alphabet_minuscule[j]) {
				nbr_alphabets++;
			printf("Alphabet %c\n", texte[i]);
			}
		}
		// Nombre de chiffres
		for (j=0; j<11; j++) {
			if (texte[i] == chiffres[j]) {
				nbr_chiffres++;
			printf("Chiffre %c %c\n", texte[i], chiffres[j]);
			}
		}
		// Nombre de ponctuatioons
		for (j=0; j<14; j++) {
			if (texte[i] == ponctuations[j]) {
				nbr_ponctuations++;
			printf("Ponctuation %c %c\n", texte[i], ponctuations[j]);
			}
		}
		// Nombre de retours à la ligne
		if (texte[i] == retour_ligne) {
			nbr_retours_ligne++;
		}
	}
	printf("Nombre d'espaces = %d\n", nbr_espaces);
	printf("Nombre de caracteres alphabetiques (sans prise en compte de FIN) = %d\n", nbr_alphabets-3);
	printf("Nombre de chiffres = %d\n", nbr_chiffres);
	printf("Nombre de ponctuations = %d\n", nbr_ponctuations);
	printf("Nombre de retours a la ligne = %d\n", nbr_retours_ligne);
	return 0;
}
