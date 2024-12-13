#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include <limits.h>
#include "queue.c"


void swap(int arr[], int ind_1, int ind_2);
void print_arr(int arr[], unsigned long size);
void quick_sort(int arr[], int low, int high);
void quick_sort_t(void * params);
int partition(int arr[], int low, int high);
int get_random_index(int low, int high);
void create_sort_task(SortTask_t task);
void* run_thread();

#define MAX_THREADS 100

// global variables ew..
pthread_mutex_t thread_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_var = PTHREAD_COND_INITIALIZER;

int done = 0;
int active_threads = 0;
int task_count = 0;
queue_t task_queue;


pthread_t thread_pool[MAX_THREADS]; 


void perform_alg(int thread_count, int num_count, int* arr, char* buffer)
{
    int arr_2[num_count];
    for(int i = 0; i < num_count; ++i)
    {
        arr_2[i] = arr[i];
    }

    clock_t start = clock();


    // Multi-thread quicksort
    for (int i = 0; i < thread_count; ++i)
    {
        if(pthread_create(&thread_pool[i], NULL, &run_thread, NULL) != 0)
        {
            perror("Thread not created\n");
            return;
        }
    }

    quick_sort(arr, 0, num_count - 1);

    // Main thread constantly checks if there are any active threads or tasks
    pthread_mutex_lock(&thread_lock);
    while(task_count > 0 || active_threads > 0)
    {
        // ?
        pthread_mutex_unlock(&thread_lock);
        pthread_mutex_lock(&thread_lock);
    }
    done = 1;
    pthread_cond_broadcast(&cond_var);
    pthread_mutex_unlock(&thread_lock);

    for (int i = 0; i < thread_count; ++i)
    {
        if(pthread_join(thread_pool[i], NULL) != 0)
        {
            perror("Thread not joined\n");
            return;
        }
    }

    clock_t stop = clock();

    deallocate(&task_queue);


    clock_t start_2 = clock();

    // Single-thread quicksort
    quick_sort_s(arr_2, 0, num_count - 1);


    clock_t stop_2 = clock();

    sprintf(buffer, "\nMultithreaded quicksort ran for: %6.3f seconds\n        On %d threads\nSinglethreaded quicksort ran for: %6.3f seconds\n        On 1 thread\n", ((double)stop - start)/CLOCKS_PER_SEC, thread_count, ((double)stop_2 - start_2)/CLOCKS_PER_SEC);

}


void create_sort_task(SortTask_t task)
{
    pthread_mutex_lock(&thread_lock);
    push(&task_queue, task);
    ++task_count;
    pthread_mutex_unlock(&thread_lock);

    pthread_cond_signal(&cond_var);
}


// Worker thread(s) function
void* run_thread()
{

    while(1)
    {
        SortTask_t  task;

        pthread_mutex_lock(&thread_lock);
        while (task_count == 0 && !done)
        {
            pthread_cond_wait(&cond_var, &thread_lock);
        }

        if(done && task_count == 0)
        {
            pthread_mutex_unlock(&thread_lock);
            break;
        }

        task = pop(&task_queue);
        --task_count;
        ++active_threads;
        pthread_mutex_unlock(&thread_lock);

        quick_sort_t(&task);

        pthread_mutex_lock(&thread_lock);
        --active_threads;
        pthread_mutex_unlock(&thread_lock);        
    }

}

int get_random_index(int low, int high)
{
    return rand() % (high - low + 1) + low;
}

int partition(int arr[], int low, int high)
{
    int pivot_index = get_random_index(low, high);
    int pivot = arr[pivot_index];

    swap(arr, pivot_index, high);

    int i = low - 1;

    for (int j = low; j < high; ++j)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr, i, j);
        }
    }

    swap(arr, i + 1, high);
    return i + 1;
}


void quick_sort_t(void* params)
{
    SortTask_t* task_params = (SortTask_t *) params;

    int* arr = task_params->arr;
    int low = task_params->low;
    int high = task_params->high;

    if (low < high)
    {
        int part_index = partition(arr, low, high); 

        SortTask_t task_params_left = {arr, low, part_index - 1};
        SortTask_t task_params_right = {arr, part_index + 1, high};

        create_sort_task(task_params_left);
        create_sort_task(task_params_right);
    }

}

void quick_sort(int arr[], int low, int high)
{
    SortTask_t params = {arr, low, high};

    quick_sort_t(&params);
}

// Single-threaded quicksort
void quick_sort_s(int arr[], int low, int high)
{

    if (low < high)
    {
        int part_index = partition(arr, low, high);

        quick_sort_s(arr, low, part_index - 1);
        quick_sort_s(arr, part_index + 1, high);
    }
}

void print_arr(int arr[], unsigned long size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int arr[], int ind_1, int ind_2)
{
    int temp = arr[ind_1];
    arr[ind_1] = arr[ind_2];
    arr[ind_2] = temp; 
}
