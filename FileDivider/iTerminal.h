/* iTerminal.h */

#pragma once
#include "stdafx.h"

/**
* Control class interface
* Implements user communication
* Manages other classes
**/
class iTerminal {
public:
	/* Terminal main method
	   Displays info, hosts menu and manages other classes */
	virtual void run() = 0;

	/* Prints string to console */
	virtual void print(std::string) = 0;

	/* Prints char array to console */
	virtual void print(char *, unsigned) = 0;

	/* Adds string to information text 
	   Use adToInfo() + printInfo() to prevent your text from being deleted by cls*/
	virtual void adToInfo(std::string) = 0;

	/* Prints to information text
	   Use adToInfo() + printInfo() to prevent your text from being deleted by cls*/
	virtual void printInfo() = 0;

	/* Reads string */
	virtual std::string readLine() = 0;
}; 
