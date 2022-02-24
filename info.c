#define NDEBUG
#include <stdio.h>
#include "string_library.h"
#include "info.h"




Info *getInfo(
    size_t (*getStringLength)(string *line),
    string *empty,
    void (*printString)(string *line),
    void *(*printRegisterInfo)(string *information),
    void *(*currentData)(string *line),
    size_t *(*getElementSize)(string *line)
)
{

    assert(&getStringLength != NULL);
    assert(&printString != NULL);
    assert(&printRegisterInfo != NULL);
    assert(&currentData != NULL);
    assert(&getElementSize != NULL);

    Info *info = (Info *)calloc(1, sizeof(Info));

    info -> currentData = currentData;
    info -> printString = printString;
    info -> empty = createString(1);
    info -> getStringLength = getStringLength;
    info -> getElementSize = getElementSize;
    info -> currentData = currentData;
    
    return info;
}



void dtorInfo(Info *info)
{

    assert(info != NULL);
    assert(info -> currentData != NULL);
    assert(info -> empty != NULL);
    assert(info -> getElementSize != NULL);
    assert(info -> getStringLength != NULL);
    assert(info -> printRegisterInfo != NULL);
    assert(info -> printString != NULL);

    if(!info)
    {
        printf("Here isn't current info about the string type\n");
        return;
    }

    free(info -> currentData);
    free(info -> empty);
    free(info -> getElementSize);
    free(info -> getStringLength);
    free(info -> printRegisterInfo);
    free(info -> printString);

    free(info);
}