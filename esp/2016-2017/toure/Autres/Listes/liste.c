/************************************
*   Author : El Hadj Babacar Cissé  *
*   Mail : ehbc221@gmail.com        *
*   Date : 18/03/2016, 19:11        *
************************************/

/********************************************
* Déclaration des bibliothèques nécessaires. *
********************************************/

#include <stdio.h>
#include <stdlib.h>

/***************************************************
* Déclaration et définition d'une liste d'entiers  *
***************************************************/

typedef struct element
{
	int valeur;
	struct element* suivant;
} element;

typedef element* liste_elements;

/**************************************************
* Traitement élémentaire sur les listes chainées. *
**************************************************/

// Définition de la constante ERREUR
#define ERREUR -1

// Créer une liste vide
liste_elements creerListe()
{
	liste_elements nouvelle_liste = NULL;
	return nouvelle_liste;
}

// Ajouter un élément en tête de liste
liste_elements insererEnTete(liste_elements liste, int valeur)
{
	element* nouvel_element = malloc(sizeof(element));
	nouvel_element->valeur = valeur;
	nouvel_element->suivant = liste;
	return nouvel_element;
}

// Ajouter un élément en fin de liste
liste_elements insererEnQueue(liste_elements liste, int valeur)
{
	element* nouvel_element = malloc(sizeof(element));
	nouvel_element->valeur = valeur;
	nouvel_element->suivant = NULL;
	if (liste == NULL) {
		return nouvel_element;
	}
	element* temporaire = liste;
	while(temporaire->suivant != NULL) {
		temporaire = temporaire->suivant;
	}
	temporaire->suivant = nouvel_element;
	return liste;
}

// Afficher une liste
void afficherListe(liste_elements liste)
{
	element* temporaire = liste;
	if(temporaire != NULL) {
	while(temporaire->suivant != NULL) {
		printf("|%d|->", temporaire->valeur);
		temporaire = temporaire->suivant;
	}
	printf("|%d|->|NIL|\n", temporaire->valeur);
	}
	else {
		printf("Cette liste est vide.\n");
	}
}

