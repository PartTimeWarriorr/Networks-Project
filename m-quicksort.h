#pragma once

#include "queue.h"
#include <time.h>
#include <pthread.h>
#include <limits.h>

void perform_alg(int thread_count, int num_count, int* arr, char* buffer);
void* run_thread();
void quick_sort(int arr[], int low, int high);
void quick_sort_t(void * params);
void create_sort_task(SortTask_t task);
void quick_sort_s(int arr[], int low, int high);
int partition(int arr[], int low, int high);
int get_random_index(int low, int high);
void swap(int arr[], int ind_1, int ind_2);
void print_arr(int arr[], unsigned long size);

#define MAX_THREADS 100

// global variables ew..
extern pthread_mutex_t thread_lock;
extern pthread_cond_t cond_var;

extern int done;
extern int active_threads;
extern int task_count;

extern queue_t task_queue;

extern pthread_t thread_pool[MAX_THREADS];