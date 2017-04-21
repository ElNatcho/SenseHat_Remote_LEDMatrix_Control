#ifndef CGUI_HPP
#define CGUI_HPP

// Includes
#include<iostream>
#include<SFML\Graphics.hpp>
#include<TGUI\TGUI.hpp>
#include"Canvas.hpp"
#include"CStaticTools.hpp"
#include"CDrawController.hpp"

// Vorwärtsdeklaration
class CProgram;

#define CONNECT_BUTTON "Verbinden_BTN"

#define IP_TEXTBOX   "IP_TB"
#define PORT_TEXTBOX "PORT_TB"

// CGUI
class CGUI : public tgui::Gui {
public:

	// -- Kon/Destruktor --
	CGUI(sf::RenderWindow &win);
	~CGUI();

	// -- Methoden --
	void update(CProgram &prog); // Methode updated das GUI
	void render(CProgram &prog); // Methode rendert das GUI

	void setSignals(CProgram &prog); // Methode mit der die Signale der UI-Elemente gesetzt wird

private:
	
	// -- Member Vars --
	tgui::Button::Ptr  _connect_BTN;
	tgui::TextBox::Ptr _ip_TB;
	tgui::TextBox::Ptr _port_TB;
	Canvas *_canvas;

	CDrawController *_drawController;

	// -- Member Methods --
	void setHost(CProgram &prog); // Methode legt den Host fest
	void sendData(CProgram &prog); // Methode sendet die nötigen Daten an den Host

};

#endif