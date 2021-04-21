#include "file.h" 
#include<limits.h>

void initFile(T_File *ptrF){ //mettre Tete et Queue à -1
	ptrF->Tete = 0;
	ptrF->Queue = 0;
}

int  retirer(T_File *ptrF,T_Elt *ptrE){ //si pas vide, en tete de file
	if(fileVide(ptrF))
		return 0;
	ptrF->Tete=(ptrF->Tete+1) % MAX;
	return 1;
}

int ajouter(T_File *ptrF,T_Elt ptrE){ // si espace libre, ajout en queue
	if(filePleine(ptrF))
		return 0;
	ptrF->Queue=(ptrF->Queue+1) % MAX;
 	ptrF->Elts[ptrF->Queue] = ptrE;
 	return 1;
} 

int fileVide(const  T_File *ptrF){ // qd Tete == 0
	return ptrF->Tete == ptrF->Queue;
}

int filePleine(const  T_File *ptrF){ // qd MAX elts dans la file 
	return (ptrF->Tete == (ptrF->Queue+1) % MAX);
}

T_Elt  premier(T_File *ptrF){ //valeur en tete de file
	T_Elt e;
	if(fileVide(ptrF))
		return e;
	return ptrF->Elts[(ptrF->Tete+1) % MAX];

}

void afficherFile(T_File *ptrF){
	T_File fTemp;
	T_Elt e;
	initFile(&fTemp);
	while(!fileVide(ptrF)){
		e = premier(ptrF);
		afficherElt(&e);
		ajouter(&fTemp,e);
		retirer(ptrF,&e);
	}
	while(!fileVide(&fTemp)){
		ajouter(ptrF,premier(&fTemp));
		retirer(&fTemp,&e);
	}
}






