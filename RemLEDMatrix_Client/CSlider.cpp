#include"CSlider.hpp"

// -- Konstruktor --
CSlider::CSlider() {
	// Alloc Memory
	_railroad = new sf::RectangleShape();
	_grabbed = new bool;
	_slider = new sf::RectangleShape();

	// Default-Werte setzen
	setSliderSize(20, 50);
	setRailroadSize(255, 20);
	setSliderColor(sf::Color(200, 200, 200));
	setRailroadColor(sf::Color(100, 100, 100));
	setPosition(0, 0);

	// Werte setzen
	*_grabbed = new bool;
}

// -- updateSlider --
// Updatet den Slider und gibt den aktuellen Wert zurück
// @param win: Window in dem der Slider gezeichnet wird
//
float CSlider::updateSlider(sf::RenderWindow &win) {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
		if (_slider->getGlobalBounds().contains(
			sf::Mouse::getPosition(win).x,
			sf::Mouse::getPosition(win).y)) {
			*_grabbed = true;
		}
		if (*_grabbed && _railroad->getPosition().x <= sf::Mouse::getPosition(win).x &&
		   (_railroad->getPosition().x + _railroad->getSize().x - _slider->getSize().x) >= sf::Mouse::getPosition(win).x) {
			_slider->setPosition(sf::Mouse::getPosition(win).x, _slider->getPosition().y);
		}
	} else {
		*_grabbed = false;
	}
	return ((_slider->getPosition().x - _railroad->getPosition().x) / (_railroad->getSize().x - _slider->getSize().x)) * 255;
}

// -- setSliderSize --
// Methode die die Größe des Sliders ändert
// @param x, y: Neue Größe des Sliders
//
void CSlider::setSliderSize(float x, float y) {
	_slider->setSize(sf::Vector2f(x, y));
}

// -- setRailroadS
// Methode die die Größe der railroad setzt
// @param x, y: Neue Größe der Railroad
//
void CSlider::setRailroadSize(float x, float y) {
	_railroad->setSize(sf::Vector2f(x, y));
}

// -- setPosition --
// Methode setzt die Position des Sliders
// @param x, y: Neue Position des Sliders
//
void CSlider::setPosition(float x, float y) {
	_railroad->setPosition(x, y);
	_slider->setPosition(_railroad->getPosition().x, 
	_railroad->getPosition().y + (_railroad->getSize().y / 2) - (_slider->getSize().y / 2));
}

// -- setSliderColor --
// Methode die die Farbe des Sliders verändert
// @param color: Neue Farbe des Sliders
//
void CSlider::setSliderColor(sf::Color color) {
	_slider->setFillColor(color);
}

// -- setRailroadColor --
// Methode die die Farbe der Railroad verändert
// @param color: Neue Farbe der Railroad
//
void CSlider::setRailroadColor(sf::Color color) {
	_railroad->setFillColor(color);
}

// -- render --
// Methode mit der der Slider gezeichnet wird
// @param win: Window in dem der Slider gezeichnet werden soll
//
void CSlider::render(sf::RenderWindow &win) {
	win.draw(*_railroad);
	win.draw(*_slider);
}

// -- adjustValue --
// Methode gleicht den "Wert" des sliders an value an
// @param value: Wert an den der Slider angepasst werden soll
//
void CSlider::adjustValue(float value) {
	if (value > 255) {
		throw "EXCEPTION: RGB-Value over 255";
		return;
	} else {
		_slider->setPosition(
			((value*(_railroad->getSize().x - _slider->getSize().x))/255) + _railroad->getPosition().x,
			_railroad->getPosition().y + (_railroad->getSize().y / 2) - (_slider->getSize().y / 2));
	}
}

// -- Destruktor --
CSlider::~CSlider() {
	// Free Memory
	SAFE_DELETE(_railroad);
	SAFE_DELETE(_slider);

}