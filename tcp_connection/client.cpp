#ifdef _WIN32
#define _WIN32_WINNT 0x0A00
#endif
#define ASIO_STANDALONE

#include <iostream>
//#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/asio/error.hpp>
//#include <boost/asio/ts/internet.hpp>
//#include <boost/asio/ts/buffer.hpp>


int main()
{
	boost::system::error_code ec;

	// io_context is essential in every boost program
	boost::asio::io_context context;

	// Get the address of somewhere we want to connect to
	auto ip_address = boost::asio::ip::make_address("93.184.216.34", ec); // conver string into address
	boost::asio::ip::tcp::endpoint endpoint(ip_address, 80);

	// create a network socket which is the hook that connects our program into the network that we are connected to
	boost::asio::ip::tcp::socket socket(context);

	// tell the socket to try to connect
	socket.connect(endpoint, ec);

	// handle if some error occured
	if (!ec)
	{
		std::cout << "CONNECTED !" << std::endl;
	}
	else {
		std::cerr << "Falied to connect: " << ec.message() << std::endl;
	}

	system("pause");
	return 0;
}
