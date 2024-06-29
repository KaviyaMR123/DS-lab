#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node* next;
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
    return newNode;
}

void displayList(Node* head) 
{
    if (head == NULL) 
    {
        printf("The list is empty.\n");
        return;
    }
    Node* current = head;
    while (current != NULL) 
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
void insertAtBeginning(Node** head, int data)
{
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    printf("Inserted %d at the beginning.\n", data);
}
void insertAtEnd(Node** head, int data) 
{
    Node* newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else 
    {
        Node* current = *head;
        while (current->next != NULL) 
        {
            current = current->next;
        }
        current->next = newNode;
    }
    printf("Inserted %d at the end.\n", data);
}
void insertAtPosition(Node** head, int data, int position)
{
    if (position < 1) 
    {
        printf("Invalid position.\n");
        return;
    }
    Node* newNode = createNode(data);
    if (position == 1)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else
    {
        Node* current = *head;
        for (int i = 1; i < position - 1 && current != NULL; i++) 
        {
            current = current->next;
        }
        if (current == NULL)
        {
            printf("Position out of range.\n");
            free(newNode);
        } 
        else
        {
            newNode->next = current->next;
            current->next = newNode;
        }
    }
    printf("Inserted %d at position %d.\n", data, position);
}
void deleteFromBeginning(Node** head) 
{
    if (*head == NULL) 
    {
        printf("The list is empty.\n");
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    printf("Deleted %d from the beginning.\n", temp->data);
    free(temp);
}
void deleteFromEnd(Node** head)
{
    if (*head == NULL) 
    {
        printf("The list is empty.\n");
        return;
    }
    Node* current = *head;
    Node* previous = NULL;
    while (current->next != NULL)
    {
        previous = current;
        current = current->next;
    }
    if (previous == NULL) 
    {
        *head = NULL;
    } 
    else
    {
        previous->next = NULL;
    }
    printf("Deleted %d from the end.\n", current->data);
    free(current);
}
void deleteFromPosition(Node** head, int position) 
{
    if (*head == NULL) 
    {
        printf("The list is empty.\n");
        return;
    }
    if (position < 1) 
    {
        printf("Invalid position.\n");
        return;
    }
    Node* current = *head;
    if (position == 1)
    {
        *head = current->next;
        printf("Deleted %d from position %d.\n", current->data, position);
        free(current);
        return;
    }
    Node* previous = NULL;
    for (int i = 1; i < position && current != NULL; i++)
    {
        previous = current;
        current = current->next;
    }
    if (current == NULL)
    {
        printf("Position out of range.\n");
    } 
    else
    {
        previous->next = current->next;
        printf("Deleted %d from position %d.\n", current->data, position);
        free(current);
    }
}
int main() 
{
    Node* head = NULL;
    int choice, data, position;
    while (1) 
    {
        printf("\nMenu:\n");
        printf("1. Display\n");
        printf("2. Insert at beginning\n");
        printf("3. Insert at end\n");
        printf("4. Insert at a specified position\n");
        printf("5. Delete from beginning\n");
        printf("6. Delete from end\n");
        printf("7. Delete from a specified position\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                displayList(head);
                break;
            case 2:
                printf("Enter the data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 3:
                printf("Enter the data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 4:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 5:
                deleteFromBeginning(&head);
                break;
            case 6:
                deleteFromEnd(&head);
                break;
            case 7:
                printf("Enter the position: ");
                scanf("%d", &position);
                deleteFromPosition(&head, position);
                break;
            case 8:
                printf("Exiting...\n");
                while (head != NULL) 
                {
                    deleteFromBeginning(&head);
                }
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
