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


        for (i=0; i<partition; i++)
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

            if(i==0){

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
            placeString[0] = i+1 +'0';
            FILE *file_pointer = fopen(name, "w");
            fprintf(file_pointer, contents);
            fclose(file_pointer);
            //STOOPPPED HERE
//            int improved= i+1;
//            char place= improved+'0';
            strcat(finalContents, placeString);
            strcat(finalContents, ":");
            strcat(finalContents, finalDesitination);
            strcat(finalContents, name);
            strcat(finalContents, "\n");
            memset(placeString,0,1024);
            memset(contents,0,1024);
        }
        FILE *file_pointer = fopen(finalName, "w");
        fprintf(file_pointer, finalContents);//STOPED HERE CHANGING FILES CONTENTS
        fclose(file_pointer);
    }
    if(strcmp(action, "read")==0){

        int q;
        FILE *file;
        char partitionFile[1024] = "";
        file = fopen(name, "r");
        if (file) {
            while ((q = getc(file)) != EOF){
                if(q=='\n'){

                    int z;
                    FILE *newfile;
                    newfile = fopen(partitionFile, "r");
                    if (newfile) {
                        while ((z = getc(newfile)) != EOF)
                            putchar(z);
                        fclose(newfile);
                    }
                    printf(" ");
                    memset(partitionFile,0,1024);

                }
                else{
                    partitionFile[strlen(partitionFile)]=q;
                }

            }

            fclose(file);
        }







    }

 //   printf("\ndone.\n");
    return 0;

}