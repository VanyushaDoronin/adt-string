#define NDEBUG
#include <readline/readline.h>
#include "string_library.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "info.h"



int main()
{
    char *data = readline("Please input your string\n");
    char *data2 = readline("Please input another string data\n");

    string *str1 = ctorString(data);
    string *str2 = ctorString(data2);
    string *concat_str = concatString(str1, str2);
    string *substring = getChildren(str1, 2, 10);
    printString(concat_str);
    printString(substring);
    printf("\ncurrent data substring : %s\n", (char *)currentData(substring));
    printf("\n substring length: %ld \n", getStringLength(substring));
    printRegisterInfo(substring);
    printf("\n size 1 element of substring : %ld\n", getElementSize(substring));

    destructString(str1);
    destructString(concat_str);
    destructString(str2);
    destructString(substring);
    return 0;
}