#include"CProgram.hpp"

// -- Konstruktor --
CProgram::CProgram() {
	// Alloc Memory
	window = new sf::RenderWindow(sf::VideoMode(405, 490), "Remote LED Matrix");
	running = new bool;
	_sfEvent = new sf::Event();
	udp_client = new CUDP_Client();
	gui = new CGUI(*window);

	// Werte setzen
	*running = true;
	gui->setSignals(*this);
}

// -- run --
// Führt den CORE_Loop des Programms aus
//
void CProgram::run() {
	while (window->isOpen()) {
		while (window->pollEvent(*_sfEvent)) { // Prüfen ob ein Event ausgelöst wurde
			lastButton = sf::Mouse::Button::Middle;
			if (_sfEvent->type == sf::Event::Closed) { // Prüfen ob das Fenster geschlossen werden soll
				*running = false;
				window->close();
			} else if (_sfEvent->type == sf::Event::KeyReleased) { // Prüfen ob ein Knopf gedrückt wurde
				if (_sfEvent->key.code == sf::Keyboard::Escape) { // Prüfen ob der ESC-Knopf gedrückt wurde
					*running = false;
					window->close();
				}
			} else if (_sfEvent->type == sf::Event::MouseButtonReleased) {
				lastButton = _sfEvent->mouseButton.button;
			}
			
			gui->handleEvent(*_sfEvent);
		}

		window->clear(sf::Color(200, 200, 200)); // Bildschirm clearen

		// GUI updaten und zeichnen
		gui->update(*this);
		gui->render(*this);

		window->display(); // Grafiken anzeigen
	}
}

// -- isRunning --
// Gibt den aktuellen Programmstatus zurück
//
bool CProgram::isRunning() {
	return *running;
}

// -- getCurEvent --
// Methode gibt das aktuelle Event zurück
//
sf::Event CProgram::getCurEvent() {
	return *_sfEvent;
}

// -- Destruktor --
CProgram::~CProgram() {
	// Free Memory
	SAFE_DELETE(udp_client);
	SAFE_DELETE(_sfEvent);
	SAFE_DELETE(running);
	SAFE_DELETE(window);
	SAFE_DELETE(gui);
}