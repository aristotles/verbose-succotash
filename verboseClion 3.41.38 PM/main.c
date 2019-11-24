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
    printf("we want to: %s\n",action);
    printf("a file called: %s\n",name);
    printf("number of partitions: %d\n",partition);
    if(strcmp(action, "create")==0){
        printf("\nwhat should the file say:\n");
        char inputContents [50] ;
        fgets(inputContents, 22, stdin);

        //gets rid of question mark
        size_t length = strlen(name);
        name[length+1] = '\0';

        int i;



        for (i=0; i<partition; i++)
        {
            size_t length = strlen(name);

            //STOPPED HERE
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

            FILE *file_pointer = fopen(name, "w");
            fprintf(file_pointer, inputContents);//STOPED HERE CHANGING FILES CONTENTS
            fclose(file_pointer);
        }




    }

    printf("\ndone.\n");
    return 0;
}