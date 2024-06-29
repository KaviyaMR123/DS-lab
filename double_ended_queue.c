#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct 
{
    int items[MAX];
    int front;
    int rear;
    int size;
} Deque;
Deque* createDeque() 
{
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->front = -1;
    dq->rear = 0;
    dq->size = 0;
    return dq;
}
int isFull(Deque* dq) 
{
    return dq->size == MAX;
}
int isEmpty(Deque* dq) 
{
    return dq->size == 0;
}
void insertFront(Deque* dq, int value) 
{
    if (isFull(dq))
    {
        printf("Deque is full!\n");
        return;
    }
    if (isEmpty(dq))
    {
        dq->front = dq->rear = 0;
    }
    else 
    {
        dq->front = (dq->front - 1 + MAX) % MAX;
    }
    dq->items[dq->front] = value;
    dq->size++;
    printf("%d inserted at the front of the deque.\n", value);
}
void insertRear(Deque* dq, int value) 
{
    if (isFull(dq)) 
    {
        printf("Deque is full!\n");
        return;
    }
    if (isEmpty(dq)) 
    {
        dq->front = dq->rear = 0;
    } 
    else
    {
        dq->rear = (dq->rear + 1) % MAX;
    }
    dq->items[dq->rear] = value;
    dq->size++;
    printf("%d inserted at the rear of the deque.\n", value);
}
int deleteFront(Deque* dq) 
{
    if (isEmpty(dq)) 
    {
        printf("Deque is empty!\n");
        return -1;
    }
    int value = dq->items[dq->front];
    dq->front = (dq->front + 1) % MAX;
    dq->size--;
    if (dq->size == 0) 
    {
        dq->front = -1;
        dq->rear = 0;
    }
    printf("%d deleted from the front of the deque.\n", value);
    return value;
}
int deleteRear(Deque* dq) 
{
    if (isEmpty(dq))
    {
        printf("Deque is empty!\n");
        return -1;
    }
    int value = dq->items[dq->rear];
    dq->rear = (dq->rear - 1 + MAX) % MAX;
    dq->size--;
    if (dq->size == 0) 
    {
        dq->front = -1;
        dq->rear = 0;
    }
    printf("%d deleted from the rear of the deque.\n", value);
    return value;
}
void displayDeque(Deque* dq)
{
    if (isEmpty(dq)) 
    {
        printf("Deque is empty!\n");
        return;
    }
    printf("Deque: ");
    int i = dq->front;
    for (int count = 0; count < dq->size; count++) 
    {
        printf("%d ", dq->items[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() 
{
    Deque* dq = createDeque();
    int choice, value;
    while (1) 
    {
        printf("\nDeque Menu:\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                printf("Enter the value to insert at the front: ");
                scanf("%d", &value);
                insertFront(dq, value);
                break;
            case 2:
                printf("Enter the value to insert at the rear: ");
                scanf("%d", &value);
                insertRear(dq, value);
                break;
            case 3:
                deleteFront(dq);
                break;
            case 4:
                deleteRear(dq);
                break;
            case 5:
                displayDeque(dq);
                break;
            case 6:
                free(dq);
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
