#include"CProgram.hpp"

// -- Konstruktor --
CProgram::CProgram() {
	// Alloc Memory
	_greenslider = new CSlider();
	_blueslider  = new CSlider();
	_redslider   = new CSlider();
	_udpClient   = new CUDP_Client("192.168.2.121", "10000");
	_draw_BTN = new CButton();
	curColor  = new sf::RectangleShape();
	_sfEvent  = new sf::Event();
	_canvas   = new Canvas();
	running   = new bool;
	window    = new sf::RenderWindow(sf::VideoMode(675, 405), "REMOTE LED MATRIX");

	// Werte setzen
	*running = true;

	curColor->setSize(sf::Vector2f(235, 70));
	curColor->setPosition(415, 200);
	curColor->setFillColor(sf::Color::Black);
	curColor->setOutlineColor(sf::Color(128, 128, 128));
	curColor->setOutlineThickness(5.F);

	// Draw Button aufsetzen
	_draw_BTN->setText("Zeichnen");
	_draw_BTN->setButtonColor(sf::Color(64, 64, 64));
	_draw_BTN->setTextColor(sf::Color(200, 200, 200));
	_draw_BTN->setPosition(410, 330);
	_draw_BTN->setButtonSize(235, 70);

	// Farbslider aufsetzen
	_redslider->setPosition(410, 20);
	_greenslider->setPosition(410, 80);
	_blueslider->setPosition(410, 140);

}

// -- run --
// Methode führt den CORE_LOOP des Programms aus
//
void CProgram::run() {
	while (window->isOpen()) {
		while (window->pollEvent(*_sfEvent)) {
			if (_sfEvent->type == sf::Event::Closed) { // Testen ob das Fenster geschlossen wird
				*running = false; // Programm stoppen
				window->close();  // Fenster schliessen
			} if (_sfEvent->type == sf::Event::MouseButtonReleased) { // Testen ob eine Taste der Maus gedrückt wurde
				lastButton = _sfEvent->mouseButton.button;
				_canvas->update(*this);
			}
		}

		window->clear(sf::Color(230, 230, 230));

		// Die LED-Matrix updaten und zeichnen
		//_canvas->update(*this);
		_canvas->render(*this);

		// Den Zeichnen-Button zeichnen und updaten
		_draw_BTN->update(*window);
		_draw_BTN->render(*window);

		if (_draw_BTN->wasPushed())
			_udpClient->sendData(_canvas->getCanvasData());

		// Farbe des curCol updaten
		curColor->setFillColor(sf::Color(
			_redslider->updateSlider(*window),
			_greenslider->updateSlider(*window),
			_blueslider->updateSlider(*window)));

		// Slider zeichnen
		_redslider->render(*window);
		_blueslider->render(*window);
		_greenslider->render(*window);

		// curCol zeichnen
		window->draw(*curColor);

		window->display();
	}
}

// -- isRunning --
// Methode gibt den aktuellen Programm-Status zurück
//
bool CProgram::isRunning() {
	return *running;
}

// -- adjustColorSlider --
// Setzt die ColorSlider und dir curCol auf eine bestimmte Farbe
// @param color: Farbe auf die die Slider, etc. gesetzt werden sollen
//
void CProgram::adjustColorSlider(sf::Color color) {
	curColor->setFillColor(color);
	_redslider->adjustValue(color.r);
	_blueslider->adjustValue(color.b);
	_greenslider->adjustValue(color.g);
}

// -- Destruktor --
CProgram::~CProgram() {
	SAFE_DELETE(_udpClient);
	SAFE_DELETE(_draw_BTN);
	SAFE_DELETE(_greenslider);
	SAFE_DELETE(_blueslider);
	SAFE_DELETE(_redslider);
	SAFE_DELETE(_sfEvent);
	SAFE_DELETE(running);
	SAFE_DELETE(_canvas);
	SAFE_DELETE(window);
}