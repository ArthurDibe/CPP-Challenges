#include <iostream>
#include <string>

char m_delimiter;               // global variable
std::size_t m_widthField = 0;   // global variable

const std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
void saveToken(const std::string& str, const std::size_t& delimiter_position, const std::size_t& next_pos, std::string& token, bool& more);

int main()
{
    std::string str = "CPU,123456,5,Central Processing Unit";
    std::string token;
    bool more = false;
    std::size_t next_pos = 0;
		    
    m_delimiter = ',';

    try { 
	    token = extractToken(str,next_pos,more);
    }
    catch(const char* msg) {
	    std::cout << msg <<std::endl;
    }

    std::cout << token;

    return 0;
}

// - This function uses the delimiter to extract the next token from str starting at next_pos,
//   if successful, it returns the extracted token found and sets more to true; false otherwise.
// - Reports an exception if there are two delimiters with no token between them.
// - Updates the current object's m_widthField data member if its current value is less than the size of the
//   token extracted.
const std::string extractToken(const std::string& str, size_t& next_pos, bool& more)
{
    std::string token;
    std::size_t delimiter_position = 0;
    // finds the index of the delimiter, starting from a specific position
    if(str[next_pos] != m_delimiter) delimiter_position = str.find(m_delimiter, next_pos);
                    
    if(delimiter_position != next_pos && delimiter_position != std::string::npos) {
	    saveToken(str,delimiter_position,next_pos,token,more);
    }
    else if(delimiter_position == std::string::npos) {
            delimiter_position = str.length();
            saveToken(str,delimiter_position,next_pos,token,more);
    }
    else {
            more = false;
            throw "EXCEPTION: Two delimiters Without Token !";
    }
    return token; 
}

// Retrieve the token between delimiters, set "more" variable to true and assign m_widthField (data member) to the length of the token saved
// if m_widthField's length is lower than the token's length
void saveToken(const std::string& str, const std::size_t& delimiter_position, const std::size_t& next_pos, std::string& token, bool& more)
{
    std::size_t length = delimiter_position-next_pos;
    token = str.substr(next_pos, length);
    more = true;
    if(m_widthField < length) m_widthField = length;
}
