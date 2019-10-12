#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

int stringToInt(std::string liczba)
{
	int res=0;
	for(int i=0; i<liczba.length(); i++)
		res += (liczba[i]-48)*pow(10, liczba.length()-1-i);
	return res;
}

int main() 
{

    std::string m_reservID, m_name, m_email; 
		unsigned int m_numOfPeople, m_dayReserv, m_timeReserv;

    std::string str1 = "45";
    std::string str2 = "3.14159";
    std::string str3 = " RES-012: John    , john@email.com   ,2           ,   5,   16";

    std::cout << str3.size() << std::endl;
    std::cout << str3 << "\n\n";

    // remove white spaces between words
   for(std::string::size_type i = 0; i < str3.size(); ++i) {
        if(str3[i] == ' '){
          str3.erase(i,1);
          i = 0;
        }
    }
    std::cout << "Removing white spaces ..."<< std::endl;
    std::cout << str3 << std::endl;

    std::string local_str = str3;
    std::cout << std::endl;

    // retrieve information of a record
    for (unsigned int init_position = 0, info_length = 0, count = 0, i = 0; i < local_str.size(); ++i)
    {

			if(local_str[i] == ':'){
        m_reservID = local_str.substr(init_position,i);
        count++;
        init_position = i + 1;
      }
      else if(local_str[i] == ','){
        if(count == 1) {
          info_length = i - init_position;
          m_name = local_str.substr(init_position,info_length);

          count++;
          init_position = i + 1;
        }
        else if(count == 2) {
          info_length = i - init_position;
          m_email = local_str.substr(init_position,info_length);

          count++;
          init_position = i + 1;
        }
        else if(count == 3) {
          info_length = i - init_position;
          m_numOfPeople = stringToInt(local_str.substr(init_position,info_length));

          count++;
          init_position = i + 1;
        }
        else if(count == 4) {
          info_length = i - init_position;
          m_dayReserv = stringToInt(local_str.substr(init_position,info_length));

          count++;
          init_position = i + 1;

          info_length = local_str.size()+1 - init_position;
          m_timeReserv = stringToInt(local_str.substr(init_position,info_length));
        }
      }
		}

  std::cout << "Reservation " << m_reservID << ":" << std::setw(10) << std::right << m_name
			<< std::setw(20) << std::left << " <" + m_email + ">";

		if (m_timeReserv >= 6 && m_timeReserv <= 9) {
			std::cout << " Breakfast ";
		}
		else if(m_timeReserv >= 11 && m_timeReserv <= 13){
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