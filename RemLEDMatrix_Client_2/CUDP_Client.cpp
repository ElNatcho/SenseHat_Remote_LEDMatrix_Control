#include"CUDP_Client.hpp"

// -- Konstruktor --
CUDP_Client::CUDP_Client() {
	// Alloc Memory
	_recEndpoint = new udp::endpoint();
	_io_service = new boost::asio::io_service();
	_send_buf = new boost::array<char, 1024>();
	_resolver = new udp::resolver(*_io_service);
	_socket = new udp::socket(*_io_service);
}

// -- Konstruktor --
CUDP_Client::CUDP_Client(std::string ip, std::string port) {
	setHost(ip, port);
}

// -- sendData --
// Methode mit der man Daten zu einem Server schicken kann
// @param data: Daten die gesendet werden sollen
//
void CUDP_Client::sendData(std::array<short, 64> data) {
	_socket->send_to(boost::asio::buffer(data), *_recEndpoint);
	_io_service->run();
}

// -- setHost --
// Methode mit der man sich mit dem Server "verbinden" kann
// @param ip  : IP des Servers
// @param port: Port des Servers
//
void CUDP_Client::setHost(std::string ip, std::string port) {
	_query = new udp::resolver::query(udp::v4(), ip, port);
	try {
		*_recEndpoint = *_resolver->resolve(*_query);
		_socket->open(udp::v4());
	} catch (std::exception &e) {
		std::cout << ">>EXCEPTION: " << e.what() << std::endl;
	}
}

// -- Destruktor --
CUDP_Client::~CUDP_Client() {
	_io_service->run();
	
	// Free Memory
	SAFE_DELETE(_send_buf);
	SAFE_DELETE(_io_service);
	SAFE_DELETE(_query);
	SAFE_DELETE(_resolver);
	SAFE_DELETE(_socket);
	SAFE_DELETE(_recEndpoint);

}