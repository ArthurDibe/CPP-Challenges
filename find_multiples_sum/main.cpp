#include <iostream>

void checkMultiple(const int &number, bool &isMult)
{
    if (number % 3 == 0 && number % 5 == 0)
        isMult = true;
    else if (number % 3 == 0)
        isMult = true;
    else if (number % 5 == 0)
        isMult = true;
}

int main()
{
    int value = 1000;
    
    return 0;
}