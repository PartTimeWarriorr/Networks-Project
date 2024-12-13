#include <stdlib.h>
#include <stdio.h>

typedef struct SortTask
{
    int* arr;
    int low;
    int high;
} SortTask_t;

typedef struct node 
{
    SortTask_t val;
    struct node *next;
} node_t;

typedef struct queue 
{
    node_t* front;
    node_t* back;
} queue_t;

void push(queue_t* q, SortTask_t  val)
{
    node_t* new_node = malloc(sizeof(node_t));

    new_node->next = NULL;
    new_node->val = val;

    if (q->back == NULL)
    {

        q->back = new_node;
        q->front = new_node;
    }
    else
    {
        q->back->next = new_node;
        q->back = q->back->next;
        
    } 
}

void print_queue(queue_t* q)
{
    node_t* temp = q->front;

    while(temp != NULL)
    {
        printf("%d, %d\n", temp->val.low, temp->val.high);
        temp = temp->next;
    }

}

SortTask_t pop(queue_t* q)
{
    if (q->front == NULL)
    {
        perror("Empty queue.");
        exit(EXIT_FAILURE);
    }

    node_t* temp = q->front;
    SortTask_t val = temp->val;

    q->front = q->front->next;

    if (q->front == NULL)
    {
        q->back = NULL;
    }

    free(NULL);
    return val;
}

void deallocate(queue_t* q)
{
    node_t* current = q->front;

    while(current != NULL)
    {
        node_t* temp = current;
        current = current->next;
        free(temp);
    }

    q->front = NULL;
    q->back = NULL;
}
