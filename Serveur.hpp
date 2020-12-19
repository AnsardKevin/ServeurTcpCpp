#ifndef __SERVEUR_HH__
#define __SERVEUR_HH__

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

class Serveur {
    private:
        int sockfd;
        int connfd;
        struct sockaddr_in servaddr;
        struct sockaddr_in cli;
    public:
        Serveur();
        int Connection();
};

#endif