#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

struct ThreadParams 
{
    int* arr;
    int low;
    int high;
};

int main() 
{
    pthread_t t1;

    // pthread_create(&t1, NULL, test_thread, NULL);

    // pthread_join(t1, NULL);

    int arr[] = {1,2,3};
    int low = 0;
    int high = 2;

    struct ThreadParams t_p = {arr, low, high};

    test_thread_struct(&t_p);

}


void test_thread()
{
    printf("Hello.\n");
}


void test_thread_struct(void * params)
{
    struct ThreadParams* t_p = (struct ThreadParams*) params;

    int* arr = t_p->arr;
    int low = t_p->low;
    int high = t_p->high;

    for (int i = 0; i <= high; ++i)
    {
        printf("%d\n", arr[i]);
    }

}