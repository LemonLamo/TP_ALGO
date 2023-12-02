#include <stdio.h>
#include <stdlib.h>

typedef struct Motcir* Pcar;
typedef struct Motcir {
    char Lettre;
    Pcar suiv;
} Cellule;

void printList(Pcar T) {
    Pcar P = T;
    do {
        printf("%c", P->Lettre);
        P = P->suiv;
    } while (P != T);
    printf("\n");
}

int main() {
    int n, i;
    Pcar  T, P , P1, P2;
    printf("Entrez le nombre d'etapes: ");
    scanf("%d", &n);

    //initialisation du mot 
    T = malloc(sizeof(Cellule)); //allouer T
    T->Lettre = 'A';
    T->suiv = T; //car c'est une listre circulaire

    printf("evolution du mot : \n");
    printList(T);

    for (i = 1 ; i <= n ; i++) {
        P = T;
        do {
            Pcar next = P->suiv;
            switch (P->Lettre) {
                case 'A' : 
                    P1 = malloc(sizeof(Cellule));
                    P2 = malloc(sizeof(Cellule));
                    P1->Lettre = 'B';
                    P2->Lettre = 'C';
                    P1->suiv = P2;
                    P2->suiv = next;
                    P->suiv = P1;
                    P->Lettre = 'A';
                    break;
                case 'B': 
                    P->Lettre = 'C';
                    break;
                case 'C': 
                    P->Lettre = 'A';
                    break;
            }
            P = next;
        } while (P != T);

        //affichage du mot 
        printf("l'etape : %d ", i);
        printList(T);
    }
    return 0;
}


