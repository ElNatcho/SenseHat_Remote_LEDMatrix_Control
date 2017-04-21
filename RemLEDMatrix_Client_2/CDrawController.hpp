#ifndef CDRAWCONTROLLER_HPP
#define CDRAWCONTROLLER_HPP

// Includes
#include<iostream>
#include<SFML\Graphics.hpp>
#include<TGUI\TGUI.hpp>
#include<exception>

// RGB-Slider
#define R_SLIDER "Red_Slider"
#define G_SLIDER "Green_Slider"
#define B_SLIDER "Blue_Slider"

// Knopf zum zeichnen
#define DRAW_BTN "Zeichnen_BTN"

// CDrawController
class CDrawController : public tgui::Gui {
public:

	// -- Kon/Destruktor --
	CDrawController();
	~CDrawController();

	// -- Methoden --
	void run(); // Führt den CORE_Loop des Fensterns ein mal aus
	sf::Color getCurColor(); // Gibt die aktuell ausgewählte Farbe zurück
	void setCurColor(sf::Color col); // Ändert die aktuell ausgewählte Farbe

	// -- Vars --
	sf::RenderWindow *window; // Fenster in dem der DrawController gezeichnet wird

private:
	
	// -- Member Vars --
	sf::Event *_sfEvent; // Events die in diesem Fenster passieren

	sf::RectangleShape *_curCol; // Rechteck zeigt die aktuell ausgewählte Farbe an

	// Gui Elemente
	tgui::Button::Ptr _draw_BTN;
	tgui::Slider::Ptr _r_slider;
	tgui::Slider::Ptr _g_slider;
	tgui::Slider::Ptr _b_slider;


};

#endif