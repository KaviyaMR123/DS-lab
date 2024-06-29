#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct 
{
    int value;
    int priority;
} Node;
typedef struct 
{
    Node items[MAX];
    int size;
} PriorityQueue;
PriorityQueue* createPriorityQueue() 
{
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->size = 0;
    return pq;
}
void swap(Node* a, Node* b) 
{
    Node temp = *a;
    *a = *b;
    *b = temp;
}
void heapifyUp(PriorityQueue* pq, int index) 
{
    int parentIndex = (index - 1) / 2;
    if (index > 0 && pq->items[index].priority < pq->items[parentIndex].priority) 
    {
        swap(&pq->items[index], &pq->items[parentIndex]);
        heapifyUp(pq, parentIndex);
    }
}
void heapifyDown(PriorityQueue* pq, int index) 
{
    int leftChildIndex = 2 * index + 1;
    int rightChildIndex = 2 * index + 2;
    int smallest = index;
    if (leftChildIndex < pq->size && pq->items[leftChildIndex].priority < pq->items[smallest].priority) 
    {
        smallest = leftChildIndex;
    }
    if (rightChildIndex < pq->size && pq->items[rightChildIndex].priority < pq->items[smallest].priority) 
    {
        smallest = rightChildIndex;
    }
    if (smallest != index) 
    {
        swap(&pq->items[index], &pq->items[smallest]);
        heapifyDown(pq, smallest);
    }
}
void enqueue(PriorityQueue* pq, int value, int priority) 
{
    if (pq->size == MAX) 
    {
        printf("Priority queue is full!\n");
        return;
    }
    pq->items[pq->size].value = value;
    pq->items[pq->size].priority = priority;
    pq->size++;
    heapifyUp(pq, pq->size - 1);
    printf("%d enqueued to the priority queue with priority %d.\n", value, priority);
}
Node dequeue(PriorityQueue* pq) 
{
    if (pq->size == 0) 
    {
        printf("Priority queue is empty!\n");
        return (Node){-1, -1};
    }
    Node item = pq->items[0];
    pq->items[0] = pq->items[pq->size - 1];
    pq->size--;
    heapifyDown(pq, 0);
    printf("%d dequeued from the priority queue with priority %d.\n", item.value, item.priority);
    return item;
}
void displayQueue(PriorityQueue* pq) 
{
    if (pq->size == 0) 
    {
        printf("Priority queue is empty!\n");
        return;
    }
    printf("Priority Queue:\n");
    for (int i = 0; i < pq->size; i++) 
    {
        printf("Value: %d, Priority: %d\n", pq->items[i].value, pq->items[i].priority);
    }
}

int main()
{
    PriorityQueue* pq = createPriorityQueue();
    int choice, value, priority;
    while (1) 
    {
        printf("\nPriority Queue Menu:\n");
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
                printf("Enter the priority of the value: ");
                scanf("%d", &priority);
                enqueue(pq, value, priority);
                break;
            case 2:
                dequeue(pq);
                break;
            case 3:
                displayQueue(pq);
                break;
            case 4:
                free(pq);
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