// Vérifier si une liste est vide ou non
int estVide(liste_elements liste)
{
	if (liste == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

// Supprimer un élément en tête de liste
liste_elements supprimerEnTete(liste_elements liste)
{
	if (liste != NULL) {
		liste_elements aRenvoyer = liste->suivant;
		free(liste);
		return aRenvoyer;
	}
	else {
		return NULL;
	}
}

// Supprimer un élément en fin de liste
liste_elements supprimerEnQueue(liste_elements liste)
{
	if (liste == NULL)
	{
		return NULL;
	}
	if (liste->suivant == NULL)
	{
		free(liste);
		return NULL;
	}
	element* temporaire = liste;
	element* avant_dernier = liste;
	while(temporaire->suivant != NULL) {
		avant_dernier = temporaire;
		temporaire = temporaire->suivant;
	}
	avant_dernier->suivant = NULL;
	free(temporaire);
	return liste;
}

// Rechercher un élément dans la liste
liste_elements rechercherElement(liste_elements liste, int valeur)
{
	if (liste == NULL)
	{
		return NULL;
	}
	element* temporaire = liste;
	while(temporaire != NULL) {
		if (temporaire->valeur == valeur) {
			return temporaire; 
		}
		temporaire = temporaire->suivant;
	}
	return NULL;
}

// Rechercher le i-ème élément de la liste
liste_elements rechercherPosition_i(liste_elements liste, int indice)
{
	int i;
	for (int i=0; i<indice && liste != NULL; ++i) {
		liste = liste->suivant;
	}
	if (liste == NULL) {
		return NULL;
	}
	else {
		return liste;
	}
}

// Compter le nombre d'occurrences de l'élément k dans la liste
int nombreOccurences(liste_elements liste, int valeur)
{
	int compteur=0;
	if (liste == NULL) {
		return compteur;
	}
	while((liste = rechercherElement(liste, valeur)) != NULL) {

		compteur++;
		liste = liste->suivant;
	}
	return compteur;
}

// Récupérer la valeur d'un élément
int valeurElement(liste_elements liste)
{
	if (liste == NULL) {
		return ERREUR;
	}
	else {
		return liste->valeur;
	}
}

// Compter le nombre d'éléments d'une liste chaîné (Algorithme itératif)
int nombreElementsIte(liste_elements liste)
{
	int compteur=0;
	while(liste != NULL) {
		compteur++;
		liste = liste->suivant;
	}
	return compteur;
}

// Compter le nombre d'éléments d'une liste chaîné (Algorithme récursif)
int nombreElementsRec(liste_elements liste)
{
	if (liste == NULL) {
		return 0;
	}
	else {
		return nombreElementsRec(liste->suivant)+1;
	}
}

// Supprimer le premier élément "valeur" qu'on trouve dans la liste
liste_elements supprimerElement(liste_elements liste, int valeur)
{
	element* temporaire = liste;
	element* avant_dernier = liste;
	while(temporaire != NULL){
		if(temporaire->valeur == valeur) {
			avant_dernier->suivant = temporaire->suivant;
			free(temporaire);
			break;
		}
		else {
			avant_dernier = temporaire;
			temporaire = temporaire->suivant;
		}
	}
	return liste;
}

// Supprimer tous les éléments ayant une certaine valeur (Algorithme itératif)
liste_elements supprimerElementsIte(liste_elements liste, int valeur)
{
	if (liste == NULL) {
		return NULL;
	}
	element* temporaire = liste;
	element* avant_dernier = liste;
	while(temporaire != NULL) {
		if (temporaire->valeur == valeur) {
			avant_dernier->suivant = temporaire->suivant;
			free(temporaire);
			temporaire = avant_dernier->suivant;
		}
		else {
			avant_dernier = temporaire;
			temporaire = temporaire->suivant;
		}
	}
	return liste;
}

// Supprimer tous les éléments ayant une certaine valeur (Algorithme récursif)
liste_elements supprimerElementsRec(liste_elements liste, int valeur)
{
	if (liste == NULL) {
		return NULL;
	}
	if (liste->valeur == valeur) {
		element* temporaire = liste->suivant;
		free(liste);
		temporaire = supprimerElementsRec(temporaire, valeur);
		return temporaire;
	}
	else {
		liste->suivant = supprimerElementsRec(liste->suivant, valeur);
		return liste;
	}
}

// Effacer complètement une liste chaînée de la mémoire (Algorithme itératif)
liste_elements effacerListeIte(liste_elements liste)
{
	element* temporaire = liste;
	element* avant_dernier;
	while(temporaire != NULL) {
		avant_dernier = temporaire->suivant;
		free(temporaire);
		temporaire = avant_dernier;
	}
	return NULL;
}

// Effacer complètement une liste chaînée de la mémoire (Algorithme récursif)
liste_elements effacerListeRec(liste_elements liste)
{
	if (liste == NULL) {
		return NULL;
	}
	else {
		element* temporaire;
		temporaire = liste->suivant;
		free(liste);
		return effacerListeRec(temporaire);
	}
	return NULL;
}

/********************************************
* Test des fonctions précedemment définies. *
********************************************/

void main(int argc, char const *argv[])
{
	liste_elements liste, liste2;
	int i, element, indice, occurences, contient, compteur;
	liste = creerListe();
	printf("\nLa liste au tout debut :\n");
	afficherListe(liste);
	for(i = 10; i>=1; i--) {
		liste = insererEnTete(liste,i);
	}
	for(i = 1; i<=10; i++) {
		liste = insererEnQueue(liste,i);
	}
	printf("\nListe apres le premier remplissage :\n");
	afficherListe(liste);
	liste = supprimerEnTete(liste);
	printf("\nListe apres suppression du premier élément :\n");
	afficherListe(liste);
	liste = supprimerEnQueue(liste);
	printf("\nListe apres suppression du dernier élément :\n");
	afficherListe(liste);
	printf("\nListe apres ajout de 100 a la fin : \n");
	liste = insererEnQueue(liste,100);
	afficherListe(liste);
	printf("\nSaisissez l'element que vous recherchez : ");
	scanf("%d", &element);
	liste2 = rechercherElement(liste, element);
	if (liste2 != NULL) {
		printf("L'element %d existe bien dans la liste.\n", element);
	}
	else {
		printf("L'element %d n'existe pas dans la liste.\n", element);
	}
	printf("\nSaisissez un nombre pour savoir s'il existe un element a cet indice ou pas : ");
	scanf("%d", &indice);
	liste2 = rechercherPosition_i(liste, indice);
	element = valeurElement(liste2);
	if (element != ERREUR) {
		printf("A la position %d se trouve l'element %d.\n", indice, element);
	}
	else {
		printf("Aucun element n'existe a la position %d.\n", indice);
	}
	compteur = nombreElementsIte(liste);
	printf("\nLa liste contient %d elements (Algorithme itératif).\n", compteur);
	compteur = nombreElementsRec(liste);
	printf("\nLa liste contient %d elements (Algorithme récursif).\n", compteur);
	printf("\nSaisissez l'element a supprimer : ");
	scanf("%d", &element);
	liste = supprimerElement(liste, element);
	printf("\nListe apres suppression de la premiere occurence de %d :\n", element);
	afficherListe(liste);
	liste = supprimerElementsIte(liste, 6);
	printf("\nListe apres suppression de tous les 6 (Algorithme itératif) :\n");
	afficherListe(liste);
	liste = supprimerElementsRec(liste, 4);
	printf("\nListe apres suppression de tous les 4 (Algorithme récursif) :\n");
	afficherListe(liste);
	printf("\nDonnez l'element dont vous voulez connaitre le nombre d'occurences : ");
	scanf("%d", &element);
	occurences = nombreOccurences(liste, element);
	printf("\nNombre d'occurences de %d est : %d fois.\n", element, occurences);
	printf("\nListe : \n");
	afficherListe(liste);
	liste = effacerListeIte(liste);
	printf("liste apres suppression de tous les elements (Algorithme itératif) :\n");
	afficherListe(liste);
	for(i = 1; i<=10; i++) {
		liste2 = insererEnQueue(liste2,i);
	}
	printf("\nListe2 : \n");
	afficherListe(liste2);
	liste2 = effacerListeRec(liste2);
	printf("liste2 apres suppression de tous les elements (Algorithme récursif) :\n");
	afficherListe(liste2);
}
