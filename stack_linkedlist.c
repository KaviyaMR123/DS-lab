#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* next;
};
void push(struct Node** top, int data);
int pop(struct Node** top);
void display(struct Node* top);
int main() 
{
    struct Node* top = NULL; 
    int choice, value;
    while(1) 
    {
        printf("\n--- Stack Operations using Linked List ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) 
        {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&top, value);
                break;
            case 2:
                value = pop(&top);
                if (value != -1) 
                {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                display(top);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
void push(struct Node** top, int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) 
    {
        printf("Heap overflow\n");
        return;
    }
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
    printf("Value pushed onto stack.\n");
}
int pop(struct Node** top) 
{
    if (*top == NULL) 
    {
        printf("Stack underflow\n");
        return -1;
    }
    struct Node* temp = *top;
    int poppedValue = temp->data;
    *top = (*top)->next;
    free(temp);
    return poppedValue;
}
void display(struct Node* top) 
{
    if (top == NULL) 
    {
        printf("Stack is empty\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack elements: \n");
    while (temp != NULL) 
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
