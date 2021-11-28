#include <iostream>
#include <string>
#include <vector>

void swap(std::string::iterator front, std::string::iterator back);
void getWord(std::string &str, std::string &word, std::size_t &foundPosition);
std::string reverse_strings(std::string str);

int main()
{
    // TESTS
    std::vector<std::string> stringList = {"The quick brown fox jumps over the lazy dog.", "apple", "a b c d", "double  spaced  words", "", "ab   ba   cd"};
    std::vector<std::string> reversedList = {"ehT kciuq nworb xof spmuj revo eht yzal .god", "elppa", "a b c d", "elbuod  decaps  sdrow", "", "ba   ab   dc"};
    auto it_expected = reversedList.begin();
    unsigned int testNumber = 1;

    for (auto it_original = stringList.begin(); it_original != stringList.end(); ++it_original)
    {
        std::string reversed = reverse_strings(*it_original);
        if (reversed == *it_expected)
        {
            std::cout << "[ " << testNumber << " - PASSED ]: result ===> \"" << reversed << "\"" << std::endl;
        }
        else
        {
            std::cout << "[ " << testNumber << " - FAILED ]: \nExpected=> \"" << *it_expected << "\"\nResulted=> \"" << reversed << "\"" << std::endl;
        }

        ++testNumber;
        ++it_expected;
    }

    return 0;
}

// Swap two characters
void swap(std::string::iterator front, std::string::iterator back)
{
    char tmp = *front;
    *front = *back;
    *back = tmp;
}