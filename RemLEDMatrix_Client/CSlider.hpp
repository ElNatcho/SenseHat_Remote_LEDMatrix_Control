#ifndef CSLIDER_HPP
#define CSLIDER_HPP

// Includes
#include<SFML\Graphics.hpp>
#include<iostream>
#include"CStaticTools.hpp"

// CSlider
class CSlider {
public:

	// -- Kon/Destruktor --
	CSlider();
	~CSlider();

	// -- Methoden --

	// Updatet den Slider und gibt den aktuellen Wert zur�ck
	float updateSlider(sf::RenderWindow &win);

	// Methode die die Gr��e des Sliders �ndert
	void setSliderSize(float x, float y);

	// Methode die die Gr��e der railroad setzt
	void setRailroadSize(float x, float y);

	// Methode setzt die Position des Sliders
	void setPosition(float x, float y);
	
	// Methode die die Farbe des Sliders ver�ndert
	void setSliderColor(sf::Color color);

	// Methode die die Farbe der Railroad ver�ndert
	void setRailroadColor(sf::Color color);

	// Methode mit der der Slider gezeichnet wird
	void render(sf::RenderWindow &win);

	// Methode gleicht den "Wert" des sliders an value an
	void adjustValue(float value);

private:

	// -- Member Vars --
	sf::RectangleShape *_railroad;
	sf::RectangleShape *_slider;
	bool *_grabbed;

};

#endif