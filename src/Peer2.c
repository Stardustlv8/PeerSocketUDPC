#include "PeerUDP.h"

int main(){

    createSocket(3002);

    int counter = 0;

    while(1){

        char * mensaje2 = "adios!";

        sendToMessage(mensaje2,"192.168.15.6",3001);

        printf("Mensaje enviado Peer2: %s %d\n", mensaje2, counter);
        
        counter ++ ;

        sleep(1);

    }
    return 0;
}