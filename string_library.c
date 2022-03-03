#define NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "string.h"
#include "string_library.h"
#include "error_treat.h"
#include "info.h"


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
        return 0;
    }

    size_t size = sizeof(line -> data[0]);

    return size;
}


void *createString(size_t set_size, int *error_status)
{

    string *new = (string *)calloc(1, sizeof(string));


    if(set_size < 0)
    {
        *error_status = ERRSIZE;
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
        return 0;
    }

    return strlen(line -> data);
}


size_t getLength(char *string_tmp)
{

    assert(string_tmp != NULL);

    if(!string_tmp)
    {
        return 0;
    }

    int counter = 0;

    for(int i = 0; string_tmp[i] != '\0'; i++)
    {
        counter++;
    }

    return counter + 1;
}


void *ctorString(void *set_data, int *error_status)
{
    
    assert(set_data != NULL);

    string *new = createString(getLength(set_data), error_status);

    if(new == NULL)
    {
        *error_status = EFAULT;
        return new;
    }

    if(set_data == NULL)
    {
        *error_status = EFAULT;
        return new;
    }

    new -> data = set_data;
    new -> length = getLength(new -> data);
    new -> element_size = getElementSize(new);

    return new;
}



void dtorString(string *line, int *error_status)
{

    assert(line != NULL);
    assert(line -> data != NULL);

    if(line == NULL || line -> data == NULL || line -> length == 0)
    {
        return;
    }

    free(line -> data);
    free(line);
}


void *getSubstring(string *parent, int begin, int end, int *status)
{

    assert(parent != NULL);

    if(parent == NULL)
    {
        *status = EFAULT;
        return NULL;
    }

    if(begin > end)
    {
        int tmp = end;
        end = begin;
        begin = tmp;
    }
    
    if(begin < 0 || end > parent -> length)
    {
        *status = ERRSIZE;
        return NULL;
    }

    char *parent_tmp = parent -> data;

    char *result = (char *)calloc(end - begin + 1, sizeof(char));

    for(int i = 0; i < end - begin; i++)
    {
        result[i] = parent_tmp[begin + i];
    }

    string *children = ctorString(result, status);


    return children;
}



void *concatString(string *str1, string *str2, int *status)
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
    
    string *concat = ctorString(result, status);

    return concat;
}


void *searchSubstring(string *line, string *substring, int *status)
{

    assert(line != NULL);
    assert(substring != NULL);
    assert(line -> data != NULL);
    assert(substring -> data != NULL);

    if(line == NULL)
    {
        *status = EFAULT;
        return NULL;
    }

    if(substring == NULL)
    {
        *status = EFAULT;
        return NULL;
    }

    if(line -> length == 0 || !(line -> data))
    {
        *status = EFAULT;
        return NULL;
    }

    if(substring -> length == 0 || !(substring -> data))
    {
        *status = EFAULT;
        return NULL;
    }

    if(substring -> length > line -> length)
    {
        *status = ERRSIZE;
        return NULL;
    }


    char *line_buffer = currentData(line);
    char *substring_buffer = currentData(substring);
    char *tmp_buffer = substring_buffer;
    char *result = NULL;

    while(*line_buffer != '\0')
    {
        result = line_buffer;

        if(*line_buffer != *tmp_buffer)
        {
            line_buffer++;
            continue;
        }


        while(*line_buffer == *tmp_buffer && *line_buffer != '\0' && *tmp_buffer != '\0')
        {
            line_buffer++;
            tmp_buffer++;

            if(*tmp_buffer == '\0')
            {
                return result;
            }
        }

        tmp_buffer = substring_buffer;
    }


    return NULL;
    
}



void *currentData(string *ptr)
{

    assert(ptr != NULL);
    if(!ptr)
    {
        return NULL;
    }

    char *return_data = ptr -> data;
    return return_data;
}


void printString(string *line, int *error_status)
{

    assert(line != NULL);
    assert(line -> data != NULL);

    if(line == NULL)
    {
        *error_status = EFAULT;
        return;
    }

    if(!(line -> data) || (line -> length == 0))
    {
        printf("This string is empty\n");
        return;
    }

    printf("%s\n", (char *)line -> data);
}


int getRegister(string *line, int *error_status)
{
    assert(line != NULL);
    assert(line -> data != NULL);

    if(line == NULL)
    {
        *error_status = EFAULT;
        return 0;
    }

    if(!line || !(line -> data) || line -> length == 0)
    {
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



void printRegisterInfo(string *line, int *error_status)
{

    assert(line != NULL);

    if(line == NULL)
    {
        *error_status = EFAULT;
        return;
    }

    int register_info = getRegister(line, error_status);

    if(!register_info)
    {
        printf("Can't get information about register\n");
        return;
    }


    switch(register_info)
    {
        case LOWER:

            printf("\nRegiser of the string is lower\n");
            break;

        case UPPER:

            printf("\nRegister of the string is upper\n");
            break;

        case DIFFERENT:

            printf("\nThis string contains symbols with both registers\n");
            break;   
        
        default:
            printf("\nCan't get information about register\n");
            return;
    }   
}

