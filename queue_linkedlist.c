#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* next;
};
struct Queue 
{
    struct Node *front, *rear;
};
struct Queue* createQueue();
void enqueue(struct Queue* q, int value);
int dequeue(struct Queue* q);
void display(struct Queue* q);
int main() 
{
    struct Queue* q = createQueue(); 
    int choice, value;
    while(1) 
    {
        printf("\n--- Queue Operations using Linked List ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) 
        {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(q, value);
                break;
            case 2:
                value = dequeue(q);
                if (value != -1) 
                {
                    printf("Dequeued value: %d\n", value);
                }
                break;
            case 3:
                display(q);
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
struct Queue* createQueue() 
{
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}
void enqueue(struct Queue* q, int value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (q->rear == NULL)
    {
        q->front = q->rear = newNode;
        printf("Value enqueued to queue.\n");
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
    printf("Value enqueued to queue.\n");
}
int dequeue(struct Queue* q)
{
    if (q->front == NULL) 
    {
        printf("Queue underflow\n");
        return -1;
    }
    struct Node* temp = q->front;
    int dequeuedValue = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) 
    {
        q->rear = NULL;
    }
    free(temp);
    return dequeuedValue;
}
void display(struct Queue* q) 
{
    if (q->front == NULL) 
    {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = q->front;
    printf("Queue elements: \n");
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

