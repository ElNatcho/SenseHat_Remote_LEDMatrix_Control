#ifndef CPROGRAM_HPP
#define CPROGRAM_HPP

// Includes
#include<iostream>
#include<SFML\Graphics.hpp>
#include<chrono>
#include<thread>
#include"CStaticTools.hpp"
#include"CUDP_Client.hpp"
#include"Canvas.hpp"
#include"CButton.hpp"
#include"CSlider.hpp"
#include"CUDP_Client.hpp"

// CProgram
class CProgram {
public:

	// -- Kon/Destruktor --
	CProgram();
	~CProgram();

	// -- Methoden --

	// CORE_LOOP des Programms
	void run();

	// Methode mit der man feststellen kann ob das Programm gerade l�uft
	bool isRunning();

	// Speichert den Status des Programms (l�uft/l�uft nicht)
	bool *running;

	// Hauptfenster des Programms
	sf::RenderWindow *window;

	// Aktuell ausgew�hlte Farbe
	sf::RectangleShape *curColor;

	// Variable speichert den zuletzt gedr�ckten Maus knopf
	sf::Mouse::Button lastButton;

	// Setzt die ColorSlider und dir curCol auf eine bestimmte Farbe
	void adjustColorSlider(sf::Color color);

private:

	// -- Member Vars --
	sf::Event *_sfEvent;
	Canvas *_canvas;

	// Startknopf
	CButton *_draw_BTN;

	// Farbslider
	CSlider *_redslider;
	CSlider *_blueslider;
	CSlider *_greenslider;

	// UDP_Client
	CUDP_Client *_udpClient;

};

#endif