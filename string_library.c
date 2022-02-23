#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "string.h"
#include "string_library.h"



struct str
{

    void *data;
    size_t length;
    size_t element_size;
};



size_t getStringSize(string *line)
{
    assert(line != NULL);
    assert(line -> data != NULL);

    if(!line || !(line -> data) || line -> length == 0)
    {
        printf("This string is empty");
        return 0;
    }

    size_t size = sizeof(line -> data);

    return size;
}


size_t getElementSize(string *line)
{

    assert(line != NULL);
    assert(line -> data != NULL);

    if(!line || !(line -> data) || line -> length == 0)
    {
        printf("This string is empty");
        return 0;
    }

    size_t size = sizeof(line -> data[0]);

    return size;
}


string *createString(size_t set_size)
{

    string *new = (string *)calloc(1, sizeof(string));


    if(set_size < 0)
    {
        printf("Length of the string can't be negative.\n");
        return new;
    }

    new -> length = set_size;

    return new;
}


size_t getStringLength(string *line)
{
    
    assert(line != NULL);
    if(!line)
    {
        printf("This string is empty\n");
        return 0;
    }

    return strlen(line -> data);
}


size_t getLength(char *string_tmp)
{

    assert(string_tmp != NULL);

    if(!string_tmp)
    {
        printf("String is empty\n");
        return 0;
    }

    int counter = 0;

    for(int i = 0; string_tmp[i] != '\0'; i++)
    {
        counter++;
    }

    return counter + 1;
}


void *ctorString(char *set_data)
{
    
    assert(set_data != NULL);

    string *new = createString(getLength(set_data));

    if(!new)
    {
        return new;
    }

    if(!set_data)
    {
        printf("Here is empty string\n");
        return new;
    }

    new -> data = set_data;
    new -> length = getLength(new -> data);

    return new;
}



void destructString(string *line)
{

    assert(line != NULL);
    //assert(line -> data != NULL);

    if(line == NULL || line -> data == NULL || line -> length == 0)
    {
        printf("Here is empty string\n");
        return;
    }

    free(line -> data);
    free(line);
}


string *getChildren(string *parent, int begin, int end)
{

    assert(parent != NULL);

    if(begin > end)
    {
        int tmp = end;
        end = begin;
        begin = tmp;
    }
    
    if(begin < 0 || end > parent -> length)
    {
        printf("Invalid input size. Please input correctly\n");
        printf("Please input begin position\n");
        scanf("%d", &begin);
        printf("Please input end postion\n");
        scanf("%d", &end);

        return getChildren(parent, begin, end);
    }

    char *parent_tmp = parent -> data;

    char *result = (char *)calloc(end - begin + 1, sizeof(char));

    for(int i = 0; i < end - begin; i++)
    {
        result[i] = parent_tmp[begin + i];
    }

    string *children = ctorString(result);


    return children;
}



string *concatString(string *str1, string *str2)
{
    
    assert(str1 != NULL);
    assert(str2 != NULL);

    if((!str1 -> data) || ! (str2 -> data))
    {
        return NULL;
    }
    
    int new_size = (size_t)str1 -> length + (size_t)str2 -> length;
    char *result = (char *)calloc(new_size, sizeof(char));

    strcat(result, str1 -> data);
    strcat(result, str2 -> data);
    
    string *concat = ctorString(result);

    return concat;
}


int searchSubstring(string *line, string *substring)
{

    assert(line != NULL);
    assert(substring != NULL);
    assert(line -> data != NULL);
    assert(substring -> data != NULL);

    int index = 0;

    if(line -> length == 0 || !(line -> data))
    {
        printf("Main string is empty. Please input correct data\n");
        return 0;
    }

    if(substring -> length == 0 || !(substring -> data))
    {
        printf("The main string contains unlimited quantity of empty substrings.\n");
        return 0;
    }
}



void *currentData(string *ptr)
{

    assert(ptr != NULL);
    if(!ptr)
    {
        printf("String is empty\n");
        return NULL;
    }

    char *return_data = ptr -> data;
    return return_data;
}



Info *getInfo(string *line)
{

    assert(line != NULL);
    assert(line -> data != NULL);

    Info *current_info = (Info *)calloc(1, sizeof(Info));

    if(!current_info)
    {
        printf("Unknown error with memory\n");
        return NULL;
    }

    current_info -> empty = createString(line -> length);   
    current_info -> size = getStringSize(line);

    return current_info;
}



int getRegister(string *line)
{
    assert(line != NULL);
    assert(line -> data != NULL);

    if(!line || !(line -> data) || line -> length == 0)
    {
        printf("This string is empty");
        return EMPTY;
    }

    int register_info = LOWER;
    char *buffer = line -> data;

    for(int i = 0; i < getLength(line -> data); i++)
    {
        if(register_info == UPPER && buffer[i] > 97)
        {
            return DIFFERENT;
        }

        else if(buffer[i] < 97 && buffer[i] >= 64)
        {
            register_info = UPPER;
        }
        
    }

    return register_info;
}



void printString(string *line)
{

    assert(line != NULL);
    assert(line -> data != NULL);

    if(!(line -> data) || (line -> length == 0))
    {
        printf("This string is empty\n");
        return;
    }

    printf("\n%s\n", (char *)line -> data);
}



void printRegisterInfo(Info *information)
{

    assert(information != NULL);

    if(!(information -> register_info))
    {
        printf("Can't get information about register\n");
        return;
    }

    switch(information -> register_info)
    {
        case LOWER:

            printf("Regiser of the string is lower\n");
            break;

        case UPPER:

            printf("Register of the string is upper\n");
            break;

        case DIFFERENT:

            printf("This string contains symbols with both registers\n");
            break;   
        
        default:
            printf("Can't get information about register\n");
            return;
    }   
}



