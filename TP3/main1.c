#include <stdio.h>
#include <string.h>

void afficher_facteurs_gauches(char *mot) {
    int i, len = strlen(mot);
    printf("FG(%s) = { ", mot);
    for (i = 1; i <= len; i++) {
        printf("%.*s", i, mot);
        if (i < len) {
            printf(", ");
        }
    }
    printf(" }\n");
}

void afficher_facteurs_droits(char *mot) {
    int i, len = strlen(mot);
    printf("FD(%s) = { ", mot);
    for (i = 1; i <= len; i++) {
        printf("%s", mot + len - i);
        if (i < len) {
            printf(", ");
        }
    }
    printf(" }\n");
}

int main() {
    char mot[50];
    printf("Entrez un mot : ");
    scanf("%s", mot);
    afficher_facteurs_gauches(mot);
    afficher_facteurs_droits(mot);
    return 0;
}

