#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#include "utils.c"
#include "m-quicksort.c"

#define BUFF_SIZE 1024

// inet_ntoa() converts IP to readable format
// ntohs() converts the port to host byte order

// server.c
int main()
{

    int my_port = 9800;
    int udp_rec_sock;

    struct sockaddr_in peer_addr;
    struct sockaddr_in my_addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = INADDR_ANY,
        .sin_port = htons(my_port),
    };


    udp_rec_sock = socket(AF_INET, SOCK_DGRAM, 0);

    if ( udp_rec_sock <= 0 )
    {
        perror("Couldn't create socket");
        exit(EXIT_FAILURE);
    }


    int result = bind( udp_rec_sock, (struct sockaddr*)&my_addr, sizeof(my_addr));

    if ( result != 0)
    {
        printf("return value: %d\n", result);
        perror("Could not bind socket to address.");
        exit(EXIT_FAILURE);
    }

    int bytes_received, bytes_sent;
    socklen_t peer_addr_len = sizeof(peer_addr);
    char buffer[BUFF_SIZE];
    char response[BUFF_SIZE];


    while(1)
    {

        if ( (bytes_received = recvfrom(udp_rec_sock, buffer, BUFF_SIZE, 0, (struct sockaddr*)&peer_addr, &peer_addr_len) ) == -1 )
        {
            perror("Couldn't recv message");
            close(udp_rec_sock);
            exit(EXIT_FAILURE);
        }

        if ( consume(buffer, "sort") == -1 )
        {
            strcpy(response, "Usage: sort <thread_count> <array_size> <array_elements>\n");
        }
        else
        {
            parse_and_quicksort(buffer, response);
        }

        if ( (bytes_sent = sendto(udp_rec_sock, response, strlen(response) + 1, 0, (struct sockaddr*)&peer_addr, sizeof(peer_addr)) ) == -1 )
        {
            perror("Failed to send message");
            close(udp_rec_sock);
            exit(EXIT_FAILURE);
        }


        if ( bytes_received == 0 )
        {
            break;
        }


        buffer[0] = '\0';
        response[0] = '\0';
        
    }

    close(udp_rec_sock);
}




void parse_and_quicksort(char* args, char* response)
{
    int thread_count = 0;
    int num_count = 0;
    char args_copy[1024];
    strcpy(args_copy, args);

    if ( (parse_args(args_copy, &thread_count, &num_count)) == -1 )
    {
        printf("Failed to parse arguments\n");
        strcpy(response, "Failed to parse arguments\n");
        return;
    }

    int arr[num_count];

    if ( (parse_input_array(args, arr)) == -1 )
    {
        printf("Failed to parse array\n");
        strcpy(response, "Failed to parse array\n");
        return;
    }

    perform(thread_count, num_count, arr, response);

    parse_output_array(arr, num_count, response);

}