#include"GlobalData.hpp"

namespace GD {

	int server_port;
	std::string fb_path;

	//Methode mit der man die globalen Daten aus einer Datei laden kann
	// @param file_dir: Pfad zur/Name der .conf Datei
	//
	void laodData(std::string file_dir) {
		std::ifstream ifstream;
		std::string str;

		// Datei öffnen
		ifstream.open(file_dir);
		if (!ifstream.is_open())
			throw "EXCEPTION: Konfig-Datei konnte nicht geöffnet werden.";

		// Daten auslesen
		try {
			ifstream >> str;
			GD::server_port = std::stoi(str);
			ifstream >> str;
			GD::fb_path = str;
		}
		catch (std::exception e) {
			std::cout << "EXCEPTION: " << e.what() << std::endl;
		}

		// Datei schliessen
		ifstream.close();
	}
}