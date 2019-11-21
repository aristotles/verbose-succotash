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