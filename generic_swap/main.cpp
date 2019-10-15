/* *******************************
AUTHOR: Dibe
FILE:	main.cpp

ABOUT THIS CODE:
	This module allocate dynamic
    memory through a function 
    called initialize and swap 
    variables' contents by calling 
    the templated function swap.
******************************* */

#include "Generic.h"

int main(int argc, char** argv) 
{
    int a = 10, b = 20;
    std::cout << "a= " << a << "\nb= " << b << std::endl;
   
    change::swap(a,b);

    std::cout << "Templated function SWAP is called !\n";
    std::cout << "a= " << a << "\nb= " << b << std::endl;

    char* string_1=nullptr; 
    char* string_2=nullptr;

    try // Check if there will be an std::bad_alloc
    {
        string_1 = change::initialize(string_1, "John", 10);
        string_2 = change::initialize(string_2, "Mary", 10);
        
    } catch (const char* msg) {
        std::cout << msg << std::endl;
    }

    std::cout << "First name entered: " << string_1 << std::endl;
    std::cout << "Second name entered: " << string_2 << std::endl;

    change::swap(string_1, string_2);

    std::cout << "\nTemplated function SWAP is called !\n";
    std::cout << "First name is now: " << string_1 << std::endl;
    std::cout << "Second name is now: " << string_2 << std::endl;


    delete[] string_1;
    delete[] string_2;
    string_1 = nullptr;
    string_2 = nullptr;

    return 0;
}