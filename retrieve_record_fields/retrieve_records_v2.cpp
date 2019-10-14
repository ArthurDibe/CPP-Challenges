/********************************
AUTHOR: Dibe
FILE:	retrieve_records_v2.cpp
ABOUT THIS CODE:
	This module implements the 
	algorithm to retrieve two
	words that surrounded by n
	white spaces in a record
********************************/

#include <iostream>
#include <string>
#include <fstream>

void display(const std::string*, const std::string*);

int main()
{
    std::string records[5], m_goodWords[5], m_badWords[5];
    records[0] = "    beggin      begin    ";
    records[1] = "  staaaaage       stage     ";
    records[2] = "hisrory    history";
    records[3] = "        namme     name          ";
    records[4] = "  learrn   learn    ";

    size_t count = 0;
    do{
        size_t first_index = records[count].find_first_not_of(' ');				// find first index of BAD WORD
		size_t last_index = records[count].find(' ', first_index);				// find the last index of BAD WORD
		m_badWords[count] = records[count].substr(first_index, last_index - first_index); // Retrieve BAD WORD

		first_index = records[count].find_first_not_of(' ', last_index);		// find last index of GOOD WORD
		last_index = records[count].find_last_not_of(' ')+1;					// find last index of GOOD WORD
		m_goodWords[count] = records[count].substr(first_index, last_index-first_index);	// Retrieve GOOD WORD

        ++count;
    }while(count < 5);

    display(m_badWords, m_goodWords);
}

void display(const std::string* m_badWords, const std::string* m_goodWords)
{
    size_t count = 0;
    do{
        std::cout << count+1 << "st ROW:|" << m_badWords[count] << "," << m_goodWords[count] << "|" << std::endl;
        ++count;
    }while(count < 5);
}