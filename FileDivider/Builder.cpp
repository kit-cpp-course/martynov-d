#include "stdafx.h"
#include "Builder.h"
#include "iTerminal.h"
#include "Config.h"

void Builder::run(iTerminal * terminal, Config * cfg) {
	
	terminal->adToInfo("**Builder launched**\nInput files must be:\n-Named \"0.fdblock\", \"1.fdblock\" etc.\n-Placed in \"FD_input\" directory\n");
	terminal->adToInfo("Make shure to use the same configuration file, that was used to divide your file!\n\n");
	system("cls");
	terminal->printInfo();
	system("pause");

	try {
		build(terminal, cfg);
	}
	catch(int i){
		if (i == 1) {
			terminal->print("Configuration file does not contain necessary information\n");
			terminal->print("!!!Make shure to use the same configuration file, that was used to divide your file!!!\n\n");
		}
	}
	
	
	system("pause");
}

void Builder::build(iTerminal * terminal, Config * cfg) {
	auto inputFiles = std::vector<std::ifstream>();
	std::ofstream outputFile;
	char * buffer;

	std::string outputFileExtension;

	buffer = new char[cfg->bufferSize()];

	if (std::experimental::filesystem::exists("FD_input")) {
		terminal->print("FD_input directory found\n\n");
	}
	else {
		terminal->print("FD_input directory not found\n\n");
		return;
	}

	std::string inputFileName;
	for (unsigned i = 0; i < cfg->fileQuantity(); i++) {
		inputFileName = "FD_input/" + std::to_string(i) + ".fdblock";
		inputFiles.push_back(std::ifstream(inputFileName, std::ios::binary));
	}

	terminal->print("Input files loaded\n\n");

	std::string s;
	std::ifstream cfgFile;
	cfgFile.open("cfg.txt");
	getline(cfgFile, s);
	getline(cfgFile, s);
	getline(cfgFile, s);
	getline(cfgFile, s);
	getline(cfgFile, s);
	if (s == "-") {
		throw 1;
		return;
	}
	outputFileExtension = s;
	getline(cfgFile, s);
	int buffsCount = std::stoi(s);
	cfgFile.close();
	

	outputFile.open("FD_out" + outputFileExtension, std::ios::binary);

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