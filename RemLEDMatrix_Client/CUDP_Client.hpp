#ifndef CUDP_CLIENT_HPP
#define CUDP_CLIENT_HPP

// Includes
#include<iostream>
#include<boost\asio.hpp>
#include<boost\array.hpp>
#include<boost\bind.hpp>
#include"CStaticTools.hpp"

using namespace boost::asio::ip;

// CUDP_Client
class CUDP_Client {
public:

	// -- Kon/Destruktor --
	CUDP_Client(std::string ip, std::string port);
	~CUDP_Client();

	// -- Methoden --

	// Methode mit der man Daten zu einem Server schicken kann
	void sendData(std::array<short, 64> data);

private:

	// -- Member Vars --
	boost::array<char, 1024> *_send_buf;
	boost::asio::io_service *_io_service;
	udp::resolver::query *_query;
	udp::resolver *_resolver;
	udp::endpoint *_recEndpoint;
	udp::socket *_socket;


};

#endif