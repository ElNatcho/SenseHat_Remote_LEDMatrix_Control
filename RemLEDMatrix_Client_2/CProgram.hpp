#ifndef CPROGRAM_HPP
#define CPROGRAM_HPP

// Includes
#include<SFML\Graphics.hpp>
#include<iostream>
#include"CStaticTools.hpp"
#include"CUDP_Client.hpp"
#include"CGUI.hpp"

// CProgram
class CProgram {
public:

	// -- Kon/Destruktor --
	CProgram();
	~CProgram();

	// -- Methoden --
	void run(); // F�hrt den CORE_Loop des Programms aus
	bool isRunning(); // Gibt den aktuellen Programmstatus zur�ck

	// -- Vars --
	bool *running; // Speichert den aktuellen Status des Programms ab
	sf::RenderWindow *window; // Hauptfenster

	sf::Event getCurEvent(); // Gibt das aktuelle Event zur�ck

	sf::Mouse::Button lastButton; // Speichert den letzten gedr�ckt Maus Button f�r einen Durchlauf

	CUDP_Client *udp_client; // UDP-Client mit dem Daten zur LED Matrix geschickt werden

private:
	
	// -- Member Vars --
	sf::Event *_sfEvent; // SFML-Event
	CGUI *gui; // Gui des Programms

};


#endif