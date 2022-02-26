//menu-header file

#ifndef MENU_H
#define MENU_H


//The function for calling main menu of the programm//
int mainMenu();



enum EnumMenuStatus
{
    SUCCES = 1,
    ERROR = -1,
    SUCCES_EXIT = 0,
};


enum EnumMenuPoints
{
    CREATE = 1,
    INFO = 2,
    SUBSTRING = 3,
    CONCAT = 4, 
    SEARCH = 5,
    EXIT = 6,
};


#endif
