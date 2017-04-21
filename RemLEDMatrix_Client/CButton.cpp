#include"CButton.hpp"

// -- Konstruktor --
CButton::CButton() {
	// Alloc Memory
	_wasPushed = new bool;
	_font = new sf::Font();
	_text = new sf::Text();
	_btn  = new sf::RectangleShape();

	// Default-Werte setzen
	setFont("C:\\Windows\\Fonts\\Consola.ttf");
	setButtonSize(200, 75);
	setTextSize(50);
	setTextColor(sf::Color::Black);
	setTextColor(sf::Color(128, 128, 128));
	setText("Knopf");
	setPosition(0, 0);

	// Werte setzen
	*_wasPushed = false;

}

// -- update --
// Methode updatet den Knopf und checkt ob der Knopf gedrückt wurde
// @param win: Window in dem der Knopf gezeichnet wird
void CButton::update(sf::RenderWindow &win) {
	if (_btn->getGlobalBounds().contains(
		sf::Mouse::getPosition(win).x,
		sf::Mouse::getPosition(win).y) &&
		sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		*_wasPushed = true;
	}
}

// -- setPosition --
// Methode mit der man die Position des Knopfes verändern kann
// @param x, y: Neue Position
//
void CButton::setPosition(float x, float y) {
	_btn->setPosition(x, y);
	_text->setPosition(_btn->getPosition().x + 10.F, _btn->getPosition().y);
}

// -- setPosition --
// Methode mit der man die Position des Knopfes verändern kann
// @param pos: Neue Position
//
void CButton::setPosition(sf::Vector2f pos) {
	setPosition(pos.x, pos.y);
}

// -- setFontColor --
// Methode mit der man die Farbe des Texts des Knopfs verändern kann
// @param color: Neue Farbe des Textes
//
void CButton::setTextColor(sf::Color color) {
	_text->setColor(color);
}

// -- setButtonColor --
// Methode mit der man die Farbe des Knopfs setzen kann
// @param color: Neue Farbe des Knopfs
//
void CButton::setButtonColor(sf::Color color) {
	_btn->setFillColor(color);
}

// -- setFont --
// Methode mit der man die Schriftart des Texts setzen kann
// @param path: Pfad zur/Name der Schriftart die verwendet werden soll
//
void CButton::setFont(std::string path) {
	if (!_font->loadFromFile(path))
		std::cout << "Schriftart konnte nicht geladen werden: " << path << std::endl;
	else
		_text->setFont(*_font);
}

// -- setButtonSize --
// Methode mit der man die Größe des Knopfes verändern kann
// @param x, y: Neue Größe des Knopfs
//
void CButton::setButtonSize(float x, float y) {
	_btn->setSize(sf::Vector2f(x, y));
}

// -- setButtonSize --
// Methode mit der man die Größe des Knopfes verändern kann
// @param size: Neue Größe des Knopfs
//
void CButton::setButtonSize(sf::Vector2f size) {
	setPosition(size.x, size.y);
}

// -- setTextSize --
// Methode mit der man die größe des Texts verändern kann
// @param size: Neue Größe
//
void CButton::setTextSize(int size) {
	_text->setCharacterSize(size);
}

// -- setText --
// Methode mit der man den Text des Buttons verändern kann
// @param text: Neuer Text des Knopfs
// 
void CButton::setText(std::string text) {
	_text->setString(text);
}

// -- render --
// Methode mit der man den Knopf zeichnen kann
// @param win
//
void CButton::render(sf::RenderWindow &win) {
	win.draw(*_btn);
	win.draw(*_text);
}

// -- invertTextColor
// Methode invertiert die Farbe des Knopfs und setzt diese Farbe als Text Farbe
//
void CButton::invertTextColor() {
	setTextColor(sf::Color(255 - _btn->getFillColor().r,
						   255 - _btn->getFillColor().g,
						   255 - _btn->getFillColor().b));
}

// -- wasPushed --
// Methode gibt zurück ob der Knopf gedrückt wurde
bool CButton::wasPushed() {
	if (*_wasPushed) {
		*_wasPushed = false;
		return true;
	} else {
		return false;
	}
}

// -- Destruktor --
CButton::~CButton() {
	// Free Memory
	SAFE_DELETE(_wasPushed);
	SAFE_DELETE(_font);
	SAFE_DELETE(_text);
	SAFE_DELETE(_btn);
}