/* *******************************
AUTHOR: Dibe
FILE:	Generic.h

ABOUT THIS CODE:
	This header conatains a
    definition of initialize function
    that will allocate dynamic memory
    for a char*. 
    In addition implements a templated 
    function that swaps variables, 
    inclusive c-style string variables 
    in a specialization for swap.
******************************* */

#ifndef CHANGE_GENERIC_H
#define CHANGE_GENERIC_H

#define _CTR_SECURE_NO_WARNINGS // for strncpy function

#include <iostream>
#include <cstring>

namespace change
{
    char* initialize(char* string, const char* name, size_t size = 10)
    {
        if(strlen(name) > size) throw "EXCEPTION: Please enter a greater size or a smaller name...";

        string = new char[size+1];
        strncpy(string, name, size);
        string[size] = '\0';

        return string;
    }

    // function template that swaps two variable
    template<typename T>
    void swap(T& a, T& b){
        T c;
        c = a;
        a = b;
        b = c;
    }

    // function template specialized in swapping two c-style string
    template<>
    void swap<char*>(char*& a, char*& b)
    {
        int size_a = strlen(a);
        int size_b = strlen(b);
        char* c = nullptr;
        size_t* size_c = nullptr;

        // check which parameter has a greater length
        if(size_a > size_b) size_c = (size_t*) &size_a; // size_c receives a pointer to a reference of size_a
        else size_c = (size_t*) &size_b;                // size_c receives a pointer to a reference of size_b
        
        c = new char[*size_c+1];    // allocate the contents of size_c (which is a reference to one of the c-style strings)

        strncpy(c, a, *size_c);
        c[*size_c] = '\0';

        strncpy(a, b, size_b);
        a[size_b] = '\0';

        strncpy(b, c, *size_c);
        b[*size_c] = '\0';

        delete[] c;
        c = nullptr;
    }
}
#endif