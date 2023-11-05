#include <stdio.h>
#include <stdlib.h>

int egaux(int tab1[], int tab2[], int n, int m) {
	int i;
    if (n != m) {
        return 0;
    }
    for (i = 0; i < n; i++) {
        if (tab1[i] != tab2[i]) {
            return 0;
        }
    }
    return 1;
}
void tri(int tab[], int n) {
    int i, j, tmp;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (tab[i] > tab[j]) {
                tmp = tab[i];
                tab[i] = tab[j];
                tab[j] = tmp;
            }
        }
    }
}

int similaires(int tab1[], int tab2[], int n, int m) {
    int i;
    if (n != m) {
        return 0;
    }
    tri(tab1, n);
    tri(tab2, m);
    for (i = 0; i < n; i++) {
        if (tab1[i] != tab2[i]) {
            return 0;
        }
    }
    return 1;
}

int comparables(int tab1[], int tab2[], int n, int m) {
    int i, j, found;
    
    tri(tab1, n);
    tri(tab2, m);
    for (i = 0; i < n; i++) {
        found = 0;
        for (j = 0; j < m; j++) {
            if (tab1[i] == tab2[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int i, n, m;
    printf("entrez la taille du premier tableau : \n");
    scanf("%d", &n);
    printf("entrez la taille du deuxieme tableau: \n");
    scanf("%d", &m);
    int tab1[n], tab2[m];
    for ( i = 0; i < n; i++) {
        printf("entrez l'element du tableau1 numero %d: \n", i + 1);
        scanf("%d", &tab1[i]);
    }
    for ( i = 0; i < m; i++) {
        printf("entrez l'element du tableau2 numero %d: \n", i + 1);
        scanf("%d", &tab2[i]);
    }

    if (egaux(tab1, tab2, n, m)) {
        printf("les tableaux sont egaux \n");
    } else {
        printf("les tableaux ne sont PAS egaux \n");
    }
    
     if (similaires(tab1, tab2, n, m)) {
        printf("les tableaux sont similaires \n");
    } else {
        printf("les tableaux ne sont PAS similaires \n");
    }
    
     if (comparables(tab1, tab2, n, m)) {
        printf("les tableaux sont comparables \n");
    } else {
        printf("les tableaux ne sont PAS comparables \n");
    }


    return 0;
}

