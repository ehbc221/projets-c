#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void afficherMenu();
void saisieTexteFin();
void saisieTexteSuperflus();

int main(int argc, char const *argv[]) {
	int numero_menu=-1, quitter=-1;
	while (quitter != 0) {
		numero_menu = -1;
		quitter = -1;
		afficherMenu();
		while (numero_menu != 0 && numero_menu != 1  && numero_menu != 2  && numero_menu != 3) {
			printf("\nTapez le numéro du programme que vous voulez éxecuter (tapez 0 pour quitter le programme) : ");
			scanf("%d", &numero_menu);
			if (numero_menu != 0 && numero_menu != 1  && numero_menu != 2  && numero_menu != 3) {
				printf("Veuillez saisir un numéro compris entre 0 et 3 SVP!\n");
			}
		}
		switch (numero_menu) {
			case 1 :
				system("clear");
				printf("\nVous avez choisi la partie numero 1.\n\n");
				saisieTexteFin();
				break;
			case 2 :
				system("clear");
				printf("\nVous avez choisi la partie numero 2.\n\n");
				saisieTexteSuperflus();
				break;
			case 3 :
				system("clear");
				printf("\nVous avez choisi la partie numero 3.\n\n");
				break;
			default :
				quitter = 0;
				printf("Vous avez chiosi de quitter le programme!\n");
				break;
		}
		numero_menu = -1;
		while (quitter != 0 && quitter != 1) {
			printf("\nTapez 0 pour quitter, oubien 1 pour continuer : ");
			scanf("%d", &quitter);
			if (quitter == 0)
			{
				printf("Vous avez choisi de quitter le programme!\n");
			}
			else{
				system("clear");
			}
			if (quitter != 0 && quitter != 1)
			{
				printf("Veuillez taper 0 ou 1 SVP!\n");
			}
		}
	}
	return 1;
}
void afficherMenu() {
	printf("Exercice 1\n");
	printf("Voici le menu :\n");
	printf("\n1 - Ecrire un programme permettant de saisir un texte terminé en tapant le mot « FIN ». Ensuite de parcourir le texte et de recenser le nombre d'espaces, de caractères alphabétiques, le nombre de chiffres, le nombre de ponctuations, le nombre de retour à la ligne, etc.\n");
	printf("\n2 - Ecrire un programme qui prend en entrée un texte puis efface tous les espaces superflus.Exemple : ' Ceci est une banane . ' Sera remplacé par : 'Ceci est une banane.'\n");
	printf("\n3 - Ecrire un programme qui prend en entrée un texte puis détermine si le texte est une tautologie ou pas. NB : Une tautologie est un texte dans lequel tous les mots commencent par une même lettre. Exemple de tautologie : ' Le lion lape le lait.'\n");
}
void saisieTexteFin() {
	char caractere, texte[100], alphabet_majuscule[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", alphabet_minuscule[] = "abcdefghijklmnopqrstuvwxyz", chiffres[] = "0123456789", ponctuations[] = ".,;:?!()[]«»-", espace=' ', retour_ligne='\n';
	int fin=0, valide=0, taille_texte=0, i=0, j=0, nbr_espaces=0, nbr_alphabets=0, nbr_chiffres=0, nbr_ponctuations=0, nbr_retours_ligne=-1;
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
}
void saisieTexteSuperflus() {
	char texte[100], espace=' ';
	int i=0, j=0, taille_texte=0, superflus=1;
	printf("Saisissez un texte puis ses espaces superflus seront effaces : ");
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
}
