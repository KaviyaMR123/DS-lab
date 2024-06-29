#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct CircularQueue 
{
    int items[MAX];
    int front;
    int rear;
} CircularQueue;
CircularQueue* createCircularQueue() 
{
    CircularQueue* q = (CircularQueue*)malloc(sizeof(CircularQueue));
    q->front = -1;
    q->rear = -1;
    return q;
}
int isEmpty(CircularQueue* q) 
{
    return q->front == -1;
}
int isFull(CircularQueue* q) 
{
    return (q->rear + 1) % MAX == q->front;
}
void enqueue(CircularQueue* q, int value) 
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
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
    printf("%d enqueued to the queue.\n", value);
}
int dequeue(CircularQueue* q) 
{
    if (isEmpty(q)) 
    {
        printf("Queue is empty!\n");
        return -1;
    }
    int item = q->items[q->front];
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % MAX;
    }
    printf("%d dequeued from the queue.\n", item);
    return item;
}
void displayQueue(CircularQueue* q) 
{
    if (isEmpty(q)) 
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    int i = q->front;
    while (i != q->rear) 
    {
        printf("%d ", q->items[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", q->items[i]);
}
int main() 
{
    CircularQueue* q = createCircularQueue();
    int choice, value;
    while (1) 
    {
        printf("\nCircular Queue Menu:\n");
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
