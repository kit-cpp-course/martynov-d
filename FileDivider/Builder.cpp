#include "stdafx.h"
#include "Builder.h"
#include "iTerminal.h"
#include "Config.h"

void Builder::run(iTerminal * terminal, Config * cfg) {
	std::string outputFileName;
	std::string inputDirectoryName;

	//Output file
	terminal->print("**Builder launched**\nEnter output file name\nOutput file extension will be added automatically\n\
OR press ENTER to use default name \"FD_out.*\"\n");
	
	terminal->print(">");
	outputFileName = terminal->readLine();

	if (outputFileName == "") {
		terminal->print("Using file name by default\n");
		outputFileName = "FD_out";
	}

	//Input dir
	terminal->print("\nInput files must be:\n-Named \"0.fdblock\", \"1.fdblock\" etc.\n-Placed in input directory\n\n");
	terminal->print("Enter input directory name\nOR press ENTER to use default name \"FD_input\"\n");

	terminal->print(">");
	inputDirectoryName = terminal->readLine();

	if (inputDirectoryName == "") {
		terminal->print("Using directory name by default\n\n");
		inputDirectoryName = "FD_out";
	}
	
	terminal->print("Make shure to use the same configuration file, that was used to divide your file!\n\n");
	system("pause");

	try {
		build(terminal, cfg, outputFileName, inputDirectoryName);
	}
	catch(int i){
		if (i == 1) {
			terminal->print("Configuration file does not contain necessary information\n");
			terminal->print("!!!Make shure to use the same configuration file, that was used to divide your file!!!\n\n");
		}
	}
	
	system("pause");
}

void Builder::build(iTerminal * terminal, Config * cfg, std::string outputFileName, std::string inputDirectoryName) {
	auto inputFiles = std::vector<std::ifstream>();
	std::ofstream outputFile;
	char * buffer;

	std::string outputFileExtension;

	buffer = new char[cfg->bufferSize()];

	if (std::experimental::filesystem::exists("FD_input")) {
		terminal->print(inputDirectoryName + " directory found\n\n");
	}
	else {
		terminal->print(inputDirectoryName + " directory not found\n\n");
		return;
	}

	std::string inputFileName;
	for (unsigned i = 0; i < cfg->fileQuantity(); i++) {
		inputFileName = inputDirectoryName + "/" + std::to_string(i) + ".fdblock";
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
	

	outputFile.open(outputFileName + outputFileExtension, std::ios::binary);

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
