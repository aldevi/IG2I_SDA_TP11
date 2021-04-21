#ifndef _EQUIPE_
#define _EQUIPE_

#include<stdio.h>

#define TAILLE_NOM 5

typedef struct{
	char nom[TAILLE_NOM];		// Nom abrégé de l'équipe, entre 2 et 4 lettres
	int j;						// Nombre de matchs joués
	int v;						// Nombre de matchs gagnés (victoires)
	int n;						// Nombre de matchs nuls
	int p;						// Nombre de matchs perdus
	int butsPour;				// Nombre de buts marqués
	int butsContre;				// Nombre de buts concédés
	int pts;					// Nombre de points
}T_equipe;

int diffButs(const T_equipe *);
float moyPointsMatch(const T_equipe *);
void miseAJourPoints(T_equipe *);
int comparer(const T_equipe *, const T_equipe *);
void afficherEquipe(const T_equipe *, char orientation, int entete);


#endif