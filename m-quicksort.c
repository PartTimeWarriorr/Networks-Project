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
void create_sort_task(SortTask task);
void* run_thread();

#define MAX_THREADS 32
#define THRESHOLD 50000

pthread_mutex_t thread_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_var = PTHREAD_COND_INITIALIZER;

int done = 0;
int active_threads = 0;
queue_t task_queue;
int task_count = 0;


pthread_t thread_arr[MAX_THREADS]; 





int main()
{

    // ========================================================

    clock_t start = clock();

    unsigned long int N = 2000000;
    int arr[N];
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 10000; // Random numbers between 0 and 9999
    }

    int size = sizeof(arr) / sizeof(int);
    // printf("%d\n", size);

    for (int i = 0; i < MAX_THREADS; ++i)
    {
        if(pthread_create(&thread_arr[i], NULL, &run_thread, NULL) != 0)
        {
            perror("Thread not created\n");
            return;
        }
    }


    quick_sort(arr, 0, size - 1);

    
    pthread_mutex_lock(&thread_lock);
    while(task_count > 0 || active_threads > 0)
    {
        pthread_cond_wait(&cond_var, &thread_lock);
    }
    done = 1;
    pthread_cond_broadcast(&cond_var);
    pthread_mutex_unlock(&thread_lock);




    for (int i = 0; i < MAX_THREADS; ++i)
    {
        if(pthread_join(thread_arr[i], NULL) != 0)
        {
            perror("Thread not joined\n");
            return;
        }
    }

    clock_t stop = clock();



    // Stack input
    printf("Multiple threads\n");
    print_arr(arr, size - 1);
    printf("%6.3f seconds\n", ((double)stop - start)/CLOCKS_PER_SEC);
    deallocate(&task_queue);
    
    // =========================================


}

void create_sort_task(SortTask task)
{
    pthread_mutex_lock(&thread_lock);
    // !
    push(&task_queue, task);
    ++task_count;
    pthread_mutex_unlock(&thread_lock);

    pthread_cond_signal(&cond_var);
}

void* run_thread()
{

    while(1)
    {
        SortTask task;

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
        // !
        task = pop(&task_queue);

        --task_count;
        // ++active_threads;
        pthread_mutex_unlock(&thread_lock);

        quick_sort_t(&task);

        // pthread_mutex_lock(&thread_lock);

        // --active_threads;

        // if (task_count == 0 && active_threads == 0)
        // {
        //     pthread_cond_signal(&cond_var);
        // }

        // pthread_mutex_unlock(&thread_lock);        
    }

}

int get_random_index(int low, int high)
{
    // int seed = time(NULL);

    // return rand_r(&seed) % (high - low + 1) + low;
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
    SortTask* task_params = (SortTask *) params;

    int* arr = task_params->arr;
    int low = task_params->low;
    int high = task_params->high;

    // print_arr(arr, high);
    // printf("low: %d, high: %d\n", low, high);


    if (low < high)
    {
        int part_index = partition(arr, low, high); 

        SortTask task_params_left = {arr, low, part_index - 1};
        SortTask task_params_right = {arr, part_index + 1, high};

        if (high - low < THRESHOLD)
        {

            create_sort_task(task_params_left);
            create_sort_task(task_params_right);
        }
        else
        {
            quick_sort_s(arr, low, part_index - 1);
            quick_sort_s(arr, part_index + 1, high);
        }


    }

}

void quick_sort(int arr[], int low, int high)
{
    SortTask params = {arr, low, high};

    quick_sort_t(&params);
}

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
