#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node {
	float coef;
	int degre;
	struct Node* next;
}Node;

Node* createNode(int coef, int degre) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(0);
    }
    newNode->coef = coef;
    newNode->degre = degre;
    newNode->next = NULL;
    return newNode;
}

Node* insertNode(Node* head, int coef, int degre) {
    Node* newNode = createNode(coef, degre);
    if(head == NULL) {
        return newNode;
    }
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Node* LirePoly (int n) {
	int degre;
	float coef;
	int i;
	Node* poly =NULL;
	printf("entrez le degré et coefficient du polynome : \n");
	for (i=0 ; i<n; i++) {
		printf("entrez le degre du %d element : \n",i+1);
		scanf("%d",&degre);
		printf("entrez le coefficiant du %d element :\n",i+1);
		scanf("%f",&coef);
		 poly = insertNode(poly, coef, degre);
	}
		
	return poly;
}
void AffichPoly (Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->degre == 0) {
            printf("%.2f", temp->coef);
        } else if (temp->degre == 1) {
            printf("%.2fx", temp->coef);
        } else {
            printf("%.2fx^%d", temp->coef, temp->degre);
        }
        if (temp->next != NULL && temp->next->coef >= 0) {
            printf("+");
        }
        temp = temp->next;
    }
    printf("\n");
}


float EvaluePoly(Node* head, float x) {
    float result = 0.0;
    Node* temp = head;
    while (temp != NULL) {
        result += temp->coef * pow(x, temp->degre);
        temp = temp->next;
    }
    return result;
}

Node* SomPoly(Node* P1, Node* P2) {
    Node* P3 = NULL;
    Node* temp1 = P1;
    Node* temp2 = P2;
    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->degre > temp2->degre) {
            P3 = insertNode(P3, temp1->coef, temp1->degre);
            temp1 = temp1->next;
        } else if (temp1->degre < temp2->degre) {
            P3 = insertNode(P3, temp2->coef, temp2->degre);
            temp2 = temp2->next;
        } else {
            P3 = insertNode(P3, temp1->coef + temp2->coef, temp1->degre);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    while (temp1 != NULL) {
        P3 = insertNode(P3, temp1->coef, temp1->degre);
        temp1 = temp1->next;
    }
    while (temp2 != NULL) {
        P3 = insertNode(P3, temp2->coef, temp2->degre);
        temp2 = temp2->next;
    }
    return P3;
}

void freePoly(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

#include <stdio.h>
#include <stdlib.h>

// Assuming Node and the functions LirePoly, AffichPoly, SomPoly, EvaluePoly, and freePoly are defined elsewhere

int main() {
    int n;
    Node *P1, *P2, *P3;
    float x, result;

    printf("Enter the number of terms in the first polynomial: \n");
    scanf("%d", &n);
    P1 = LirePoly(n);
    printf("First Polynomial: ");
    AffichPoly(P1);

    printf("Enter the number of terms in the second polynomial: \n");
    scanf("%d", &n);
    P2 = LirePoly(n);
    printf("Second Polynomial: ");
    AffichPoly(P2);

    P3 = SomPoly(P1, P2);
    printf("The sum of the two polynomials is: ");
    AffichPoly(P3);

    printf("Enter a value for x to evaluate the sum polynomial: \n");
    scanf("%f", &x);
    result = EvaluePoly(P3, x);
    printf("The sum polynomial evaluated at x = %.2f is %.2f\n", x, result);

    freePoly(P1);
    freePoly(P2);
    freePoly(P3);

    return 0;
}


