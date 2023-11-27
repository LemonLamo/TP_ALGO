#include <stdio.h>
#include <stdlib.h>

// Créer une liste contenant tous les multiples d’une certaine valeur. La fonction donnera le choix de la politique de création des listes

// Définition de la structure d'un nœud
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Fonction pour créer un nouveau nœud
Node *CreateNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Fonction pour afficher les éléments de la liste chaînée
void DisplayList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Fonction pour créer une liste contenant tous les multiples d'une certaine valeur
Node *CreateMultipleList(int value, int limite, int policy) {
    int i;
    Node *head = NULL;
    Node *tail = NULL;
    for (i = 0; i <= limite; i++) {
        int multiple = value * i;
        Node *newNode = CreateNode(multiple);
        if (policy == 1) {
            // création en LIFO
            if (head == NULL) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        } else if (policy == 2) {
            // création en FIFO
            if (head == NULL) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
    }
    return head;
}

// Compter le nombre des éléments pairs et impairs dans la liste
void CountOddEvenElements(Node *head) {
    Node *current = head;
    int oddcount = 0, evencount = 0;
    while (current != NULL) {
        if (current->data % 2 == 0) {
            evencount++;
        } else {
            oddcount++;
        }
        current = current->next;
    }
    printf("Le nombre d'elements pairs dans la liste est %d\n", evencount);
    printf("Le nombre d'elements impairs dans la liste est %d\n", oddcount);
}

// Supprimer la première occurrence d’une certaine valeur. Il faut afficher la liste avant et après suppression.
Node *DeleteFirstOccurence(Node *head, int targetvalue) {
    Node *prev = NULL;
    Node *current = head;

    // Trouver la première occurrence
    while (current != NULL && current->data != targetvalue) {
        prev = current;
        current = current->next;
    }

    if (current != NULL) {
        // Si la première occurrence est en tête de liste
        if (prev == NULL) {
            head = current->next;
        } else {
            prev->next = current->next;
        }
        free(current);
    }

    return head;
}

// Fusionner deux listes en entrée pour produire une troisième liste triée.
Node *MergeSortedLists(Node *list1, Node *list2) {
    Node *mergedList = NULL;
    Node *current = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            if (mergedList == NULL) {
                mergedList = current = CreateNode(list1->data);
            } else {
                current->next = CreateNode(list1->data);
                current = current->next;
            }
            list1 = list1->next;
        } else {
            if (mergedList == NULL) {
                mergedList = current = CreateNode(list2->data);
            } else {
                current->next = CreateNode(list2->data);
                current = current->next;
            }
            list2 = list2->next;
        }
    }

    // Ajouter les éléments restants de list1
    while (list1 != NULL) {
        current->next = CreateNode(list1->data);
        current = current->next;
        list1 = list1->next;
    }

    // Ajouter les éléments restants de list2
    while (list2 != NULL) {
        current->next = CreateNode(list2->data);
        current = current->next;
        list2 = list2->next;
    }

    return mergedList;
}

int main(int argc, char *argv[]) {
    int value1, value2, limite1, limite2, policy1, policy2, targetvalue1, targetvalue2;

    // Première liste
    printf("Entrez la valeur 1 : ");
    scanf("%d", &value1);

    printf("Entrez la limite 1 : ");
    scanf("%d", &limite1);

    printf("Choisissez la politique 1 (1 pour LIFO, 2 pour FIFO) : ");
    scanf("%d", &policy1);

    Node *list1 = CreateMultipleList(value1, limite1, policy1);

    printf("Liste créée 1 : ");
    DisplayList(list1);

    CountOddEvenElements(list1);

    printf("Entrez la valeur a supprimer de la liste 1 : ");
    scanf("%d", &targetvalue1);

    list1 = DeleteFirstOccurence(list1, targetvalue1);

    printf("La liste apres suppression 1 : \n");
    DisplayList(list1);

    // Deuxième liste
    printf("Entrez la valeur 2 : ");
    scanf("%d", &value2);

    printf("Entrez la limite 2 : ");
    scanf("%d", &limite2);

    printf("Choisissez la politique 2 (1 pour LIFO, 2 pour FIFO) : ");
    scanf("%d", &policy2);

    Node *list2 = CreateMultipleList(value2, limite2, policy2);

    printf("Liste créée 2 : ");
    DisplayList(list2);

    CountOddEvenElements(list2);

    printf("Entrez la valeur a supprimer de la liste 2 : ");
    scanf("%d", &targetvalue2);

    list2 = DeleteFirstOccurence(list2, targetvalue2);

    printf("La liste apres suppression 2 : \n");
    DisplayList(list2);

    // Fusionner les deux listes triées
    Node *mergedList = MergeSortedLists(list1, list2);

    printf("Liste fusionnee triee : ");
    DisplayList(mergedList);
    
  // Libérer l'espace créé par les listes
    Node *current = list1;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }

    current = list2;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }

    current = mergedList;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
