#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <semaphore.h>
#include "readAll.h"
#include "readPart.h"
#include "create.h"
#include "run.h"
#include "delete.h"
#include "handleTheRequest.h"
#define RESOURCE_SERVER_PORT 8020 // Change this!
#define BUF_SIZE 256

// We make this a global so that we can refer to it in our signal handler
int serverSocket;

/*
 We need to make sure we close the connection on signal received, otherwise we have to wait
 for server to timeout.
 */
void closeConnection() {
    printf("\nClosing Connection with file descriptor: %d \n", serverSocket);
    close(serverSocket);
    exit(1);
}
// Create a separat emethod for



int main(int argc, char *argv[]) {
    int connectionToClient, bytesReadFromClient;

    // Create a server socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serverAddress;
    bzero(&serverAddress, sizeof(serverAddress));
    serverAddress.sin_family      = AF_INET;


    // INADDR_ANY means we will listen to any address
    // htonl and htons converts address/ports to network formats

    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddress.sin_port        = htons(RESOURCE_SERVER_PORT);

    // Bind to port
    if (bind(serverSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) == -1) {
        printf("Unable to bind to port just yet, perhaps the connection has to be timed out\n");
        exit(-1);
    }

    // Before we listen, register for Ctrl+C being sent so we can close our connection
    struct sigaction sigIntHandler;
    sigIntHandler.sa_handler = closeConnection;
    sigIntHandler.sa_flags = 0;

    sigaction(SIGINT, &sigIntHandler, NULL);

    // Listen and queue up to 10 connections
    listen(serverSocket, 10);

    while (1) {
        /*
         Accept connection (this is blocking)
         2nd parameter you can specify connection
         3rd parameter is for socket length
         */
        connectionToClient = accept(serverSocket, (struct sockaddr *) NULL, NULL);

        // Kick off a thread to process request
        pthread_t someThread;
        pthread_create(&someThread, NULL, handleTheRequest, (void *)&connectionToClient);
       // return 0;
    }
    return 0;
}
















//#include <stdio.h>
//#include <string.h>
//#include "readAll.h"
//#include "readPart.h"
//#include "create.h"
//#include "run.h"
//#include "delete.h"
//
//
//int main() {
//
//
//        while(1==1){
//
//            run();
//            printf("anything else?(y/n)\n");
//            char inputAction[40];
//            fgets(inputAction, 40, stdin);
//
//            if(inputAction[0]=='y'){
//            }
//            else{
//                break;
//            }
//        }
//
//
//
//        return 0;
//
//    }