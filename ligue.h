#include"file/file.h"


#define NOMBRE_EQUIPES 16

typedef struct{
	T_equipe equipes[NOMBRE_EQUIPES];
	T_File matchsAJOUER; 
}T_ligue;

void chargerEquipes(char *chemin, T_ligue *ligue);
void simulation(T_ligue *ligue, int nbMatches);
void miseAJourClassement(T_ligue *);
void tirageAuSortDeterministe(T_ligue *);
void tirageAuSortAleatoire(T_ligue *);
void jouerTousLesMatchs(T_ligue *);
void sauvegarderTableau(const T_ligue *);
void afficherTableau(const T_ligue *);
