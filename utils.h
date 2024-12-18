
#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INT_LEN 10

int parse_args(char* input, int* thread_count, int* num_count);
void parse_output_array(int arr[], int num_count, char* buf);
int parse_input_array(char* input, int arr[]);
int consume(char** input, const char** keyword);