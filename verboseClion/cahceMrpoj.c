#include <stdlib.h>
#include <stdio.h>
#define CACHE_DATA_SIZE 256
#define CACHE_TABLE_SIZE 8

//CONNER CARLSON SAM KRATSAS ADAM HENRICK
//SECOND CHANCE FIFO
struct CacheInfo {
    char *cacheData;
    int lastUsed;
    int rValue;
};

int main(int argc, char *argv[]) {
    struct CacheInfo cacheTable[CACHE_TABLE_SIZE];
   int placePointer=0;
    // Initialize cache table
    for(int i = 0; i < CACHE_TABLE_SIZE; i++) {
        struct CacheInfo cache;
        cache.lastUsed = i;
        cache.cacheData = malloc(CACHE_DATA_SIZE);
        cache.rValue=0;
        cacheTable[i] = cache;
    }


    while (1) {
        for(int i = 0; i < CACHE_TABLE_SIZE; i++) {
            printf("Entry:%d-Data:%s\n", cacheTable[i].lastUsed,cacheTable[i].cacheData);
        }


        printf("1 - Write, 2 - Read : ");
        int option = 0;
        scanf("%d", &option);

        int cacheEntry = 0;

        if (option == 2) {
            printf("Enter cache entry: ");
            scanf("%d", &cacheEntry);
            printf("Page Data: %s\n", cacheTable[cacheEntry].cacheData);
            cacheTable[cacheEntry].rValue=1;
        }
        else if (option == 1) {


            while(1)
            {
                if(placePointer==8){
                    placePointer=0;
                }
                if (cacheTable[placePointer].rValue==0){
                    cacheTable[placePointer].rValue=1;
                    cacheEntry=placePointer;
                    placePointer++;
                    break;
                }
                if (cacheTable[placePointer].rValue==1){
                    cacheTable[placePointer].rValue=0;
                    placePointer++;
                }
            }

            printf("Enter data for cache: ");
            scanf("%s", cacheTable[cacheEntry].cacheData);
            struct CacheInfo* address = &cacheTable[cacheEntry];
            printf("Address is %p\n", address);
            printf("Value is %d\n", address->lastUsed);
            printf("Value is %s\n", address->cacheData);
        }
    }
}

#include <stdio.h>

int main() {
    printf("Nasus\n");
    // create a FILE typed pointer
    FILE *file_pointer;
    char str[] ="";
    scanf("%s", str);
    printf("Nasus\n");
    char str[] ="";
    scanf("%s", newstr);

    file_pointer = fopen(str, "w");
//GET SUBSTRING
    // Write to the file
    fprintf(file_pointer, newstr);
    // Close the file
    fclose(file_pointer);


    return 0;
}
#include <stdio.h>
#include <string.h>
int main() {
    printf("Nasus\n");
    // create a FILE typed pointer
    ;
    char str[10] ;
    scanf("%s", str);

    printf("Naseeus\n");
    char newstr[500] ;
    scanf("%s", newstr);

    FILE *file_pointer = fopen(str, "w");
//GET SUBSTRING
    // Write to the file
    fprintf(file_pointer, newstr);
    // Close the file
    fclose(file_pointer);


    return 0;
}
===================================================

#include <stdio.h>
#include <string.h>

