#include <stdio.h>
#include <string.h>
#include "readAll.h"
#include "readPart.h"
#include "create.h"


int main() {

        printf("hello what should we do:\n");


        char inputAction[40];
        fgets(inputAction, 40, stdin);


        char action[1024] = "";
        char name[1024] = "";
        int bool = 0;
        int partition = 0;
        const char *invalid_characters = " ";
        char *mystring = inputAction;
        char *c = mystring;

        while (*c) {

            if (bool == 0) {
                if (strchr(invalid_characters, *c)) {}
                else {

                    size_t len = strlen(action);
                    action[len++] = *c; /* we overwriting the null-character with another one */
                    action[len] = '\0';

                }
            }

            if (bool == 2) {

                partition = (int) (*c);
                partition = partition - 48;
                bool = 3;
            }
            if (bool == 1) {

                if (strchr(invalid_characters, *c)) {
                    bool = 2;
                } else {
                    size_t nameLen = strlen(name);
                    name[nameLen++] = *c; /* we overwriting the null-character with another one */
                    name[nameLen] = '\0';
                }


            }


            if (strchr(invalid_characters, *c) && bool == 0) {
                printf("\n");
                bool = 1;
            }

            c++;
        }

        if (strcmp(action, "create") == 0) {
            //==============================================================================================

            create(name, strlen(name),partition);


            //==============================================================================================
        }
        if (strcmp(action, "read") == 0) {

            if (partition == 0) {
               readAll(name, strlen(name));
            } else {
                readPart(name, strlen(name),partition);
            }

        }

        return 0;

    }