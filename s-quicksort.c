#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <limits.h>



int main()
{
    // int arr[] = {111,111,11,1,1,11,1,1,1,1,1,1,1,1,1,1,1,1,1,111111,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,1,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,1,1,1,1,1,1,1,11,111,1,1,1,1,1,1,1,1,1,1,1,11,111,1,1,1,1,1,1,1,1,1,1,1,11,111,1,1,1,1,1,1,1,1,1,1,1,11,111,1,1,1,1,1,1,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,1,11,111,1,1,1,1,1,1,1,1,1,1,1,11,111,1,1,1,1,1,1,1,1,1,11,111,1,1,1,1,1,1,1,1,1,11,111,1,1,1,1,1,1,1,1,1,11,111,1,1,1,1,1,1,1,1,1,11,111,1,1,1,1,1,1,1,1,1,11,111,1,1,1,1,1,1,1,1,1,11,111,1,1,1,1,1,1,1,1,1,11,111,1,1,1,1,1,1,1,1,1,11,111,1,1,1,1,1,1,1,1,1,11,111,1,1,1,1,1,1,1,1,1,11,111,1,1,1,1,1,1,1,1,1,11,111,1,1,1,1,1,1,1,1,1,11,111,1,1,1,1,1,1,1,1,1,11,111,1,1,1,1,1,1,1,1,1,11,111,1,1,1,1,1,1,1,1,1,11,11,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1111111,111,11,111,11,11,11,11,11111111111111111111,11,11,11,11,11,11,111,1111111111111111111111111,1111111111111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,11,11,111,11,11,11,11,111,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,11,1,1,1,1,1,1,1};
    // int size = sizeof(arr) / sizeof(int);
    // quick_sort(arr, 0, size - 1);

    clock_t start = clock();


    unsigned long int N = 2000000;
    int arr[N];
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 10000; // Random numbers between 0 and 9999
    }
    quick_sort(arr, 0, N - 1);

    clock_t stop = clock();


    printf("Single thread\n");
    printf("%6.3f seconds\n", ((double)stop - start)/CLOCKS_PER_SEC);
    // print_arr(arr, N - 1);

    // int arr_big[] = {111,111,11,1,1,11,1,1,1,1,1,1,1,1,1,1,1,1,1,111111,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,1,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,1,1,1,1,1,1,1,11,111,1,1,1,1,1,1,1,1,1,1,1,11,111,1,1,1,1,1,1,1,1,1,1,1,11,111,1,1,1,1,1,1,1,1,1,1,1,11,111,1,1,1,1,1,1,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,11,111,1,1,1,1,11,1,1,1,1,1,1,11,111,1,1,1,1,1,1,1,1,1,1,1,11,111,1,1,1,1,1,1,1,1,1,11,111,1,1,1,1,1,1,1,1,1,11,111,1,1,1,1,1,1,1,1,1,11,111,1,1,1,1,1,1,1,1,1,11,111,1,1,1,1,1,1,1,1,1,11,111,1,1,1,1,1,1,1,1,1,11,111,1,1,1,1,1,1,1,1,1,11,111,1,1,1,1,1,1,1,1,1,11,111,1,1,1,1,1,1,1,1,1,11,111,1,1,1,1,1,1,1,1,1,11,111,1,1,1,1,1,1,1,1,1,11,111,1,1,1,1,1,1,1,1,1,11,111,1,1,1,1,1,1,1,1,1,11,111,1,1,1,1,1,1,1,1,1,11,111,1,1,1,1,1,1,1,1,1,11,11,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1111111,111,11,111,11,11,11,11,11111111111111111111,11,11,11,11,11,11,111,1111111111111111111111111,1111111111111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,11,11,111,11,11,11,11,111,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,111,11,11,11,11,11,11,11,1,1,1,1,1,1,1};
    // int size_big = sizeof(arr_big) / sizeof(int);
    // quick_sort(arr_big, 0, size_big - 1);
    // print_arr(arr_big, size_big);

    // tests?

    // 1.
    // int seed = time(NULL);

    // for (int i = 0; i < 10; i++)
    // {
    //     int rd = rand_r(&seed) % (10 - 1 + 1) + 1;
    //     printf("%d\n", rd);
    // }

    // 2.
    // int arr[] = {1,2,3};
    // int size = sizeof(arr) / sizeof(int);
    // printf("%d\n", size);

    // 3.
    // int arr_2[] = {2,4,5,6};
    // int size_2 = sizeof(arr_2) / sizeof(int);
    // swap(arr_2, 0, 2);
    // print_arr(arr_2, size_2);


    // 4. 
    // int arr_3[] = {10, 8, 7, 3, 11, 3, 11, 4, 5, 3, 11, 4, 5, 3, 11, 4, 5, 3, 11, 4, 5, 3, 11, 4, 5, 3, 11, 4, 5, 3, 11, 4, 5, 3, 11, 4, 5, 4, 5, 3, 3, 11, 4, 5, 3, 11, 4, 5, 3, 11, 4, 5, 3, 11, 4, 5, 11, 4, 5};
    // int size_3 = sizeof(arr_3) / sizeof(int);    
    // print_arr(arr_3, size_3);
    
    // quick_sort(arr_3, 0, size_3 - 1);
    // print_arr(arr_3, size_3);

}

int get_random_index(int low, int high)
{
    int seed = time(NULL);

    return rand_r(&seed) % (high - low + 1) + low;
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

void quick_sort(int arr[], int low, int high)
{

    if (low < high)
    {
        int part_index = partition(arr, low, high); 

        quick_sort(arr, low, part_index - 1);
        quick_sort(arr, part_index + 1, high);
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
