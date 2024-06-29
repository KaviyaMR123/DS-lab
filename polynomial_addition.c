#include <stdio.h>
#include <stdlib.h>
typedef struct PolynomialTerm 
{
    int coefficient;
    int exponent;
} PolynomialTerm;
typedef struct Polynomial
{
    PolynomialTerm* terms;
    int termCount;
} Polynomial;
Polynomial createPolynomial(int termCount) 
{
    Polynomial poly;
    poly.termCount = termCount;
    poly.terms = (PolynomialTerm*)malloc(termCount * sizeof(PolynomialTerm));
    return poly;
}
void inputPolynomial(Polynomial* poly) 
{
    for (int i = 0; i < poly->termCount; i++) 
    {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &poly->terms[i].coefficient, &poly->terms[i].exponent);
    }
}
void displayPolynomial(Polynomial poly) 
{
    for (int i = 0; i < poly.termCount; i++) 
    {
        printf("%dx^%d", poly.terms[i].coefficient, poly.terms[i].exponent);
        if (i != poly.termCount - 1) 
        {
            printf(" + ");
        }
    }
    printf("\n");
}
Polynomial addPolynomials(Polynomial poly1, Polynomial poly2) 
{
    Polynomial result = createPolynomial(poly1.termCount + poly2.termCount);
    int i = 0, j = 0, k = 0;
    while (i < poly1.termCount && j < poly2.termCount) 
    {
        if (poly1.terms[i].exponent > poly2.terms[j].exponent) 
        {
            result.terms[k++] = poly1.terms[i++];
        } 
        else if (poly1.terms[i].exponent < poly2.terms[j].exponent) 
        {
            result.terms[k++] = poly2.terms[j++];
        }
        else
        {
            result.terms[k].exponent = poly1.terms[i].exponent;
            result.terms[k++].coefficient = poly1.terms[i++].coefficient + poly2.terms[j++].coefficient;
        }
    }
while (i < poly1.termCount) 
{
        result.terms[k++] = poly1.terms[i++];
}
while (j < poly2.termCount) 
{
        result.terms[k++] = poly2.terms[j++];
}
    result.termCount = k;
    return result;
}
int main() 
{
    int termCount1, termCount2;
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &termCount1);
    Polynomial poly1 = createPolynomial(termCount1);
    printf("Enter the terms of the first polynomial:\n");
    inputPolynomial(&poly1);
    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &termCount2);
    Polynomial poly2 = createPolynomial(termCount2);
    printf("Enter the terms of the second polynomial:\n");
    inputPolynomial(&poly2);
    printf("First Polynomial: ");
    displayPolynomial(poly1);
    printf("Second Polynomial: ");
    displayPolynomial(poly2);
    Polynomial result = addPolynomials(poly1, poly2);
    printf("Resultant Polynomial: ");
    displayPolynomial(result);
    free(poly1.terms);
    free(poly2.terms);
    free(result.terms);
    return 0;
}
