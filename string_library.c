#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "string.h"
#include "string_library.h"


typedef struct str
{

    void *data;
    size_t length;
}string;




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

