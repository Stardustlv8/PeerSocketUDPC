#include "PeerUDP.h"

int main(){

    char * mensaje = "Hola!";
    char mensaje2[30];
    createSocket(3002);
    
    sendToMessage(mensaje,"192.168.15.6",3001);
    
    printf("Mensaje enviado: %s\n", mensaje);
    
    receiveToMessage(mensaje2);

    printf("Peer 2 Mensaje recibido: %s\n", mensaje2);

    return 0;
}