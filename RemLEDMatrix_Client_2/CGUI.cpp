#include"CGUI.hpp" 
#include"CProgram.hpp"

// -- Konstruktor --
CGUI::CGUI(sf::RenderWindow &win) {
	this->setWindow(win);

	// Alloc Memory
	_canvas  = new Canvas();
	_ip_TB   = tgui::TextBox::create();
	_port_TB = tgui::TextBox::create();
	_connect_BTN = tgui::Button::create();
	_drawController = new CDrawController();

	// Werte Setzen
	// IP-Textbox
	_ip_TB->setFont("blurb.ttf");
	_ip_TB->setTextSize(30);
	_ip_TB->setSize(255, 30);
	_ip_TB->setPosition(10, 410);
	_ip_TB->setMaximumCharacters(15);
	_ip_TB->setText("IP");
	this->add(_ip_TB, IP_TEXTBOX);

	// Port-Textbox
	_port_TB->setFont("blurb.ttf");
	_port_TB->setTextSize(30);
	_port_TB->setSize(120, 30);
	_port_TB->setPosition(275, 410);
	_port_TB->setMaximumCharacters(7);
	_port_TB->setText("PORT");
	this->add(_port_TB, PORT_TEXTBOX);

	// Verbinden Knopf
	_connect_BTN->setFont("blurb.ttf");
	_connect_BTN->setTextSize(30);
	_connect_BTN->setText("Verbinden");
	_connect_BTN->setPosition(10, 450);
	_connect_BTN->setSize(200, 30);
	this->add(_connect_BTN, CONNECT_BUTTON);
}

// -- update --
// Methode updated das GUI
// @param prog: Aktuell laufendes Programm
//
void CGUI::update(CProgram &prog) {
	_drawController->run();
	_canvas->update(prog, _drawController);
}

// -- render --
// Methode rendert das GUI
// @param prog: Aktuell laufendes Programm
//
void CGUI::render(CProgram &prog) {
	this->draw();
	_canvas->render(prog);
}

// -- setSignals --
// Methode mit der die Signale der UI-Elemente gesetzt wird
// @param prog: Aktuell laufendes Programm
//
void CGUI::setSignals(CProgram &prog) {
	// Den Verbinden Knopf verlinken
	this->get<tgui::Button>(CONNECT_BUTTON)->connect(
		"pressed",
		&CGUI::setHost,
		this,
		std::ref(prog));

	// Den Zeichnen Knopf verlinken
	_drawController->get<tgui::Button>(DRAW_BTN)->connect(
		"pressed",
		&CGUI::sendData,
		this,
		std::ref(prog));
}

// -- setHost --
// Methode legt den Host fest
// @param prog: Aktuell laufendes Programm
//
void CGUI::setHost(CProgram &prog) {
	prog.udp_client->setHost(
		this->get<tgui::TextBox>(IP_TEXTBOX)->getText().toAnsiString(),
		this->get<tgui::TextBox>(PORT_TEXTBOX)->getText().toAnsiString());
}

// -- sendData --
// Methode sendet die nötigen Daten an den Host
// @param prog: Aktuell laufendes Programm
//
void CGUI::sendData(CProgram &prog) {
	prog.udp_client->sendData(_canvas->getCanvasData());
}

// -- Destruktor --
CGUI::~CGUI() {
	// Free Memory
	SAFE_DELETE(_canvas);
	SAFE_DELETE(_drawController);
}