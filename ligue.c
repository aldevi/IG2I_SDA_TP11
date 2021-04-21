#include"ligue.h"

#define TAILLEMAX_LIGNE 50

void chargerEquipes(char *chemin, T_ligue *ligue){
	
}

void simulation(T_ligue *ligue, int nbMatches){
	
}

void miseAJourClassement(T_ligue * ligue){
	
}

void tirageAuSortDeterministe(T_ligue *){
	
}

void tirageAuSortAleatoire(T_ligue *ligue){
	
}

void jouerTousLesMatchs(T_ligue *ligue){
	
}

void sauvegarderTableau(const T_ligue * ligue){
	
}

void afficherTableau(const T_ligue *ligue){
	afficherEquipe(&ligue->equipes[0],'H',1);
	for(int i=1;i<NOMBRE_EQUIPES;i++){
		printf("%d:",i+1);
		afficherEquipe(&ligue->equipes[i],'H',0);
	}
	printf("------------------\n");
}