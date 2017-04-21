#ifndef CBUTTON_HPP
#define CBUTTON_HPP

// Includes
#include<iostream>
#include<SFML\Graphics.hpp>
#include"CStaticTools.hpp"

// CButton
class CButton {
public:

	// -- Kon/Destruktor --
	CButton();
	~CButton();

	// -- Methoden --

	// Methode updatet den Knopf und checkt ob der Knopf gedr�ckt wurde
	void update(sf::RenderWindow &win);

	// Methoden mit welchen man die Position des Knopfes setzen kann
	void setPosition(float x, float y);
	void setPosition(sf::Vector2f pos);

	// Methoden mit welchen man die Farben des Knopfes ver�ndern kann
	void setTextColor(sf::Color color);
	void setButtonColor(sf::Color color);

	// Methode mit der man die Schriftart des Texts setzen kann
	void setFont(std::string path);

	// Methoden mit welchen man die Gr��e des Knopfes ver�ndern kann
	void setButtonSize(float x, float y);
	void setButtonSize(sf::Vector2f size);

	// Methode mit der man die Gr��e des Texts ver�ndern kann
	void setTextSize(int size);

	// Methode mit der man den Text des Buttons ver�ndern kann
	void setText(std::string text);

	// Methode mit der man den Knopf zeichnen kann
	void render(sf::RenderWindow &win);

	// Methode invertiert die Farbe des Knopfs und setzt diese Farbe als Text Farbe
	void invertTextColor();

	// Methode gibt zur�ck ob der Knopf gedr�ckt wurde
	bool wasPushed();

private:

	// -- Member Vars --
	bool *_wasPushed;
	sf::Font *_font;
	sf::Text *_text;
	sf::RectangleShape *_btn;

};

#endif