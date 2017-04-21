#ifndef GLOBALDATA_HPP
#define GLOBALDATA_HPP

// Includes
#include<iostream>
#include<string>
#include<fstream>

namespace GD 
{
	extern int server_port; // Port auf den der Server lauschen soll
	extern std::string fb_path; // Pfad zum FB der LED Matrix

	//Methode mit der man die globalen Daten aus einer Datei laden kann
	// @param file_dir: Pfad zur/Name der .conf Datei
	//
	void laodData(std::string file_dir);
}

#endif