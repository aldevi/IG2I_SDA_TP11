# SDA1 - TP 11: Tirage au sort pour un tournoi de football #

L’objectif de ce TP est d’effectuer un tirage au sort pour déterminer les matchs à jouer pour une ligue de football constituée de 16 équipes. Celles-ci sont enregistrées sur un fichier texte qui sera lu au début du programme pour charger toutes les équipes.
Le programme est composé de trois modules (*équipe*, *match* et *ligue*) qu’il faudra développer pour pouvoir effectuer ce tirage au sort.
Le tirage au sort sera réalisé étape par étape en répondant aux différentes questions suivantes:

## Étape 1 ##

### Module [*équipe*](equipe.h) ###

Les champs de la structure du type équipe sont les mêmes sur le fichier [tableau.csv](tableau.csv) (qu’on chargera après). Ils représentent les principales données dont ce programme aura besoin.
Quatre fonctions à définir pour:

1. Calculer la différence de buts pour une équipe (buts marqués – buts concédés).
2. Calculer la moyenne de points par match d’une équipe.
3. Mettre à jour le nombre de points d’une équipe en fonction du nombre de victoires (3 pts) et de matchs nuls (1 pt).
4. Comparer deux équipes et retourner un entier strictement positif si la première équipe est meilleure que la deuxième, un entier strictement négatif si la deuxième est meilleure et zéro si les deux équipe ne peuvent être départagées. Une équipe (e1) est meilleure qu’une autre (e2) si:
	  1. e1 a un nombre de points strictement supérieur à celui de e2
	  2. e1 et e2 ont le même nombre de points et e1 a une meilleure différence de buts que e2
	  3. e1 et e2 ont le même nombre de points, la même différence de buts et l’attaque de e1 est meilleure que celle de e2
---

## Étape 2 ##

### Module [*match*](match.h) ###

Le type match se résume dans ce programme en quatre champs, pas la de s’encombrer avec des données (possession, cartons,...) qu’on va pas utiliser. Le plus important ici est de savoir le nombre (positif) de buts marqués par chaque équipe une fois le match joué. On procédera ici à deux simulations différentes:

1. En donnant en entrée le score du match (buts marqués par chaque équipe)
2. En générant aléatoirement le nombre de buts pour chaque équipe

Les données de chaque équipe devront être mis à jour en fonction du score du match.

### Module [*ligue*](ligue.h) ###

Les équipes présentes sur le fichier seront chargées dans le tableau des équipes. Le tirage au sort déterminera ensuite les matchs à jouer.

1. Charger d’abord les équipe depuis le fichier livré. Il est conseillé de laisser de coté une copie original du fichier. 

---
## Étape 3 ##
2. Le tableau des équipes est chargé avec des données nulles (0 matchs, 0 victoires,…). On va simuler le déroulement d’un certain nombre de matchs (n) en donnant aléatoirement à chaque équipe un nombre de victoires, de matchs nuls et de défaites de tel sorte à ce que le nombre de match joués soit égale à n.
3. Mettre le classement des équipes dans le bon ordre
4. Le tirage au sort va se faire selon la règle suivante: une équipe qui se trouve dans la première moitié du tableau doit affronter une équipe de la deuxième moitié. Deux versions/tirages seront proposé(e)s par le programme:
	1. Version déterministe: La première équipe affronte la dernière, la deuxième affronte l’avant-dernière,… la huitième joue face à la neuvième.
	2. Version aléatoire: On tire aléatoirement une équipe de la première moitié de ligue et son adversaire aléatoirement de la deuxième moitié. On répète la sélection tant qu’il y a des équipes pas encore tirées au sort (tant qu’on a pas constitué les huit matchs).

---

## Étape 4 (bonus) ##

1. Afficher le tableau de la ligue dans le bon ordre
2. Simuler les matchs du tirage au sort avec des scores aléatoires. Afficher chaque match une fois simulé. 
3. Ré-afficher le tableau de la ligue après le déroulement de tous les matchs.
4. Enregistrer le tableau dans un fichier (avec un nouveau nom), au même format  que le fichier original.
