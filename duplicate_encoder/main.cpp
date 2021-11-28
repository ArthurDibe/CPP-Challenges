#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

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
    std::string result = "";
    std::string str_copy = word;

    // replace uppercase characters to lowercase
    std::for_each(str_copy.begin(), str_copy.end(), [](char &c)
    {
        if (isupper(c))
            c = std::tolower(c);
    });

    // encode the characters of the string
    std::for_each(str_copy.cbegin(), str_copy.cend(),[&str_copy, &result](char c)
    {
        unsigned int curr_count = std::count(str_copy.cbegin(), str_copy.cend(), c);

        if (curr_count > 1)
            result += ')';
        else
            result += '(';
    });

    return result;
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
            std::cout << "[ " << testNumber << " - FAILED ]: " << *it_original << std::endl;
            std::cout << "Expected=> \"" << *it_expected << "\"" << std::endl;
            std::cout << "Resulted=> \"" << result << "\"" << std::endl
                      << std::endl;
        }

        ++testNumber;
        ++it_expected;
    }
}