//header file 

#ifndef STRING_LIBRARY_H
#define STRING_LIBRARY_H


typedef struct str string;


typedef struct StringInfo
{
    int register_info;
    size_t size;
    void *empty;

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



enum RegisterInformation
{
    LOWER = 0,
    UPPER = 1,
    DIFFERENT = 2,
    EMPTY = -1,
};


#endif