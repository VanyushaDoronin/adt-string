//header string-info file

#ifndef INFO_H
#define INFO_H

typedef struct StringInfo
{
    size_t (*getStringLength)(string *);
    void *empty;
    void *(*currentData)(string *);
    size_t (*getStringSize)(string *);
    void (*printRegisterInfo)(string *);
    void (*printString)(string *);

}Info;



//The function for creating string info//
Info *getInfo(size_t (*getStringLength)(string *),
    void *(*currentData)(string *),
    size_t (*getStringSize)(string *),
    void (*printRegisterInfo)(string *),
    void (*printString)(string *));

//The function for destructing string info//
void dtorInfo(Info *info);

//The function for outputing all data of the strings//
void printStringInfo(string *str1, string *str2, Info *info);


#endif