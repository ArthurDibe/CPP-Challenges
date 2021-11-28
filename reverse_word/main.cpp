#include <iostream>
#include <string>
#include <vector>

void swap(std::string::iterator front, std::string::iterator back);
void getWord(std::string &str, std::string &word, std::size_t &foundPosition);
void reverseWord(std::string &word);
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

// Swap two characters of a word
void swap(std::string::iterator front, std::string::iterator back)
{
    char tmp = *front;
    *front = *back;
    *back = tmp;
}

// find a word in the string sentence
void getWord(std::string &str, std::string &word, std::size_t &foundPosition)
{
    const std::size_t initialPosition = 0;

    foundPosition = str.find_first_of(' ');
    word = str.substr(initialPosition, foundPosition); // save the word before single space found
    str.erase(initialPosition, foundPosition + 1);     // erase the word saved + single space
}

// reverse one word
void reverseWord(std::string &word)
{
    auto back_it = word.end();
    for (auto front_it = word.begin(); front_it != back_it; ++front_it)
    {
        if (front_it != back_it - 1)
            swap(front_it, --back_it); // swap characters if they are not the same position in the word
    }
    word += ' '; // add single space after the word
}

std::string reverse_strings(std::string str)
{
    std::string word, result = "";
    std::size_t foundPosition = 0;

    while (foundPosition != std::string::npos)
    {
        getWord(str, word, foundPosition);
        reverseWord(word);
        result += word; // add the reversed word into the string
    }

    result.erase(result.length() - 1, 1); // erase a single space from the end of the string

    return result;
}