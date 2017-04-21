#include"CDrawController.hpp"

// -- Konstruktor --
CDrawController::CDrawController() {
	// Alloc Memory
	window = new sf::RenderWindow(sf::VideoMode(250,165), "Zeichentools");
	_curCol = new sf::RectangleShape();
	_sfEvent = new sf::Event();
	_r_slider = tgui::Slider::create();
	_g_slider = tgui::Slider::create();
	_b_slider = tgui::Slider::create();
	_draw_BTN = tgui::Button::create();

	// Werte setzen
	this->setWindow(*window);

	_curCol->setSize(sf::Vector2f(240, 30));
	_curCol->setPosition(5, 5);
	_curCol->setOutlineThickness(2.F);
	_curCol->setOutlineColor(sf::Color::Black);
	_curCol->setFillColor(sf::Color::Black);
	
	// Slider konfigurieren
	// Roten Slider
	_r_slider->setPosition(10, 50);
	_r_slider->setSize(220, 10);
	_r_slider->setMaximum(255);
	this->add(_r_slider, R_SLIDER);

	// Grüner Slider
	_g_slider->setPosition(10, 75);
	_g_slider->setSize(220, 10);
	_g_slider->setMaximum(255);
	this->add(_g_slider, G_SLIDER);

	// Blauer Slider
	_b_slider->setPosition(10, 100);
	_b_slider->setSize(220, 10);
	_b_slider->setMaximum(255);
	this->add(_b_slider, B_SLIDER);

	// Zeichnen-Button konfiguriren
	_draw_BTN->setPosition(10, 125);
	_draw_BTN->setSize(220, 30);
	_draw_BTN->setFont("blurb.ttf");
	_draw_BTN->setText("Zeichnen");
	_draw_BTN->setTextSize(30);
	this->add(_draw_BTN, DRAW_BTN);

}

// -- run --
// Führt den CORE_Loop des Fensterns ein mal aus
//
void CDrawController::run() {
	if (window->isOpen()) {
		while (window->pollEvent(*_sfEvent)) { // Checken ob Events vorhanden sind
			this->handleEvent(*_sfEvent);
		}

		window->clear(sf::Color(200, 200, 200));

		// Aktuelle Farbe updaten und anzeigen
		_curCol->setFillColor(this->getCurColor());
		window->draw(*_curCol);

		this->draw();

		window->display();
	}
}

// -- getCurColor -- 
// Gibt die aktuell ausgewählte Farbe zurück
//
sf::Color CDrawController::getCurColor() {
	return sf::Color(
		this->get<tgui::Slider>(R_SLIDER)->getValue(),
		this->get<tgui::Slider>(G_SLIDER)->getValue(),
		this->get<tgui::Slider>(B_SLIDER)->getValue());
}

// -- setCurColor --
// Ändert die aktuell ausgewählte Farbe
// @param col: Neue Farbe
//
void CDrawController::setCurColor(sf::Color col) {
	_curCol->setFillColor(col);
	this->get<tgui::Slider>(R_SLIDER)->setValue(col.r);
	this->get<tgui::Slider>(G_SLIDER)->setValue(col.g);
	this->get<tgui::Slider>(B_SLIDER)->setValue(col.b);
}

// -- Destruktor --
CDrawController::~CDrawController() {

}