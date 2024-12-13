#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INT_LEN 10

int parse_args(char* input, int* thread_count, int* num_count);

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

    while ( token != NULL )
    {
        if (strlen(token) >= MAX_INT_LEN + 1)
        {
            perror("Input number is too big");
            return -1;

        }

        for ( int i = 0; i < strlen(token); ++i)
        {
            // :)
            if(i == 0 && (!isdigit(token[i]) && token[i] != '-'))
            {
                perror("Input is not a number");
                return -1;

            }
            else
            {
                continue;
            }

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
