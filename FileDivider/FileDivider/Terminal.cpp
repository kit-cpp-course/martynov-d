#include "stdafx.h"
#include "Terminal.h"
#include "Divider.h"
#include "Builder.h"
#include "Config.h"
#include "Help.h"


void Terminal::printMenu(int cursorPosition) {
	std::string menuPoints[] = { "  1. Divide\n",
								"  2. Build\n", 
								"  3. Help\n",
								"  4. Exit\n"};

	menuPoints[cursorPosition][0] = '>';

	for (int i = 0; i < menuSize; i++) {
		print(menuPoints[i]);
	}
}

void Terminal::run() {
	int cp = 0;
	Config cfg = Config();
	infoText = "FileDivider v0.3 by Dmitry Martynov\n\n";
	std::string infoTextBackup;
	
	cfg.loadConfig(this);
	
	print(infoText);
	infoTextBackup = infoText;
	printMenu(cp);
	
	while (true) {
		char c = _getch();
		
		system("cls");
		print(infoText);
		
		if(c == 72) { 
			if (cp > 0) { cp--; }
			printMenu(cp);
		}
		else if(c == 80) { 
			if (cp < menuSize-1) { cp++; }
			printMenu(cp);
		}
		else if (c == '\r') {
			switch (cp)
			{
			case 0:
				Divider divider = Divider();
				divider.run(this, & cfg);
				break;
			case 1:
				Builder builder = Builder();
				builder.run(this, & cfg);
				break;
			case 2:
				print(help);
				system("pause");
				break;
			case 3:
				return;
			}
			infoText = infoTextBackup;
		}
		else {
			printMenu(cp);
		}
		
	}
}

void Terminal::adToInfo(std::string s) {
	infoText += s;
}

void Terminal::print(std::string s) {
	std::cout << s;
}

void Terminal::printInfo() {
	print(infoText);
}

void Terminal::print(char * c, unsigned length) {
	for (unsigned i = 0; i < length; i++) {
		std::cout << c[i];
	}
}

std::string Terminal::readLine() {
	std::string s;
	std::getline(std::cin, s);
	return s;
}

