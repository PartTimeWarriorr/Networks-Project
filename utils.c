#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INT_LEN 10

int parse_args(char* input, int* thread_count, int* num_count);

// int main()
// {

    // received input from client
    
    // char input_vars[] = "sort 32 4 1 10 5 44";
    // char test_vars[1024] = "sort 1";
    // int thread_count = 0;
    // int num_count = 0;

    // printf("%d",atoi("-1"));
    

    // consume(test_vars, "sort");
    // printf(test_vars);

    // char input_copy[256];
    // strncpy(input_copy, input_vars, strlen(input_vars));
    // input_copy[strlen(input_vars)] = '\0';
    
    // parse_args(input_copy, &thread_count, &num_count);

    // int arr[num_count];

    // parse_input_array(input_vars, arr);

    // quicksort array (possibly copy it and then sort singlethreaded as well)
    // return information about sorting times

    // char buff[1024];
    // parse_output_array(arr, num_count, buff);
    // printf("%s\n", buff);

    // send sorted array back to client
    // as well as sorting times with the different algo's

// }

int parse_args(char* input, int* thread_count, int* num_count)
{   

    char* token = strtok(input, " ");

    for ( int i = 0; i < strlen(token); ++i)
    {
        if (!isdigit(token[i]))
        {
            perror("Input is not a number");
            return -1;
        }
    }
    *thread_count = atoi(token); // ???

    if(*thread_count == 0)
    {
        printf("Input should be a positive number\n");
        return -1;
    }

// ???
    if ( (token = strtok(NULL, " ")) == 0 )
    {
        printf("Input string is empty\n");
        return -1;
    }
    
    for ( int i = 0; i < strlen(token); ++i)
    {
        if (!isdigit(token[i]))
        {
            perror("Input is not a number");
            return -1;
        }
    }
    *num_count = atoi(token);

    if(*num_count == 0)
    {
        printf("Input should be a positive number\n");
        return -1;
    }

    return 0;

}


void parse_output_array(int arr[], int num_count, char* buf)
{
    strcat(buf, "Sorted array: ");

    for ( int i = 0; i < num_count; ++i )
    {
        char num[256];
        sprintf(num, "%d ", arr[i]);
        strcat(buf, num);
    }

    strcat(buf, "\n");
}


int parse_input_array(char* input, int arr[])
{
    char* token = strtok(input, " ");
    token = strtok(NULL, " ");
    token = strtok(NULL, " ");
    int i = 0;


    // TODO make negative numbers valid
    while ( token != NULL )
    {
        if (strlen(token) >= MAX_INT_LEN + 1)
        {
            perror("Input number is too big");
            return -1;

        }

        for ( int i = 0; i < strlen(token); ++i)
        {
            if (!isdigit(token[i]))
            {
                perror("Input is not a number");
                return -1;
            }
        }
        arr[i++] = atoi(token);
        token = strtok(NULL, " ");
    }

    return 0;

}


int consume(char** input, const char** keyword)
{
    if ( strncmp(input, keyword, strlen(keyword)) == 0 )
    {
        char* ptr = input;
        memmove(ptr, ptr + strlen(keyword) + 1, strlen(input) - strlen(keyword));
    }
    else
    {
        printf("Expected keyword: %s\n", keyword);
        return -1;
    }

    return 0;
}
