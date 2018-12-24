#include "stdafx.h"
#include "Config.h"
#include "iTerminal.h"

unsigned Config::fileQuantity() { return _fileQuantity; }
unsigned Config::bufferSize() { return _bufferSize; }

void Config::loadConfig(iTerminal * terminal) {

	std::string s;

	std::ifstream fin;
	fin.open("cfg.txt");

	if (fin) {
		getline(fin, s);
		getline(fin, s);
		s = s.substr(s.find("=")+1);
		_fileQuantity = std::stoi(s);
		getline(fin, s);
		s = s.substr(s.find("=") + 1);
		_bufferSize = std::stoi(s);
		
		s = "Cfg loaded\n";
	}
	else
	{
		terminal->adToInfo("Cfg file not found\nCreating cfg file by default\n");
		setDefaultConfig();
		saveConfig();
		s = "";
	}

	s += "Current file quantity = " + std::to_string(_fileQuantity) + "\nCurrent buffer size = " + std::to_string(_bufferSize) + "\n\n";

	terminal->adToInfo(s);

	fin.close();
}

void Config::saveConfig() {
	std::ofstream fout;
	fout.open("cfg.txt");
	fout << "Do NOT change anything in this file except numbers\n";
	fout << "File_Quantity=" << _fileQuantity << "\nBuffer_Size=" << _bufferSize << std::endl;
	fout << "For building only.DO NOT CHANGE ANYTHING BELOW\n-\n";
	fout.close();
}

void Config::setDefaultConfig() {
	_fileQuantity = 2;
	_bufferSize = 13;
}