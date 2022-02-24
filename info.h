//header string-info file

#ifndef INFO_H
#define INFO_H

typedef struct StringInfo
{
    size_t (*getStringLength)(string *line);
    string *empty;
    void (*printString)(string *line);
    void *(*printRegisterInfo)(string *information);
    void *(*currentData)(string *line);
    size_t *(*getElementSize)(string *line);

}Info;



//The function for creating string info//
Info *getInfo();

//The function for destructing string info//
void dtorInfo(Info *info);


#endif