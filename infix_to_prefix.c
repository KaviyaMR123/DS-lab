#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
typedef struct 
{
    int top;
    char items[MAX];
} Stack;
void initialize(Stack *s) 
{
    s->top = -1;
}
int isEmpty(Stack *s) 
{
    return s->top == -1;
}
int isFull(Stack *s) 
{
    return s->top == MAX - 1;
}
void push(Stack *s, char value) 
{
    if (isFull(s)) 
    {
        printf("Stack overflow\n");
        return;
    }
    s->items[++s->top] = value;
}
char pop(Stack *s) 
{
    if (isEmpty(s)) 
    {
        printf("Stack underflow\n");
        return -1;
    }
    return s->items[s->top--];
}
char peek(Stack *s) 
{
    if (isEmpty(s)) 
    {
        return -1;
    }
    return s->items[s->top];
}
int precedence(char op) 
{
    switch (op) 
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return 0;
}
void reverseString(char *str) 
{
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) 
    {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}
void infixToPrefix(char infix[], char prefix[]) 
{
    Stack s;
    initialize(&s);
    int n = strlen(infix);
    char infixReversed[MAX];
    char tempPrefix[MAX];
    int j = 0;
    strcpy(infixReversed, infix);
    reverseString(infixReversed);
    for (int i = 0; i < n; i++) 
    {
        if (isalnum(infixReversed[i])) 
        {
            tempPrefix[j++] = infixReversed[i];
        }
        else if (infixReversed[i] == ')') 
        {
            push(&s, infixReversed[i]);
        }
        else if (infixReversed[i] == '(') 
        {
            while (!isEmpty(&s) && peek(&s) != ')') 
            {
                tempPrefix[j++] = pop(&s);
            }
            if (!isEmpty(&s) && peek(&s) != ')') 
            {
                printf("Invalid expression\n");
                return;
            } 
            else
            {
                pop(&s);
            }
        }
        else 
        {
            while (!isEmpty(&s) && precedence(infixReversed[i]) < precedence(peek(&s))) 
            {
                tempPrefix[j++] = pop(&s);
            }
            push(&s, infixReversed[i]);
        }
    }
    while (!isEmpty(&s)) 
    {
        tempPrefix[j++] = pop(&s);
    }
   tempPrefix[j] = '\0';
    strcpy(prefix, tempPrefix);
    reverseString(prefix);
}
int main() 
{
    char infix[MAX], prefix[MAX];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);
    return 0;
}
