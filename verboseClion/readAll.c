//
// Created by Samuel on 11/26/19.
//
#include <stdio.h>
#include <string.h>
#include "readAll.h"

int readAll(){


        if(0==0){
//        name[strlen(name)-1] = '\0';

            int q;
            FILE *file;
            char partitionFile[1024] = "";
            file = fopen("cat.txt", "r");
            int begining=0;
            int starter=0;
            int arrayDimensionPlace=0;
            int wordCount=1;
            char mainArray[8][150];
            memset(mainArray[1],0,150);
            memset(mainArray[2],0,150);
            memset(mainArray[3],0,150);
            memset(mainArray[4],0,150);
            memset(mainArray[5],0,150);
            memset(mainArray[6],0,150);
            memset(mainArray[7],0,150);
            memset(mainArray[0],0,150);
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


                                mainArray[arrayDimensionPlace][starter]=z;
                                starter+=1;
                                if(arrayDimensionPlace==0&&(32== z)){
                                    wordCount+=1;
                                }
                            }

                            arrayDimensionPlace+=1;
                            starter=0;


                            fclose(newfile);
                        }
                        printf(" ");
                        memset(partitionFile,0,150);
                        begining=0;

                    }
                    else{
                        partitionFile[strlen(partitionFile)]=q;
                    }

                }
                int loopXvalue;
                char mastOut[1024] = "";
                int masterPlace=0;
                int arrayPlaceHolders[8]={0,0,0,0,0,0,0,0};

                for(loopXvalue=0;loopXvalue<wordCount;loopXvalue++){
                    int loopYvalue=0;
                    for(loopYvalue=0;loopYvalue<8;loopYvalue++){
                        int k;

                        for(int k=arrayPlaceHolders[loopYvalue];k<150;k++){
                            if(mainArray[loopYvalue][k]==' '){
                                mastOut[masterPlace]=mainArray[loopYvalue][k];
                                masterPlace+=1;
                                arrayPlaceHolders[loopYvalue]+=1;
                                break;
                            }
                            else if(mainArray[loopYvalue][k]=='\0'){
                                mastOut[masterPlace]=' ';
                                masterPlace+=1;
                                break;
                            }
                            else{
                                mastOut[masterPlace]=mainArray[loopYvalue][k];
                                masterPlace+=1;
                                arrayPlaceHolders[loopYvalue]+=1;
                            }

                        }


                    }

                }

                printf("%s",mastOut);










//            for(printLoop=0;printLoop<arrayDimensionPlace;printLoop++){
//                size_t arrayLen = strlen(mainArray[printLoop]);
//                int x;
//                for(x=0;x<arrayLen;x++){
//
//                }
//
//
//            }


                fclose(file);
            }



        }

        return 0;
    }
