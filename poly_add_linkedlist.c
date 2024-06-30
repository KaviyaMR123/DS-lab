#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int coeff;
    int exp;
    struct Node* next;
};
void createNode(int coeff, int exp, struct Node** poly);
void display(struct Node* poly);
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2);
void readPolynomial(struct Node** poly);
int main() 
{
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* sum = NULL;
    printf("Enter the first polynomial:\n");
    readPolynomial(&poly1);
    printf("Enter the second polynomial:\n");
    readPolynomial(&poly2);
    printf("First Polynomial: ");
    display(poly1);
    printf("Second Polynomial: ");
    display(poly2);
    sum = addPolynomials(poly1, poly2);
    printf("Sum of Polynomials: ");
    display(sum);
    return 0;
}
void createNode(int coeff, int exp, struct Node** poly) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *poly;
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    if (*poly == NULL) 
    {
        *poly = newNode;
        return;
    }
    while (last->next != NULL) 
    {
        last = last->next;
    }
    last->next = newNode;
}
void display(struct Node* poly)
{
    while (poly != NULL) 
    {
        printf("%dx^%d", poly->coeff, poly->exp);
        poly = poly->next;
        if (poly != NULL) 
        {
            printf(" + ");
        }
    }
    printf("\n");
}
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) 
{
    struct Node* sum = NULL;
    while (poly1 != NULL && poly2 != NULL) 
    {
        if (poly1->exp > poly2->exp) 
        {
            createNode(poly1->coeff, poly1->exp, &sum);
            poly1 = poly1->next;
        } 
        else if (poly1->exp < poly2->exp) 
        {
            createNode(poly2->coeff, poly2->exp, &sum);
            poly2 = poly2->next;
        } 
        else
        {
            createNode(poly1->coeff + poly2->coeff, poly1->exp, &sum);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL)
    {
        createNode(poly1->coeff, poly1->exp, &sum);
        poly1 = poly1->next;
    }
    while (poly2 != NULL)
    {
        createNode(poly2->coeff, poly2->exp, &sum);
        poly2 = poly2->next;
    }
    return sum;
}
void readPolynomial(struct Node** poly)
{
    int n, coeff, exp;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
    {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        createNode(coeff, exp, poly);
    }
}
