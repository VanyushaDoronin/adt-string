#define NDEBUG
#include <stdio.h>
#include "string_library.h"
#include <stdlib.h>
#include <assert.h>
#include "info.h"
#include "menu.h"





Info *getInfo(size_t (*getStringLength)(string *),
    void *(*currentData)(string *),
    size_t(*getStringSize)(string *),
    void (*printRegisterInfo)(string *),
    void (*printString)(string *))
{

    assert(info -> currentData != NULL);
    assert(info -> empty != NULL);
    assert(info -> getElementSize != NULL);
    assert(info -> getStringLength != NULL);

    Info *info = (Info *)calloc(1, sizeof(Info));

    info -> currentData = currentData;
    info -> empty = createString(1);
    info -> getStringLength = getStringLength;
    info -> getStringSize = getStringSize;  
    info -> printRegisterInfo = printRegisterInfo;
    info -> printString = printString;

    return info;
}



void dtorInfo(Info *info)
{

    assert(info != NULL);

    
    free(info -> empty);
    free(info);
}



void printStringInfo(string *str1, string *str2, Info *info)
{
    
    assert(str1 != NULL);
    assert(str2 != NULL);

    if(!str1 && !str2)
    {
        printf("\n Both strings are empty\n");
        return;
    }
    
    if(!str2 && str1)
    {
        printf("\nString with data: %s\n", (char *)info -> currentData(str1));
        printf("Length is: %ld\n", info -> getStringLength(str1));
        printf("Size of the element: %ld\n", info -> getStringSize(str1));
        info -> printRegisterInfo(str1);
        return;
    }

    if(!str1 && str2)
    {
        printf("\nString with data: %s\n", (char *)info -> currentData(str2));
        printf("Length is: %ld\n", info -> getStringLength(str2));
        printf("Size of the element: %ld\n", info -> getStringSize(str2));
        info -> printRegisterInfo(str2);
        return;
    }

    if(str1 && str2) 
    {

        printf("\nString with data: %s\n", (char *)info -> currentData(str1));
        printf("Length is: %ld\n", info -> getStringLength(str1));
        printf("Size of the element: %ld\n", info -> getStringSize(str1));
        info -> printRegisterInfo(str1);

        printf("\nString with data: %s\n", (char *)info -> currentData(str1));
        printf("Length is: %ld\n", info -> getStringLength(str1));
        printf("Size of the element: %ld\n", info -> getStringSize(str1));
        info -> printRegisterInfo(str1);
    }
}