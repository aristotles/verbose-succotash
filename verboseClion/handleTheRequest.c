//
// Created by Samuel on 12/6/19.
//
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
#include <unistd.h>
#include "run.h"
#include "handleTheRequest.h"
#define BUF_SIZE 256
void * handleTheRequest(void * request) {
    int connectionToClient = *(int *)request;
    char receiveLine[BUF_SIZE];
    char fistLine[BUF_SIZE];
    char sendLine[BUF_SIZE];
    char theBody[BUF_SIZE];
    char allPlace=0;
    int isCreate=0;
    int bytesReadFromClient = 0;
    // Read the request that the client has
    while ( (bytesReadFromClient = read(connectionToClient, receiveLine, BUF_SIZE)) > 0) {
        // Need to put a NULL string terminator at end
        receiveLine[bytesReadFromClient] = 0;

        // Show what client sent
        printf("Received: %s\n", receiveLine);
        if(isCreate==0) {
            if (receiveLine[0] == 'c') {
                for(int x=0; x<strlen(receiveLine); x++)
                {
                    fistLine[x]=receiveLine[x];
                }
                isCreate=1;
            } else {
                run(receiveLine, strlen(receiveLine), connectionToClient,0,0);
                close(connectionToClient);
            }
        }
        else{

            if(receiveLine[0]=='\n'){
                run(fistLine, strlen(fistLine), connectionToClient,theBody,strlen(theBody));
                close(connectionToClient);
            }
            for(int x=0; x<strlen(receiveLine); x++)
            {
                theBody[allPlace]=receiveLine[x];
                allPlace++;
            }
            theBody[strlen(theBody)] = 0;

        }

        // Print text out to buffer, and then write it to client (connfd)
        //  snprintf(sendLine, sizeof(sendLine), "please enter a create,read or delete command");

        printf("Sending %s\n", sendLine);
        //  write(connectionToClient, sendLine, strlen(sendLine));

        // Zero out the receive line so we do not get artifacts from before
        bzero(&receiveLine, sizeof(receiveLine));

    }
    return 0;
}