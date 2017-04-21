#include"Canvas.hpp"
#include"CProgram.hpp"

// -- Konstruktor --
Canvas::Canvas() {
	// Alloc Memory
	_canvasData = new std::array<short, 64>();

	// Speicher für die repräsentative LED Matrix reservieren
	_LED_matrix = new std::array<std::array<sf::RectangleShape*, MATRIX_WIDTH>*, MATRIX_HEIGHT>();
	for (int y = 0; y < _LED_matrix->size(); y++) {
		_LED_matrix->at(y) = new std::array<sf::RectangleShape*, MATRIX_WIDTH>();
		for (int x = 0; x < _LED_matrix->at(y)->size(); x++) {
			_LED_matrix->at(y)->at(x) = new sf::RectangleShape();
			_LED_matrix->at(y)->at(x)->setPosition((LED_WIDTH + LED_OFFSET_X) * x + LED_OFFSET_X,
				(LED_HEIGHT + LED_OFFSET_Y) * y + LED_OFFSET_Y);
			_LED_matrix->at(y)->at(x)->setSize(sf::Vector2f(LED_WIDTH, LED_HEIGHT));
			_LED_matrix->at(y)->at(x)->setFillColor(sf::Color::Black);
		}
	}

}

// -- update --- 
// Methode updatet die repräsentative LED Matrix
// @param program: Ref zum aktuell laufenden Programm
// @param dc: Aktueller DrawController des Programms
//
void Canvas::update(CProgram &program, CDrawController *dc) {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) || 
		sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)) {
		for (int y = 0; y < _LED_matrix->size(); y++) {
			for (int x = 0; x < _LED_matrix->at(y)->size(); x++) {
				if (_LED_matrix->at(y)->at(x)->getGlobalBounds().contains(
					sf::Mouse::getPosition(*program.window).x,
					sf::Mouse::getPosition(*program.window).y)) {
					if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
						_LED_matrix->at(y)->at(x)->setFillColor(dc->getCurColor());
					else if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
						dc->setCurColor(_LED_matrix->at(y)->at(x)->getFillColor());
				}
			}
		}
	}
}

// -- render --
// Methode zeichnet die repräsentative LED Matrix
// @param program: Ref zum aktuell laufenden Programm
//
void Canvas::render(CProgram &program) {
	for (int y = 0; y < _LED_matrix->size(); y++) {
		for (int x = 0; x < _LED_matrix->at(y)->size(); x++) {
			program.window->draw(*_LED_matrix->at(y)->at(x));
		}
	}
}

// -- getCanvasData --
// Gibt ein Byte-Array zurück, dass das aktuelle Canvas repräsentiert
//
std::array<short, 64> Canvas::getCanvasData() {
	for (int i = 0; i < _LED_matrix->size(); i++) {
		for (int j = 0; j < _LED_matrix->at(i)->size(); j++) {
			_canvasData->at(i * 8 + j) = (getColor(_LED_matrix->at(i)->at(j)->getFillColor().r,
										  _LED_matrix->at(i)->at(j)->getFillColor().g,
										  _LED_matrix->at(i)->at(j)->getFillColor().b));
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
	return *_canvasData;
}

// -- getColor --
// Methode konvertiert eine 24-bit (32-bit) Farbe zu einer 16-bit Farbe
// @param r, g, b: RGB-Wert der konvertiert werden soll
//
short Canvas::getColor(int r, int g, int b) {
	r &= 0xF8;
	g &= 0xFC;
	b &= 0xF8;
	return (r << 8) | (g << 3) | (b >> 3);
}

// -- Destruktor --
Canvas::~Canvas() {
	SAFE_DELETE(_canvasData);
	for (int i = 0; i < _LED_matrix->size(); i++) {
		for (int j = 0; j < _LED_matrix->at(i)->size(); j++) {
			SAFE_DELETE(_LED_matrix->at(i)->at(j));
		}
		SAFE_DELETE(_LED_matrix->at(i));
	}
	SAFE_DELETE(_LED_matrix);
}