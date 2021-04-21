#include"match.h"

void jouer(T_match *m, int bLoc, int bVis){
}

void jouerAleatoire(T_match *m){

}

void afficherMatch(const T_match *m){
	if(m->butsVis < 0 || m->butsLoc <0)
		printf("\n%s # %s (match à jouer)\n",m->loc->nom,m->vis->nom);
	else
		printf("\n%s %d # %d %s\n",m->loc->nom,m->butsLoc,m->butsVis,m->vis->nom);
}