int main() {
    printf("hello what should we do:\n");


    char inputAction[40] ;
    fgets(inputAction, 40, stdin);



    char action[1024] = "";
    char name[1024] = "";
    int bool=0;
    int partition=0;
    const char *invalid_characters = " ";
    char *mystring = inputAction;
    char *c = mystring;

    while (*c)
    {

        if(bool==0){
            if (strchr(invalid_characters, *c)){}
            else{

                size_t len = strlen(action);
                action[len++] = *c; /* we overwriting the null-character with another one */
                action[len] = '\0';

            }
        }

        if(bool==2){

            partition=(int)(*c);
            partition=partition-48;
            bool=3;
        }
        if(bool==1){

            if (strchr(invalid_characters, *c))
            {
                bool=2;
            }
            else{
                size_t nameLen = strlen(name);
                name[nameLen++] = *c; /* we overwriting the null-character with another one */
                name[nameLen] = '\0';
            }


        }


        if (strchr(invalid_characters, *c)&&bool==0)
        {
            printf("\n");
            bool=1;
        }

        c++;
    }
    char finalName[1024] = "";
    char finalDesitination[1024] = "Users/samuel/GitHub/verbose-succotash/verboseClion/cmake-build-debug/";
    strcpy(finalName, name);
//    printf("we want to: %s\n",action);
//    printf("a file called: %s\n",name);
//    printf("number of partitions: %d\n",partition);

    if(strcmp(action, "create")==0){
        //==============================================================================================
        printf("\nwhat should the file say:\n");
        char inputContents [1024] ;
        fgets(inputContents, 1024, stdin);

        //gets rid of question mark
        size_t length = strlen(name);
        name[length+1] = '\0';

        int i;


        char contents[1024] = "";
        char finalContents[1024] = "";
        char placeString[1024] = "";

        char *contentstring = inputContents;
        char *w = contentstring;


        for (i=1; i<partition+1; i++)
        {
            size_t length = strlen(name);

            while (*w)
            {
                if(strchr(invalid_characters, *w)){
                    w++;
                    break;
                }
                else{
                    size_t len = strlen(contents);
                    contents[len++] = *w; /* we overwriting the null-character with another one */
                    contents[len] = '\0';
                    w++;

                }

            }

            if(i==1){

                name[length-4] = i +'0';
                name[length-3] = '.';
                name[length-2] = 't';
                name[length-1] = 'x';
                name[length-0] = 't';
            }
            else{
                name[length-5] = i +'0';
                name[length-4] = '.';
                name[length-3] = 't';
                name[length-2] = 'x';
                name[length-1] = 't';
            }
            placeString[0] = i +'0';
            FILE *file_pointer = fopen(name, "w");
            fprintf(file_pointer, contents);
            fclose(file_pointer);

            strcat(finalContents, placeString);
            strcat(finalContents, ":");
            strcat(finalContents, finalDesitination);
            strcat(finalContents, name);
            strcat(finalContents, "\n");
            memset(placeString,0,1024);
            memset(contents,0,1024);
        }
        FILE *file_pointer = fopen(finalName, "w");
        fprintf(file_pointer, finalContents);
        fclose(file_pointer);



        //==============================================================================================
    }
    if(strcmp(action, "read")==0){
        if(partition==0){
            name[strlen(name)-1] = '\0';

            int q;
            FILE *file;
            char partitionFile[1024] = "";
            file = fopen(name, "r");
            int begining=0;
            if (file) {

                while ((q = getc(file)) != EOF){
                    if(begining<2){
                        begining+=1;
                    }
                    else if(q=='\n'){

                        int z;
                        FILE *newfile;
                        newfile = fopen(partitionFile, "r");
                        if (newfile) {
                            while ((z = getc(newfile)) != EOF){

                                putchar(z);
                            }


                            fclose(newfile);
                        }
                        printf(" ");
                        memset(partitionFile,0,1024);
                        begining=0;

                    }
                    else{
                        partitionFile[strlen(partitionFile)]=q;
                    }

                }

                fclose(file);
            }
        }
        else{


            int q;
            FILE *file;
            char partitionFile[1024] = "";
            file = fopen(name, "r");
            int timetoCheck=1;
            int timetoMake=0;
            if (file) {

                while ((q = getc(file)) != EOF){
                    if(timetoMake==1){
                        if(q=='\n'){

                            int z;
                            FILE *newfile;
                            newfile = fopen(partitionFile, "r");
                            if (newfile) {
                                while ((z = getc(newfile)) != EOF)
                                    putchar(z);
                                fclose(newfile);
                            }


                            timetoMake=0;
                        }
                        if(q==':'){

                        }

                        else{
                            partitionFile[strlen(partitionFile)]=q;
                        }
                    }
                    if(timetoCheck==1){
                        if(q==(partition+'0')){
                            timetoMake=1;
                            timetoCheck=0;
                        }
                    }
                    if(q=='\n'){
                        timetoCheck=1;
                    }


                }

                fclose(file);
            }

        }

    }

    //   printf("\ndone.\n");
    return 0;

}