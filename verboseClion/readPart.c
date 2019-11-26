//
// Created by Samuel on 11/26/19.
//
#include <stdio.h>
#include <string.h>
#include "readPart.h"
int readPart(char *var1, int var2, int partition){


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

    int q;
    FILE *file;
    char partitionFile[1024] = "";
    file = fopen(thename, "r");
    int timetoCheck = 1;
    int timetoMake = 0;
    if (file) {

        while ((q = getc(file)) != EOF) {
            if (timetoMake == 1) {
                if (q == '\n') {

                    int z;
                    FILE *newfile;
                    newfile = fopen(partitionFile, "r");
                    if (newfile) {
                        while ((z = getc(newfile)) != EOF)
                            putchar(z);
                        fclose(newfile);
                    }


                    timetoMake = 0;
                }
                if (q == ':') {

                } else {
                    partitionFile[strlen(partitionFile)] = q;
                }
            }
            if (timetoCheck == 1) {
                if (q == (partition + '0')) {
                    timetoMake = 1;
                    timetoCheck = 0;
                }
            }
            if (q == '\n') {
                timetoCheck = 1;
            }


        }

        fclose(file);
    }
}