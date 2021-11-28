#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void tester(std::vector<std::string> &, std::vector<std::string> &);
std::string duplicate_encoder(const std::string &word);

int main()
{

    // TESTS
    std::vector<std::string> stringList = {"din", "recede", "Success", "CodeWarrior", "Supralapsarian", "(( @", " ( ( )"};
    std::vector<std::string> encodedList = {"(((", "()()()", ")())())", "()(((())())", ")()))()))))()(", "))((", ")))))("};

    tester(stringList, encodedList);

    return 0;
}

std::string duplicate_encoder(const std::string &word)
{

    return "";
}

void tester(std::vector<std::string> &original, std::vector<std::string> &resultExpected)
{
    auto it_expected = resultExpected.begin();
    unsigned int testNumber = 1;

    for (auto it_original = original.begin(); it_original != original.end(); ++it_original)
    {
        std::string result = duplicate_encoder(*it_original);
        if (result == *it_expected)
        {
            std::cout << "[ " << testNumber << " - PASSED ]: " << *it_original << " ===> \"" << result << "\"" << std::endl;
        }
        else
        {
            std::cout << "[ " << testNumber << " - FAILED ]: \nExpected=> \"" << *it_expected << "\"\nResulted=> \"" << result << "\"" << std::endl << std::endl;
        }

        ++testNumber;
        ++it_expected;
        
    }
}