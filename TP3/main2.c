#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* strninsert(char *S1, char *S2, int k, int i) {
    char *result = malloc(strlen(S1) + strlen(S2) - i + 1);
    strncpy(result, S1, k);
    strcpy(result + k, S2 + i);
    strcpy(result + k + strlen(S2) - i, S1 + k);
    return result;
}

char* strndel(char *S, int i, int k) {
    char *result = malloc(strlen(S) - i + 1);
    strncpy(result, S, k);
    strcpy(result + k, S + k + i);
    return result;
}

void remplace(char *M, char *S1, char *S2) {
    char *p = M;
    while ((p = strstr(p, S1)) != NULL) {
        memmove(p + strlen(S2), p + strlen(S1), strlen(p) - strlen(S1) + 1);
        memcpy(p, S2, strlen(S2));
    }
}

int main() {
    char S1[50], S2[50], M[50], S[50];
    int k, i;

    printf("Entrez la premiere chaine (par exemple, 'poesie') : ");
    scanf("%s", S1);
    printf("Entrez la deuxieme chaine (par exemple, 'pralin') : ");
    scanf("%s", S2);
    printf("Entrez la position d'insertion (par exemple, 2) : ");
    scanf("%d", &k);
    printf("Entrez la position de depart dans la deuxieme chaine (par exemple, 3) : ");
    scanf("%d", &i);
    char *result = strninsert(S1, S2, k, i);
    printf("Resultat de strninsert : %s\n", result);
    free(result);

    printf("Entrez une chaine (par exemple, 'ordinateur') : ");
    scanf("%s", S);
    printf("Entrez le nombre de caracteres a supprimer (par exemple, 3) : ");
    scanf("%d", &i);
    printf("Entrez la position de depart pour la suppression (par exemple, 2) : ");
    scanf("%d", &k);
    result = strndel(S, i, k);
    printf("Resultat de strndel : %s\n", result);
    free(result);

    printf("Entrez une chaine (par exemple, 'fmbctimbs') : ");
    scanf("%s", M);
    printf("Entrez la chaine à remplacer (par exemple, 'mb') : ");
    scanf("%s", S1);
    printf("Entrez la chaine de remplacement (par exemple, 'on') : ");
    scanf("%s", S2);
    remplace(M, S1, S2);
    printf("Resultat de remplace : %s\n", M);

    return 0;
}


