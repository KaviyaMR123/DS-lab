#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct Queue 
{
    int items[MAX];
    int front;
    int rear;
} Queue;
Queue* createQueue() 
{
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}
int isEmpty(Queue* q) 
{
    return q->front == -1;
}
int isFull(Queue* q) 
{
    return q->rear == MAX - 1;
}
void enqueue(Queue* q, int value) 
{
    if (isFull(q)) 
    {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(q)) 
    {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
    printf("%d enqueued to the queue.\n", value);
}
int dequeue(Queue* q) 
{
    if (isEmpty(q)) 
    {
        printf("Queue is empty!\n");
        return -1;
    }
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    printf("%d dequeued from the queue.\n", item);
    return item;
}
void displayQueue(Queue* q) 
{
    if (isEmpty(q)) 
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++) 
    {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main() 
{
    Queue* q = createQueue();
    int choice, value;
    while (1) 
    {
        printf("\nQueue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(q, value);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                displayQueue(q);
                break;
            case 4:
                free(q);
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
