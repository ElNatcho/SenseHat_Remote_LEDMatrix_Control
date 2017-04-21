#ifndef CANVAS_HPP
#define CANVAS_HPP

// Includes
#include<SFML\Graphics.hpp>
#include<iostream>
#include<array>
#include<thread>
#include<chrono>
#include"CDrawController.hpp"

#define MATRIX_HEIGHT 8
#define MATRIX_WIDTH  8

#define LED_HEIGHT 45.F
#define LED_WIDTH  45.F
#define LED_OFFSET_X 5.F
#define LED_OFFSET_Y 5.F

// Forwärtsdeklaration
class CProgram;

// Canvas
class Canvas {
public:

	// -- Kon/Destruktor --
	Canvas();
	~Canvas();

	// -- Methoden --
	void update(CProgram &program, CDrawController *dc); // Methode updatet die repräsentative LED Matrix
	void render(CProgram &program); // Methode zeichnet die repräsentative LED Matrix

	// Gibt ein Byte-Array zurück, dass das aktuelle Canvas repräsentiert
	std::array<short, 64> getCanvasData();

	// Methode konvertiert eine 24-bit (32-bit) Farbe zu einer 16-bit Farbe
	short getColor(int r, int g, int b);

private:

	// -- Member Vars --

	// Matrix repräsentiert die LED Matrix
	std::array<std::array<sf::RectangleShape*, MATRIX_WIDTH>*, MATRIX_HEIGHT>* _LED_matrix;
	std::array<short, 64> *_canvasData;

};

#endif