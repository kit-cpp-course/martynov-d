#pragma once
#include "stdafx.h"
#include "iTerminal.h"

/**
* iTerminal realisation
* Implements user communication
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
	/* Terminal main method
	   Displays info, hosts menu and manages other classes */
	void run() override;
	
	/* Prints string to console */
	void print(std::string) override;
	
	/* Prints char array to console */	
	void print(char *, unsigned) override;
	
	/* Adds string to infoText */
	void adToInfo(std::string) override;
	
	/* Prints infoText */
	void printInfo() override;

	/* Reads string from console */
	std::string readLine() override;
};