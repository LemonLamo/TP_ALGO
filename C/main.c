#include <stdio.h>

void MENU() {
    printf("***********  MENU  ***********\n");
    printf("** 1/ Addition              **\n");
    printf("** 2/ Soustraction          **\n");
    printf("** 3/ Multiplication        **\n");
    printf("** 4/ Division              **\n");
    printf("** 5/ Quitter               **\n");
    printf("******************************\n");
    printf("Faites votre choix : ");
}

int main() {
    int choix;
    char answer;
    double num1, num2, resultat;

    do {
        MENU();
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Entrez le premier nombre : ");
                scanf("%lf", &num1);
                printf("Entrez le deuxième nombre : ");
                scanf("%lf", &num2);
                resultat = num1 + num2;
                printf("Résultat : %.2lf\n\n", resultat);
                break;
            case 2:
                printf("Entrez le premier nombre : ");
                scanf("%lf", &num1);
                printf("Entrez le deuxième nombre : ");
                scanf("%lf", &num2);
                resultat = num1 - num2;
                printf("Résultat : %.2lf\n\n", resultat);
                break;
            case 3:
                printf("Entrez le premier nombre : ");
                scanf("%lf", &num1);
                printf("Entrez le deuxième nombre : ");
                scanf("%lf", &num2);
                resultat = num1 * num2;
                printf("Résultat : %.2lf\n\n", resultat);
                break;
            case 4:
                printf("Entrez le premier nombre : ");
                scanf("%lf", &num1);
                printf("Entrez le deuxième nombre : ");
                scanf("%lf", &num2);
                if (num2 != 0) {
                    resultat = num1 / num2;
                    printf("Résultat : %.2lf\n\n", resultat);
                } else {
                    printf("Erreur : Division par zéro\n\n");
                }
                break;
            case 5:
                printf("Au revoir !\n");
                return 0;
            default:
                printf("Choix invalide. Veuillez choisir une option valide.\n");
        }

        printf("Voulez-vous refaire une autre opération ? Tapez 'o' ou 'O' pour oui : ");
        scanf(" %c", &answer);
    } while (answer == 'o' || answer == 'O');

    return 0;
}

