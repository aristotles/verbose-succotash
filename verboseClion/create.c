//
// Created by Samuel on 11/26/19.
//
#include <stdio.h>
#include <string.h>
#include "create.h"
int create(char *var1, int var2, int partition){

    const char *invalid_characters = " ";
    char finalName[1024] = "";
    char inputContents[1024];
    char thename[1024]="";
    int place=0;
    char contents[1024] = "";
    char finalContents[1024] = "";
    char placeString[1024] = "";
    char mainArray[8][150];
    int partCount=0;
    int arrayPlaceHolders[8]={0,0,0,0,0,0,0,0};
    int i;

    memset(mainArray[1],0,150);
    memset(mainArray[2],0,150);
    memset(mainArray[3],0,150);
    memset(mainArray[4],0,150);
    memset(mainArray[5],0,150);
    memset(mainArray[6],0,150);
    memset(mainArray[7],0,150);
    memset(mainArray[0],0,150);

    for(int x=0; x<var2; x++)
    {
        thename[x]=*var1;
        var1++;
        place++;
    }

    thename[strlen(thename)] = 0;
    strcpy(finalName, thename);

    printf("\nwhat should the file say:\n");

    fgets(inputContents, 1024, stdin);

    //gets rid of question mark
    size_t length = strlen(thename);
    thename[length + 1] = '\0';

    char *contentstring = inputContents;
    char *w = contentstring;

    for (i = 1; i < 1000; i++) {

        if(partCount==partition){
            partCount=0;
        }
        while (*w) {
            if (strchr(invalid_characters, *w)) {
                mainArray[partCount][arrayPlaceHolders[partCount]]=' ';
                arrayPlaceHolders[partCount]++;
                partCount++;
                w++;
                break;
            } else {
                mainArray[partCount][arrayPlaceHolders[partCount]]=*w;
                arrayPlaceHolders[partCount]++;
                w++;

            }

        }

    }
    int p;

    for (p = 1; p < partition+1; p++) {

        char newNam[1024]="";

        strcat(newNam,"disk");
        placeString[0] = p + '0';
        strcat(newNam,placeString);
        strcat(newNam,"/");
        strcat(newNam,thename);

        FILE *file_pointer2 = fopen(newNam, "w");
        fprintf(file_pointer2, mainArray[p-1]);
        fclose(file_pointer2);

        strcat(finalContents, placeString);
        strcat(finalContents, ":disk");
        strcat(finalContents, placeString);
        strcat(finalContents, "/");
        strcat(finalContents, thename);
        strcat(finalContents, "\n");
        memset(placeString, 0, 1024);

    }

    FILE *file_pointer = fopen(finalName, "w");
    fprintf(file_pointer, finalContents);
    fclose(file_pointer);

}