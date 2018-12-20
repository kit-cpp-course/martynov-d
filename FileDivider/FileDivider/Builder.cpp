#include "stdafx.h"
#include "Builder.h"
#include "iTerminal.h"
#include "Config.h"

void Builder::run(iTerminal * terminal, Config * cfg) {
	terminal->adToInfo("**Builder launched**\nInput files must be:\n-Named \"0.txt\", \"1.txt\" etc.\n-Placed in \"FD_Input\" directory\n");
	terminal->adToInfo("Make shure to use the same configuration file, that was used to divide your file!\n\n");
	system("cls");
	terminal->printInfo();
	system("pause");

	build(terminal, cfg);

	system("pause");
}

void Builder::build(iTerminal * terminal, Config * cfg) {
	auto inputFiles = std::vector<std::ifstream>();
	std::ofstream outputFile;
	char * buffer;

	buffer = new char[cfg->bufferSize()];

	if (std::experimental::filesystem::exists("FD_intput")) {
		terminal->print("FD_input directory found\n\n");
	}
	else {
		terminal->print("FD_input directory not found\n\n");
		return;
	}

	std::string inputFileName;
	for (unsigned i = 0; i < cfg->fileQuantity(); i++) {
		inputFileName = "FD_input/" + std::to_string(i) + ".txt";
		inputFiles.push_back(std::ifstream(inputFileName, std::ios::binary));
	}

	terminal->print("Input files loaded\n");

	outputFile.open("FD_out.txt", std::ios::binary);

	std::string s;
	std::ifstream cfgFile;
	cfgFile.open("cfg.txt");
	getline(cfgFile, s);
	getline(cfgFile, s);
	getline(cfgFile, s);
	getline(cfgFile, s);
	getline(cfgFile, s);
	int buffsCount = std::stoi(s);
	cfgFile.close();

	int looper = 0;
	for(buffsCount; buffsCount >= 0; buffsCount--){

		for (unsigned i = 0; i <= cfg->bufferSize(); i++) {
			buffer[i] = ' ';
		}
		inputFiles[looper].read(buffer, cfg->bufferSize());

		outputFile.write(buffer, cfg->bufferSize());

		if (looper < cfg->fileQuantity() - 1) { looper++; }
		else { looper = 0; }

	}

	terminal->print("File built successfully\n");
	
	outputFile.close();

	for (unsigned i = 0; i < cfg->fileQuantity(); i++) {
		inputFiles[i].close();
	}
}
