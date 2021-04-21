#include"ligue.h"

void testLigue();
void testEquipe();
void testMatch();

int main(){
	//testEquipe();
	//testMatch();
	//testLigue();

	return 0;
}


void testEquipe(){
	T_equipe e1 = {"LOSC",14,8,3,3,37,24,0};
	T_equipe e2 = {"RCL",14,6,5,3,25,23,0};
	T_equipe e3 = {"OM",14,6,5,3,30,28,0};
	T_equipe *ptrEA,*ptrEB;
	printf("Avant MÀJ des points:\n");
	afficherEquipe(&e1,'V',1);
	miseAJourPoints(&e1);
	printf("\nAprès MÀJ des points:\n");
	afficherEquipe(&e1,'H',1);

	miseAJourPoints(&e2);
	miseAJourPoints(&e3);

	printf("\nMoyenne de points par match de %s: %f\n",e2.nom,moyPointsMatch(&e2));

	ptrEA = &e2; ptrEB = &e3;
	printf("\nComparaison entre %s et %s: ",ptrEA->nom,ptrEB->nom);
	int cmp = comparer(ptrEA,ptrEB);
	if(cmp>0)
		printf("%s est meilleure\n",ptrEA->nom);
	else if(cmp<0)
		printf("%s est meilleure\n",ptrEB->nom);
	else
		printf("ex aequo !\n");

}

void testMatch(){
	T_equipe e1 = {"LOSC",14,8,3,3,37,24,0};
	T_equipe e2 = {"RCL",14,6,5,3,25,23,0};
	T_equipe e3 = {"OM",14,6,5,3,30,28,0};
	miseAJourPoints(&e1); miseAJourPoints(&e2); miseAJourPoints(&e3);

	T_match m1 = {&e1,&e2,-1,-1};
	T_match m2 = {&e3,&e1,-1,-1};

	afficherMatch(&m1);
	afficherMatch(&m2);
	afficherEquipe(&e1,'H',1); afficherEquipe(&e2,'H',0); afficherEquipe(&e3,'H',0);

	jouer(&m1,2,1);
	jouerAleatoire(&m2);
	afficherMatch(&m1);
	afficherMatch(&m2);
	afficherEquipe(&e1,'H',1); afficherEquipe(&e2,'H',0); afficherEquipe(&e3,'H',0);
}

void testLigue(){
	T_ligue ligue;
	chargerEquipes("tableau.csv",&ligue);
	printf("Tableau après chargement...\n");
	afficherTableau(&ligue);
	simulation(&ligue,21);
	printf("Tableau après simulation...\n");
	afficherTableau(&ligue);
	printf("Tirage au sort:\n");
	//tirageAuSortDeterministe(&ligue);
	tirageAuSortAleatoire(&ligue);
	printf("\nAffichage depuis la file:\n");
	afficherFile(&ligue.matchsAJOUER);
	printf("\nSimulation de tous les matchs...\n");
	jouerTousLesMatchs(&ligue);
	printf("Tableau après simulation des matchs du tirage...\n");
	miseAJourClassement(&ligue);
	afficherTableau(&ligue);
	printf("Sauvegarde du tableau dans le répretoire courant...\n");
	sauvegarderTableau(&ligue);
}