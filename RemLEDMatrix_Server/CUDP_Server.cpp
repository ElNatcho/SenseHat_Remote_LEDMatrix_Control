#include"CUDP_Server.hpp"

// -- Konstruktor --
CUDP_Server::CUDP_Server(boost::asio::io_service &io_service)
	: _socket(io_service, udp::endpoint(udp::v4(), GD::server_port)) {
	std::cout << ">Start Listening..." << std::endl;
	try {
		_led_matrix = new CLEDMatrix(GD::fb_path);
		_start_receive();
	} catch (int ex) {
		std::cout << ex << std::endl;
	}
}

void CUDP_Server::_start_receive() {
	_socket.async_receive_from(
		boost::asio::buffer(_recBuffer), _remEndpoint,
		boost::bind(&CUDP_Server::_handle_receive, this,
			boost::asio::placeholders::error,
			boost::asio::placeholders::bytes_transferred));
}

void CUDP_Server::_handle_receive(const boost::system::error_code &ec, std::size_t len) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			_led_matrix->setPixel(i, j, _recBuffer.at(i * 8 + j));
		}
	}
	_start_receive();
}

// -- Destruktor --
CUDP_Server::~CUDP_Server() {
	delete _led_matrix; _led_matrix = nullptr;
}