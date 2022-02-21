#define NDEBUG
#include <readline/readline.h>
#include "string_library.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>



int main()
{
    char *data = readline("Please input your string\n");
    char *data2 = readline("Please input another string data\n");

    string *str1 = ctorString(data);
    string *str2 = ctorString(data2);
    string *concat_str = concatString(str1, str2);
    string *substring = getChildren(str1, 2, 10);
    printf("Here is concatination result %s\n", (char*)currentData(concat_str));
    printf("Here is substring %s %ld\n", (char*)currentData(substring), stringLength(substring));

    destructString(str1);
    destructString(concat_str);
    destructString(str2);
    destructString(substring);
    return 0;
}