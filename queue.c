

#include <stdio.h>
#include <stdlib.h>

struct line
{
    int m;
    int n;
    int *arr;
    int size;
};

int isEmpty(struct line *q)
{ 
    if (q->n == q->m)
        return 1;
    else
        return 0;
}

int isFull(struct line *q)
{
    if (q->n == q->size - 1)
        return 1;
    else
        return 0;
}

void enqueue(struct line *q, int data)
{
    if (isFull(q))
    {
        printf("Queue is full.\n");
    }
    q->n++;              
    q->arr[q->n] = data;
}

int dequeue(struct line *q)
{
    int x;
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
    }
    else
    {
        q->m++; 
        x = q->arr[q->m];
    }
    return x;
}

int main()
{

    struct line q;
    q.size = 10;
    q.m = q.n = -1; 
    q.arr = (int *)malloc(q.size * (sizeof(int *)));

    enqueue(&q, 22);
    enqueue(&q, 33);
    enqueue(&q, 44);

    printf("Dequeuing the elements: %d ", dequeue(&q));
    printf("%d", dequeue(&q));
    if (isFull(&q))
    {
        printf("Queue is full.\n");
    }

    if (isEmpty(&q))
    {
        printf("Queue is empty.\n");
    }
    return 0;
}
