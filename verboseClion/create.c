//
// Created by Samuel on 11/26/19.
//
#include <stdio.h>
#include <string.h>
#include "create.h"
int create(char *var1, int var2, int partition){



    char thename[1024]="";
    int place=0;
    for(int x=0; x<var2; x++)
    {
        thename[x]=*var1;
        /*increment pointer for next element fetch*/
        var1++;
        place++;
    }

    thename[strlen(thename)] = 0;

    const char *invalid_characters = " ";
    char finalName[1024] = "";
    char finalDesitination[1024] = "Users/samuel/GitHub/verbose-succotash/verboseClion/cmake-build-debug/";
    strcpy(finalName, thename);

    printf("\nwhat should the file say:\n");
    char inputContents[1024];
    fgets(inputContents, 1024, stdin);

    //gets rid of question mark
    size_t length = strlen(thename);
    thename[length + 1] = '\0';

    int i;


    char contents[1024] = "";
    char finalContents[1024] = "";
    char placeString[1024] = "";

    char *contentstring = inputContents;
    char *w = contentstring;


    for (i = 1; i < partition + 1; i++) {
        size_t length = strlen(thename);

        while (*w) {
            if (strchr(invalid_characters, *w)) {
                w++;
                break;
            } else {
                size_t len = strlen(contents);
                contents[len++] = *w; /* we overwriting the null-character with another one */
                contents[len] = '\0';
                w++;

            }

        }

        if (i == 1) {

            thename[length - 4] = i + '0';
            thename[length - 3] = '.';
            thename[length - 2] = 't';
            thename[length - 1] = 'x';
            thename[length - 0] = 't';
        } else {
            thename[length - 5] = i + '0';
            thename[length - 4] = '.';
            thename[length - 3] = 't';
            thename[length - 2] = 'x';
            thename[length - 1] = 't';
        }
        placeString[0] = i + '0';
        FILE *file_pointer = fopen(thename, "w");
        fprintf(file_pointer, contents);
        fclose(file_pointer);

        strcat(finalContents, placeString);
        strcat(finalContents, ":");
        strcat(finalContents, finalDesitination);
        strcat(finalContents, thename);
        strcat(finalContents, "\n");
        memset(placeString, 0, 1024);
        memset(contents, 0, 1024);
    }
    FILE *file_pointer = fopen(finalName, "w");
    fprintf(file_pointer, finalContents);
    fclose(file_pointer);
}