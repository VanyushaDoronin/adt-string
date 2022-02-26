#define NDEBUG
#include <stdio.h>
#include <assert.h>
#include <readline/readline.h>
#include "string_library.h"
#include "info.h"
#include "menu.h"



int mainMenu()
{

    static void *str1;
    static void *str2;

    static Info *info;

    if(!info)
    {
        info = getInfo(getStringLength, currentData, getStringSize, printRegisterInfo, printString);
    }

    if(!str1)
    {
        str1 = NULL;
    }
    if(!str2)
    {
        str2 = NULL;
    }

    int choose = 0;

    printf("\n1. Create a string with new data\n");
    printf("2. Get info about created string\n");
    printf("3. Get substring of the string\n");
    printf("4. Concatination of created strings\n");
    printf("5. Search substring in one of created strings\n");
    printf("6. Exit\n");
    printf("Please choose one point from the list\n");

    int input_status = 0;

    scanf("%d", &choose);

    switch(choose)
    {

        case CREATE:

            if(str1)
            {
                printf("\nExisting string will be removed\n");
                dtorString(str1);
            }

            if(str2)
            {
                printf("\nExisting string will be removed\n");
                dtorString(str2);
            }

            char *buffer_str1 = readline("\nPlease enter first string:\n");
            char *buffer_str2 = readline("\nPlease enter next string:\n");

            str1 = ctorString(buffer_str1);
            str2 = ctorString(buffer_str2);

            return SUCCES;


        case INFO:

            printf("Please choose string, which info you need\n");
            printf("\n1. First string\n");
            printf("2. Next string\n");
            printf("3. Both\n");
            input_status = 0;

            scanf("%d", &choose);

            if(choose == 1)
            {
                printStringInfo(str1, NULL, info);
            }
            else if(choose == 2)
            {
                printStringInfo(NULL, str2, info);
            }
            else
            {
                printStringInfo(str1, str2, info);
            }
            return SUCCES;


        case SUBSTRING:

            printf("Please choose string, which info you need\n");
            printf("\n1. First string\n");
            printf("2. Next string\n");
            input_status = 0;
            int begin;
            int end;

            scanf("%d", &choose);

           

            printf("\nPlease choose begin position\n");
            scanf("%d", &begin);
            printf("Please choose end position\n");
            scanf("%d", &end);

            string *substring;

            if(choose == 1)
            {
                substring = getChildren(str1, begin, end);
            }
            
            if(choose == 2)
            {
                substring = (getChildren(str2, begin, end));
            }

            info -> printString(substring);
            dtorString(substring);
            return SUCCES;


        case CONCAT:
            
            if(!str1 || !str2)
            {
                printf("One string is empty\n");
                return SUCCES;
            }

            printf("\nStrings concatination is: \n");

            string *concat = concatString(str1, str2);
            info -> printString(concat);
            dtorString(concat);

            return SUCCES;


        case SEARCH:





        case EXIT:

            if(str1)
            {
                dtorString(str1);
            }
                
            if(str2)
            {
                dtorString(str2);
            }

            if(info)
            {
                dtorInfo(info);
            }
            
        

            return SUCCES_EXIT;
        

        default:
            printf("\nUnknown error\n");
            return ERROR;
    }
}





