#include <stdio.h>
#include <string.h>
#include "readAll.h"
#include "readPart.h"
#include "create.h"
#include "run.h"
#include "delete.h"


int main() {


        while(1==1){

            run();
            printf("anything else?(y/n)\n");
            char inputAction[40];
            fgets(inputAction, 40, stdin);

            if(inputAction[0]=='y'){
            }
            else{
                break;
            }
        }



        return 0;

    }