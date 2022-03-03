//header file 


#ifndef STRING_LIBRARY_H
#define STRING_LIBRARY_H

/**
 * @brief Abstract data type String
 */
typedef struct str string;


/**
 * @brief Create a String object
 
 * @param set_size is input of size
 * @return void* 
 */
void *createString(size_t set_size, int *error_status);


/**
 * @brief Get the Length of the String
 * 
 * @param string_tmp is data of String object
 * @return size_t 
 */
size_t getLength(char *string_tmp);


/**
 * @brief Create and initialize String object
 * 
 * @param set_data is a String object
 * @return void* 
 */
void *ctorString(void *set_data, int *error_status);


/**
 * @brief Destruct String object
 * 
 * @param line is a String to destruct  
 */
void dtorString(string *line, int *error_status);


/**
 * @brief Get the Children object
 * 
 * @param parent is a String object from which the substring is obtained
 * @param begin is index of the element where substring starts
 * @param end is index of the element where substring ends
 * @return void* 
 */
void *getSubstring(string *parent, int begin, int end, int *error_status);


/**
 * @brief Concatination two String-objects
 * 
 * @param str1 is first string
 * @param str2 is another string
 * @return void* 
 */
void *concatString(string *str1, string *str2, int *error_status);


/**
 * @brief Search substring in the String object
 * 
 * @param line is main String object
 * @param substring is a subString object
 * @return void* pointer on the first substring occurence
 */
void *searchSubstring(string *line, string *substring, int *error_status);


/**
 * @brief Get the String current data
 * 
 * @param ptr is a String object
 * @return void* 
 */
void *currentData(string *ptr);


/**
 * @brief Get the String Length object
 * 
 * @param line is a String object
 * @return size_t 
 */
size_t getStringLength(string *line);


/**
 * @brief Get the full String Size object
 * 
 * @param line is a String object 
 * @return size_t 
 */
size_t getStringSize(string *line);


/**
 * @brief Get the Size of one element in the String object
 * 
 * @param line is a String object
 * @return size_t 
 */
size_t getElementSize(string *line);

/**
 * @brief Get the Register information about the String object
 * 
 * @param line is a String Object
 * @return int 
 */
int getRegister(string *line, int *error_status);


/**
 * @brief Print String object
 * 
 * @param line is a String object
 */
void printString(string *line, int *error_status);


/**
 * @brief Printf register information about the String object
 * 
 * @param line is a String object
 */
void printRegisterInfo(string *line, int *error_status);


/**
 * @brief This is enumeration of possible cases to register infromation
 */
enum RegisterInformation
{
    LOWER = 1,
    UPPER = 2,
    DIFFERENT = 3,
    EMPTY = -1,
};


#endif