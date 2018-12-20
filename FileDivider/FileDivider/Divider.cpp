#include "stdafx.h"
#include "Divider.h"
#include "iTerminal.h"
#include "Config.h"

void Divider::run(iTerminal * terminal, Config * cfg) {
	terminal->adToInfo("**Divider launched**\nEnter source file name\nOR press ENTER to cancel\n");
	system("cls");
	terminal->printInfo();

	std::string inputFileName;
	std::ifstream inputFile;

	while (true) {
		terminal->print(">");
		inputFileName = "";
		inputFileName = terminal->readLine();

		if (inputFileName == "") {
			terminal->print("**Divider stopped**\n\n");
			system("pause");
			break; 
		}

		inputFile.open(inputFileName);

		if (inputFile) {
			divide(terminal, cfg, inputFileName);
			inputFile.close();
			break;
		}

		terminal->print("File not found\n\n");
		system("pause");

		system("cls");
		terminal->printInfo();

	}
}

void Divider::divide(iTerminal * terminal, Config * cfg, std::string inputFileName) {
	auto outputFiles = std::vector<std::ofstream>();
	std::ifstream inputFile;
	char * buffer;

	inputFile.open(inputFileName, std::ios::binary);

	buffer = new char[cfg->bufferSize()];

	std::experimental::filesystem::create_directory("FD_output");

	std::string outputFileName;
	for (unsigned i = 0; i < cfg->fileQuantity(); i++) {
		outputFileName = "FD_output/" + std::to_string(i) + ".txt";
		outputFiles.push_back(std::ofstream(outputFileName, std::ios::binary));
	}


	int looper = 0;
	int buffsCount = 0;
	while (!inputFile.eof()) {
		for (unsigned i = 0; i <= cfg->bufferSize(); i++) {
			buffer[i] = ' ';
		}
		inputFile.read(buffer, cfg->bufferSize());

		buffsCount++;

		outputFiles[looper].write(buffer, cfg->bufferSize());

		if (looper < cfg->fileQuantity() - 1) { looper++; }
		else { looper = 0; }

	}

	inputFile.close();

	for (unsigned i = 0; i < cfg->fileQuantity(); i++) {
		outputFiles[i].close();
	}


	std::string s = "";
	std::string tmp;
	std::ifstream cfgFile;
	cfgFile.open("cfg.txt");
	getline(cfgFile, tmp);
	s += tmp + "\n";
	getline(cfgFile, tmp);
	s += tmp + "\n";
	getline(cfgFile, tmp);
	s += tmp + "\n";
	getline(cfgFile, tmp);
	s += tmp + "\n";
	cfgFile.close();

	std::ofstream cfgFileO;
	cfgFileO.open("cfg.txt");
	cfgFileO << s << buffsCount << std::endl;
	cfgFileO.close();
}