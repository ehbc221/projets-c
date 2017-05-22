/************************************************
* Déclaration des bibliothèques nécessaires.    *
************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <tgmath.h>

/*****************************************************
* Déclaration et définition d'une liste d'entiers    *
*****************************************************/

typedef struct element
{
	int valeur;
	struct element *suivant;
} element;

typedef element *liste_elements;
typedef liste_elements *pliste;

/*****************************************************
* Traitement élémentaire sur les listes chainées.    *
*****************************************************/

// Définition de la constante ERREUR
#define ERREUR -1

/*************************************************************
* Quelques fonctions pour les futurs tests dans le main()    *
*************************************************************/

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

// Récupérer la valeur d'un élément
int valeurElement(liste_elements liste)
{
	if (liste == NULL) {
		return 0;
	}
	else {
		return liste->valeur;
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

// Récupérer le dernier élément d'une liste
liste_elements dernierElement(liste_elements liste)
{
	liste_elements fin_liste = liste;
	if (liste == NULL) {
		return NULL;
	}
	else {
		while (liste != NULL) {
			fin_liste = liste;
		}
		return fin_liste;
	}
}

// Récupérer le prédecesseur et le successeur d'un élément d'une liste
void recupererAvantEtApres(liste_elements liste1, liste_elements place, liste_elements* avant, liste_elements* apres)
{
	if (liste1 == place) {
		*avant = NULL;
		*apres = liste1->suivant;
	}
	else {
		while (liste1->suivant != NULL) {
			if (liste1->suivant == place) {
				*avant = liste1;
				*apres = liste1->suivant->suivant;
			}
			else {
				liste1 = liste1->suivant;
			}
		}
	}
}

// Créer un nouveau singleton de liste d'un seul élément
liste_elements creerListeSingleton(int valeur)
{
	liste_elements liste = malloc(sizeof(element));
	liste->valeur = valeur;
	liste->suivant = NULL;
	return liste;
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

// Minimum d'une liste (Algorithme itératif)
int minListeIte(liste_elements liste)
{
	if (liste == NULL) {
		return ERREUR;
	}
	else {
		int element_min = liste->valeur;
		while (liste->suivant != NULL) {
			liste = liste->suivant;
			if (liste->valeur < element_min) {
				element_min = liste->valeur;
			}
		}
		return element_min;
	}
}

/******************************************************
* Fonctions demandées dans l'éxercice 5 (PARTIE 1)    *
******************************************************/

/**************************************************************************************************
	1) Rechercher l’élément maximal d’une liste ** (Algorithme itératif & Algorithme récursif)    *
**************************************************************************************************/

// Algorithme itératif
int maxListeIte(liste_elements liste)
{
	if (liste == NULL) {
		return ERREUR;
	}
	else {
		int element_max = liste->valeur;
		while (liste->suivant != NULL) {
			liste = liste->suivant;
			if (liste->valeur > element_max) {
				element_max = liste->valeur;
			}
		}
		return element_max;
	}
}

// Algorithme récursif
int maxListeRec(liste_elements liste)
{
	if (liste == NULL) {
		return ERREUR;
	}
	int valeur = liste->valeur;
	if (liste->suivant == NULL) {
		return valeur;
	}
	int valeur_max = maxListeRec(liste->suivant);
	if (valeur > valeur_max) {
		return valeur;
	}
	return valeur_max;
}

/************************************
	2) Concaténer deux listes *		*
************************************/

void concat(liste_elements *liste1, liste_elements *liste2)
{
	if (*liste1 == NULL) {
		return;
	}
	if (*liste2 == NULL) {
		*liste1 = *liste2;
		return;
	}
	else {
		liste_elements temporaire = *liste1;
		while(temporaire->suivant != NULL) {
			temporaire = temporaire->suivant;
		}
		temporaire->suivant = *liste2;
	}
}

/********************************************************
	3) Extraire deux listes à partir d’une liste ***    *
********************************************************/

void separerListe(liste_elements *liste1, liste_elements *liste2, liste_elements *liste3)
{
	liste_elements l1=*liste1, l2=NULL, l3=NULL;
	if (l1 == NULL) {
		return;
	}
	if (l1->valeur >= 0) {
		l2 = *liste2 = *liste1;
	}
	else {
		l3 = *liste3 = *liste1;
	}
	while (l1->suivant != NULL) {
		l1 = l1->suivant;
		if (l1->valeur >= 0) {
			if (l2 == NULL)	{
				*liste2 = l2 = l1;
			}
			else {
				l2->suivant = l1;
				l2 = l2->suivant;
			}
		}
		else {
			if (l3 == NULL)	{
				*liste3 = l3 = l1;
			}
			else {
				l3->suivant = l1;
				l3 = l3->suivant;
			}
		}
	}
	l2->suivant = NULL;
	l3->suivant = NULL;
	*liste1 = NULL;
}

/***********************************************
	4) Permuter deux places d’une liste ***    *
***********************************************/

int permuterDeuxPlaces(liste_elements *liste, element *t, element *v)
{
	if (*liste == NULL) {
		if ((t == NULL) && (v == NULL)) {
			return 0;
		}
		else {
			return -1;
		}
	}
	else {
		if ((t == NULL) || (v == NULL)) {
			return -1;
		}
		liste_elements fin_liste = dernierElement(*liste);
		liste_elements fin_t = dernierElement(t);
		liste_elements fin_v = dernierElement(v);
		if (!((fin_t == fin_liste) && (fin_v == fin_liste))) {
			return -1;
		}
	}
	if (t == v) {
		return 0;
	}
	liste_elements temporaire = *liste;
	liste_elements avant_t, apres_t;
	recupererAvantEtApres(temporaire, t, &avant_t, &apres_t);
	temporaire = *liste;
	liste_elements avant_v, apres_v;
	recupererAvantEtApres(temporaire, v, &avant_v, &apres_v);
	if ((avant_v == t) || (avant_t == v)) {
		if (avant_v == t) {
			if (avant_t == NULL) {
				printf("case : .->[t]->[v]-> => .->[v]->[t]->\n");
				*liste = v;
			}
			else {
				printf("case : [..]->[t]->[v]-> => [..]->[v]->[t]->\n");
				avant_t->suivant = v;
			}
			v->suivant = t;
			t->suivant = apres_v;
		}
		else {
			if (avant_v == NULL) {
				printf("case : .->[v]->[t]-> => .->[t]->[v]->\n");
				*liste = t;
			}
			else {
				printf("case : [..]->[v]->[t]-> => [..]->[t]->[v]->\n");
				avant_v->suivant = t;
			}
			t->suivant = v;
			v->suivant = apres_t;
		}
	}
	else {
		if ((avant_t == NULL) || (avant_v == NULL)) {
			if (avant_t == NULL) {
				printf("case : .->[t]->[..]->[v]-> => .->[v]->[..]->[t]->\n");
				*liste = v;
				avant_v->suivant = t;
			}
			if (avant_v == NULL) {
				printf("case : .->[v]->[..]->[t]-> => .->[t]->[..]->[v]->\n");
				*liste = t;
				avant_t->suivant = v;
			}
		}
		else {
			printf("case : [..]->[t/v]->[..]->[v/t]-> => [..]->[v/t]->[..]->[t/v]->\n");
			avant_v = t;
			avant_t = v;
		}
		t->suivant = apres_v;
		v->suivant = apres_t;
	}
	return 0;
}

/************************************
	5) Supprimer des éléments **    *
************************************/

// Supprimer toutes les occurrences d’un élément donné (valeur)
liste_elements supprimerElements(liste_elements liste, int valeur)
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

// Ne laisser que les k premières occurrences de cet élément et on supprime les suivantes
liste_elements supprimerElementsInfK(liste_elements liste, int valeur, int k)
{
	int compteur=0;
	if (liste == NULL) {
		return NULL;
	}
	element* temporaire = liste;
	element* avant_dernier = liste;
	while(temporaire != NULL) {
		if (temporaire->valeur == valeur && compteur < k) {
			avant_dernier->suivant = temporaire->suivant;
			free(temporaire);
			temporaire = avant_dernier->suivant;
			compteur++;
		}
		else {
			avant_dernier = temporaire;
			temporaire = temporaire->suivant;
		}
	}
	return liste;
}

// Pour chaque élément de la liste, on ne laisse que sa première occurrence
liste_elements supprimerElementsSansPremier(liste_elements liste, int valeur)
{
	int compteur=0;
	if (liste == NULL) {
		return NULL;
	}
	element* temporaire = liste;
	element* avant_dernier = liste;
	while(temporaire != NULL) {
		if (temporaire->valeur == valeur && compteur < 1) {
			avant_dernier->suivant = temporaire->suivant;
			free(temporaire);
			temporaire = avant_dernier->suivant;
			compteur++;
		}
		else {
			avant_dernier = temporaire;
			temporaire = temporaire->suivant;
		}
	}
	return liste;
}

/********************************
	6) Inverser une liste **    *
********************************/

// (Algorithme itératif)
void inverserIte(liste_elements *liste)
{
	if (*liste == NULL) {
		return;
	}
	if ((*liste)->suivant == NULL) {
		return;
	}
	liste_elements precedent = *liste;
	liste_elements temporaire = precedent->suivant;
	if (temporaire->suivant == NULL) {
		temporaire->suivant = precedent;
		precedent->suivant = NULL;
		*liste = temporaire;
		return;
	}
	else {
		precedent->suivant = NULL;
	}
	liste_elements suivant;
	while (temporaire->suivant != NULL) {
		suivant = temporaire->suivant;
		temporaire->suivant = precedent;
		precedent = temporaire;
		temporaire = suivant;
	}
	temporaire->suivant = precedent;
	*liste = temporaire;
}

// (Algorithme récursif)
liste_elements * inverserRec(liste_elements* liste)
{
	if (*liste == NULL) {
		return NULL;
	}
	if ((*liste)->suivant == NULL) {
		return liste;
	}
	liste_elements tete = *liste;
	(*inverserRec(&(tete->suivant)))->suivant = tete;
	*liste = tete->suivant;
	tete->suivant = NULL;
	return &tete;
}

/******************************************************************
	7) Construire une liste à partir d’une source de données *    *
******************************************************************/

// Depuis un tableau
liste_elements nouvelleListeDepuisTab(int* contenu, int taille)
{
	if (taille < 1) {
		return creerListe();
	}
	liste_elements liste = creerListeSingleton(contenu[0]);
	liste_elements temporaire = liste;
	int i;
	for (i=1; i<taille; i++) {
		temporaire->suivant = creerListeSingleton(contenu[i]);
		temporaire = temporaire->suivant;
	}
	return liste;
}

// Depuis une autre liste
liste_elements nouvelleListeDepuisListe(liste_elements liste)
{
	if (liste == NULL) {
		return NULL;
	}
	liste_elements tete = liste;
	liste_elements temporaire = creerListeSingleton(liste->valeur);
	liste_elements nouvelle_liste = temporaire;
	while (liste->suivant != NULL && liste->suivant != tete)
	{
		liste = liste->suivant;
		temporaire->suivant = creerListeSingleton(liste->valeur);
		if (liste->suivant != NULL) {
			temporaire->suivant->suivant = temporaire;
		}
		temporaire = temporaire->suivant;
	}
	if (liste->suivant != NULL) {
		temporaire->suivant = nouvelle_liste;
	}
	return nouvelle_liste;
}

/*********************************************
	8) Refermer une liste sur elle-même *    *
*********************************************/

void listeLinVersCirc(pliste liste)
{
	if (liste == NULL) {
		return;
	}
	liste_elements temporaire = *liste;
	if (temporaire == NULL) {
		return;
	}
	while (temporaire->suivant != NULL) {
		temporaire = temporaire->suivant;
	}
	temporaire->suivant = *liste;
}

/***************************************************************
	9) Effectuer et retourner deux calculs sur une liste **    *
***************************************************************/

void produits(liste_elements liste, int *positif, int *negatif)
{
	if (liste != NULL) {
		int produit_positif = 1;
		int produit_positif_ok = 0;
		int produit_negatif = 1;
		int produit_negatif_ok = 0;
		int valeur = liste->valeur;
		if (valeur > 0) {
			produit_positif = valeur;
			produit_positif_ok = 1;
		}
		if (valeur < 0) {
			produit_negatif = valeur;
			produit_negatif_ok = 1;
		}
		while (liste->suivant != NULL) {
			liste = liste->suivant;
			valeur = liste->valeur;
			if (valeur > 0) {
				produit_positif *= valeur;
				produit_positif_ok = 1;
			}
			if (valeur < 0) {
				produit_negatif *= valeur;
				produit_negatif_ok = 1;
			}
		}
		if (produit_positif_ok) {
			*positif = produit_positif;
		}
		if (produit_negatif_ok) {
			*negatif = produit_negatif;
		}
	}
}

/***************************************
	10) Couper une liste en deux **    *
***************************************/

// A – à partir d’un pointeur sur le maillon qui devient tête de la seconde liste de sortie
int couperListeA(pliste pliste1, pliste pliste2, liste_elements point_de_coupure)
{
	liste_elements liste = *pliste1;
	if (point_de_coupure == NULL) {
		return 0;
	}
	if (point_de_coupure == liste) {
		*pliste1 = NULL;
		*pliste2 = liste;
		return 0;
	}
	while (liste->suivant != NULL && liste->suivant != point_de_coupure) {
		liste = liste->suivant;
	}
	if (liste->suivant == NULL) {
		return ERREUR;
	}
}

// B – juste devant le premier maillon contenant une valeur donnée x
int couperListeB(pliste pliste1, pliste pliste2, int x)
{
	liste_elements liste = *pliste1;
	if (x == liste->valeur) {
		*pliste1 = NULL;
		*pliste2 = liste;
		return 0;
	}
	while (liste->suivant != NULL && liste->suivant->valeur != x) {
		liste = liste->suivant;
	}
	if (liste->suivant == NULL) {
		return 0;
	}
}

// C – à partir de la k ième position (c’est-à-dire k maillons dans la première liste de sortie et le reste dans la seconde)
int couperListeC(pliste pliste1, pliste pliste2, unsigned k)
{
	liste_elements liste = *pliste1;
	if (k == 0) {
		*pliste1 = NULL;
		*pliste2 = liste;
		return 0;
	}
	while (liste->suivant != NULL && --k > 0) {
		liste = liste->suivant;
	}
	if (liste->suivant == NULL) {
		return ERREUR;
	}
}

// D – juste devant le maillon contenant la valeur minimale de la liste
int couperListeD(pliste pliste1, pliste pliste2)
{
	liste_elements liste = *pliste1;
	int min = minListeIte(liste);
	if (min == liste->valeur) {
		*pliste1 = NULL;
		*pliste2 = liste;
		return 0;
	}
	while (liste->suivant != NULL && liste->suivant->valeur != min) {
		liste = liste->suivant;
	}
}

// E – telles que les deux listes de sortie aient même longueur n, ou que la première soit de longueur n+1 et la seconde de longueur n
int couperListeE(pliste pliste1, pliste pliste2)
{
	liste_elements liste = *pliste1;
	int n = nombreElementsIte(liste);
	int point_de_coupure = (n % 2 == 0) ? n / 2 : n / 2 + 1;
	int status = 1;
	if (*pliste2 != NULL) {
		status = 2;
	}
	while (--point_de_coupure > 0) {
		liste = liste->suivant;
	}
}

/****************************************************
	11) Supprimer un sous-ensemble d’une liste *    *
****************************************************/

// A – un maillon sur deux, en commençant par la tête de liste
int removeAllA(pliste pliste1)
{
	if (pliste1 == NULL) {
		return ERREUR;
	}
	liste_elements liste = *pliste1;
	if (liste == NULL) {
		return 0;
	}
	*pliste1 = liste->suivant;
	free(liste);
	liste = *pliste1;
	liste_elements temporaire;
	while (liste != NULL && liste->suivant != NULL) {
		temporaire = liste->suivant;
		liste->suivant = temporaire->suivant;
		free(temporaire);
		liste = liste->suivant;
	}
	return 1;
}

// B – les maillons contenant des éléments impairs


// C – les maillons contenant des éléments pairs


// D – les maillons contenant des éléments supérieurs à un seuil donné


// E – les maillons contenant des éléments inférieurs à un seuil donné, d’une liste simplement chaînée (d’entiers)


/***********************************************************
	12) Saisir, enregistrer puis évaluer un polynôme***    *	
***********************************************************/

// Structure de données du polynôme
typedef struct terme
{
	long int coefficient;
	long int exposant;
	struct terme* termeSuivant;
} terme;
typedef terme *polynomial;

// Saisie du polynôme
void saisirPolynome(polynomial *polynome)
{
	*polynome = NULL;
	int taille = 1;
	char chaine_coefficients[11];
	char chaine_exposants[11];
	printf("Saisissez une serie de coefficient et exposants, puis terminez votre saisie par le coefficient ’fin’ :\n");
	printf("coefficient %d : ", taille);
	scanf("%s", chaine_coefficients);
	if (strcmp("fin", chaine_coefficients) == 0) {
		return;
	}
	printf("exponsant %d ", taille);
	scanf("%s", chaine_exposants);
	taille++;
	*polynome = malloc(sizeof(terme));
	polynomial temporaire = *polynome;
	temporaire->coefficient = atol(chaine_coefficients);
	temporaire->exposant = atol(chaine_exposants);
	temporaire->termeSuivant = NULL;
	printf("coefficient %d : ", taille);
	scanf("%s", chaine_coefficients);
	if (strcmp("fin", chaine_coefficients) == 0) {
		return;
	}
	polynomial avant;
	while (strcmp("fin", chaine_coefficients) != 0) {
		avant = temporaire;
		temporaire = temporaire->termeSuivant;
		printf("exponsant %d : ", taille);
		scanf("%s", chaine_exposants);
		taille++;
		temporaire = malloc(sizeof(terme));
		temporaire->coefficient = atol(chaine_coefficients);
		temporaire->exposant = atol(chaine_exposants);
		avant->termeSuivant = temporaire;
		printf("coefficient %d : ", taille);
		scanf("%s", chaine_coefficients);
	}
	temporaire->termeSuivant = NULL;
}

// Évaluation du polynôme
long evaluerPolynomial(polynomial polynome, long x)
{
	long resultat = 0;
	if (polynome == NULL) {
		return resultat;
	}
	resultat += (polynome->coefficient) * (powl(x, polynome->exposant));
	printf("Évaluation du premier terme : %ld\n", resultat);
	while (polynome->termeSuivant != NULL) {
		polynome = polynome->termeSuivant;
		long valeurTerme = (polynome->coefficient) * (powl(x, polynome->exposant));
		printf("Évaluation du terme suivant : %ld\n", valeurTerme);
		resultat += valeurTerme;
	}
	return resultat;
}

// Affichage d’un terme du polynôme
void afficherTerme(polynomial polynome)
{
	if (polynome == NULL) {
		return;
	}
	if (polynome->coefficient == 0) {
		return;
	}
	if (polynome->coefficient == 1) {
		if (polynome->exposant == 0) {
			printf("+1");
		}
		else if (polynome->exposant == 1) {
			printf("+X");
		}
		else {
			printf("+X^(%ld)", polynome->exposant);
		}
		return;
	}
	if (polynome->coefficient == -1) {
		if (polynome->exposant == 0) {
			printf("-1");
		}
		else if (polynome->exposant == 1) {
			printf("-X");
		}
		else {
			printf("-X^(%ld)", polynome->exposant);
		}
		return;
	}
	if (polynome->coefficient < 0) {
		if (polynome->exposant == 0) {
			printf("%ld", polynome->coefficient);
		}
		else if (polynome->exposant == 1) {
			printf("%ldX", polynome->coefficient);
		}
		else {
			printf("%ldX^(%ld)", polynome->coefficient, polynome->exposant);
		}
	}
	else {
		if (polynome->exposant == 0) {
			printf("+%ld", polynome->coefficient);
		}
		else if (polynome->exposant == 1) {
			printf("+%ldX", polynome->coefficient);
		}
		else {
			printf("+%ldX^(%ld)", polynome->coefficient, polynome->exposant);
		}
	}
}

// Affichage du polynôme
void afficherPolynome(polynomial polynome)
{
	if (polynome == NULL) {
		return;
	}
	printf("[");
	afficherTerme(polynome);
	while (polynome->termeSuivant != NULL) {
		polynome = polynome->termeSuivant;
		afficherTerme(polynome);
	}
	printf("]");
}

/*************************************************
* Test des fonctions précedemment définies. *    *
*************************************************/

void main(int argc, char const *argv[])
{
	/*
		Déclaration des variables
	*/
	liste_elements liste1, liste2, liste3, liste4, liste5, liste6, liste7, liste8, liste9, liste10, liste11, liste12, liste13, liste14, liste15, liste16, liste17, liste18, liste19, liste20, liste21, liste22, liste_test, element;
	struct element t, v;
	int i, j, valeur, k, valeur_max, positifs, negatifs, x;
	int tab_int[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	printf("%d\n", tab_int[10]);
	polynomial polynome;
	long resultat_polynome;

	/*
		Création et affichage de la liste1 initiale(vide)
	*/
	liste1 = creerListe();
	liste2 = creerListe();
	liste3 = creerListe();
	liste4 = creerListe();
	liste5 = creerListe();
	liste6 = creerListe();
	liste7 = creerListe();
	liste8 = creerListe();
	liste9 = creerListe();
	liste10 = creerListe();
	liste11 = creerListe();
	liste12 = creerListe();
	liste13 = creerListe();
	liste14 = creerListe();
	liste15 = creerListe();
	liste16 = creerListe();
	liste17 = creerListe();
	liste18 = creerListe();
	liste19 = creerListe();
	liste20 = creerListe();
	liste21 = creerListe();
	liste22 = creerListe();
	liste_test = creerListe();
	printf("\nLa liste1 au tout debut :\n");
	afficherListe(liste1);

	/*
		Remplissage et affichage des variables
	*/
	// liste1
	for(i = 10; i>=1; i--) {
		liste1 = insererEnTete(liste1,i);
	}
	for(i = 1; i<=10; i++) {
		liste1 = insererEnQueue(liste1,i);
	}
	liste1 = insererEnQueue(liste1,1);
	printf("\nListe1 apres le premier remplissage :\n");
	afficherListe(liste1);
	// liste2 & liste3
	for(i = 5; i>=1; i--) {
		liste2 = insererEnTete(liste2,i);
	}
	for(i = 10; i>=6; i--) {
		liste3 = insererEnTete(liste3,i);
	}
	printf("\nListe2 apres le premier remplissage :\n");
	afficherListe(liste2);
	printf("\nListe3 apres le premier remplissage :\n");
	afficherListe(liste3);
	// liste4
	for(i = -5; i<=5; i++) {
		liste4 = insererEnQueue(liste4,i);
	}
	printf("\nListe4 apres le premier remplissage :\n");
	afficherListe(liste4);
	// t & v
	t = *liste1;
	v = *liste1->suivant;
	// liste7
	for(i = 1; i<=5; i++) {
		for (j=0; j<=5; j++) {
			liste7 = insererEnQueue(liste7,j);
		}
	}
	printf("\nListe7 apres le premier remplissage :\n");
	afficherListe(liste7);
	// liste8
	for(i = 0; i<=10; i++) {
		liste8 = insererEnQueue(liste8,i);
	}
	printf("\nListe8 apres le premier remplissage :\n");
	afficherListe(liste8);
	// tab_int
	printf("Tableau apres premier remplissage : \n");
	for (i=0; i<=10; i++) {
		printf("%d\t", tab_int[i]);
	}
	printf("\n");
	// liste11
	for(i = -3; i<=4; i++) {
		liste11 = insererEnQueue(liste11,i);
	}
	printf("\nListe11 apres le premier remplissage :\n");
	afficherListe(liste11);

	/*
		1) Rechercher l’élément maximal d’une liste ** (Algorithme itératif & Algorithme récursif)
	*/
	printf("\n\n\n------------------------------------------------------------------------------------------\n");
	printf("1) Rechercher l’élément maximal d’une liste ** (Algorithme itératif & Algorithme récursif)\n");
	printf("------------------------------------------------------------------------------------------\n");
	valeur_max = maxListeIte(liste1);
	if (valeur_max != ERREUR) {
		printf("\n(Algorithme itératif) : La valeur maximale de la liste1 est %d.\n", valeur_max);
	}
	else {
		printf("\nCette liste est vide.\n");
	}
	valeur_max = maxListeRec(liste1);
	if (valeur_max != ERREUR) {
		printf("\n(Algorithme récursif) : La valeur maximale de la liste1 est %d.\n", valeur_max);
	}
	else {
		printf("\nCette liste est vide.\n");
	}

	/*
		Remplissage et affichage de la liste2 et liste3
	*/

	/*
		2) Concaténer deux listes *
	*/
	printf("\n\n\n---------------------------\n");
	printf("2) Concaténer deux listes *\n");
	printf("---------------------------\n");
	concat(&liste2, &liste3);
	printf("\nListe2 apres concatenation avec liste3 :\n");
	afficherListe(liste2);

	/*
		3) Extraire deux listes à partir d’une liste ***
	*/
	printf("\n\n\n------------------------------------------------\n");
	printf("3) Extraire deux listes à partir d’une liste ***\n");
	printf("------------------------------------------------\n");
	printf("liste4 : ");
	afficherListe(liste4);
	separerListe(&liste4, &liste5, &liste6);
	printf("\nListe4 apres extraction des 2 listes : liste5(positive) et liste6(negative) :\n");
	printf("liste5 : ");
	afficherListe(liste5);
	printf("liste6 : ");
	afficherListe(liste6);

	/*
		4) Permuter deux places d’une liste ***
	*/
	/*
	printf("\n\n\n---------------------------------------\n");
	printf("4) Permuter deux places d’une liste ***\n");
	printf("---------------------------------------\n");
	printf("liste1 : ");
	afficherListe(liste1);
	permuterDeuxPlaces(&liste1, &t, &v);
	printf("\nListe1 apres echange des noeuds 3 et 4 :\n");
	afficherListe(liste1);
	*/

	/*
		5) Supprimer des éléments **
	*/
	printf("\n\n\n----------------------------\n");
	printf("5) Supprimer des éléments **\n");
	printf("----------------------------\n");
	printf("liste7 : \n");
	afficherListe(liste7);
	valeur = 1;
	supprimerElements(liste7, valeur);
	printf("\nListe7 apres suppression de tous les %d :\n", valeur);
	afficherListe(liste7);
	k = 4;
	valeur = 3;
	supprimerElementsInfK(liste7, valeur, k);
	printf("\nListe7 apres suppression des %d premieres occurrences des %d :\n", k, valeur);
	afficherListe(liste7);
	valeur = 5;
	supprimerElementsSansPremier(liste7, valeur);
	printf("\nListe7 apres suppression des toutes les occurrences de %d, sauf la premiere :\n", valeur);

	/*
		6) Inverser une liste **
	*/
	printf("\n\n\n------------------------\n");
	printf("6) Inverser une liste **\n");
	printf("------------------------\n");
	printf("liste8 : \n");
	afficherListe(liste8);
	inverserIte(&liste8);
	printf("\nListe8 apres inversion (Algorithme itératif) :\n");
	afficherListe(liste8);
	inverserIte(&liste8);
	printf("\nInversion de cette derniere liste (Algorithme récursif) :\n");
	afficherListe(liste8);

	/*
		7) Construire une liste à partir d’une source de données *
	*/
	printf("\n\n\n----------------------------------------------------------\n");
	printf("7) Construire une liste à partir d’une source de données *\n");
	printf("----------------------------------------------------------\n");
	printf("Liste9 :\n");
	afficherListe(liste9);
	liste9 = nouvelleListeDepuisTab(&tab_int[0], 10);
	printf("\nListe9 a partir du tableau :\n");
	afficherListe(liste9);
	printf("\nListe10 :\n");
	afficherListe(liste10);
	liste10 = nouvelleListeDepuisListe(liste9);
	printf("\n\nListe10 a partir de la liste9 :\n");
	afficherListe(liste10);

	/*
		8) Refermer une liste sur elle-même *
	*/
	printf("\n\n\n-------------------------------------\n");
	printf("8) Refermer une liste sur elle-même *\n");
	printf("-------------------------------------\n");
	// Afficher cette liste provoquerait une boucle infinie


	/*
		9) Effectuer et retourner deux calculs sur une liste **
	*/
	printf("\n\n\n-------------------------------------------------------\n");
	printf("9) Effectuer et retourner deux calculs sur une liste **\n");
	printf("-------------------------------------------------------\n");
	printf("Liste11 :\n");
	afficherListe(liste11);
	printf("\nListe12 et liste13 apres produits respectifes des entiers positifs et celui negatifs :\n");
	produits(liste11, &positifs, &negatifs);
	printf("Produits des entiers positifs : %d\n", positifs);
	printf("Produits des entiers negatifs : %d\n", negatifs);

	/*
		10) Couper une liste en deux **
	*/
	printf("\n\n\n--------------------------------\n");
	printf("10) Couper une liste en deux **\n");
	printf("-------------------------------\n");
	printf("Liste12 :\n");
	afficherListe(liste11);
	printf("\nListe12 et liste13 apres produits respectifes des entiers positifs et celui negatifs :\n");
	produits(liste11, &positifs, &negatifs);

	/*
		11) Supprimer un sous-ensemble d’une liste *
	*/


	/*
		12) Saisir, enregistrer puis évaluer un polynôme***
	*/
	saisirPolynome(&polynome);
	afficherPolynome(polynome);
	x = 2;
	resultat_polynome = evaluerPolynomial(polynome, x);
	printf("\n\nLa valeur du polynome est : %ld\n", resultat_polynome);

}
