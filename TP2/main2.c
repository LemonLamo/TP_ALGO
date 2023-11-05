#include <stdio.h>
#include <stdlib.h>

#define N 10
#define M 20


void tri_mat1(int mat[N][M], int n, int m) {
    int i, j, k, l;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            for (k = 0; k < n; k++) {
                for (l = 0; l < m; l++) {
                    if (mat[i][j] < mat[k][l]) {
                        int temp = mat[i][j];
                        mat[i][j] = mat[k][l];
                        mat[k][l] = temp;
                    }
                }
            }
        }
    }
}

void tri_mat2(int mat[N][M], int n, int m) {
    int i, j, k, temp, array[N*M];

    // Transformer la matrice en tableau
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            array[i*m + j] = mat[i][j];
        }
    }

    // Trier le tableau
    for (i = 0; i < n*m; i++) {
        for (j = i + 1; j < n*m; j++) {
            if (array[i] > array[j]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    // Transformer le tableau en matrice
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            mat[i][j] = array[i*m + j];
        }
    }
}

void afficher_mat(int mat[N][M], int n, int m) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}



 int main() {
    int mat[N][M];
    int n, m;
    int i, j;

    printf("Entrez le nombre de lignes de la matrice : ");
    scanf("%d", &n);
    printf("Entrez le nombre de colonnes de la matrice : ");
    scanf("%d", &m);

    printf("Entrez les éléments de la matrice :\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("mat[%d][%d] = ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
    
    
    printf("Matrice avant le tri :\n");
    afficher_mat(mat, n, m);
    

    tri_mat1(mat, n, m);

    printf("Matrice après le tri avec la premiere methode :\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    
      tri_mat2(mat, n, m);
      
      
    printf("Matrice après le tri avec la deuxieme methode :\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}

