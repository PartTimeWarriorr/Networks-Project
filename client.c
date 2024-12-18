#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#define BUFF_SIZE 4000

// client.c
int main()
{
    const char* peer_ip = "127.0.0.1";
    int peer_port = 9800;

    struct sockaddr_in peer_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(peer_port),
    };

    if ( inet_pton(AF_INET, peer_ip, &peer_addr.sin_addr) <= 0 )
    {
        perror("Invalid IP address.");
        exit(EXIT_FAILURE);
    }

    int udp_sock = socket(AF_INET, SOCK_DGRAM, 0);

    if ( udp_sock <= 0 )
    {
        perror("Couldn't create socket");
        exit(EXIT_FAILURE);
    }

    char msg[BUFF_SIZE];
    char recv_buffer[BUFF_SIZE];
    int bytes_sent, bytes_received;
    socklen_t peer_addr_len = sizeof(peer_addr);

    while(1)
    {
        // Await input from user
        printf("> ");
        fgets(msg, sizeof(msg), stdin);
        msg[strcspn(msg, "\n")] = 0; // gets rid of trailing newline

        // If input == exit: exit client program 
        if ( strncmp(msg, "exit", 4) == 0)
        {
            if ( (bytes_sent = sendto(udp_sock, msg, strlen(msg) + 1, 0, (struct sockaddr*)&peer_addr, sizeof(peer_addr))) == -1 )
            {
                perror("Failed to send message");
                close(udp_sock);
                exit(EXIT_FAILURE);
            }

            break;

        }

        // Send input to server
        if ( (bytes_sent = sendto(udp_sock, msg, strlen(msg) + 1, 0, (struct sockaddr*)&peer_addr, sizeof(peer_addr))) == -1 )
        {
            perror("Failed to send message");
            close(udp_sock);
            exit(EXIT_FAILURE);
        }

        // Receive server output
        if ( (bytes_received = recvfrom(udp_sock, recv_buffer, BUFF_SIZE, 0, (struct sockaddr*)&peer_addr, &peer_addr_len) ) == -1 )
        {
            perror("Couldn't recv message");
            close(udp_sock);
            exit(EXIT_FAILURE);
        }

        // Format received output
        recv_buffer[bytes_received] = '\0';
        printf("\n========================================================\nServer: %s", recv_buffer);
        printf("========================================================\n");


        recv_buffer[0] = '\0';
        msg[0] = '\0';
        
    }

    close(udp_sock);

}

