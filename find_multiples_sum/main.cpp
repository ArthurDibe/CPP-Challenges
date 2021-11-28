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

int solution(int number)
{
    unsigned int result = 0;
    bool isMult = false;
    static const int originalNumber = number;

    if (number > 0)
    {
        if (number != originalNumber)
            checkMultiple(number, isMult);

        if (isMult)
            result += number + solution(number - 1);
        else
            result += solution(number - 1);
    }

    return result;
}

int main()
{
    int value = 1000;
    std::cout << "the sum of all the multiples of 3 or 5 below " << value << " = " << solution(value) << std::endl;
    return 0;
}