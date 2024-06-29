#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
} Node;
Node* createNode(int data) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void displayForward(Node* head) 
{
    if (head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    Node* current = head;
    printf("List in forward order: ");
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
void displayReverse(Node* tail)
{
    if (tail == NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    Node* current = tail;
    printf("List in reverse order: ");
    while (current != NULL) 
    {
        printf("%d -> ", current->data);
        current = current->prev;
    }
    printf("NULL\n");
}
void insertAtBeginning(Node** head, Node** tail, int data) 
{
    Node* newNode = createNode(data);
    if (*head == NULL) 
    {
        *head = *tail = newNode;
    } 
    else
    {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
    printf("Inserted %d at the beginning.\n", data);
}
void insertAtEnd(Node** head, Node** tail, int data) 
{
    Node* newNode = createNode(data);
    if (*tail == NULL)
    {
        *head = *tail = newNode;
    }
    else
    {
        newNode->prev = *tail;
        (*tail)->next = newNode;
        *tail = newNode;
    }
    printf("Inserted %d at the end.\n", data);
}
void deleteFromBeginning(Node** head, Node** tail)
{
    if (*head == NULL) 
    {
        printf("The list is empty.\n");
        return;
    }
    Node* temp = *head;
    if (*head == *tail)
    {
        *head = *tail = NULL;
    }
    else
    {
        *head = (*head)->next;
        (*head)->prev = NULL;
    }
    printf("Deleted %d from the beginning.\n", temp->data);
    free(temp);
}
void deleteFromEnd(Node** head, Node** tail) 
{
    if (*tail == NULL) 
    {
        printf("The list is empty.\n");
        return;
    }
    Node* temp = *tail;
    if (*head == *tail)
    {
        *head = *tail = NULL;
    }
    else
    {
        *tail = (*tail)->prev;
        (*tail)->next = NULL;
    }
    printf("Deleted %d from the end.\n", temp->data);
    free(temp);
}
int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    int choice, data;
    while (1) 
    {
        printf("\nMenu:\n");
        printf("1. Display forward\n");
        printf("2. Display reverse\n");
        printf("3. Insert at beginning\n");
        printf("4. Insert at end\n");
        printf("5. Delete from beginning\n");
        printf("6. Delete from end\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                displayForward(head);
                break;
            case 2:
                displayReverse(tail);
                break;
            case 3:
                printf("Enter the data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, &tail, data);
                break;
            case 4:
                printf("Enter the data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(&head, &tail, data);
                break;
            case 5:
                deleteFromBeginning(&head, &tail);
                break;
            case 6:
                deleteFromEnd(&head, &tail);
                break;
            case 7:
                printf("Exiting...\n");
                while (head != NULL)
                {
                    deleteFromBeginning(&head, &tail);
                }
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
