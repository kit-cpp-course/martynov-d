/* Config.h */

#pragma once
#include "stdafx.h"

class iTerminal;

/**
* Configuration responsible class
* Creates, loads and manages configurations
**/
class Config {
private:
	/* Represents .fdblock files quantity */
	unsigned _fileQuantity;
	/* Represents buffer size */
	unsigned _bufferSize;

public:
	/* Loads configurations from cfg.txt file or creates new cfg.txt */
	void loadConfig(iTerminal *);

	/* Saves configurations to cfg.txt file */
	void saveConfig();

	/* Sets default values to configurations*/
	void setDefaultConfig();

	/* Returns .fdblock file quantity */
	unsigned fileQuantity();

	/* Returns buffer size */
	unsigned bufferSize();

};