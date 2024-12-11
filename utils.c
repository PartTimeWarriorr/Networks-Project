#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INT_LEN 10

void parse_args(char* input, int* thread_count, int* num_count);

int main()
{
    
    char input_vars[] = "sort 32 4 1 10 5 44";
    int thread_count = 0;
    int num_count = 0;

    consume(input_vars, "sort");

    char input_copy[256];
    strncpy(input_copy, input_vars, strlen(input_vars));
    input_copy[strlen(input_vars)] = '\0';
    
    parse_args(input_copy, &thread_count, &num_count);

    int arr[num_count];

    parse_input(input_vars, arr);
    // printf("%d\n", thread_count);
    // printf("%d\n", num_count);
    // print_arr(arr, num_count);

    char buff[1024];
    parse_output_array(arr, num_count, buff);
    printf("%s\n", buff);



}

void parse_args(char* input, int* thread_count, int* num_count)
{   
    char* token = strtok(input, " ");
    *thread_count = atoi(token);
    token = strtok(NULL, " ");
    *num_count = atoi(token);

}


void parse_output_array(int arr[], int num_count, char* buf)
{
    strcpy(buf, "");

    for ( int i = 0; i < num_count; ++i )
    {
        char num[256];
        sprintf(num, "%d ", arr[i]);
        strcat(buf, num);
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

// void parse_input(char* input, int* thread_count, int* num_count, int arr[])
void parse_input(char* input, int arr[])
{
    char* token = strtok(input, " ");
    token = strtok(NULL, " ");
    token = strtok(NULL, " ");
    int i = 0;


    // printf("Thread count: %d, Num count: %d\n", *thread_count, *num_count);
    while ( token != NULL )
    {
        if (strlen(token) >= MAX_INT_LEN + 1)
        {
            perror("Input number is too big");
            exit(EXIT_FAILURE);

        }

        for ( int i = 0; i < strlen(token); ++i)
        {
            if (!isdigit(token[i]))
            {
                perror("Input is not a number");
                exit(EXIT_FAILURE);
            }
        }
        char* buf[256];
        strcpy(buf, token);
        arr[i++] = atoi(buf);
        token = strtok(NULL, " ");
    }

}


void consume(char** input, const char** keyword)
{
    if ( strncmp(input, keyword, strlen(keyword)) == 0 )
    {
        char* ptr = input;
        memmove(ptr, ptr + strlen(keyword) + 1, strlen(input) - strlen(keyword));
    }
    else
    {
        printf("Expected keyword: %s\n", keyword);
        exit(EXIT_FAILURE);
    }
}


// Input: sort[' ']?<thread-count> <num-count> <separated-nums>