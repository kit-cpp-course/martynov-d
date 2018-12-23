#pragma once
#include "stdafx.h"

class iTerminal;

class Config {
private:
	unsigned _fileQuantity;
	unsigned _bufferSize;
	bool _newConfig;

public:
	void loadConfig(iTerminal *);
	void saveConfig();
	void setDefaultConfig();
	unsigned fileQuantity();
	unsigned bufferSize();
	bool newConfig();

};