#pragma once

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


#include "utils.h"
#include "m-quicksort.h"

#define BUFF_SIZE 4000

void parse_and_quicksort(char* args, char* response);
