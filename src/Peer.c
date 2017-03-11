#include "PeerUDP.h"

int main(){
    char mensaje[30];

    createSocket(3001);
    
    receiveToMessage(mensaje);

    printf("Mensaje recibido: %s\n", mensaje);

    char * mensaje2 = "adios!";

    sendToMessage(mensaje2,"192.168.15.6",3002);

    printf("Mensaje enviado: %s\n", mensaje2);

    return 0;
}