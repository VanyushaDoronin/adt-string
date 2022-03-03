#include "error_treat.h"



void printERROR(int status)
{
    
    switch(status)
    {
        case EFAULT:
            printf("Null pointer as a input parameter of function\n");
            return;

        case ERRSIZE:
            printf("Incorrect size of the object\n");
            return;


        default:
            printf("Unknown error\n");
            return;
    }
}