//
// Created by Samuel on 11/27/19.
//
#include <stdio.h>
#include <string.h>
#include "run.h"
#include "readAll.h"
#include "readPart.h"
#include "create.h"
#include "delete.h"
#include <unistd.h>
int run(char *var1, int var2,int connection, char*bodyArray,int bodyLength){



    int place=0;
    char inputAction[1024]="";
    char *mystring = inputAction;
    char *c = mystring;
    for(int x=0; x<var2; x++)
    {inputAction[x]=*var1;
        /*increment pointer for next element fetch*/
        var1++;
        place++;
    }
    inputAction[strlen(inputAction)-1] = 0;

    char action[1024] = "";
    char name[1024] = "";
    int bool = 0;
    int partition = 0;
    int bodyStart=1;
    const char *invalid_characters = " ";




        while (*c) {

            switch(bool) {
                case 0 :
                   {
                       bodyStart++;
                       if (strchr(invalid_characters, *c)) {}
                       else {

                           size_t len = strlen(action);
                           action[len++] = *c; /* we overwriting the null-character with another one */
                           action[len] = '\0';

                       }
                       break;
                   }
                case 2 :
                {
                    bodyStart++;
                    partition = (int) (*c);
                    partition = partition - 48;
                    bool = 3;
                    break;
                }
                case 1 :{
                    bodyStart++;
                    if (strchr(invalid_characters, *c)) {
                        bool = 2;
                    } else {
                        size_t nameLen = strlen(name);
                        name[nameLen++] = *c; /* we overwriting the null-character with another one */
                        name[nameLen] = '\0';
                    }
                    break;
                }
            }

            if (strchr(invalid_characters, *c) && bool == 0) {
                printf("\n");
                bool = 1;
            }

            c++;
        }
    char newBody[1024] = "";
    for(int x=0; x<bodyLength; x++)
    {newBody[x]=*bodyArray;
        /*increment pointer for next element fetch*/
        bodyArray++;
    }

        switch(action[0]) {
            case 'c' :
                create(name, strlen(name),partition,newBody,strlen(newBody),bodyStart);
                break;
            case 'd' :
                deleteAll(name, strlen(name));

                break;
            case 'r' :{
                if (partition == 0) {
                    readAll(name, strlen(name),connection);

                } else {
                    readPart(name, strlen(name),partition,connection);

                }
                break;
            }
        }
   //todo trust user input?
    return 0;
}