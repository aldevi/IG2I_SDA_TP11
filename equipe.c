#include "equipe.h"

int diffButs(const T_equipe *e)
{
	return e->butsPour - e->butsContre;
}

float moyPointsMatch(const T_equipe *e)
{
	return e->pts * 1.0 / e->j * 1.0;
}

void miseAJourPoints(T_equipe *e)
{
	int new_score = 0;
	new_score += e->v * 3;
	new_score += e->n * 1;

	e->pts = new_score;
}

int comparer(const T_equipe *e1, const T_equipe *e2)
{
	if (e1->pts > e2->pts)
	{
		return 1;
	}
	else if (e1->pts < e2->pts)
	{
		return -1;
	}

	if (diffButs(e1) > diffButs(e2))
	{
		return 1;
	}
	else if (diffButs(e1) < diffButs(e2))
	{
		return -1;
	}

	if (e1->butsPour > e2->butsPour)
	{
		return 1;
	}
	else if (e1->butsPour < e2->butsPour)
	{
		return -1;
	}

	return 0;
}

/**
 *
*/
void afficherEquipe(const T_equipe *e, char orientation, int entete)
{
	if (orientation == 'H' || orientation == 'h')
	{
		if (entete == 1)
			printf("NOM\tpts\tJ\tG\tN\tP\tp\tc\t+/-\n");
		printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", e->nom, e->pts, e->j, e->v, e->n, e->p, e->butsPour, e->butsContre, diffButs(e));
	}
	else if (orientation == 'V' || orientation == 'v')
	{
		if (entete == 1)
			printf("Nom d'équipe:\t%s\nPoints:\t\t%d\nJoués:\t\t%d\nGagnés:\t\t%d\nNuls:\t\t%d\nPerdus:\t\t%d\nButs pour:\t%d\nButs contre:\t%d\nDiff. de buts:\t%d\n",
				   e->nom, e->pts, e->j, e->v, e->n, e->p, e->butsPour, e->butsContre, diffButs(e));
		else
			printf("%s\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", e->nom, e->pts, e->j, e->v, e->n, e->p, e->butsPour, e->butsContre, diffButs(e));
	}
	else
		printf("Erreur d'affichage de l'équipe %s: mauvais paramètre(s) !\n", e->nom);
}