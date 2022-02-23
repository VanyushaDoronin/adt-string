//header file 

#ifndef STRING_LIBRARY_H
#define STRING_LIBRARY_H


typedef struct str string;


typedef struct StringInfo
{
    int register_info;
    size_t size;
    void *empty;
    //void *printString(string *line);

}Info;


//The function for creating empty string//
string *createString(size_t set_size);

//The function for getting length of the string//
size_t getLength(char *string_tmp);

//The functiong for creating non-empty string//
void *ctorString(char *set_data);

//The function to destruct string//
void destructString(string *line);

//The function for getting substring//
string *getChildren(string *parent, int begin, int end);

//The function for string concatination//
string *concatString(string *str1, string *str2);

//Function-getter data of the string\n//
void *currentData(string *ptr);

//The function-getter length of the string//
size_t getStringLength(string *line);

//The function-getter sizeof elements of the string//
size_t getElementSize(string *line);

//The function for getting register info of the string//
int getRegister(string *line);

//The function for printing string//
void printString(string *line);

//This function output information about register of the string//
void printString(string *line);



enum RegisterInformation
{
    LOWER = 1,
    UPPER = 2,
    DIFFERENT = 3,
    EMPTY = -1,
};


#endif