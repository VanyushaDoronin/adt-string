#define NDEBUG
#include <readline/readline.h>
#include "string_library.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "error_treat.h"
#include "info.h"



int main()
{

    int menu_status = 1;
    while(menu_status)
    {
        menu_status = mainMenu();
        
        if(menu_status == SUCCES_EXIT)
        {
            return 0;
        }
        
        CHECK_ERROR(menu_status);
    }

    return 0;
}