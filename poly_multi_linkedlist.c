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
struct Node* multiplyPolynomials(struct Node* poly1, struct Node* poly2);
void readPolynomial(struct Node** poly);
void addTerm(struct Node** poly, int coeff, int exp);
int main() 
{
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* product = NULL;
    printf("Enter the first polynomial:\n");
    readPolynomial(&poly1);
    printf("Enter the second polynomial:\n");
    readPolynomial(&poly2);
    printf("First Polynomial: ");
    display(poly1);
    printf("Second Polynomial: ");
    display(poly2);
    product = multiplyPolynomials(poly1, poly2);
    printf("Product of Polynomials: ");
    display(product);
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
struct Node* multiplyPolynomials(struct Node* poly1, struct Node* poly2) 
{
    struct Node* product = NULL;
    struct Node* temp1 = poly1;
    struct Node* temp2;
    while (temp1 != NULL) 
    {
        temp2 = poly2;
        while (temp2 != NULL) 
        {
            int coeff = temp1->coeff * temp2->coeff;
            int exp = temp1->exp + temp2->exp;
            addTerm(&product, coeff, exp);
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return product;
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
void addTerm(struct Node** poly, int coeff, int exp) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *poly;
    struct Node* prev = NULL;
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    if (*poly == NULL || (*poly)->exp < exp) 
    {
        newNode->next = *poly;
        *poly = newNode;
        return;
    }
    while (temp != NULL && temp->exp > exp) 
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp != NULL && temp->exp == exp) 
    {
        temp->coeff += coeff;
        free(newNode); 
    } 
    else
    {
        newNode->next = temp;
        prev->next = newNode;
    }
}
