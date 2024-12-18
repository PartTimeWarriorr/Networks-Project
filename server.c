#include "server.h"


// server.c
int main()
{

    int my_port = 9800;
    int udp_sock;

    struct sockaddr_in peer_addr;
    struct sockaddr_in my_addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = INADDR_ANY,
        .sin_port = htons(my_port),
    };

    udp_sock = socket(AF_INET, SOCK_DGRAM, 0);

    if ( udp_sock <= 0 )
    {
        perror("Couldn't create socket");
        exit(EXIT_FAILURE);
    }


    int result = bind( udp_sock , (struct sockaddr*)&my_addr, sizeof(my_addr));
    if ( result != 0)
    {
        perror("Could not bind socket to address.");
        exit(EXIT_FAILURE);
    }

    int bytes_received, bytes_sent;
    socklen_t peer_addr_len = sizeof(peer_addr);
    char buffer[BUFF_SIZE];
    char response[BUFF_SIZE];


    while(1)
    {

        // Receive message from client
        if ( (bytes_received = recvfrom(udp_sock, buffer, BUFF_SIZE, 0, (struct sockaddr*)&peer_addr, &peer_addr_len) ) == -1 )
        {
            perror("Couldn't recv message");
            close(udp_sock);
            exit(EXIT_FAILURE);
        }

        if ( strncmp(buffer, "exit", 4) == 0 ) // Check for exit command
        {
            break;
        }
        else if ( consume(buffer, "sort") == -1 ) // Check for sort command 
        {
            strcpy(response, "Usage: sort <thread_count> <array_size> <array_elements>\n");
        }
        else
        {
            parse_and_quicksort(buffer, response);
        }

        // Send response to client
        if ( (bytes_sent = sendto(udp_sock, response, strlen(response) + 1, 0, (struct sockaddr*)&peer_addr, sizeof(peer_addr)) ) == -1 )
        {
            perror("Failed to send message");
            close(udp_sock);
            exit(EXIT_FAILURE);
        }


        if ( bytes_received == 0 )
        {
            break;
        }


        buffer[0] = '\0';
        response[0] = '\0';
        
    }

    close(udp_sock);
}




void parse_and_quicksort(char* args, char* response)
{
    int thread_count = 0;
    int num_count = 0;
    char args_copy[2048];
    strcpy(args_copy, args);

    // Parses thread_count and num_count 
    if ( (parse_args(args_copy, &thread_count, &num_count)) == -1 )
    {
        printf("Failed to parse arguments\n");
        strcpy(response, "Failed to parse arguments\n");
        return;
    }

    // Init array...
    int arr[num_count];

    // Parses input array
    if ( (parse_input_array(args, arr)) == -1 )
    {
        printf("Failed to parse array\n");
        strcpy(response, "Failed to parse array\n");
        return;
    }

    // Executes single- and multi-threaded quicksort with the input parameters
    perform_alg(thread_count, num_count, arr, response);

    // Parses output array and stores it in response buffer
    parse_output_array(arr, num_count, response);

}