#include<iostream>
#include"CUDP_Server.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cout << "RemLEDMatrix <Conf-File>" << std::endl;
		return 0;
	} else {
		GD::laodData(argv[1]);
	}

	try {
		std::cout << ">Start listining on port " << GD::server_port << std::endl;
		boost::asio::io_service io_service;
		CUDP_Server updServer(io_service);
		io_service.run();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}