#include "match.h"

void jouer(T_match *m, int bLoc, int bVis){
	
	// On met à jour les données du match
	m->butsLoc = bLoc;
	m->butsVis = bVis;

	// On met à jour les données des équipes
	// Local
	m->loc->j += 1; // maj : Nombre de matchs joués
	m->loc->butsPour += bLoc; // maj : Nombre de buts marqués
	m->loc->butsContre += bVis; // maj : Nombre de buts concédés

	// Visiteur
	m->vis->j += 1; // maj : Nombre de matchs joués
	m->vis->butsPour += bVis; // maj : Nombre de buts marqués
	m->vis->butsContre += bLoc; // maj : Nombre de buts concédés

	// Mise à jour victoire et défaite

	// Les locaux ont gagné le match
	if (bLoc > bVis) {
		m->loc->v += 1; // maj : Nombre victoire local
		m->vis->p += 1; // maj : Nombre défaite visiteur
	}
	// Il y a égalité
	else if (bLoc == bVis){
		m->loc->n += 1; // maj : Nombre match nul local
		m->vis->n += 1; // maj : Nombre match nul visiteur
	}
	// Les locaux ont perdu
	else if (bLoc < bVis){
		m->loc->p += 1; // maj : Nombre défaite local
		m->vis->v += 1; // maj : Nombre victoire visiteur
	}

}

void jouerAleatoire(T_match *m){
	srand(time(NULL));
	int bLoc = rand() % MAXBUTS;
	int bVis = rand() % MAXBUTS;

	jouer(m, bLoc, bVis);
}

void afficherMatch(const T_match *m){
	if(m->butsVis < 0 || m->butsLoc <0)
		printf("\n%s # %s (match à jouer)\n",m->loc->nom,m->vis->nom);
	else
		printf("\n%s %d # %d %s\n",m->loc->nom,m->butsLoc,m->butsVis,m->vis->nom);
}