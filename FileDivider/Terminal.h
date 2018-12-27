/* Terminal.h */

#pragma once
#include "stdafx.h"
#include "iTerminal.h"

/**
* iTerminal realisation
* Implements user communication via console
* Manages other classes
**/
class Terminal : public iTerminal{
private:
	const int menuSize = 4;
	/* Contains overall information about version, config status etc. */
	std::string infoText;

	/* Prints menu */
	void printMenu(int);

public:
	
	void run() override;
	
	void print(std::string) override;
	
	void print(char *, unsigned) override;
	
	void adToInfo(std::string) override;
	
	void printInfo() override;

	std::string readLine() override;
};