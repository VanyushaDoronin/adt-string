//header file for error treatment
#ifndef ERRTREAT_H
#define ERRTREAT_H

#include <stdio.h>
#include <errno.h>
#include <assert.h>
#include "string_library.h"
#include "info.h"
#include "menu.h"



#define CHECK_ERROR(status)                            \
    if(status != SUCCES)                               \
    {                                                  \
        printERROR(status);                            \
    }                                                  \


enum ErrorTypes
{
    NULLPTR = -1,
};

/**
 * @brief This function output error message in console
 * 
 * @param status is error code
 */
void printERROR(int status);



#endif



