#include <stdio.h>
#include <stdlib.h>

typedef struct Pile {
    int info;
    struct Pile* precedent;
} Pile;

void empiler (Pile **p, int x) {
    Pile *element = malloc(sizeof(Pile));
    element->info = x;
    element->precedent = *p;
    *p = element;
}

void desempiler (Pile **p) {
    if (*p == NULL) {
        printf("La pile est vide");
    } else {
        Pile *tmp = (*p)->precedent;
        free(*p);
        *p = tmp;
    }
}

void affich (Pile *p) {
    Pile *q = p;
    while (q != NULL) {
        printf("%d ", q->info);
        q = q->precedent;
    }
    printf("\n");
}

Pile* rechercher_val(Pile **p, int val) {
    Pile *q=*p;
    while((q!=NULL) && (q->info!=val)) {
        q=q->precedent;
    }
    return q;
}

Pile* remplacer (Pile **p , int val1, int val2) {
    Pile *q=*p;
    while (q!=NULL) {
        if(q->info==val1) {
            q->info=val2;
        }
        q=q->precedent;
    } 
    return *p;
}

Pile* inserer (Pile **p, int k , int val) {
    Pile *q=*p;
    for(int i=0 ;i<k-1;i++) {
        q=q->precedent;
    }
    Pile *nouvelle_case=malloc(sizeof(Pile));
    nouvelle_case->info=val;
    nouvelle_case->precedent=q->precedent;
    q->precedent=nouvelle_case;
    return *p;
}

Pile* supprimer(Pile **p, int k) {
    Pile *q = *p;
    Pile *r = NULL;
    int i;
    // Parcourir jusqu'à la position k
    for(i = 0; i < k && q != NULL; i++) {
        r = q;
        q = q->precedent;
    }
    // Si la position k est atteinte
    if(i == k && q != NULL) {
        // Si l'élément à supprimer est le sommet de la pile
        if(r == NULL) {
            *p = q->precedent;
        } else {
            r->precedent = q->precedent;
        }
        free(q);
    }
    return *p;
}

Pile* Fusion(Pile *A, Pile *B) {
    Pile *C = NULL;
    Pile **D = &C;

    while (A != NULL && B != NULL) {
        Pile *nouveau;
        if (A->info < B->info) {
            nouveau = malloc(sizeof(Pile));
            nouveau->info = A->info;
            A = A->precedent;
        } else {
            nouveau = malloc(sizeof(Pile));
            nouveau->info = B->info;
            B = B->precedent;
        }
        *D = nouveau;
        D = &(nouveau->precedent);
    }

    // Copier le reste de la pile A si elle n'est pas vide
    while (A != NULL) {
        Pile *nouveau = malloc(sizeof(Pile));
        nouveau->info = A->info;
        A = A->precedent;
        *D = nouveau;
        D = &(nouveau->precedent);
    }

    // Copier le reste de la pile B si elle n'est pas vide
    while (B != NULL) {
        Pile *nouveau = malloc(sizeof(Pile));
        nouveau->info = B->info;
        B = B->precedent;
        *D = nouveau;
        D = &(nouveau->precedent);
    }

    // Marquer la fin de la nouvelle pile
    *D = NULL;

    return C;
}

void fractionner (Pile *A, Pile **B, Pile **C) {
    while (A != NULL) {
        if (A->info % 2 == 0) {
            empiler(B, A->info);
        } else {
            empiler(C, A->info);
        }
        A = A->precedent;
    }
}

int main() {
    int i, n1,n2,n3;
    int val;
      int val1, val2;
    int k, val3;
    int k1;
    Pile *pile1 = NULL;
    Pile *pile2 = NULL;
    Pile *pile3 = NULL;
     Pile *pilePair = NULL;
    Pile *pileImpair = NULL;
    printf("entrez le nombre d'elements dans la pile : \n");
    scanf ("%d", &n1);
  
    for (i = 0; i < n1; i++) {
        int value;
        printf("entrez un entier a ajouter a la pile: \n");
        scanf("%d", &value);
        empiler(&pile1, value);
    }
    printf("\naffichage de la pile:\n");
    affich(pile1);
    printf("-------------------------------------------\n");
    printf("\ndessampilage de la pile:\n");
     for(i = 0; i < n1; i++) {
        desempiler(&pile1);
        affich(pile1);
    }
    free(pile1);
    printf("la pile est vide maintenant :))");
    printf("\n-------------------------------------------\n");
       printf("entrez le nombre d'elements dans la nouvelle pile : \n");
    scanf ("%d", &n2);
 for (i = 0; i < n2; i++) {
        int value;
        printf("entrez un entier a ajouter a la nouvelle pile: \n");
        scanf("%d", &value);
        empiler(&pile2, value);
    }
    printf("\naffichage de la nouvelle pile:\n");
    affich(pile2);
    printf("-------------------------------------------\n");

    printf("\nrecherche de la valeur dans la pile:\n");
    
    printf("entrez la valeur a rechercher : \n");
    scanf("%d", &val);
    Pile *res = rechercher_val(&pile2, val);
    if(res != NULL) {
        printf("La valeur %d a ete trouvee dans la pile\n", val);
    } else {
        printf("La valeur %d n'a pas ete trouvee dans la pile\n", val);
    }
    printf("-------------------------------------------\n");
    printf("\nremplacement de la valeur dans la pile:\n");

    printf("entrez la valeur a remplacer : \n");
    scanf("%d", &val1);
    printf("entrez la nouvelle valeur : \n");
    scanf("%d", &val2);
    remplacer(&pile2, val1, val2);
    affich(pile2);
    printf("-------------------------------------------\n");
    printf("\ninsertion de la valeur a la position dans la pile:\n");
   
    printf("entrez la position : \n");
    scanf("%d", &k);
    printf("entrez la valeur a inserer : \n");
    scanf("%d", &val3);
    inserer(&pile2, k, val3);
    affich(pile2);
    printf("-------------------------------------------\n");
    printf("\nsuppression de l'element a la position dans la pile:\n");
    
    printf("entrez la position : \n");
    scanf("%d", &k1);
    supprimer(&pile2, k1);
    affich(pile2);

    printf("\n-------------------------------------------\n");
    printf("\nfusion de deux piles:\n");

     printf("entrez le nombre d'elements dans la pile : \n");
    scanf ("%d", &n3);
    for (i = 0; i < n3; i++) {
        int value;
        printf("entrez un entier a ajouter a la troisieme pile: \n");
        scanf("%d", &value);
        empiler(&pile3, value);
    }
    printf("\naffichage de la troisieme pile:\n");
    affich(pile3);

    Pile *pileFusion = Fusion(pile2, pile3);
    printf("\naffichage de la pile fusionnee:\n");
    affich(pileFusion);
    printf("-------------------------------------------\n");

    printf("\nfractionnement de la pile:\n");

   
    fractionner(pileFusion, &pilePair, &pileImpair);

    printf("\naffichage de la pile des nombres pairs:\n");
    affich(pilePair);

    printf("\naffichage de la pile des nombres impairs:\n");
    affich(pileImpair);
    printf("-------------------fin du programme ------------------------\n");

        free(pile2);
          free(pile3);
            free(pileFusion);
              free(pileImpair);
                free(pilePair);

    return 0;
    
}