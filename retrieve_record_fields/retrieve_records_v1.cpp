/********************************
AUTHOR: Dibe
FILE:	retrieve_records_v1.cpp
ABOUT THIS CODE:
	This module implements the
	algorithm to retrieve five
	words that surrounded by n
	white spaces in a record.
	each field has a comma as
	a delimiter. The first field
	ends with ":"
********************************/

#include <iostream>
#include <string>
#include <iomanip>	// used to set the output style
#include <cmath>	// used to convert string to integer

void trim(std::string& str);
int stringToInt(std::string liczba);
void retrieveInfo(std::string& local_str, std::string& m_reservID, std::string& m_name, std::string& m_email, size_t& m_numOfPeople, size_t& m_dayReserv, size_t& m_timeReserv);
void display(std::string& m_reservID, std::string& m_name, std::string& m_email, size_t& m_numOfPeople, size_t& m_dayReserv, size_t& m_timeReserv);

int main()
{
	std::string m_reservID, m_name, m_email;
	size_t m_numOfPeople, m_dayReserv, m_timeReserv;

	std::string str1 = "45";
	std::string str2 = "3.14159";
	std::string str3 = " RES-012: John    , john@email.com   ,2           ,   5,   16"; // an record

	std::cout << "Original Record: \"" << str3 << "\"\n";	// display the record
	std::cout << "Record's number of characters: " << str3.size() << "\n\n";		// display the size of the record

	// remove white spaces between words
	trim(str3);

	std::string local_str = str3;
	std::cout << std::endl;

	// retrieve the information from a record
	retrieveInfo(local_str, m_reservID, m_name, m_email, m_numOfPeople, m_dayReserv, m_timeReserv);


	// Display all the informations retrieved from a record
	display(m_reservID, m_name, m_email, m_numOfPeople, m_dayReserv, m_timeReserv);
}

// remove white spaces between words
void trim(std::string& str)
{
	for (std::string::size_type i = 0; i < str.size(); ++i) {
		if (str[i] == ' ') {
			str.erase(i, 1);
			i = 0;
		}
	}
	std::cout << "Removing white spaces ...\n" << std::endl;
	std::cout << "Record without white spaces: \"" << str << "\"" << std::endl;
	std::cout << "Record's number of characters: " << str.size() << "\n\n";
}


// retrieve information of a record
void retrieveInfo(std::string& local_str, std::string& m_reservID, std::string& m_name, std::string& m_email, size_t& m_numOfPeople, size_t& m_dayReserv, size_t& m_timeReserv)
{
	for (unsigned int init_position = 0, info_length = 0, count = 0, i = 0; i < local_str.size(); ++i)
	{
		if (local_str[i] == ':') {	// check if it is the first field of the record
			m_reservID = local_str.substr(init_position, i);
			count++;
			init_position = i + 1;
		}
		else if (local_str[i] == ',')
		{
			if (count == 1) {				// check if it is the 2nd field of the record
				info_length = i - init_position;
				m_name = local_str.substr(init_position, info_length);

				count++;
				init_position = i + 1;
			}
			else if (count == 2) {				// check if it is the 3rd field of the record
				info_length = i - init_position;
				m_email = local_str.substr(init_position, info_length);

				count++;
				init_position = i + 1;
			}
			else if (count == 3) {				// check if it is the 4th field of the record
				info_length = i - init_position;
				m_numOfPeople = stringToInt(local_str.substr(init_position, info_length));

				count++;
				init_position = i + 1;
			}
			else if (count == 4) {				// check if it is the last field of the record
				info_length = i - init_position;
				m_dayReserv = stringToInt(local_str.substr(init_position, info_length));

				count++;
				init_position = i + 1;

				info_length = local_str.size() + 1 - init_position;
				m_timeReserv = stringToInt(local_str.substr(init_position, info_length));
			}
		}
	}
}

// convert string to integer
int stringToInt(std::string liczba)
{
	int res = 0;
	for (int i = 0; i < liczba.length(); i++)
		res += (liczba[i] - 48)*pow(10, liczba.length() - 1 - i);
	return res;
}

// Display all the informations retrieved from a record
void display(std::string& m_reservID, std::string& m_name, std::string& m_email, size_t& m_numOfPeople, size_t& m_dayReserv, size_t& m_timeReserv)
{
	std::cout << "RESERVATION DETAILS - OUTPUT\n" << "Reservation " << m_reservID << ":" << std::setw(10) << std::right << m_name
		<< std::setw(20) << std::left << " <" + m_email + ">";

	if (m_timeReserv >= 6 && m_timeReserv <= 9) {
		std::cout << " Breakfast ";
	}
	else if (m_timeReserv >= 11 && m_timeReserv <= 13) {
		std::cout << " Lunch ";
	}
	else if (m_timeReserv >= 17 && m_timeReserv <= 19) {
		std::cout << " Dinner ";
	}
	else {
		std::cout << " Drinks ";
	}

	std::cout << "on day " << m_dayReserv << " @ " << m_timeReserv
		<< ":00 for " << m_numOfPeople << " people." << std::endl;
}