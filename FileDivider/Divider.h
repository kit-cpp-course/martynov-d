/* Divider.h */

#pragma once
#include "stdafx.h"

class iTerminal;
class Config;

/* Manages input file splitting into .fdblock files*/
class Divider {
private:
	/**
	* Loads input file
	* Creates output .fdblock files and FD_output directory
	* Splits input file into .fdblock files
	* Updates cfg.txt file
	**/
	void divide(iTerminal *, Config *, std::string);
public:
	/** 
	* Divider main method
	* Shows info
	* Asks for input file name
	* Launches divide() method
	**/
	void run(iTerminal *, Config *);
};