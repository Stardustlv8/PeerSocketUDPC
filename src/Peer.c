#include "PeerUDP.h"

int main(){

    char mensaje[30];

    createSocket(3001);
    
    run();

    int counter = 0;

    while(1){

        char * mensaje2 = "adios!";

        sendToMessage(mensaje2,"192.168.15.6",3002);

        printf("Mensaje enviado: %s %d\n", mensaje2, counter);

        counter++;

        sleep(1);

    }

    return 0;

}