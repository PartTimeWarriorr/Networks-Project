#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#define BUFF_SIZE 256

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


    char buffer[256];

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

    int bytes_received;
    socklen_t peer_addr_len = sizeof(peer_addr);

    while(1)
    {

        if ( (bytes_received = recvfrom(udp_rec_sock, buffer, BUFF_SIZE - 1, 0, (struct sockaddr*)&peer_addr, &peer_addr_len) ) == -1 )
        {
            perror("Couldn't recv message");
            close(udp_rec_sock);
            exit(EXIT_FAILURE);
        }

        if ( bytes_received == 0 )
            break;
        
        printf("Received packet from: %s:%d\n", inet_ntoa(peer_addr.sin_addr), ntohs(peer_addr.sin_port));
        printf("Packet is: %d bytes long\n", bytes_received);
        buffer[bytes_received] = '\0';
        printf("Message: %s\n", buffer);
    }

    // socklen_t peer_addr_len = sizeof(peer_addr);
    // int bytes_received = recvfrom(udp_rec_sock, buffer, 256, 0, (struct sockaddr*)&peer_addr, &peer_addr_len);

    // if ( bytes_received <= 0)
    // {
    //     perror("Receive from failed.");
    //     exit(EXIT_FAILURE);
    // }

    // printf("Received a packet from: %s:%d -- Message = %s\n", inet_ntoa(peer_addr.sin_addr), ntohs(peer_addr.sin_port), buffer);

    close(udp_rec_sock);
}


// inet_ntoa() converts IP to readable format
// ntohs() converts the port to host byte order


void perform_quicksort_alg(char** buffer)
{

}