#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#define BUFF_SIZE 256

// client.c
int main()
{

    const char* peer_ip = "127.0.0.1";
    int peer_port = 9800;
    // const char* msg = "I am a UDP datagram";

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
    int bytes_sent;


    while(1)
    {
        printf("> ");
        fgets(msg, sizeof(msg), stdin);
        msg[strcspn(msg, "\n")] = 0; // gets rid of trailing newline

        if ( strncmp(msg, "exit", 4) == 0)
            break;

        if ( (bytes_sent = sendto(udp_sock, msg, strlen(msg) + 1, 0, (struct sockaddr*)&peer_addr, sizeof(peer_addr))) == -1 )
        {
            perror("Failed to send message");
            close(udp_sock);
            exit(EXIT_FAILURE);
        }

        printf("Sent: \"%s\", to: %s:%d\n", msg, peer_ip, peer_port);
        
    }




    close(udp_sock);

}

