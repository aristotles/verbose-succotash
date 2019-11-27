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
int run(){
    char inputAction[40];
    char action[1024] = "";
    char name[1024] = "";
    int bool = 0;
    int partition = 0;
    const char *invalid_characters = " ";
    char *mystring = inputAction;
    char *c = mystring;

    printf("hello what should we do:\n");
    fgets(inputAction, 80, stdin);

        while (*c) {

            switch(bool) {
                case 0 :
                   {
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
                    partition = (int) (*c);
                    partition = partition - 48;
                    bool = 3;
                    break;
                }
                case 1 :{

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

        switch(action[0]) {
            case 'c' :
                create(name, strlen(name),partition);
                break;
            case 'd' :
                deleteAll(name, strlen(name));
                break;
            case 'r' :{
                if (partition == 0) {
                    readAll(name, strlen(name));
                } else {
                    readPart(name, strlen(name),partition);
                }
                break;
            }
        }
    return 0;
}