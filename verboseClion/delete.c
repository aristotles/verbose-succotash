//
// Created by Samuel on 11/27/19.
//
#include <stdio.h>
#include <string.h>
#include "readAll.h"
#include "readPart.h"
#include "create.h"
#include "run.h"
#include "delete.h"
int deleteAll(char *var1, int var2){

    char thename[1024]="";
    int place=0;
    int q;
    FILE *file;
    char partitionFile[1024] = "";
    int begining=0;

    for(int x=0; x<var2; x++)
    {
        thename[x]=*var1;
        var1++;
        place++;
    }

    thename[strlen(thename)-1] = 0;
    file = fopen(thename, "r");

    if (file) {
        while ((q = getc(file)) != EOF){
            if(begining<2){
                begining+=1;
            }
            else if(q=='\n') {
                remove(partitionFile);
                memset(partitionFile,0,150);
                begining=0;
            }
            else{
                partitionFile[strlen(partitionFile)]=q;
            }
        }}

    remove(thename);
    return 0;
}