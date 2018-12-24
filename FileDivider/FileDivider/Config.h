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

	/* Sets _fileQuantity and _bufferSize by default */
	void setDefaultConfig();

	/* _fileQuantity getter */
	unsigned fileQuantity();

	/* _bufferSize getter */
	unsigned bufferSize();

};