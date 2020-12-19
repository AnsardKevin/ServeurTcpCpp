#include <stdio.h> 
#include <netdb.h> 
#include <unistd.h>
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <arpa/inet.h>
#include <signal.h>
#include <iostream>

#include "Serveur.hpp"

#define MAX 80 
#define PORT 8080 
#define SA struct sockaddr 


Serveur::Serveur() {
    this->sockfd = 0;
    this->connfd = 0;

    // assign IP, PORT 
    this->servaddr.sin_addr.s_addr = inet_addr("0.0.0.0"); 
    this->servaddr.sin_family = AF_INET; 
    this->servaddr.sin_port = htons(PORT); 
}

// Function designed for chat between client and server. 
void func(int sockfd) 
{ 
    char buff[MAX]; 
    int n; 
    // infinite loop for chat 
//    for (;;) { 
        bzero(buff, MAX); 
  
        // read the message from client and copy it in buffer 
        send(sockfd, "hello world!!!\n", sizeof("hello world!!!\n"), 0);
/*        read(sockfd, buff, sizeof(buff)); 
        // print buffer which contains the client contents 
        printf("From client: %s\t To client : ", buff); 
        bzero(buff, MAX); 
        n = 0; 
        // copy server message in the buffer 
        while ((buff[n++] = getchar()) != '\n') 
            ; 
  
        // and send that buffer to client 
        write(sockfd, buff, sizeof(buff)); 
  
        // if msg contains "Exit" then server exit and chat ended. 
        if (strncmp("exit", buff, 4) == 0) { 
            printf("Server Exit...\n"); 
            break; 
        } 
        */
//    } 
}


int Serveur::Connection() {
    socklen_t len = 0;
    this->sockfd = socket(AF_INET, SOCK_STREAM, 0); 

    if (this->sockfd == -1) { 
        printf("socket creation failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully created..\n"); 
  
    // Binding newly created socket to given IP and verification 
    if ((bind(this->sockfd, (struct sockaddr *)&this->servaddr, sizeof(this->servaddr))) != 0) { 
        printf("socket bind failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully binded..\n"); 
  
    // Now server is ready to listen and verification 
    if ((listen(this->sockfd, 5)) != 0) { 
        printf("Listen failed...\n"); 
        exit(0); 
    } 
    else
        printf("Server listening..\n"); 
    len = sizeof(this->cli); 
  
    // Accept the data packet from client and verification 
    this->connfd = accept(this->sockfd, (struct sockaddr *)&this->cli, &len);
//    connfd = accept(sockfd, (SA*)&cli, &len); 
    if (this->connfd < 0) { 
        printf("server acccept failed...\n"); 
        exit(0); 
    } 
    else
        printf("server acccept the client...\n"); 
  
    // Function for chatting between client and server 
    func(this->connfd); 
  
    // After chatting close the socket 
    close(this->sockfd);
    return 0;
} 
  
// Driver function
int main() 
{
    Serveur *serv = new Serveur();
    serv->Connection();
    return 0;
}