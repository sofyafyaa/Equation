/**
 * @file main.cpp
 * @author Sofyaa Savelyeva
 * @brief This program solve quadratic equation in real and complex numbers
 * @version 1.0
 * @date 2022-09-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <math.h>
#include "interface.h"

//#define TEST_MODE
/**
 * @brief
 * program runs unit tests from file tests.txt (if argumet of main is 1)
 * after that runs interface of program
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */

int main(int argc, char* argv[]) {
    my_assert(0, -1);
    #ifdef TEST_MODE 
    if (argc == 2) {
        char* key = argv[1];
        test_program(key);
    }
    else {
        test_program("test.txt");
    }

    #else
    use_program();
    #endif

    return 0;
}