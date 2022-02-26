#define NDEBUG
#include <readline/readline.h>
#include "string_library.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "info.h"



int main()
{

    int menu_status = 1;
    while(menu_status)
    {
        menu_status = mainMenu();
    }








    /*char *data = readline("Please input your string\n");
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
    printf("here is pointer on the first substring symbol %s", (char *)searchSubstring(str1, str2, 0));

    dtorString(str1);
    dtorString(concat_str);
    dtorString(str2);
    dtorString(substring);*/
    return 0;
}