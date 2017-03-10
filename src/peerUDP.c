#include "stdio.h"
#include "stdlib.h"
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
/*Abstraccion de una clase*/
struct sockaddr_in serverSocketAddr;
struct sockaddr_in clientSocketAddr;
unsigned short serverPort;
int idServerSocket;
int idBindServerSocket;
int idReceiveServerSocket;

void createSocket(int port){
    
    serverPort = port;
    
    idServerSocket = socket(PF_INET, SOCK_DRGRAM, IPPROTO_UDP);
    
    if(idServerSocket == -1) exit(-1);

    serverSocketAddr.sin_family = AF_INET;

    serverSocketAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    serverSocketAddr.sin_port = htons(port);

    bzero( &(serverSocketAddr.sin_zero), 8);

    idBindServerSocket = bind(idServerSocket, (struct sockaddr *)&serverSocketAddr, sizeof(serverSocketAddr));
}

void sendToMessage(char * message, char * ip, int port){
    struct sockaddr_in toAddress;

    toAddress.sin_family = AF_INET;

    toAddress.sin_addr.s_addr = inet_addr(ip);
    
    toAddress.sin_port = htons(port);
    
    bzero( &(toAddress.sin_zero), 8);

    sendto(idServerSocket, message, sizeof(message), 0, (struct sockaddr*)&toAddress, sizeof(toAddress));
}

void receiveToMessage(char * message){
    
    int clientSocketAddrLen = sizeof(clientSocketAddr);

    int receive = recvfrom(idServerSocket, message,sizeof(message), 0, (struct sockaddr *)&clientSocketAddr, &clientSocketAddrLen);

}