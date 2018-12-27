/* Builder.h */

#pragma once
#include "stdafx.h"

class iTerminal;
class Config;

/* Manages file restortion from .fdblock files*/
class Builder {
private:
	/**
	* Loads input .fdblock files
	* Loads cfg.txt file
	* Creates output file
	* Rebuilds output file from .fdblock files
	**/
	void build(iTerminal *, Config *, std::string, std::string);
public:
	/**
	* Builder main method
	* Shows info
	* Checks cfg.txt
	* Launches build() method
	**/
	void run(iTerminal *, Config *);
};