#ifndef _MATCH_
#define _MATCH_


#include"equipe.h"
#include<stdlib.h>
#include<time.h>

#define MAXBUTS 5			//Nombre maximale de buts à affecter à 
							//une équipe en cas de résultat aléatoire
typedef struct{
	T_equipe *loc;			//Les locaux
	T_equipe *vis;			//Les visiteurs
	int butsLoc;			//Nombre de buts marqués par les locaux
	int butsVis;			//Nombre de buts marqués par les visiteurs
}T_match;

void jouer(T_match *, int, int);
void jouerAleatoire(T_match *);
void afficherMatch(const T_match *);

#endif