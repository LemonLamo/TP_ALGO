#include <stdio.h>
#include <stdlib.h>

//declaration de la listeBD
typedef struct ListeBD {
	int val;
	struct ListeBD *suiv , *pred;
} Cellule;

typedef struct ListeBD* PlisteBD;

typedef struct ListeG {
	int val;
	struct ListeG *suivG;
	PlisteBD tete, queue;
} CelluleTG;

typedef struct ListeG* PlisteG;

//procedure binaire  
void Binaire (PlisteBD *T, PlisteBD *Q , int x) {
	PlisteBD P;
	//allouer(t);
	//creation en LIFO
	*T = malloc(sizeof(Cellule));
	(*T)->val = x%2 ;
	x = x /2;
    (*T)->suiv = NULL;
    *Q = *T;
    while (x != 0) {
    	P=malloc(sizeof(Cellule));
    	P->val = x%2;
    	x= x/2;
    	P->suiv = *T;
    	(*T)->pred = P;
    	*T=P;
	}
	(*T)->pred = NULL;	
}

int pair (PlisteBD Q) {
     if (Q->val ==0) {
     	return 1;
	 } else {
	 	return 0;
	 }
}

void incremente(PlisteBD *T, PlisteBD *Q) {
	PlisteBD P;
	P=*Q;
	while (P != NULL && P->val ==1) {
		P->val =0;
		P=P->pred;
	}
	if (P != NULL) {
		P->val = 1;
	} else {
		P=malloc(sizeof(Cellule));
		P->val = 1;
		P->suiv = *T;
	    (*T)->pred = P;
	    *T= P;
	    (*T)->pred = NULL;
	}	
}

//afficher X en binaire 
void affiche(PlisteBD T){
	while (T !=NULL){
		printf("%d",T->val);
		T=T->suiv;
	}
}

//procedure stocker (LIFO)
void Stocker (PlisteG *TG , int x) {
	PlisteG PG;
	PlisteBD T,Q;
	Binaire(&T,&Q,x);
	//creation de la structure with PlisteG
	PG = malloc(sizeof(CelluleTG));
	PG->tete= T;
	PG->queue = Q;
	PG->suivG=*TG;
	*TG=PG;
	
}

int main(int argc, char *argv[]) {
      int x , i, n;
      PlisteBD T,Q;
      PlisteG PG, TG;
      printf("entrez le nombre d'elements : \n");

      	scanf("%d",&n);
	 
	  
	  TG=NULL;
	printf("donnez les %d elements de la structure : \n",n);
	for (i=0; i<n ;i++) {
		scanf("%d",&x);
		Stocker(&TG , x);
	}
	
    PG=TG;
    printf("la structure avant l'incrementation : \n");
	while (PG !=NULL) {
		T= PG->tete;
		affiche(T);
		printf("\n");
		PG= PG->suivG;
	}
   //affichage with incrementing les nombres impairs 
   
   PG=TG;
   while (PG != NULL) {
   	     T=PG->tete;
   	     Q=PG->queue;
   	     if (pair(Q) ==0) {
   	     	incremente(&T,&Q);
   	     	PG->tete=T;
			}
		PG=PG->suivG;
   }
     PG=TG;
printf("la structure apres incrementation de chiffres impairs : \n");
   while (PG !=NULL) {
   	    T=PG->tete;
   	    affiche(T);
   	    printf("\n");
   	    PG=PG->suivG;
   }
    
	return 0;
}

