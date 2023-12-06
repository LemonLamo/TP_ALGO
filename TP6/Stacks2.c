#include <stdio.h>
#include <stdlib.h>

typedef struct Pile {
    int valeur;
    struct Pile* precedent;
} Pile;

void empiler(Pile **p, int x) {
    Pile *element = malloc(sizeof(Pile));
    element->valeur = x;
    element->precedent = *p;
    *p = element;
}

int depiler(Pile **p) {
    if (*p == NULL) {
        printf("Erreur : Pile vide\n");
        exit(EXIT_FAILURE);
    }

    int valeurDepilee = (*p)->valeur;
    Pile *temp = *p;
    *p = (*p)->precedent;
    free(temp);

    return valeurDepilee;
}

void afficherPile(Pile *p) {
    Pile *q = p;
    while (q != NULL) {
        printf("%d ", q->valeur);
        q = q->precedent;
    }
    printf("\n");
}

// Fonction pour vérifier si un caractère est un opérateur
int estOperateur(char caractere) {
    return (caractere == '+' || caractere == '-' || caractere == '*' || caractere == '/');
}

// Fonction pour obtenir la priorité d'un opérateur
int obtenirPriorite(char operateur) {
    if (operateur == '*' || operateur == '/') {
        return 2;
    } else if (operateur == '+' || operateur == '-') {
        return 1;
    } else {
        return 0;
    }
}

// Fonction pour convertir une expression infixée en postfixée
void infixVersPostfixe(char infix[], char postfixe[]) {
    Pile *pile = NULL;
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        char caractere = infix[i];

        if (caractere >= '0' && caractere <= '9') {
            postfixe[j++] = caractere;
        } else if (caractere == '(') {
            empiler(&pile, caractere);
        } else if (caractere == ')') {
            while (pile != NULL && pile->valeur != '(') {
                postfixe[j++] = depiler(&pile);
            }
            depiler(&pile); // Dépiler la parenthèse ouvrante
        } else if (estOperateur(caractere)) {
            while (pile != NULL && obtenirPriorite(pile->valeur) >= obtenirPriorite(caractere)) {
                postfixe[j++] = depiler(&pile);
            }
            empiler(&pile, caractere);
        }

        i++;
    }

    // Dépiler les opérateurs restants de la pile
    while (pile != NULL) {
        postfixe[j++] = depiler(&pile);
    }

    postfixe[j] = '\0'; // Ajouter la terminaison de chaîne
}

// Fonction pour évaluer une expression postfixée
int evaluerPostfixe(char postfixe[]) {
    Pile *pile = NULL;
    int i = 0;

    while (postfixe[i] != '\0') {
        char caractere = postfixe[i];

        if (caractere >= '0' && caractere <= '9') {
            empiler(&pile, caractere - '0'); // Convertir le caractère en entier
        } else if (estOperateur(caractere)) {
            int operande2 = depiler(&pile);
            int operande1 = depiler(&pile);

            switch (caractere) {
                case '+':
                    empiler(&pile, operande1 + operande2);
                    break;
                case '-':
                    empiler(&pile, operande1 - operande2);
                    break;
                case '*':
                    empiler(&pile, operande1 * operande2);
                    break;
                case '/':
                    empiler(&pile, operande1 / operande2);
                    break;
            }
        }

        i++;
    }

    return depiler(&pile);
}

int main() {
    char infixExpression[50];
    printf("Entrez une expression arithmetique infixee (par exemple, '(5+3)*4') : ");
    scanf("%s", infixExpression);

    char postfixeExpression[50];

    // Convertir de l'infixe au postfixe
    infixVersPostfixe(infixExpression, postfixeExpression);
    printf("Expression post-fixee : %s\n", postfixeExpression);

    // Évaluer l'expression post-fixee
    int resultat = evaluerPostfixe(postfixeExpression);
    printf("Resultat : %d\n", resultat);

    return 0;
}
