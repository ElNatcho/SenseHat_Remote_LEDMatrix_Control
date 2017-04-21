#ifndef CUDP_SERVER_HPP
#define CUDP_SERVER_HPP

// Includes
#include<iostream>
#include<boost/asio.hpp>
#include<boost/bind.hpp>
#include<boost/array.hpp>
#include"GlobalData.hpp"
#include"CLEDMatrix.hpp"

using namespace boost::asio::ip;

// CUDP_Server
class CUDP_Server {
public:

	// -- Kon/Destruktor --
	CUDP_Server(boost::asio::io_service &io_service);
	~CUDP_Server();

private:

	// -- Member Vars --
	udp::socket _socket;
	udp::endpoint _remEndpoint;
	boost::array<short, 64> _recBuffer;

	CLEDMatrix *_led_matrix;

	// -- Member Methods --
	void _start_receive();
	void _handle_receive(const boost::system::error_code &ec, std::size_t len);

};

#endif