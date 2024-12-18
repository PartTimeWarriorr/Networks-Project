#pragma once

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


void push(queue_t* q, SortTask_t  val);
void print_queue(queue_t* q);
SortTask_t pop(queue_t* q);
void deallocate(queue_t* q);